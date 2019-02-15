# 排序算法  

[toc]  

[参考博客](https://blog.csdn.net/K346K346/article/details/50791102)  

## 评价标准  

* 是否稳定

  * 稳定：如果a在b的前面且a=b，排序之后a仍然在b的前面；  
  
  * 不稳定：如果a在b的前面且a=b，排序之后a在b的后面。

* 时间复杂度（算法执行所消耗的时间）  

* 空间复杂度（运行完一个程序所需内存大小）  

## 算法总结  

@import "E:\GitHub\Interview-question-collection\picture\sortalgorithm.jpg"  

![picture](https://github.com/holyhond/Interview-question-collection/tree/master/picture/sortalgorithm.jpg)  

最简单的排序方法：  

```c++
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
```

## 一、交换类排序  

&emsp;&emsp;基本思想：两两比较待排序的排序码，交换不满足排序关系的数对。  

### 1.1 冒泡排序  

&emsp;&emsp;冒泡排序是对最简单的排序方法进行改进，每次交换后对后续排序有帮助，大数会越来越大，小数会越来越小。冒泡排序的基本思想是：<font color=#ff000 size=3>两两相邻元素比较，如果前者大于后者，则交换。</font>  时间复杂度为O(n)~O(n^2)。

```c++
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
```  

&emsp;&emsp;冒泡排序的改进：加入一个bool类型，判断是否进行过交换，如果没有交换，则说明已经排好序。  

```c++
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
```  

### 1.2 快速排序  

&emsp;&emsp;冒泡排序是对相邻的两个记录进行比较和交换，每次交换只能上移或下移一次，导致移动和交换次数较多。快速排序则又称为分区交换排序，是对冒泡排序的改进，采用的是分治的思想。  

* 算法原理  
    (1). 选取一个分区标准；  
    (2). 将小于标准的数放到左边，大于标准的数放到右边，标准数放到中间；  
    (3). 标准数左边和右边分别进行第（1）和（2）步。

* 稳定性：不稳定  

* 时间复杂度：$O (n\log_{2}n)$到$O(n^2)$,平均复杂度为$O(n\lg n)$。  

```c++
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
```  

## 二、插入类排序  

&emsp;&emsp;插入排序的基本方法是：每次将一个待排序的数插入到前面排好序的数字中的适当位置，直到全部插完为止。  

### 2.1 直接插入  

* 算法原理：从待排序的数字的第二个数字开始，依次与前面已排好序的数字进行对比，插入到合适的位置。  

* 稳定性：稳定排序。  

* 时间复杂度：O(n)到O(n^2)，平均时间复杂度为O(n^2)。  

```c++
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
```  

### 2.2 希尔排序  

* 算法原理：

* 稳定性：

* 时间复杂度：

&emsp;&emsp;

## 三、选择类排序  

&emsp;&emsp;每次从待排序的数字中选择最小的数字放在排好序的数字后面，直到全部排完。  

### 3.1 简单选择排序  

* 算法原理：从所有数字中选择最小的数字与第一个数字进行交换，然后从剩下的数字中找最小的数字与第二个数字进行交换，循环到最后一个数字为止。  

* 稳定性：不稳定排序。  

* 时间复杂度：最坏最好均为O(n^2)。  

```c++
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
```

### 3.2 堆排序  

* 算法原理：  

* 稳定性：

* 时间复杂度：

&emsp;&emsp;

## 四、归并类  

&emsp;&emsp;

### 4.1 归并排序  

* 算法原理：  

* 稳定性：

* 时间复杂度：