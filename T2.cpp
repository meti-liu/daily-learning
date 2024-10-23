#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;



int main()
{
    int n;
    cin>>n;
    vector<queue<string>> q(n+1);//n个q，但是n是变量，故用动态数组vector储存queue
    for(int i=1;i<=n;i++)
    {
        string name;
        while(cin>>name && name != "END") q[i].push(name);
    } 
    string action;
    queue<string> Leave;
    string newName;

    while(cin>>action)
    {
        if(action=="ENTERS")
        {
            int num;
            cin>>newName>>num;
            if(num>=1&&num<=n) q[num].push(newName);
        }
        else if(action=="LEAVES")
        {
            int num;
            cin>>num;
            if(num>=1&&num<=n&&!q[num].empty())
            {
                string l=q[num].front();
                Leave.push(l);
                q[num].pop();
            }
        }
    }

    while(!Leave.empty())
    {
        cout<<Leave.front()<<endl; 
        Leave.pop();
    } 

    for(int i=1;i<=n;i++)
    {
        cout<<"q"<<i<<":";
        while(!q[i].empty())
        {
            cout<<q[i].front()<<" ";
            q[i].pop();
        }
        cout<<endl;
    }
}