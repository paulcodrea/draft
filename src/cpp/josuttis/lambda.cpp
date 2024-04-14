#include <iostream>
#include <string>
#include <vector>

template<typename LambdaT>
void foo(LambdaT op1, LambdaT op2)
{
}

int main()
{
  auto l1 = [] {
    return 42;
  };

  auto l2 = [] {
    return 42;
  };

  auto l3 = l2;

  std::cout << l1() << '\n';
  std::cout << l2() << '\n';
  std::cout << l3() << '\n';

  //foo(l1, l2); // ERROR
  foo(l2, l3);  // OK

  std::cout << std::is_same<decltype(l1), decltype(l2)>::value << '\n';
  std::cout << std::is_same<decltype(l3), decltype(l2)>::value << '\n';

  const int c = 42;
  std::remove_const_t<decltype(c)> x;   // int
  const int& r = c;
  std::remove_const_t<decltype(r)> x;   // const int&
  std::remove_const_t<std::remove_reference_t<decltype(r)>> x; // int 
}
