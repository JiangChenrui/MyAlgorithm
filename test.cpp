#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int main(){
    string a;
    string key, value;
    cin>>key>>value>>a;
    int num = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]==value[0])
            num++;
    }
    cout<<num<<endl;
    for(int i=0;i<a.size();i++){
        if(a[i]==key[0]){
            i += key.size()-1;
            cout<<endl;
        }
        else if(a[i]==value[0]){
            i += value.size()-1;
            cout<<' ';
        }
        else 
            cout<<a[i];
    }
    return 0;
}