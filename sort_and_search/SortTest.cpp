#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include<fstream>
#include"sort.h"
#include<string>

using namespace std;

int main()
{
    vector<int> nums;
    clock_t start, finish;
    double totaltime;
    ifstream fin("data.txt");
    for(int i=0;i<1000000;i++){
        string str;
        getline(fin, str, '\n');
        nums.push_back(stoi(str));
    }
    fin.close();
    start = clock();
    // insertSort(nums);
    // bubble_Sort(nums);
    // selection_sort(nums);
    // sort(nums.begin(), nums.end());
    // quickSort(nums, 0, nums.size()-1);

    finish = clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<totaltime<<"Ãë"<<endl;

    return 0;
}