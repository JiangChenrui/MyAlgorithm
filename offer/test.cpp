#include<iostream>
#include<algorithm>
#include<vector>
#include <regex>
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

// int main(){
//     int n, k;
//     cin>>n>>k;
//     vector<int> number;
//     for(int i=0;i<n;i++){
//         int num;
//         cin>>num;
//         number.push_back(num);
//     }
//     sort(number.begin(), number.end());
//     int min, temp;

//     while(k>0){
//         for(int i=temp;i<n;i++){
//             if(number[i]>0){
//                 temp = i;
//                 min = number[i];
//                 break;
//             }
//         } 
//         cout<<min<<endl;
//         for(int i=temp;i<n;i++){
//             number[i] -= min;
//         }
//         min = number[temp];
//         k--;
//     }
//     return 0;
// }

bool checkSpecialChar(string str){
    string cm{".*[ `~!@#$%^&*()+=|{}':;',\\[\\].<>/?~！@#￥%……&*（）——+|{}【】‘；：”“’。，、？].*"};
    // string cm{".*h.*"};
    regex reg(cm);
    bool res = regex_match(str, reg);
    return res;
}

bool checkUrl(std::string str) {
    // std::string cm = {"^rtsp:\/\/([a-z]{0,10}:.{0,10}@)?(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5]).*"};
    // std::string cm1 = {"^rtsp+://([a-z]{0,10}:.{0,10}@)?(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5]):[0-9]{1,5}"};
    // std::string cm2 = {"^rtsp+://([a-z]{0,10}:.{0,10}@)?(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])"};
    std::string cm3 = {"^rtsp+://([a-z]{0,10}:.{0,10}@)?(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5]).*"};
    // std::regex reg(cm);
    // std::regex reg1(cm1);
    // std::regex reg2(cm2);
    std::regex reg3(cm3);
    // cout<<regex_match(str, reg) <<' '<< regex_match(str, reg1) <<' '<<regex_match(str, reg2)<<endl;
    // cout<<regex_match(str, reg3)<<endl;
    // return (std::regex_match(str, reg) || std::regex_match(str, reg1) || std::regex_match(str, reg2));
    return std::regex_match(str, reg3);
}


int main(){
    string s1, s2;
    s1 = "rtsp://admin:boyun2017@192.168.4.168:8554/channel121";
    s2 = "rtsp://admin:boyun2017@192.168.1.156:1223";
    cout<<checkUrl(s1)<<endl;
    cout<<checkUrl(s2)<<endl;
    return 0;
}