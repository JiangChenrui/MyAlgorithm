#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void simple_sort(vector<int> nums)
{
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]>nums[j])
                swap(nums[i], nums[j]);
        }
    }
}

void insertSort(vector<int> nums)
{
    int temp;
    for(int i=1;i<nums.size()-1;i++)
    {
        int j=i-1;
        temp = nums[i]; //要插入的数
        while(j>=0 && nums[j]>temp)
        {
            // 选择插入的位置
            nums[j+1] = nums[j];
            j--;
        }
        if(j!=i-1)
            nums[j+1] = temp;
    }
}

void bubble_Sort(vector<int> nums)
{
    /*
    冒泡排序，每次将最大值放到最后
    */
    for(int i=nums.size()-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j]>nums[j+1])
                swap(nums[j], nums[j+1]);
        }
    }
}

void bubble_Sort2(vector<int> nums)
{
    for(int i=nums.size()-1;i>=0;i--)
    {
        bool train = false;
        for(int j=0;j<i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                swap(nums[j], nums[j+1]);
                train = true;
            }
        }
        if(train = false)
            return;
    }
}

void selection_sort(vector<int> &nums)
{
    /*
    简单选择排序,
    */
    for(int i=0;i<nums.size()-1;i++)
    {
        int mini = i;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]<nums[mini])
                mini = j;
        }
        if(mini!=i)
            swap(nums[mini], nums[i]);
    }
}

void quickSort(vector<int> &nums, int begin, int end)
{
    /*
    快速排序
    */
    if(begin>=end)
        return;
    int left = begin;
    int right = end;
    int key = nums[left];
    while(left<right)
    {
        while(left<right && nums[right]>=key)
            right--;
        swap(nums[left], nums[right]);
        while(left<right && nums[left]<=key)
            left++;
        swap(nums[left], nums[right]);
    }
    quickSort(nums, begin, left-1);
    quickSort(nums, left+1, end);
}

void shell(vector<int> nums)
{

}