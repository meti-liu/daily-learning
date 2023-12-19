#include<iostream>
using namespace std;
class Node
{
public:

    int data;
    Node* next;//后指针
    Node* prev;//前指针
    Node(int a):data(a),prev(nullptr),next(nullptr){}
};
class doublelist
{
public:
    Node* head;
    Node* tail;
    doublelist():head(nullptr),tail(nullptr){}

    void append(int data)
    {

        Node* newnode=new Node(data);
        if(head==nullptr) 
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }

    void printlist()
    {
        Node* current=head;
        while(current!=nullptr)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
    }
};
int main()
{
    doublelist a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.printlist();

    return 0;
}