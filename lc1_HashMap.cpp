#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>  // 用于 istringstream 解析输入
using namespace std;


class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        
    }
    
};






int main()
{
    Solution solution;
    vector<int> nums;
    int target;

    string line;
    
    ifstream ifs("in.txt");
    getline(ifs, line);  // 读取整行输入
    
    istringstream iss(line);  // 用 istringstream 分割输入
    int num;
    while (iss >> num) {
        nums.push_back(num);  // 将输入的每个数字添加到数组中
    }


    getline(ifs, line);
    target = stoi(line);
    
    vector<int> result = solution.twoSum(nums, target); 
    
    cout <<result[0]<<" "<< result[1] << endl;
    
    return 0;
}