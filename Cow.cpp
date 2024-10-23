#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int Cow(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 3;
    else return Cow(n-1)+Cow(n-3);
}
int main()
{
    int n;
    string s;
    ifstream ifs("in.txt");
    getline(ifs,s);
    n=stoi(s);
    cout<<Cow(n);
    return 0;
}