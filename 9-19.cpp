#include<iostream>
using namespace std;
template<typename T>
void Sort(T list[],int n)//先选择排序，才能用二分法查找
{
    for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
    {
        if(list[i]>list[j]) swap(list[i],list[j]);
    }
}
template<typename T>
int binarySearch(T list[],int n,T key)//类型为T的数组,n个元素,每个元素类型均为T
{
    int mid,low,high;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(list[mid]==key) return mid+1;
        else if(list[mid]<key) low=mid;
        else if(list[mid]>key) high=mid;
    }
    return -1;
}
int main()
{
    cout<<"data:"<<endl;
    int data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    Sort<int>(data,20);
    for(int i=0;i<20;i++) cout<<data[i]<<" ";
    int key;
    cin>>key;
    cout<<endl<<"location:"<<binarySearch<int>(data,20,key);
    return 0;
}