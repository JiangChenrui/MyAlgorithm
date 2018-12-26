#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>>& result, int level, vector<int>& vec, vector<int>& nums)
{
    if(level==nums.size())
    {
        result.push_back(vec);
        return;
    }
    vec.push_back(nums[level]);
    dfs(result,level+1,vec,nums);
    vec.pop_back();
    dfs(result,level+1,vec,nums);
    // result.push_back(vec);
    // for(int i=level;i<nums.size();i++)
    // {
    //     vec.push_back(nums[i]);
    //     dfs(result,i+1,vec,nums);
    //     vec.pop_back();
    // }
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> vec;
    if(nums.empty())
        return result;
    dfs(result, 0, vec, nums);
    return result;
}

int main()
{
    vector<int> nums;
    for(int i=1;i<4;i++)
        nums.push_back(i);
    vector<vector<int>> result;
    result = subsets(nums);
    return 0;
}