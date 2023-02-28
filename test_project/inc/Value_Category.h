#ifndef VALUE_CATEGORY
#define VALUE_CATEGORY
#include <iostream>
struct A {
  std::string s;

  A() : s("测试") {}

  A(const A &o) : s(o.s) { std::cout << "移动失败！\n"; }

  A(A &&o) : s(std::move(o.s)) {}

  A &operator=(const A &other) {
    s = other.s;
    std::cout << "复制赋值\n";
    return *this;
  }

  A &operator=(A &&other) {
    s = std::move(other.s);
    std::cout << "移动赋值\n";
    return *this;
  }
};

extern A f(A a);


struct B : A {
  std::string s2;
  int n;
  // 隐式移动赋值运算符 B& B::operator=(B&&)
  // 调用 A 的移动赋值运算符
  // 调用 s2 的移动赋值运算符
  // 并进行 n 的逐位复制
};

struct C : B {
  ~C() {} // 析构函数阻止隐式移动赋值
};

struct D : B {
  D() {}
  ~D() {}                       // 析构函数本会阻止隐式移动赋值
  D &operator=(D &&) = default; // 无论如何都强制移动赋值
};

extern int test_value_0();
#endif