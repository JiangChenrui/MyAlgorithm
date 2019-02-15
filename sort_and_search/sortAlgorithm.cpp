#include<iostream>
#include<vector>
#include"sortAlgorithm.h"

using namespace std;
int main() {
    vector<vector <int>> numbers = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
    };
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> result;
    // result = topKFrequent(nums, 3);
    // result = searchRange(nums, 9);
    // result = searchRange2(nums, 8);
    // vector<Interval> input = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    // merge(input);
    // cout<<search(nums, 3)<<endl;
    cout<<searchMatrix(numbers, 5)<<endl;
    return 0;
}