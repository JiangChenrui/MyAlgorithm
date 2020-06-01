bool checkSpecialChar(string str){
    string cm{".*[`~!@#$%^&*()+=|{}':;',\\[\\].<>/?~！@#￥%……&*（）——+|{}【】‘；：”“’。，、？].*"};
    // string cm{".*h.*"};
    regex reg(cm);
    bool res = regex_match(str, reg);
    return !res;
}