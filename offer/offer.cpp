#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
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

    int findorder(vector<int> array, int num) {
        for(int i=0;i<array.size();i++){
            if(array[i] == num)
                return i;
        }
    }
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        vector<int> number;
        if(pushV.empty() || popV.empty())
            return false;
        for(int i=0;i<pushV.size();i++){
            number.push_back(findorder(pushV, popV[i]));
        }
        int max = number[0];
        for(int i=1;i<number.size()-1;i++){
            if(number[i]>max)
                max = number[i];
            if(number[i]<max && number[i]<number[i+1])
        }
    }
};

int main() {
    Solution S1;
    vector<int> num;
    num = {2, 3, 4, 5, 6, 7};
    vector<vector <int>> input;
    input = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // S1.printMatrix({{1},{3}});
    // cout<<S1.NumberOf1(12312)<<endl;
    // cout<<S1.Power(2.45465, 45)<<endl;
    // S1.reOrderArray(num);

    return 0;
}