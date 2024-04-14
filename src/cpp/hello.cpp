#include <iostream>
#include "functions.h"

using std::cout;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;
using std::begin;
using std::end;

#include <algorithm>
using std::sort;
using std::count;

int main()
{

  /*
  double firstNumber=0;
  double secondNumber=0;
  // std::cout << "Hello";

  cout << "Enter a number: ";
  cin >> firstNumber;
  //  cout << "You have entered " << firstNumber << '\n';

  cout << "Enter a second number: ";
  cin >> secondNumber;
  //  cout << "You have entered " << secondNumber << '\n';

  double total = add(firstNumber, secondNumber);
  cout << "Total sum " << total << '\n';

  string name;
  cout << "whoami";

  cin >> name;

  int l = name.length();
  cout << "Your name has " << l << "characters long \n";

  */

  vector<int> nums;
  for (int i = 0; i < 10; i++)
  {
    nums.push_back(i);
  }

  for (auto item: nums)
  {
    cout << item << " ";
  }
  cout << '\n';

  // vector<string> words;

  return 0;
}
