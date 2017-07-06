/*************************************************************************
	> File Name: 从尾到头部打印链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月06日 星期四 22时27分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode
{
    int key;
    ListNode* next;
};

void reversePrint(ListNode* node)
{
    if(node!=NULL)
    {
        reversePrint(node->next);
        cout<<node->key<<endl;
    }
}

void test()
{
    ListNode A;
    ListNode B;
    ListNode C;
    A.key=1;
    A.next=&B;
    B.key=2;
    B.next=&C;
    C.key=3;
    C.next=NULL;
    reversePrint(&A);
}

int main()
{
    test();
    return 0;
}
