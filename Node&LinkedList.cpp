#include<iostream>
using namespace std;
class Node//节点
{
public:
    int data;
    Node *next;
    //Node(int a):data(a),next(nullptr){}
    Node(int a)//每个node都有data和next指针（指向下一个node）
    {
        this->data=a;
        this->next=nullptr;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList():head(nullptr){}//head初始化为空

    void append(int data)
    {
        Node *newNode=new Node(data);//新建一块内存
        if(head==nullptr) head=newNode;
        else
        {
            Node *temp=head;//temp从最左端开始
            while(temp->next!=nullptr) temp=temp->next;
            //非空就右移，temp移到最右端
            //temp和temp->next都是node
            temp->next=newNode;
        }
    }
};
int main()
{
    LinkedList a;
    a.append(1);
    a.append(2);
    a.append(3);
    return 0;
}