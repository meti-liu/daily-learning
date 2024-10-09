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

class LinkList
{
public:
    LinkNode* head;
    LinkList()
    {
        this->head=nullptr;
    }

    LinkNode* getn(int n)
    {
        LinkNode* temp=head;
        for(int i=0;i<n;i++) temp=temp->next;
        return temp;
    }

    int getElement(int i)//i位置元素值多少
    {
        LinkNode* temp=head;
        int index=0;
        while(temp!=nullptr&&index<i)
        {
            temp=temp->next;
            index++;
        }
        if(temp!=nullptr) return temp->data;
    }






    void insert(int i,int e)//在第i个节点插入e这个元素
    {
        LinkNode* p=getn(i);
        LinkNode* s=new LinkNode(e);
        s->next=p->next;
        p->next=s;
    }


    void remove(int i,int e)//i节点删除e元素
    {
        LinkNode*p=getn(i);
        LinkNode*q=p->next;
        p->next=q->next;
        delete q;
    }

    int getLength()
    {
        int l=0;
        LinkNode* temp=head;
        while(temp!=nullptr)
        {
            l++;
            temp=temp->next;
        }
        return l;
    }

};


int main()
{
    LinkList list;
    

}