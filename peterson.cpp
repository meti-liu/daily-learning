#include<iostream>
using namespace std;
//Peterson
bool flag[2]={false,false};
int turn=0;
//P0
void P0()
{
    flag[0]=true;//自己的意愿
    turn=1;//谦让
    while(flag[1]==true&&turn==1);//等待
    //critical section 临界区
    flag[0]=false;
}
int main()
{
    P0();
    return 0;
}