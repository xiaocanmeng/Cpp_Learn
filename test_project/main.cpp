#include "Value_Category.h"
#include "Perfect_Forwarding.h"
#include "Dangling_references.h"
#include "Iostream.h"

/*在CMakeLists.txt中增加宏定义进行控制*/
int main()
{
#if value 
  test_value_0(); //测试值类别
#endif  

#if Perfect_Forwarding 
  test_Perfect_Forwarding_1();
  //测试完美转发，完美转发 = 引用折叠 + 万能引用 + std::forward
#endif

#if Dangling_references 
  std::string &r = f(); // 悬垂引用
  std::cout << r;       // 未定义行为：从悬垂引用读取
  // std::string s = f();  // 未定义行为：从悬垂引用复制初始化
#endif

#if Iostream
  test_iostream();
#endif

      return 0;
}