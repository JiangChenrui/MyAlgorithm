#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
/*
回溯算法第一弹！！！
基本框架是
DFS()
{
    if()
    {
        ***********
        return;
    }
    vec.push_back();
    DFS();
    vec.pop_back();
}

*/
void DFS(vector<string> &result, string dict[], string digits, int level, string vec)
{
    if(level == digits.size())
        {
            result.push_back(vec);
            return;
        }
    string str = dict[digits[level] - '0'];
    for(int i=0;i<str.size();i++)
    {
        vec.push_back(str[i]);
        DFS(result, dict, digits, level+1, vec);
        vec.pop_back();
    }
}

vector<string> letterCombinations(string digits) 
{
    vector<string> result;
    if(digits.empty())
        return result;    
    string phonedigits[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};    
    DFS(result, phonedigits, digits, 0, "");
    return result;
}
int main()
{
    letterCombinations("234");
    return 0;
}