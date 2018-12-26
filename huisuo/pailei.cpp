#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void DFS(vector<vector <int> >& result, vector<int>& vec, vector<int>& nums, int level, vector<int> m)
{
    if(level==nums.size())
    {
        result.push_back(vec);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(m[i]==0)
        {
            vec.push_back(nums[i]);
            m[i] = 1;
            DFS(result, vec, nums, level+1, m);
            vec.pop_back();
            m[i] = 0;
        }      
        
    }
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector <int>> result;
    vector<int> vec;
    vector<int> m(nums.size(), 0);
    DFS(result, vec, nums, 0, m);
    return result;
}

int main()
{
    vector<vector<int>> result;
    vector<int> nums;
    for(int i=1;i<4;i++)
        nums.push_back(i);
    result = permute(nums);
    return 0;
}