//验证搜索二叉树
//测试链接：https://leetcode.cn/problems/validate-binary-search-tree/

//解法1
class Solution_1 {
    int maxn = 2 << 30;
    bool vail = 1, first=0;
    void solve(TreeNode* cur)
    {
        if (cur == NULL) return;
        solve(cur->left);
        if (!vail) return;
        if (maxn >= cur->val && first) {
            vail = 0;
            return;
        }
        maxn = cur->val;first=1;
        solve(cur->right);
    }
public:
    bool isValidBST(TreeNode * root) {
        solve(root);
        return vail;
    }
};

//解法2：
