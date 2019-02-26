#include<map>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    /*
    前k个高频元素，题目地址：https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/50/sorting-and-searching/97/
    */
    map<int, int> m;
    vector<vector<int>> top(nums.size()+1);
    vector<int> res;
    for(auto a : nums)
        m[a]++;
    for(auto it : m)
        top[it.second].push_back(it.first);
    for(int i=nums.size();i>=0;i--)
        for(int j=0;j<top[i].size();j++)
        {
            res.push_back(top[i][j]);
            if(res.size()==k)
                return res;
        }
    return res;
}

int findKthLargest(vector<int>& nums, int k) {
    /*
    数组中的第K大元素，题目地址：https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/50/sorting-and-searching/98/
    */
    if(k>nums.size())
        return 0;
    for(int i=nums.size()-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j]>nums[j+1])
                swap(nums[j], nums[j+1]);
        }
        if(nums.size()-i == k)
            return nums[i];
    }
}
vector<int> searchRange1(vector<int>& nums, int target) {
    /*
    在排序数组中查找元素的第一个和最后一个位置
    使用二分法的思想，先找到值为target的位置，然后分别向前和向后遍历进行搜索
    */
    vector<int> result = {-1, -1};
    int left = 0;
    int right = nums.size()-1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if(nums[mid]==target)
        {
            while(mid>=left && nums[mid]==target)
                mid--;
            result[0] = mid+1;
            mid = (left + right) / 2;
            while(mid<=right && nums[mid]==target)
                mid++;
            result[1] = mid-1;
            break;
        }
        else if(nums[mid]>target)
            right = mid - 1;
        else if(nums[mid]<target)
            left = mid +1;
    }
    return result;
}
int findFirst(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;
    int idx = -1; 
    while(left<=right){
        int mid = (left + right) / 2;
        if(nums[mid]>=target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
        if(nums[mid]==target){
            idx = mid;
        }
    }
    return idx;
}
int findLast(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;
    int idx = -1;
    while(left<=right){
        int mid = (left + right) / 2;
        if(nums[mid]<=target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        if(nums[mid]==target){
            idx = mid;
        }
    } 
    return idx;
}
vector<int> searchRange2(vector<int>& nums, int target){
    /*
    对开始位置和结束位置分别使用二分法进行确定
    */
    vector<int> result;
    result.push_back(findFirst(nums, target));
    result.push_back(findLast(nums, target));
    return result;
}

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool comp(Interval &a, Interval &b){
    return (a.start<b.start);
}
vector<Interval> merge(vector<Interval>& Intervals){
    vector<Interval> result;
    if(Intervals.empty()){
        return result;
    }
    sort(Intervals.begin(), Intervals.end(), comp);
    result.push_back(Intervals[0]);
    for(int i=1;i<Intervals.size();i++){
        if(result.back().end >= Intervals[i].start){
            result.back().end = max(Intervals[i].end, result.back().end);
        }
        else{
            result.push_back(Intervals[i]);
        }
    }
    return result;
}
// vector数组中back()返回当前vector数组最末的一个元素

int search(vector<int>& nums, int target){
    /*
    搜索旋转排序数组
    题目地址：https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/50/sorting-and-searching/102/
    */
    int left=0, right=nums.size()-1;
    int mid;
    while(left<=right){
        mid = (left + right) / 2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>nums[right]){
            if(target>=nums[left] && target<nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(target>nums[mid] && target<=nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    /*
    搜索二维数组
    */ 
    if(matrix.empty()||matrix[0].empty()){
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int x=0, y=n-1;
    while(x<m && y>=0){
        if(matrix[x][y]==target)
            return true;
        else if(matrix[x][y]>target)
            y--;
        else
            x++;
    }
    return false;
}