#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool Find(int target, vector<vector<int> > array) {
    int m = array.size();
    int n = array[0].size();
    if(m<=0 || n<=0)
        return false;
    int i=0,j=n-1;
    while(i<m && j>=0){
        int temp = array[i][j];
        if(temp==target){
            return true;
        }
        else if(temp<target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

void replaceSpace(char *str,int length) {
    int Space_num = 0;
    for(int i=0;i<length;i++)
        if(str[i]==' ')
            Space_num++;
    int len = length + Space_num * 2 - 1;
    while(length>0){
        if(str[length-1]==' '){
            length--;
            str[len--] = '0';
            str[len--] = '2';
            str[len--] = '%';
        }
        else{
            str[len--] = str[length-1];
            length--;
        }
    }
}

int main(){
    vector<vector<int>> nums;
    nums = {{1, 2, 3, 4},
            {5, 6, 7, 8},
            {6, 7, 8, 9}};
    // bool result = Find(10, nums);
    // cout<<"The result is "<<result<<endl;
    char str[18] = "We are happy he t";
    replaceSpace(str, 18);
    cout<<str<<endl;
    return 0;
}
