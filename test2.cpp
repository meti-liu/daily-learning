#include<iostream>
#include<vector>

#include <sstream>  // 用于 istringstream 解析输入
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i=0;i<nums.size();i++)
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target) return {i,j};
        }
        return {-1,-1};
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int target;

    string line;
    

    getline(cin, line);  // 读取整行输入
    
    istringstream iss(line);  // 用 istringstream 分割输入
    int num;
    while (iss >> num) {
        nums.push_back(num);  // 将输入的每个数字添加到数组中
    }


    cin>>target;
    
    vector<int> result = solution.twoSum(nums, target); 
    
    cout <<result[0]<<" "<< result[1] << endl;
    
    return 0;
}