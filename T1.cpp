#include<iostream>
using namespace std;
int head;
int n;
struct Node
{
    int i;
    int addr;
    int data;
    int next;
    Node(int i):i(i){}
};

int main()
{
    cin>>head>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>Node(i).addr;
        cin>>Node(i).data;
        cin>>Node(i+1).addr;
    }
}