/*************************************************************************
	> File Name: 单例模式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 22时52分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Singleton1()
{
    //最简单的：把构造函数设为私有，静态实例
public:
    static Singleton1*  getInstance();

private:
    Singleton1();
    static Singleton1* instance;
}
