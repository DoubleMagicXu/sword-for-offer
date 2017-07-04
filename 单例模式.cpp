/*************************************************************************
	> File Name: 单例模式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 22时52分07秒
 ************************************************************************/
//懒汉式,只试用于单线程
#include<iostream>
using namespace std;
class Singleton1
{
    //最简单的：把构造函数设为私有，静态实例
public:
    static Singleton1*  getInstance()
    {
        if(instance==NULL)
        {
            
            instance=new Singleton1();
        }
        return instance;
    }

private:
    Singleton1(){};
    static Singleton1* instance;//外面实例化
};
Singleton1* Singleton1::instance=NULL;



//饿汉式
class Singleton2
{
public:
    static const Singleton2* getInstance()
    {
        return instance;
    }
private:
    Singleton2()
    {
    
    }
    static const Singleton2* instance;//为什么一定要加const
};

const Singleton2* Singleton2:: instance=new Singleton2();


void test()
{
    Singleton1* x=Singleton1::getInstance();
   const  Singleton2* y=Singleton2::getInstance();
}
int main()
{
    test();
    return 0;
}
