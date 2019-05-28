#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<string.h>
#include<queue>
#include<map>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL){}
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL){
    }
};

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL){
    }
};

struct TreeLinkNode{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution{
public:
    int NumberOf1(int n) {
        // 二进制中1的个数
        // 错误解法 计算负数会出错
        // int result=0;
        // while(n!=0){
        //     if((n&1) == 1){
        //         result++;
        //     }
        //     n = n>>1;
        // }
        // return result;

        // int result=0;
        // int flag=1;
        // while(flag!=0){
        //     if((n&flag) != 0){
        //         result++;
        //     }
        //     flag = flag << 1;
        // }
        // return result;

        int result=0;
        while(n != 0){
            result++;
            n = (n - 1) & n;
        }
        return result;
    }

    double Power(double base, int exponent) {
        // 数值的整数次方
        // 垃圾方法
        // if(exponent==0)
        //     return 1;
        // return Power(base, exponent-1)*base;

        // 优秀方法，10^13 = 10^1101 = 10^1 * 10^100 * 10^1000
        double res=1;
        int n;
        if(base==0)
            return false;
        if(exponent>0){
            n = exponent;
        }
        else if(exponent<0){
            n = -exponent;
        }
        else{
            return 1;
        }
        while(n != 0) {
            if((n&1) == 1)
                res *= base;
            base *= base;
            n >>= 1;
        }
        return exponent>0? res:(1/res);
    }

    double power2(double base, int exponent){
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        bool isNegative = true;
        if(exponent<0){
            exponent = -exponent;
            isNegative = false;
        }
        double pow = Power(base*base, exponent/2);
        if(exponent%2!=0)
            pow *= base;
        return isNegative? pow:(1/pow);
    }

    void reOrderArray(vector<int> &array) {
        // 调整数组顺序使奇数位于偶数
        vector<int> even; // 存储偶数
        int j=0;
        for(int i=0;i<array.size();i++){
            if(array[i]%2 == 0)
                even.push_back(array[i]);
            else{
                array[j++] = array[i]; 
            }
        }
        int i=0;
        for(j;j<array.size();j++){
            array[j] = even[i++];
        }
    }

    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pre, *now;
        pre = pHead;
        now = NULL;
        now->next = NULL;
        while(pre!=NULL){
            ListNode *temp;
            temp = pre->next;
            pre->next = now;
            now = pre;
            pre = temp;
        }
        return now;
    }

    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pHead, *pNode;
        if(pHead1->val > pHead2->val){
            pHead = pHead2;
            pHead2 = pHead2->next;
        }
        else{
            pHead = pHead1;
            pHead1 = pHead1->next;
        }
        pNode = NULL;
        pHead->next = pNode;
        while(pHead1!=NULL || pHead2!=NULL){
            if(pHead1 == NULL){
                pNode = pHead2;
                break;
            }
            else if(pHead2 == NULL){
                pNode = pHead1;
                break;
            }
            if(pHead1->val > pHead2->val){
                pNode = pHead2;
                pHead2 = pHead2->next;
            }
            else{
                pNode = pHead1;
                pHead1 = pHead1->next;
            }
        }
        return pHead;
    }

    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2==NULL)
        // 如果2为空，说明2的节点都与1相同，因为主程序排除了2为空的可能，2只能是递归调用完后为空
            return true;
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val == pRoot2->val){
            return isSubtree(pRoot1->left, pRoot2->left) &&
                isSubtree(pRoot1->right, pRoot2->right);
        }
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 判断2是否是1的子结构
        if(pRoot2==NULL || pRoot1==NULL)
            return false;        
        return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2)
            || HasSubtree(pRoot1->right, pRoot2);
        // 首先判断根节点是不是子结构，然后分别判断左右子树，使用这个函数的递归来将1二叉树的所有节点进行遍历 
    }

    void Mirror(TreeNode *pRoot){
        // 二叉树的镜像
        if(pRoot==NULL)
            return;
        TreeNode *temp;
        temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        // 顺时针打印矩阵
        vector<int> result;
        int left = 0, up = 0, right = matrix[0].size()-1, down = matrix.size()-1;
        if(right==-1 || down==-1)
            return result;
        while(left<=right && up<=down){
            for(int a=left;a<=right;a++){
                result.push_back(matrix[up][a]);
            }
            up += 1;
            for(int b=up;b<=down;b++){
                result.push_back(matrix[b][right]);
            }
            right -= 1;
            if(up <= down){
                for(int c=right;c>=left;c--){
                    result.push_back(matrix[down][c]);
                }
                down -= 1;
            }
            if(left<=right){
                for(int d=down;d>=up;d--){
                    result.push_back(matrix[d][left]);
                }
                left += 1;
            }
        }
        return result;
    }

    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        // 判断序列是否是栈的弹出序列，想法是建一个栈，能够完全弹出栈就会为空，不能就为false
        stack<int> s;
        int len = pushV.size();
        if(len==0)
            return false;
        for(int i=0, j=0;i<len;i++){
            s.push(pushV[i]);
            while(j<len && s.top()==popV[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }

    vector<int> PrintFromTopToBottom(TreeNode* root) {
        // 从上往下，从左到右打印二叉树。使用队列存储二叉树
        vector<int> result;
        queue<TreeNode*> q;
        if(root==NULL)
            return result;
        q.push(root);
        while(!q.empty()){
            result.push_back(q.front()->val);
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
        }        
        return result;
    }

    bool judge(vector<int> array, int start, int end){
        if(start >= end)
            return true;
        int mid = start;
        while(array[mid] < array[end])
            mid++;
        for(int j=mid;j<end;j++){
            if(array[j] < array[end])
                return false;
        }
        return judge(array, start, mid-1) && judge(array, mid, end-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 二叉树的后序遍历序列，使用递归的方法，二分数组进行
        int len = sequence.size();
        if(len==0)
            return false;
        if(len==1)
            return true;
        return judge(sequence, 0, len-1);
    }

    private: void FindPath1(vector<vector<int>> &result, vector<int> &arr, TreeNode* root, int num){
        if(root==NULL)
            return;        
        arr.push_back(root->val);
        if(!root->left && !root->right && num-root->val == 0){
            result.push_back(arr);
        }
        else if(num-root->val <0){
            arr.pop_back();
            return;
        }
        else if(num-root->val >0){
            FindPath1(result, arr, root->left, num-root->val);
            FindPath1(result, arr, root->right, num-root->val);
        }
        arr.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        // 二叉树中和为某一值的路径，题目表述不清楚，必须是到树的底部
        vector<vector<int>> result;
        vector<int> arr;
        if(root==NULL)
            return result;
        FindPath1(result, arr, root, expectNumber);
        return result;
    }

    RandomListNode* Clone(RandomListNode* pHead){
        // 复杂链表的复制
        // 方法，将原列表复制，如将ABCD转换为AABBCCDD，将所有关系复制，然后分割
        if(!pHead) return NULL;
        RandomListNode *currNode = pHead;
        while(currNode){
            RandomListNode *node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        currNode = pHead;
        while(currNode){
            RandomListNode *node = currNode->next;
            if(currNode->random){
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        // 拆分
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next){
            tmp = currNode->next;
            currNode->next = tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }

    TreeNode* Convert(TreeNode* pRootOfTree){
        // 二叉搜索树与双向链，使用中序遍历解决，使用pre记录上次操作的节点，便于返回。
        if(pRootOfTree==NULL)
            return NULL;
        TreeNode* pre = NULL;
        ConvertHelp(pRootOfTree, pre);

        TreeNode* res = pRootOfTree;
        while(res->left){
            res = res->left;
        }
        return res;
    }   
    void ConvertHelp(TreeNode* cur, TreeNode*& pre){
        if(cur==NULL)
            return;
        
        ConvertHelp(cur->left, pre);

        cur->left = pre;
        if(pre)
            pre->right = cur;
        pre = cur;

        ConvertHelp(cur->right, pre);
    }

    // vector<string> Permutation(string str){
    //     // 字符串的排列
    //     string end;
    //     vector<string> result;
    //     end.push_back(str.back());
    //     str.pop_back();
    //     PermutationHelp(str, end, result);
    // }
    // void PermutationHelp(string start, string end, vector<string> &res){
    //     if(start.size()==1){
    //         res.push_back(start+end);
    //     }
    // }
    vector<string> Permutation(string str){
        // 字符串的排列
        vector<string> result;
        if(str.empty()) return result;

        PermutationHelp(str, result, 0);

        sort(result.begin(), result.end());

        return result;
    }
    void PermutationHelp(string str, vector<string> &res, int begin){
        if(begin==str.size()-1){
            if(find(res.begin(), res.end(), str) == res.end()){
                // 保证没有重复元素
                res.push_back(str);
            }
        }
        else{
            for(int i=begin;i<str.size();i++){
                // 循环里面套递归
                swap(str[i], str[begin]);
                PermutationHelp(str, res, begin+1);
                swap(str[i], str[begin]);
            }
        }
    }
 

    bool duplicate(int numbers[], int length, int* duplication) {
        // 数组中重复的数字
        if(length<2)
            return false;        
        for(int i=0;i<length;){
            if(numbers[i] == i){
                i++;
            }
            else if(numbers[numbers[i]]!=numbers[i]){
                int temp;
                temp = numbers[numbers[i]];
                numbers[numbers[i]] = numbers[i];
                numbers[i] = temp;
            }
            else{
                duplication[0] = numbers[i];
                return true;
            }                       
        }
        return false;
    }   

    void replaceSpace(char* str, int length){
        // 替换空格
        if(length<=0){
            return;
        }
        int space_num=0;
        for(int i=0;i<length;i++){
            if(str[i]==' ')
                space_num++;
        }
        length--;
        int len = length + space_num*2;
        while(length>=0){
            if(str[length]==' '){
                length--;
                str[len--] = '0';
                str[len--] = '2';
                str[len--] = '%';
            }
            else{
                str[len--] = str[length--];
            }
        }
    }

    vector<int> printListFromTailToHead(ListNode* head){
        // 从尾到头打印链表
        vector<int> result;
        if(head==NULL){
            return result;
        }
        // 使用栈实现
        ListNode* node = head;
        stack<int> s;
        while(node!=NULL){
            s.push(node->val);
            node = node->next;
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;

    }
    // vector<int> result;
    // vector<int> printListFromTailToHead(ListNode* head){
    //     // 使用递归
    //     ListNode* node = head;
    //     if(node!=NULL){
    //         if(node->next!=NULL)
    //             printListFromTailToHead(node->next);
    //         result.push_back(node->val);
    //     }
    //     return result;
    // }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin){
        // 重建二叉树
        TreeNode* head;
        int len = pre.size();
        if(len==0)
            return NULL;
        vector<int> left_pre, left_vin, right_pre, right_vin;
        int node;
        for(int i=0;i<len;i++){
            if(pre[0] == vin[i]){
                node == i;
                break;
            }
        }
        for(int i=0;i<node;i++){
            left_pre.push_back(pre[i+1]);
            left_vin.push_back(vin[i]);
        }
        for(int i=node+1;i<len;i++){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        head->left = reConstructBinaryTree(left_pre, left_vin);
        head->right = reConstructBinaryTree(right_pre, right_vin);
        return head;
    }

    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 二叉树的下一个结点
        TreeLinkNode* node;
        if(pNode->right!=NULL){
            node = pNode->right;
            while(node->left){
                node = node->left;
            }
            return node;
        }
        while(pNode->next!=NULL){
            node = pNode->next;
            if(node->left == pNode){
                return node;
            }
            pNode = pNode->next;
        }
        return NULL;
    }

//     // 用两个栈实现队列
//     void push(int node){
//         stack1.push(node);
//     }
//     int pop(){
//         int res;
//         if(!stack2.empty()){
//             res = stack2.top();
//             stack2.pop();
//             return res;
//         }
//         else{
//             while(!stack1.empty()){
//                 stack2.push(stack1.top());
//                 stack1.pop();
//             }
//             res = stack2.top();
//             stack2.pop();
//             return res;
//         }        
//     }
// private:
//     stack<int> stack1;
//     stack<int> stack2;

    int Fibonacci(int n){
        // 斐波那契数列
        int f=0, g=1;
        while(n--){
            g += f;
            f = g - f;
        }
        return f;
    }

    int minNumberInRotateArray(vector<int> rotateArray){
        // 旋转数组
        if(rotateArray.size()==0)
            return 0;
        int low=0, high=rotateArray.size()-1, mid;
        while(low<high){
            mid = (low + high) / 2;
            if(rotateArray[mid]<=rotateArray[high])
                high = mid;
            else
                low = mid + 1;
        }
        return rotateArray[low];
    }

    bool hasPath(char* matrix, int rows, int cols, char* str){
        // 矩阵中的路径
        vector<bool> flag(rows*cols, false);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(helper(matrix, rows, cols, i, j, str, 0, flag))
                    return true;
            }
        }
        return false;
    }
    bool helper(char* matrix, int rows, int cols, int i, int j, char* str, int k, vector<bool> flag){
        int index = i * cols + j;
        if(i<0 || j<0 || i>=rows || j>=cols || matrix[index]!=str[k] || flag[index]==true){
            return false;
        }
        if(k == strlen(str) - 1) return true;
        flag[index] = true;
        if(helper(matrix, rows, cols, i-1, j, str, k+1, flag)
        || helper(matrix, rows, cols, i+1, j, str, k+1, flag)
        || helper(matrix, rows, cols, i, j-1, str, k+1, flag)
        || helper(matrix, rows, cols, i, j+1, str, k+1, flag))
            return true;
        flag[index] = false;
        return false;
    }
    int movingCount(int threshold, int rows, int cols){
        // 机器人的运动范围
        vector<bool> flag(rows*cols, false);
        return moving(rows, cols, 0, 0, flag, threshold);
    }   
    int moving(int rows, int cols, int i, int j, vector<bool> &flag, int threshold){
        // 传入引用，否则会使更改不能生效
        int index = i * cols + j;
        int sum = compute_sum(i, j);
        if(i<0 || j<0 || i>=rows || j>=cols || flag[index]==true || sum>threshold){
            return 0;
        }
        flag[index] = true;
        return moving(rows, cols, i-1, j, flag, threshold)
            + moving(rows, cols, i+1, j, flag, threshold)
            + moving(rows, cols, i, j-1, flag, threshold)
            + moving(rows, cols, i, j+1, flag, threshold)
            + 1;
    }
    int compute_sum(int i, int j){
        int sum=0;
        while(i>0){
            sum += i%10;
            i = i/10;
        }
        while(j>0){
            sum += j%10;
            j = j/10;
        }
        return sum;
    }

    int integerBreak(int n){
        // 整数拆分
        int result = 1;
        if(n<3){
            return 1;
        }
        if(n==3)
            return 2;
        while(n>4){
            result *= 3;
            n -= 3;
        }
        return n*result;
    }

    void printToMaxOfNDigits(int n){
        // 打印从 1 到最大的 n 位数
        
    }

    int MoreThanHalfNum_Solution(vector<int> numbers) {
        // 数组中出现次数超过一半的数字
        map<int, int> mp;
        int result = 0;
        int len = numbers.size();
        if(len==1)
            return 1;
        for(int i=0;i<len;i++){
            mp[numbers[i]]++;
            if(mp[numbers[i]]>len/2){
                result = numbers[i];
                break;
            }
        }
        return result;
    }

    int FindGreatestSumOfSubArray(vector<int> array) {
        // 连续字数组的最大和
        vector<int> result;
        if(array.empty())
            return 0;
        result.push_back(array[0]);
        for(int i=1;i<array.size();i++){
            result.push_back(max(result[i-1]+array[i], array[i]));
        }
        int res=result[0];
        for(int i=0;i<result.size();i++){
            if(result[i]>res)
                res = result[i];
        }
        return res;
    }   

    int NumberOf1Between1AndN_Solution(int n){
        // 整数中1出现的次数
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
            int a = n/m, b = n%m;
            ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }
        return ones;
    }

    static bool cmp(int a, int b){
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A<B;
    }
    string PrintMinNumber(vector<int> numbers) {
        // 把数组排成最小的数
        // to_string将整数转化为字符串，sort的第三个参数定义比较规则，需要设置成静态函数
        string result = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i=0;i<numbers.size();i++){
            result += to_string(numbers[i]);
        }
        return result;
    }    

    int GetUglyNumber_Solution(int index) {
        // 丑数
        if(index<7) return index;
        vector<int> arr;
        int p2=0, p3=0, p5=0, newNum = 1;
        arr.push_back(newNum);
        while(arr.size() < index){
            newNum = min(min(arr[p2]*2, arr[p3]*3), arr[p5]*5);
            if(arr[p2] * 2 == newNum) p2++;
            if(arr[p3] * 3 == newNum) p3++;
            if(arr[p5] * 5 == newNum) p5++;
            arr.push_back(newNum);
        }
        return newNum;
    }

    int FirstNotRepeatingChar(string str) {
        // 第一个只出现一次的字符
        map<char, int> mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
        }
        for(int i=0;i<str.size();i++){
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }    

    int InversePairs(vector<int> data){
        // 数组中的逆序对，o(n^2)算法
        // int result;
        // for(int i=0;i<data.size()-1;i++){
        //     for(int j=i+1;j<data.size();j++){
        //         if(data[i]>data[j])
        //             result++;
        //     }
        // }        
        // return result % 1000000007;
        if(data.size()==0){
            return 0;
        }
        vector<int> copy;
        for(int i=0;i<data.size();i++){
            copy.push_back(data[i]);
        }
        int result = InversePairsCore(data, copy, 0, data.size()-1);
        return result;
    }

    private: 
    int InversePairsCore(vector<int> &data, vector<int> &copy, int low, int high){
        if(low==high){
            return 0;
        }
        int mid = (low+high) >> 1;
        int left = InversePairsCore(data, copy, low, mid);
        int right = InversePairsCore(data, copy, mid+1, high);
        int count = 0;
        int i = mid;
        int j = high;
        int locCopy = high;
        while(i>=low && j>mid){
            if(data[i]>data[j]){
                count += j - mid;
                copy[locCopy--] = data[i--];
                if(count>=1000000007)
                    count %= 1000000007;
            }
            else{
                copy[locCopy--] = data[j--];
            }
        }
        for(;i>=low;i--){
            copy[locCopy--] = data[i];
        }
        for(;j>mid;j--){
            copy[locCopy--] = data[j];
        }
        for(int s=low;s<=high;s++){
            data[s] = copy[s];
        }
        return (left + right + count) % 1000000007;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // 两个链表的第一个公共结点
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
    public: 
    int GetNumberOfK(vector<int> data ,int k) {
        // 数字在排序数组中出现的次数
        int low = getLower(data, k);
        int up = getUper(data, k);
        return up - low;
    }   
    private:
    int getLower(vector<int> &data, int k){
        int start = 0, end = data.size() - 1;
        int mid = (start + end) >> 1;
        while(start <= end){
            if(data[mid] >= k){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = (start + end) >> 1;
        }
        return mid;
    }
    int getUper(vector<int> &data, int k){
        int start = 0, end = data.size() - 1;
        int mid = (start + end) >> 1;
        while(start <= end){
            if(data[mid] > k){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = (start + end) >> 1;
        }
        return mid;
    }
    public:
    int TreeDepth(TreeNode* pRoot){
        // 二叉树深度
        if(pRoot==NULL)
            return 0;
        return max(TreeDepth(pRoot->left) + 1, TreeDepth(pRoot->right) + 1);
    }
    bool IsBalanced_Solution(TreeNode* pRoot){
        // 平衡二叉树
        if(pRoot==NULL)
            return true;
        return abs(TreeDepth(pRoot->left)-TreeDepth(pRoot->right))<=1 && 
        IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    // void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    //     // 数组中只出现一次的数字
    //     map<int, int> mp;
    //     for(int i=0;i<data.size();i++){
    //         mp[data[i]]++;
    //     }
    //     int num=0;
    //     for(int i=0;i<data.size();i++){
    //         if(mp[data[i]]==1){
    //             if(num==0){
    //                 *num1 = data[i];
    //                 num++;
    //             }
    //             else{
    //                 *num2 = data[i];
    //             }
    //         }
    //     }
    // }
    public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        // 使用异或
        if(data.size()<2)
            return;
        int temp = data[0];
        for(int i=1;i<data.size();i++){
            temp ^= data[i];    // 获取数组异或结果
        }
        if(temp==0)
            return;
        int index=0;
        while((temp & 1) == 0){        
            // 获取temp二进制中第一个1的数
            temp >>= 1;
            ++index;
        }
        *num1 = *num2 = 0;
        for(int i=0;i<data.size();i++){
            if(IsBit(data[i], index)){
                *num1^=data[i];
            }
            else{
                *num2^=data[i];
            }
        }
    }   
    private:
    bool IsBit(int num, int index){
        num = num>>index;
        return (num&1);
    }
    // public:
    // static bool cmp(int a, int b){
    //     // 需要添加静态标识
    //     string A="";
    //     string B="";
    //     A += to_string(a);
    //     A += to_string(b);
    //     B += to_string(b);
    //     B += to_string(a);
    //     return A<B;
    // }
    // string PrintMinNumber(vector<int> numbers) {
    //     string result="";
    //     sort(numbers.begin(), numbers.end(), cmp);
    //     for(int i=0;i<numbers.size();i++){
    //         result += to_string(numbers[i]);
    //     }
    //     return result;
    // } 
    public:
    string ReverseSentence(string str){
        string res="", tmp="";
        for(int i=0;i<str.size();i++){
            if(str[i]==' '){
                res = " " +  tmp + res;
                tmp = "";
            }
            else{
                tmp += str[i];
            }
        }
        if(tmp.size()){
            res = tmp + res;
        }
        return res;
    }
};

int main() {
    Solution S1;
    vector<int> num;
    int num1, num2;
    num = {3, 321, 32};
    char matrix[] = "student. a am I";  // 可赋值
    // char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";  // 不可赋值
    // char str[]="SLHECCEIDEJFGGFIE";
    // cout<<S1.hasPath(matrix, 5, 8, str)<<endl;
    // int numbers[]={2, 1, 3, 0, 4};
    // int *a;
    // vector<vector <int>> input;
    // input = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // cout<<S1.IsPopOrder({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2})<<endl;
    // S1.printMatrix({{1},{3}});
    // cout<<S1.NumberOf1(12312)<<endl;
    // cout<<S1.Power(2.45465, 45)<<endl;
    // S1.reOrderArray(num);
    // cout<<S1.duplicate(numbers, 5, a)<<' '<<a[0]<<endl;
    // cout<<S1.VerifySquenceOfBST(num)<<endl;
    // cout<<S1.Fibonacci(40)<<endl;
    // cout<<S1.movingCount(9, 5, 5)<<endl;
    // cout<<S1.integerBreak(4)<<endl;
    // vector<string> res = S1.Permutation("abc");
    // cout<<S1.MoreThanHalfNum_Solution(num)<<endl;
    // cout<<S1.FindGreatestSumOfSubArray(num)<<endl;
    // cout<<S1.PrintMinNumber(num)<<endl;
    // cout<<S1.GetUglyNumber_Solution(19)<<endl;
    // cout<<S1.InversePairs(num)<<endl;
    // cout<<S1.GetNumberOfK(num, 4)<<endl;
    // S1.FindNumsAppearOnce(num, &num1, &num2);
    // while(scanf("%d", &num1)){
    //     scanf("%d", &num2);
    //     cout<<(num1 & num2)<<endl;
    // }
    // cout<<S1.PrintMinNumber(num)<<endl;
    cout<<S1.ReverseSentence(matrix)<<endl;
    return 0;
}