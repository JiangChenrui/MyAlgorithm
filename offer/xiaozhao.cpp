#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<string.h>
#include<queue>
#include<map>
#include<limits.h>
using namespace std;

long long MaxProduct(vector<long long> &array){
    if(array.size()<3)
        return 0;
    if(array.size()==3)
        return array[0] * array[1] * array[2];
    long long max1, max2, max3, min1, min2;
    max1 = max2 = max3 = INT_MIN;
    min1 = min2 = INT_MAX;
    for(int i=0;i<array.size();i++){
        if(array[i]<min1){
            min2 = min1;
            min1 = array[i];
        }
        else if(array[i]<min2){
            min2 = array[i];
        }
        if(array[i]>max1){
            max3 = max2;
            max2 = max1;
            max1 = array[i];
        }
        else if(array[i]>max2){
            max3 = max2;
            max2 = array[i];
        }
        else if(array[i]>max3){
            max3 = array[i];
        }
    }
    return max(max1*max2*max3, max1*min1*min2);
}

string BigIntPro(string &a, string &b){
    string result;
    int alen  = a.size()-1, blen = b.size()-1;
    int temp=0;
    while(alen>=0&&blen>=0){
        int pro = int(a[alen]) * int(b[blen]) + temp;
        result.append(to_string(pro%10));
        temp = pro / 10;
        alen--;
        blen--;
    }
    if(alen>0){
        if(temp!=0){
            result.append(to_string(int(a[alen])+temp));
            temp=0;
        }
        else{
            result.append(to_string(a[alen]));
        }        
        alen--;
    }
    else if(blen>0){
        if(temp!=0){
            result.append(to_string(int(b[blen])+temp));
            temp=0;
        }
        else{
            result.append(to_string(b[blen]));
        }        
        blen--;
    }
    result.reserve();   
    return result;
}

string BigIntPro2(string &a, string &b){
    string res(a.size() + b.size(), '0');
    string shorter = a.size() < b.size() ? a : b;
    string longer = a.size() < b.size() ? b : a;
    for(int i=shorter.size()-1;i>=0;--i){
        int carry = 0;   // 进位
        for(int j=longer.size()-1;j>=0;--j){
            int temp = (longer[j] - '0') * (shorter[i] - '0') + carry + res[i+j+1] - '0';
            res[i+j+1] = temp % 10 + '0';
            carry = temp / 10;
            if(carry && j==0){  // 如果短串用完且carry不为0，需要修改结果
                res[i] += carry;
            }
        }
    }
    // 去掉前排的0
    int i=0;
    while(res[i]=='0')
        res.erase(0, 1);  // 删除字符串第0个位置开始第一个字符
    return res;
}
int Performance(vector<int> &h, vector<int> &w){
    int res = 0;
    int n = h.size()-1, m = w.size()-1;
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());
    while(m>=0&&n>=0){
        if(w[m]>=h[n]){
            res++;
            m--;
            n--;
        }
        else{
            n--;
        }
    }
    return res;
}
// 迷宫
char G[105][105];
int book[105][105][1200], N, M;
int Next[4][2]={0, 1, 0, -1, 1, 0, -1, 0};
struct node{
    int x, y, k, step;
    node(int x, int y, int k, int step):x(x), y(y), k(k), step(step){}
};
int bfs(int startX, int startY){
    queue<node> Q;
    Q.push(node(startX, startY, 0, 0));
    while(!Q.empty()){
        node head=Q.front();
        Q.pop();
        if(G[head.x][head.y]=='3') return head.step;
        for(int i=0;i<4;i++){
            int nx = head.x + Next[i][0], ny = head.y + Next[i][1];
            if(nx>=N || nx<0 || ny>=M || ny<0 || G[nx][ny]=='0')
                continue;
            int key = head.k;
            if('a'<=G[nx][ny]&&G[nx][ny]<='z')
                key = key | (1 << (G[nx][ny] - 'a'));
            if('A'<=G[nx][ny]&&G[nx][ny]<='Z'&&(key&(1<<(G[nx][ny]-'A')))==0)
                continue;
            if(!book[nx][ny][key]){
                book[nx][ny][key]=1;
                Q.push(node(nx, ny, key, head.step+1));
            }
        }
    }
    return 0;
}
void migon(){
    int i, j;
    while(scanf("%d%d", &N, &M)!=EOF){
        for(i=0;i<N;i++)
            cin>>G[i];
        memset(book, 0, sizeof(book));
        int flag=0;
        for(i=0;i<N;i++){
            if(flag==1)
                break;
            for(j=0;j<M;j++){
                if(G[i][j]=='2'){
                    flag=1;
                    book[i][j][0]=1;
                    printf("%d\n", bfs(i, j));
                    break;
                }
            }
        }
    }
}

// 彩色砖块
int colorBatten(){
    string str;
    cin>>str;
    int res=0;
    sort(str.begin(), str.end());
    str.erase(unique(str.begin(), str.end()), str.end());
    if(str.size()==1){
        res = 1;
    }
    else if(str.size()==2)
        res = 2;
    cout<<res<<endl;
    return 0;
}

// 交错01串
int swap_zero_one(string &str){
    int len = str.size();
    if(len<=0)
        return 0;
    int max = 1, swap = 1;
    for(int i=1;i<len;i++){
        if(str[i]!=str[i-1]){
            swap++;
            if(swap>max)
                max = swap;            
        }
        else{
            swap = 1;
        }
    }  
    return max;
}

// 操作序列
void operate(int n, vector<int> nums){
    if(n==1)
        cout<<nums[0]<<endl;
    if(n%2==0){
        for(long long i=n-1;i>=0;i-=2){
            cout<<nums[i]<<' ';
        }
        cout<<nums[0];
        for(long long i=2;i<n;i+=2){
            cout<<' '<<nums[i];
        }
        cout<<endl;
    }
    else{
        for(long long i=n-1;i>=0;i-=2){
            cout<<nums[i]<<' ';
        }
        cout<<nums[1];
        for(long long i=3;i<n;i+=2){
            cout<<' '<<nums[i];
        }
        cout<<endl;
    }
}

