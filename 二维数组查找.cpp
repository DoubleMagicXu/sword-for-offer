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
