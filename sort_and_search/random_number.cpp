#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<sstream>
#include<fstream>

using namespace std;
int main()
{
    srand(time(0));
    // 生成随机数，存入文本中
    ofstream fout;
    string filename = "data.txt";
    fout.open(filename.c_str(), ios_base::out|ios_base::ate);
    if(!fout.is_open())
        return 0;
    for(int i=0;i<1000000;i++){
        fout<<rand()<<endl;
    }
    fout.close();
    // 读取随机数文件，读入数组a中
    // int a[10001];
    // stringstream streamd;
    // ifstream fin("data.txt");
    // for(int i=0;i<10000;i++){
    //     string str;
    //     getline(fin, str, '\n');
    //     streamd<<str;
    //     streamd>>a[i];
    //     streamd.clear();
    // }
    // fin.close();
    //打印数组
    // for(int i=0;i<30;i++){
    //     cout<<a[i]<<endl;
    // }
    return 0;
}