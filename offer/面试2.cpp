#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int w, h;
    int x0, x1, y0, y1;
    cout<<"Plesase input w and h"<<endl;
    cin>>w>>h;
    cin>>x0>>y0>>x1>>y1;
    while(x0>=0 && x1<w && y0>=0 && y1<h){
        if(x0%2==0 && (x1-x0)%16==0 && (y1-y0)%8==0){
            cout<<x0<<' '<<y0<<' '<<x1<<' '<<y1<<endl;
            return 0;
        }
        int a = 16 - (x1 - x0) % 16;
        int b = 8 -(y1 - y0) % 8;
        for(int i=0;i<a;i++){
            if(x0%2!=0){
                x0--;
            }
            else{
                x1++;
            }
        }
        for(int i=0;i<b;i++){
            if(y0>0){
                y0--;
            }
            else{
                y1++;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}