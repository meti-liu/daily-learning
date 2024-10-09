#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>  
#include<algorithm>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end()); 
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return { left, right };
        }
        else if (sum < target) {
            left++;  
        }
        else {
            right--;  
        }
    }
    return { -1, -1 };
}


int main()
{
   
    vector<int> nums;
    int target;
    string l;

    ifstream ifs("in.txt");
    getline(ifs, l);
    istringstream iss(l);
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }


    getline(ifs, l);
    target = stoi(l);

    vector<int> ans = twoSum(nums, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}