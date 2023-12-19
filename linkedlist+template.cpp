#include<iostream>
using namespace std;
template <typename T>
class Node//节点
{
public:
    T data;
    Node<T> *next;
    //Node(T a):data(a),next(nullptr){}
    Node(T a)//每个node都有data和next指针（指向下一个node）
    {
        this->data=a;
        this->next=nullptr;
    }
};
template <typename T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList():head(nullptr){}//head初始化为空

    void append(T data)
    {
        Node<T> *newNode=new Node<T>(data);//新建一块内存
        if(head==nullptr) head=newNode;
        else
        {
            Node<T> *temp=head;//temp从最左端开始
            while(temp->next!=nullptr) temp=temp->next;
            //非空就右移，temp移到最右端
            //temp和temp->next都是指向node的指针
            temp->next=newNode;
        }
    }
            void printlist()
    {
        Node<T>* current=head;
        while(current!=nullptr)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
    }
};
int main()
{
    LinkedList<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.printlist();
    LinkedList<string> b;
    b.append("Hello");
    b.append(" World");
    b.printlist();
    return 0;
}