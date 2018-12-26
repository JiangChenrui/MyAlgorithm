#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void DFS(vector<vector <int> >& result, vector<int>& vec, vector<int>& nums, int level)
{
    if(vec.size()==level)
    {
        result.push_back(vec);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        vec.push_back(nums[i]);
        DFS(result, vec, nums, level+1);
        vec.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector <int>> result;
    vector<int> vec;
    DFS(result, vec, nums, 0);
    return result;
}

int main()
{
    vector<int> nums;
    for(int i=1;i<4;i++)
        nums.push_back[i];
    permute(nums);
    return 0;
}