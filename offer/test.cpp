#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// int main(){
//     int n;
//     vector<int> number;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int num;
//         cin>>num;
//         number.push_back(num);
//     }
//     int cost=0, host=0;
//     for(int i=0;i<n;i++){
//         host += number[i];
//         if(host>=0){
//             cost += host;
//         }
//         else{
//             cost += -host;
//         }
//     }
//     cout<<cost<<endl;
//     return 0;
// }

// int main(){
//     int n, k;
//     cin>>n>>k;
//     vector<int> number;
//     for(int i=0;i<n;i++){
//         int num;
//         cin>>num;
//         number.push_back(num);
//     }
//     while(k>0){
//         int min=number[0];
//         for(int i=1;i<n;i++){
//             if(min<=0){
//                 if(number[i]>0)
//                     min = number[i];          
//             }
//             else{
//                 if(number[i]<min && number[i]>0){
//                     min=number[i];
//                 }
//             }
//         }
//         if(min==0)
//             min=0;
//         cout<<min<<endl;
//         k--;
//         for(int i=0;i<n;i++){
//             if(number[i]>0)
//                 number[i] -= min;
//         }
//     }
//     return 0;
// }

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> number;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        number.push_back(num);
    }
    sort(number.begin(), number.end());
    int min, temp;

    while(k>0){
        for(int i=temp;i<n;i++){
            if(number[i]>0){
                temp = i;
                min = number[i];
                break;
            }
        } 
        cout<<min<<endl;
        for(int i=temp;i<n;i++){
            number[i] -= min;
        }
        min = number[temp];
        k--;
    }
    return 0;
}