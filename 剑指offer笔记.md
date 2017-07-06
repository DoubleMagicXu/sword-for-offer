#剑指offer笔记

**赋值运算符函数**
    1.返回值为引用
    2.参数为常量引用
    3.释放实例自身已有的内存
    4.赋值给自身的情况

````c++
/*************************************************************************
	> File Name: 赋值运算符.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 20时51分32秒
 ************************************************************************/
#include<cstring>
#include<iostream>
using namespace std;
class CMyString
{
public:
    CMyString(char* pData=NULL);
    CMyString(const CMyString& str);
    void print();
    ~CMyString();
    CMyString& operator = (const CMyString &str);//注意参数；返回值；
private:
    char* m_pData;
};//注意引号

CMyString::CMyString(char* pData)
{
    if(pData==NULL)
    {
        m_pData=new char[1];
        m_pData[0]='\0';
    }
    else
    {
        m_pData=new char[strlen(pData)+1];
        strcpy(m_pData,pData);
    }
}
CMyString::CMyString(const CMyString& str)//注意参数
{
    m_pData=new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);//深拷贝
    
}

void CMyString::print()
{
    cout<<m_pData<<endl;//注意
}

CMyString& CMyString::operator = (const CMyString& str )
{
    if(this!=&str)
    {
        //不是本身
        delete []m_pData;
        m_pData=new char[strlen(str.m_pData)+1];
        strcpy(m_pData,str.m_pData);

    }
    return *this;//注意返回值
}

CMyString::~CMyString()
{
    delete []m_pData;
}

int main()
{
    char* a=(char*)"hello";
    CMyString A(a);
    CMyString B((char*)"nihao");
    A=B;
    A.print();
    return 0;
}
````

**单例模式**

    懒汉式以及饿汉式

````c++
/*************************************************************************
	> File Name: 单例模式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 22时52分07秒
 ************************************************************************/
//懒汉式,只适用于单线程
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
````
**二维数组查找**

````c++
/*************************************************************************
	> File Name: 二维数组查找.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月06日 星期四 15时19分03秒    
    > 二维数组由左到右，由上到下递增
 ************************************************************************/

#include<iostream>
using namespace std;
bool Find(int matrix[],int row,int column,int number)
{
    bool outcome=false;
    if(matrix!=NULL&&row>0&&column>0)//判断合法性
    {
        int i=0;//第一行
        int j=column-1;//最后一列
        while(i<=row&&j>=0)
        {
            if(number==matrix[i*column+j])
            {
                outcome=true;
                cout<<i+1<<"行\t"<<j+1<<"列"<<endl;
                break;
            }
            else if(matrix[i*column+j]>number)
            {
                j--;
            }
            else
            {
                i++;
            }
        

        }
    }
    if(!outcome)
    {
        cout<<"没找到"<<endl;
    }
    return outcome;
}
int main()
{
    int matrix[]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    Find(matrix,4,4,9);
    return 0;
}
````
*注意不可以从左上角和右下角开始查找。*

**字符串替换**
````c++
/*************************************************************************
	> File Name: 替换空格.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月06日 星期四 16时07分33秒
    > 把所有空格替换成%20;思路是首先把数组扫一遍，统计有多少个空格，再从数组末尾进行相应操作
*************************************************************************/
#include<iostream>
using namespace std;
void ReplaceBlack(char string[],int length)
{
    //首先检查合法性
    if(string!=NULL&&length>0)
    {
        int newLength=0;
        int count=0;
        while(newLength<length&&string[newLength]!='\0')//没结束
        {
            if(newLength==length-1)//如果整个数组都没出现'\0'
            {
                return;
            }
            if(string[newLength]==' ')//空格
            {
                count++;
            }
            newLength++;
        }
        newLength++;
        int oldLength=newLength;
        newLength=newLength+count*2;//一个空格就加两个单位大小
        if(newLength>length||count==0)//容量不够或者没有空格
        {
            return;
        }
        while(oldLength-1>=0)
        {
            if(string[oldLength-1]!=' ')//不是空格，则照搬
            {
                string[newLength-1]=string[oldLength-1];
                newLength--;
                oldLength--;
            }
            else
            {
                string[newLength-1]='0';
                newLength--;
                string[newLength-1]='2';
                newLength--;
                string[newLength-1]='%';
                newLength--;
                oldLength--;
            }
        }


    }
    return;
}

void test()
{
    char string[20]={'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    ReplaceBlack(string,20);
    cout<<string<<endl;
}
int main()
{
    test();
    return 0 ;
}
````



