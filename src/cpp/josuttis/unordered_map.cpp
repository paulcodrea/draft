#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "buckets.hpp"

class UUID {
};

int main()
{
  std::unordered_map<int, std::string> coll;
  
  //coll.push_back(15);                            // append one element
  coll.insert({0, "Test"});                            // append one element

  coll.max_load_factor(0.70f);

  // initialize vector with values
  for (int val : {1, 2, 3, 5, 8, 9, 11, 13, 17}) {
    coll.insert({val, "TestData" + std::to_string(val)});
  }

  for (const auto& [key, val] : coll) {          // print elements with range-based for loop
    std::cout << key << ":" << val << ' ';
  }
  std::cout << '\n';

  printHashTableState(coll);

  for (int val : {700, 133, 0, 20}) {
    coll.insert({val, "TestData" + std::to_string(val)});
  }
  printHashTableState(coll);

  std::hash<std::string> hfString;
  std::cout << hfString("Nomura") << '\n';
  std::cout << hfString("Numora") << '\n';
  std::cout << hfString("") << '\n';
  std::hash<int> hfInt;
  std::cout << "42: " << hfInt(42) << '\n';
  std::cout << "0:  " << hfInt(0) << '\n';
  std::cout << "1000000000: " << hfInt(1000000000) << '\n';
}
