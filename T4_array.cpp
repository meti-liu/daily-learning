#include<iostream>
#include<fstream>
using namespace std;

void s(int a[],int n)
{
    //int b[n],c[n];//n不是常数，需要用指针的方式声明bc
    int* b=new int[n];
    int* c=new int[n];
    int even=0,odd=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            b[even]=a[i];
            even++;
        }
        if(a[i]%2==1)
        {
            c[odd]=a[i];
            odd++;
        }
    }
    for(int i=0;i<even;i++) a[i]=b[i];
    for(int i=0;i<odd;i++) a[even+i]=c[i];
}
int main()
{
    ifstream ifs("in.txt");
    ofstream ofs("out.txt");
    int a[200];
    int n=0;
    // while(ifs>>a[n]) n++;
    //while
    while (ifs >> a[n]) n++;

cout << endl;
    s(a,n);
    for(int i=0;i<n;i++) ofs<<a[i]<<" ";
    ifs.close();
    ofs.close();
    return 0;
}