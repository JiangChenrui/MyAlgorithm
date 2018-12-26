#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(vector<string> &result, int level, string out, int left, int right, int n)
{
    if(out.size()==2 * n)
    {
        if(out[out.size()-1]!=')')
            return;
        result.push_back(out);
        return;
    }
    if(right-left<0 || left<0 || right<0)
        return;
    for(int i=0;i<2;i++)
    {
        if(i==0)
        {
            out.push_back('(');
            DFS(result, level+1, out, left-1, right, n);
            out.pop_back();
        }
        else
        {
            out.push_back(')');
            DFS(result, level+1, out, left, right-1, n);
            out.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) 
{
    vector<string> result;
    DFS(result, 0, "", n, n, n);
    return result;
}

int main()
{
    generateParenthesis(8);
    return 0;
}