/* ------------------------------------------------------------------|
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.3 MB, 在所有 C++ 提交中击败了91.51%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int curr = 1;
    int upper = 0;
    int lower = n - 1;
    int left = 0;
    int right = n - 1;
    while (upper < lower) {
        for (int i = left; i < right; ++i) {
            res[upper][i] = ++curr;
        }
        for (int i = upper; i < lower; ++i) {
            res[i][right] = ++curr;
        }
        for (int i = right; i > left; --i) {
            res[lower][i] = ++curr;
        }
        for (int i = lower; i > upper; --i) {
            res[i][left] = ++curr;
        }
        upper++; left++;
        lower--; right--;
    }
    if (n % 2) {
        res[upper][left] = ++curr;
    }
    return res;    
}