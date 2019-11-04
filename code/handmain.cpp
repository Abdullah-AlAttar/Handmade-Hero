#include <iostream>

#include <windows.h>
#include <string>

struct Point
{
  int a,b;
};
int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd)
{
  auto [a,b] = Point{3,4};
  std::string str{"Wow"};
  str += std::to_string(a) + " "+ std::to_string(b);

  std::cout<<"Hello World"<<std::endl;
  MessageBox(
      0,
      str.c_str(),
      "HandMade",
      MB_OK | MB_ICONINFORMATION);
  return 0;
}
