#include <iostream>
#include <string>
#include <vector>

template<typename CollT>
void print(const CollT& coll)
{
  for (const auto& elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << " (" << coll.size() << " elems)\n";
}

std::vector<std::string> getData()
{
  return {"have", "a", "break"};
}

  int main()
  {
#ifdef RBFOR_ERROR
    // ERROR using the range-based for loop:
    for (char c : getData()[0]) {
#else
      // OK:
      const auto& rg = getData();
      for (char c : rg[0]) {
#endif
        std::cout << c << '\n';
      }
    }
