#include<iostream>
using namespace std;
class A
{
    public : virtual void Func()
    {
        cout << "A::Func" << endl;
    }
};
class B:public A
{
    public : virtual void Func()
    {
        cout << "B::Func" << endl;
    }
};
int main()
{
    A a;
    A *pa = new B();//pa指向新建B类对象首地址
    pa->Func();
    //64位程序指针位8个字节
    long long *p1 = (long long*) &a;
    long long *p2 = (long long*) pa;
    *p2 = *p1;//使B对象首地址=A对象首地址
    pa->Func();//此时B对象首地址(虚函数表)变为A 即多态形成的原因
    return 0;
}