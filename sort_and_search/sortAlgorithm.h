#include<map>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    /*
    ǰk����ƵԪ�أ���Ŀ��ַ��https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/50/sorting-and-searching/97/
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
    �����еĵ�K��Ԫ�أ���Ŀ��ַ��https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/50/sorting-and-searching/98/
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
    �����������в���Ԫ�صĵ�һ�������һ��λ��
    ʹ�ö��ַ���˼�룬���ҵ�ֵΪtarget��λ�ã�Ȼ��ֱ���ǰ����������������
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
    �Կ�ʼλ�úͽ���λ�÷ֱ�ʹ�ö��ַ�����ȷ��
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
// vector������back()���ص�ǰvector������ĩ��һ��Ԫ��

int search(vector<int>& nums, int target){
    /*
    ������ת��������
    ��Ŀ��ַ��https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/50/sorting-and-searching/102/
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
    ������ά����
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