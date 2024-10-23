#include<iostream>
#include<stack>
#include<fstream>
#include<sstream>
using namespace std;

stack<int> st;

int main()
{
    string line;
    getline(cin,line);
    istringstream iss(line);
    int num;
    while(iss>>num)
    {
        if(num==-1)
        {
            cout<<st.top()<<endl;
            st.pop();
        }
        if(num!=-1) st.push(num);
    }
}