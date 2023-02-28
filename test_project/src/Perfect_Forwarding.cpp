#if 1
#include <boost/type_index.hpp>
#include <iostream>

using namespace std;
using boost::typeindex::type_id_with_cvr;

template <typename T> void PrintType(T &&param) {
  // 利用Boost库打印模板推导出来的 T 类型
  cout << "T type：" << type_id_with_cvr<T>().pretty_name() << endl;

  // 利用Boost库打印形参的类型
  cout << "param type:" << type_id_with_cvr<decltype(param)>().pretty_name()
       << endl;
}

void test_Perfect_Forwarding_1() 
{
  int a = 0;    // 左值
  PrintType(a); // 传入左值

  int &lvalue_refence_a = a;   // 左值引用
  PrintType(lvalue_refence_a); // 传入左值引用

  PrintType(int(2)); // 传入右值
}
#endif

#if 0
/*
 *  Boost库在这里已经不需要了，我们将其拿掉，可以更简洁的看清楚转发的代码实现
 */

#include <iostream>
using namespace std;


// 接收左值的函数 f()
template <typename T> void f(T &) { cout << "f(T &)" << endl; }

// 接收右值的函数f()
template <typename T> void f(T &&) { cout << "f(T &&)" << endl; }

// 万能引用，转发接收到的参数 param
template <typename T> void PrintType(T &&param) {
  f(std::forward<T>(param)); // 将参数param转发给函数 void f()
}

void test_Perfect_Forwarding_2() {
  int a = 0;
  PrintType(a);      //传入左值
  PrintType(int(0)); //传入右值
}
#endif
/*
 *  精简了标准库的代码，在细节上可能不完全正确，但是足以让我们了解转发函数
 * forward 的了
 */

/*
template <typename T> T &&forward(T &param) 
{ return static_cast<T &&>(param); }
*/