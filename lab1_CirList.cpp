#include<iostream>
//禁止使用string？？？？？
using namespace std;

struct Node
{
    char data;
    Node* next;
    Node():next(nullptr){}
    Node(char d)
    {
        this->data=d;
        this->next=nullptr;
    }
};



class LinkList
{
public:
    Node* head;
    
    LinkList()
    {
        this->head=nullptr;
        // head->next=head;??????
    }

    void insert(char c)//头插法需要找到尾节点O(n)
    {
        Node* s=new Node(c);
        if(head==nullptr)
        {
            head=s;
            head->next=head;
        }
        else
        {
            Node* cur=head;
            while(cur->next!=head) cur=cur->next; 
            Node* tail=cur;
            tail->next=s;
            s->next=head;
        }

    }

    int length()
    {
        Node* cur=head;
        int len=1;
        while(cur->next!=head)
        {
            len++;
            cur=cur->next;
        }
        return len;
    }

};

bool isEqual(LinkList& L1,LinkList& L2)
{
    if(L1.length()!=L2.length()) return 0;
    int len=L1.length();

    Node* cur1=L1.head;
    Node* cur2=L2.head;
    bool match=true;
    for(int i=0;i<len;i++)
    {
        Node*p1=cur1;
        Node*p2=cur2;
        if(p1->data!=p2->data) match=false;
        else
        {
            match=true;
            for(int j=0;j<len;j++)
            {
                p1=p1->next;
                p2=p2->next;
                if(p1->data!=p2->data)
                {
                    match=false;
                    break;
                }
            }
            if(match) return 1;
        }

        cur1=cur1->next;
    }

    return 0;
}




int main()
{                                                     
    char ch;
    LinkList L1,L2;

    while (cin.peek() != '\n') 
    {
        cin >> ch;
        L1.insert(ch); 
    }
    cin.get();  // 消耗掉换行符

    while (cin.peek() != '\n') 
    {
        cin >> ch;
        L2.insert(ch); 
    }


    cout<<isEqual(L1,L2);


    return 0;
}