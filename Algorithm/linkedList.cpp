/*
Linked List
*/


#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int element;
    ListNode *prev, *next;
};

void delNode(ListNode* node){
    node->prev->next=node->next;
    node->next->prev=node->prev;
}

void recNode(ListNode* node){
    node->prev->next=node;
    node->next->prev=node;
}

int main(void){
    ListNode* list=new ListNode[10];

    for(int i=0; i<10; i++){
        list[i].element=i;
        if(i!=0) list[i].prev=list[i-1].next;
        if(i!=9) list[i].next=list[i+1].prev;
    }
    cout<<"INSERTED"<<endl;
    delNode(&list[5]);
    cout<<"DELETED"<<endl;
    for(int i=0; i<9; i++){
        cout<<list[i].element<<endl;
    }
}
