#include<iostream>
using namespace std;


struct LinkNode
{
    int data;
    LinkNode* next;
    LinkNode():next(nullptr){}
    //LinkNode(int d):data(d),next(nullptr){}
    LinkNode(int val)
    {
        this->data=val;
        this->next=nullptr;
    }
};