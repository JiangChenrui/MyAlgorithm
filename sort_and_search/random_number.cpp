#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<sstream>
#include<fstream>

using namespace std;
int main()
{
    srand(time(0));
    // ����������������ı���
    ofstream fout;
    string filename = "data.txt";
    fout.open(filename.c_str(), ios_base::out|ios_base::ate);
    if(!fout.is_open())
        return 0;
    for(int i=0;i<1000000;i++){
        fout<<rand()<<endl;
    }
    fout.close();
    // ��ȡ������ļ�����������a��
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
    //��ӡ����
    // for(int i=0;i<30;i++){
    //     cout<<a[i]<<endl;
    // }
    return 0;
}