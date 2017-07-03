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
