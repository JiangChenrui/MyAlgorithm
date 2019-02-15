# �����㷨  

[toc]  

[�ο�����](https://blog.csdn.net/K346K346/article/details/50791102)  

## ���۱�׼  

* �Ƿ��ȶ�

  * �ȶ������a��b��ǰ����a=b������֮��a��Ȼ��b��ǰ�棻  
  
  * ���ȶ������a��b��ǰ����a=b������֮��a��b�ĺ��档

* ʱ�临�Ӷȣ��㷨ִ�������ĵ�ʱ�䣩  

* �ռ临�Ӷȣ�������һ�����������ڴ��С��  

## �㷨�ܽ�  

@import "E:\GitHub\Interview-question-collection\picture\sortalgorithm.jpg"  

![picture](https://github.com/holyhond/Interview-question-collection/tree/master/picture/sortalgorithm.jpg)  

��򵥵����򷽷���  

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

## һ������������  

&emsp;&emsp;����˼�룺�����Ƚϴ�����������룬���������������ϵ�����ԡ�  

### 1.1 ð������  

&emsp;&emsp;ð�������Ƕ���򵥵����򷽷����иĽ���ÿ�ν�����Ժ��������а�����������Խ��Խ��С����Խ��ԽС��ð������Ļ���˼���ǣ�<font color=#ff000 size=3>��������Ԫ�رȽϣ����ǰ�ߴ��ں��ߣ��򽻻���</font>  ʱ�临�Ӷ�ΪO(n)~O(n^2)��

```c++
void bubble_Sort(vector<int> nums)
{
    /*
    ð������ÿ�ν����ֵ�ŵ����
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

&emsp;&emsp;ð������ĸĽ�������һ��bool���ͣ��ж��Ƿ���й����������û�н�������˵���Ѿ��ź���  

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

### 1.2 ��������  

&emsp;&emsp;ð�������Ƕ����ڵ�������¼���бȽϺͽ�����ÿ�ν���ֻ�����ƻ�����һ�Σ������ƶ��ͽ��������϶ࡣ�����������ֳ�Ϊ�������������Ƕ�ð������ĸĽ������õ��Ƿ��ε�˼�롣  

* �㷨ԭ��  
    (1). ѡȡһ��������׼��  
    (2). ��С�ڱ�׼�����ŵ���ߣ����ڱ�׼�����ŵ��ұߣ���׼���ŵ��м䣻  
    (3). ��׼����ߺ��ұ߷ֱ���еڣ�1���ͣ�2������

* �ȶ��ԣ����ȶ�  

* ʱ�临�Ӷȣ�$O (n\log_{2}n)$��$O(n^2)$,ƽ�����Ӷ�Ϊ$O(n\lg n)$��  

```c++
void quickSort(vector<int> &nums, int begin, int end)
{
    /*
    ��������
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

## ��������������  

&emsp;&emsp;��������Ļ��������ǣ�ÿ�ν�һ��������������뵽ǰ���ź���������е��ʵ�λ�ã�ֱ��ȫ������Ϊֹ��  

### 2.1 ֱ�Ӳ���  

* �㷨ԭ���Ӵ���������ֵĵڶ������ֿ�ʼ��������ǰ�����ź�������ֽ��жԱȣ����뵽���ʵ�λ�á�  

* �ȶ��ԣ��ȶ�����  

* ʱ�临�Ӷȣ�O(n)��O(n^2)��ƽ��ʱ�临�Ӷ�ΪO(n^2)��  

```c++
void insertSort(vector<int> nums)
{
    int temp;
    for(int i=1;i<nums.size()-1;i++)
    {
        int j=i-1;
        temp = nums[i]; //Ҫ�������
        while(j>=0 && nums[j]>temp)
        {
            // ѡ������λ��
            nums[j+1] = nums[j];
            j--;
        }
        if(j!=i-1)
            nums[j+1] = temp;
    }
}
```  

### 2.2 ϣ������  

* �㷨ԭ��

* �ȶ��ԣ�

* ʱ�临�Ӷȣ�

&emsp;&emsp;

## ����ѡ��������  

&emsp;&emsp;ÿ�δӴ������������ѡ����С�����ַ����ź�������ֺ��棬ֱ��ȫ�����ꡣ  

### 3.1 ��ѡ������  

* �㷨ԭ��������������ѡ����С���������һ�����ֽ��н�����Ȼ���ʣ�µ�����������С��������ڶ������ֽ��н�����ѭ�������һ������Ϊֹ��  

* �ȶ��ԣ����ȶ�����  

* ʱ�临�Ӷȣ����þ�ΪO(n^2)��  

```c++
void selection_sort(vector<int> &nums)
{
    /*
    ��ѡ������,
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

### 3.2 ������  

* �㷨ԭ��  

* �ȶ��ԣ�

* ʱ�临�Ӷȣ�

&emsp;&emsp;

## �ġ��鲢��  

&emsp;&emsp;

### 4.1 �鲢����  

* �㷨ԭ��  

* �ȶ��ԣ�

* ʱ�临�Ӷȣ�