#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person {
  std::string name;
 public:
  Person(const std::string& n)
   : name{n} {
  }
  Person(const char* n)
   : name{n} {
  }
  std::string getName() const {
    return name;
  }
  friend std::ostream& operator<< (std::ostream& strm, const Person& p) {
    return strm << p.name;
  }

  Person(const Person& p) 
   : name{p.name} {
       std::cout << "COPY " << p << '\n';
  }
  Person& operator= (const Person& p) {
    std::cout << "COPYASSIGN " << p << '\n';
    name = p.name;
    return *this;
  }
  Person(Person&& p) = default;
  Person& operator= (Person&& p) = default;
};


//  Person p{"TestPerson for move"};
//  insertTwice(coll, p);
//  insertTwice(coll, std::move(p));
#ifdef OVERLOADING
void insertTwice(std::vector<Person>& vec, const Person& p) 
{
  vec.push_back(p);
  vec.push_back(p);
}
void insertTwice(std::vector<Person>& vec, Person&& p) 
{
  vec.push_back(p);    // COPY
  vec.push_back(std::move(p));   // MOVE
}
#else // perfect forwarding:
template<typename ElemT, typename ValueT>
void insertTwice(std::vector<ElemT>& vec, ValueT&& p) 
{
  vec.push_back(p);    // COPY
  vec.push_back(std::forward<ValueT>(p));   // COPY or MOVE
}
#endif


int main(int argc, char** argv)
{
  int numPersons = 1000;
  if (argc > 1) {
    numPersons = std::atoi(argv[1]);
  }
  std::vector<Person> coll{"1", "2", "3", "5", "8", "9", "11", "13", "17"};  // initialize vector with values
  coll.reserve(numPersons +100);

  for (unsigned i = 0; i < coll.size(); ++i) {   // print elements with index operator
    std::cout << coll[i] << ' ';
  }
  std::cout << '\n';

  std::cout << "capacity(): " << coll.capacity() << '\n';

  for (int i=0; i < numPersons; ++i) {
    coll.push_back("PersonWithALongName" + std::to_string(i));                            // append one element
  }
  std::cout << "capacity(): " << coll.capacity() << '\n';

  for (const auto& elem : coll) {                        // print elements with range-based for loop
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  coll.insert(coll.begin(), {"0", "8", "23"});         // insert multiple elements

  std::sort(coll.begin(), coll.end(),
            [] (const auto& p1, const auto& p2) {
              return p1.getName() < p2.getName();
            });           // sort all elements

  for (auto pos = coll.begin(); pos != coll.end(); ++pos) {  // low-level loop with iterator
    std::cout << *pos << ' ';                                // printing each element
  }  
  std::cout << '\n';

  Person p{"TestPerson for move"};
  insertTwice(coll, p);
  insertTwice(coll, std::move(p));
}
