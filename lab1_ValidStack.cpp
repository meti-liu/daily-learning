#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char> s;
    int n;
    char a[25],b[25];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int k=0;
    for(int i=0;i<n;i++)
    {
        s.push(a[i]);

        while(s.empty()==false&&s.top()==b[k])
        {
            s.pop();
            k++;
        }

    }
    if(s.empty()&&k==n) cout<<"true";
    else cout<<"false";
    return 0;
}