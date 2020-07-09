#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

string question1(int num) {
    string str;
    int n = num;
    while (n != 0) {
        if ((n - 2) % 2 == 0) {
            str += '3';
            n = (n - 2) / 2;
        } else {
            str += '2';
            n = (n - 1) / 2;
        }
    }
    reverse(str.begin(), str.end());
    return str;
}

string question2(int num, string str) {
    string result;
    map<char, int> mp;
    for (int i = 0; i < str.size(); i++) {
        mp[str[i]]++;
    }
    int star = 0;
    for (int i = 0; i < str.size(); i++) {
        result = str[i];
        if (mp[str[i]] != 1)
            continue;
        else {
            star++;
            if (star == num) return result;
        }
    }
    return "Myon~";
}

int question3(string str) {
    int result;
    vector<string> num;
    int a = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '+' && str[i] != '-' && str[i] != '*') {
            num[a] += str[i];
        } else {
            a++;
            num[a] = str[i];
            a++;
        }
    }
    for (int i = 0; i < num.size(); i++) {
        if (num[i] != "+" && num[i] != "-" && num[i] != "*") {
        }
    }
}

int question4(int n, int m, int id, vector<vector<int> > &num) {
    int result;
    vector<int> com;
    com.push_back(id);
    for (int i = 0; i < num.size(); i++) {
        if (num[i][0] == id) {
            com.push_back(num[i][1]);
        }
        if (num[i][1] == id) {
            com.push_back(num[i][0]);
        }
    }
}
int main() {
    int n, m, id;
    cin >> n, id, m;
    vector<vector<int> > num;
    for (int i = 0; i < m; i++) {
        scanf("%d,%d", &num[i][0], &num[i][1]);
    }
    cout << question4(n, m, id, num) << endl;
    return 0;
}