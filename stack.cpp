#include<iostream>
#include<cassert>//assert库
using namespace std;
template<class T,int size>
class Stack
{
private:
    int top;//top用于记录栈内元素个数
    T a[size];
public:
    Stack():top(-1){}//初始化为-1

    void push(T item)
    {
        if(top>=size-1)
        {
            cout<<"Stack overflow"<<endl;//栈满溢出
            return;
        }
        //return a[++top];（++在前就是先++）
        top++;
        a[top]=item;//从a0开始
    }
    T pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
            assert(false);//如果弹出空栈，程序停止运行
        }
        return a[top--];//注意顺序，先返回a，再--
    }
    T peek()
    {
        if(top==-1)
        {
            cout<<"stack is empty"<<endl;
            assert(false);//查找空栈，停止运行
        }
        return a[top]; 
    }
    bool isEmpty()
    {
        return top==-1;
    }
};
int main()
{
    Stack<int,10> intstack;
    intstack.push(10);
    intstack.push(20);
    intstack.push(30);
    cout<<intstack.peek()<<endl;
    cout<<intstack.pop()<<endl;
    intstack.pop();
    cout<<intstack.peek()<<endl;
    return 0;
}