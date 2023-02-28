#include "Value_Category.h"
#include "Perfect_Forwarding.h"

int main()
{
#if 0
  test_value_0(); //测试值类别
#endif  

  test_Perfect_Forwarding();
  //测试完美转发，完美转发 = 引用折叠 + 万能引用 + std::forward


  return 0;
}