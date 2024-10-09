#include<iostream>
#include<string>
using namespace std;


bool valid(string s)
{
    int stacksize=0;
    for(int i=0;i<s.size();i++)//for (char cur : s)
    {
        char cur=s[i];
        if(cur=='I') stacksize++;
        else if(cur=='O')
        {
            if(stacksize<=0) return false;
            else stacksize--;
        }
    }
    return true;
}


int main()
{
    string s;
    cin>>s;
    cout<<valid(s);
    return 0;
}