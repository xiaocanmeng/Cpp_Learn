#include <iostream>
#include <string>
#include <utility>
using namespace std;
#include "Value_Category.h"

A f(A a) { return a; }

int test_value_0() 
{
  A a1, a2;
  //纯右值：不拥有身份且可被移动的表达式
  std::cout << "尝试从右值临时量移动赋值 A\n";
  a1 = f(A()); // 从纯右值临时量移动赋值
  //亡值：拥有身份且可被移动的表达式被称作亡值 (xvalue)
  std::cout << "尝试从亡值移动赋值 A\n";
  a2 = std::move(a1); // 从亡值移动赋值

  std::cout << "\n尝试移动赋值 B\n";
  B b1, b2;
  std::cout << "移动前，b1.s = \"" << b1.s << "\"\n";
  b2 = std::move(b1); // 调用隐式移动赋值
  std::cout << "移动后，b1.s = \"" << b1.s << "\"\n";

  std::cout << "\n尝试移动赋值 C\n";
  C c1, c2;
  c2 = std::move(c1); // 调用复制赋值运算符

  std::cout << "\n尝试移动赋值 D\n";
  D d1, d2;
  d2 = std::move(d1);
 int a=0;
 ++a = 0;
//  a++ = 1;
 int &b =a;//左值引用
 int && c=  0;//右值引用
 const int &d = 11;//常量左引用
std::cout<<b<<std::endl<<c<<std::endl<<d;
//  std::cout<<++a<<std::endl;
//  std::cout<<a++;
 //"aa" = "bb"
 return 0;
}

class IntNum {
public:
  IntNum(int x = 0) { //构造函数
    xptr = new int(x);
    // xptr = &x;
    // *xptr = x;
    cout << "Calling constructor..." << endl;
  }
  IntNum(const IntNum &n) { //复制构造函数
    xptr = new int(*n.xptr);
    cout << "Calling copy constructor..." << endl;
  };
  IntNum(IntNum &&n) { //移动构造函数
    xptr = n.xptr;
    n.xptr = nullptr;
    cout << "Calling move constructor..." << endl;
  }

  ~IntNum() { //析构函数
    delete xptr;
    cout << "Destructing..." << endl;
  }
  int getInt() { return *xptr; }

private:
  int *xptr;

public:
  char b = 'B';
};
//返回值为IntNum类对象
IntNum getNum() {
  IntNum a;
  for (int i = 0; i < 10; i++) {
    cout << "*";
  }
  return a;
}

int test_value_2() 
{
//指针可以用->

  IntNum *tst_1 = new  IntNum(6);
  cout<<tst_1->getInt()<<endl<<tst_1->b<<endl;
  cout << (*tst_1).getInt() << endl << (*tst_1).b << endl;
  IntNum tst_2(9);
  cout <<tst_2.getInt()<<endl<<tst_2.b<< endl;
  cout << (&tst_2)->getInt() << endl << (&tst_2)->b << endl;
  IntNum tst_3(*tst_1);//调用复制构造函数，深度复制
  cout << tst_3.getInt() << endl << tst_3.b << endl;
  delete tst_1;
  tst_1 = nullptr;
  IntNum b(move(getNum()));
  return 0;
}
