#include<iostream>
using namespace std;

const int MAXSIZE=100;

// empty()
// push(T e)
// pop(T& e)
// gettop(T& e)

template<typename T>
class Stack
{
private:
    T* data;
    int top;

public:
    Stack()
    {
        data=new T[MAXSIZE];
        top=-1;
    }

    bool empty()
    {
        return top==-1;
    }

    bool full()
    {
        return MAXSIZE-1;
    }

    void push(T value)
    {
        if(!full())
        {
            top++;
            data[top]=value;
        }
    }

    void pop(T& e)
    {
        e=data[top];
        top--;
    }
};


























int main()
{

}