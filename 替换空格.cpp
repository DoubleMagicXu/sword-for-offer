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
