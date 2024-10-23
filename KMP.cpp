#include<iostream>
#include<string>
using namespace std;
void GetNext(string t,int* next)
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<t.length()-1)
    {
        if(j=-1||t[k]==t[j])
        {
            j++;k++;
            next[j]=k;
        }
        else k=next[k];
    }
}

int KMP(string s,string t)
{
    int n=s.length(),m=t.length();
    int *next=new int[m+1];
    GetNext(t,next);
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(s[i]==t[j]||j==-1||t[j]=='*')//通配符
        {
            i++;j++;
        }
        else j=next[j];   
    }
    if(j>=m) return i-j;
    else return -1;
}

int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    if(KMP(s,t)!=-1) cout<<"match";
    else cout<< "not match";
    return 0;
}