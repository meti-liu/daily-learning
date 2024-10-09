#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        int a,b;
        for(string token:tokens)
        {

            if(token=="+"||token=="-"||token=="*"||token=="/")
            {

                a=s.top(); s.pop();
                b=s.top(); s.pop();
                
                if (token == "+") 
                    s.push(b + a);
                else if (token == "-") 
                    s.push(b - a);
                else if (token == "*") 
                    s.push(b * a);
                else if (token == "/") 
                    s.push(b / a);  
            }
            else
            {
                int num=stoi(token);//字符串转int
                s.push(num);
            }
        }
        return s.top();
    }
};


int main()
{
    vector<string> tokens;
    ifstream ifs("in.txt");
    string line;
    if(getline(ifs,line))//在文件中一行行读取数据进line
    {
        stringstream ss(line);
        string token;
        while(getline(ss,token,',')) tokens.push_back(token);
        //将有逗号的string改为无逗号的string
    }
    Solution solution;
    cout<<solution.evalRPN(tokens);
    return 0;
}