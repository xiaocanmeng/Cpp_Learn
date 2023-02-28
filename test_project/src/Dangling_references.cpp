#include <iostream>
//悬垂引用
std::string &f() {
  std::string s = "Example";
  return s; // 退出 s 的作用域：调用其析构函数并解分配其存储
}