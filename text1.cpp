#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void GetNext(string t,int* next)//通过指针来定义一个函数内的数组
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<t.length())
    {
        if(k==-1||t[j]==t[k])
        {
            j++;k++;
            next[j]=k;
        }
        else k=next[k];
    }
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    string s=s1+s2;
    int l=s.length();
    int* next=new int[l+1];
    GetNext(s,next);
    string ss=s.substr(0,next[l]);//for(int i=0;i<next[l];i++) cout<<s[i];
    cout<<ss<<" ";
    cout<<next[l];
}