#include <iostream>
#include <string>
#include <string_view>

int main()
{
  std::string s;
  std::cout << sizeof(s) << '\n';
  std::cout << s.capacity() << '\n';
  int valOfEnd = s[0];
  std::cout << valOfEnd << '\n';

  std::cout << "---\n";

  std::string_view sv;
  std::cout << sv.size() << '\n';
  std::cout << ">" << sv << "<\n";
  valOfEnd = sv[0];   // RUNTIME ERROR
  std::cout << valOfEnd << '\n';
}
