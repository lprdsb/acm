#include <iostream>
 
constexpr int size(int i)
{
    return i*2;
}
 
int main(void)
{
    int i = 10;
    int s = size(i);//编译错误:传入参数接受了一个非常量实参，此时constexpr退化为普通函数了
}