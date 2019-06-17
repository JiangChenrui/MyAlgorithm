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