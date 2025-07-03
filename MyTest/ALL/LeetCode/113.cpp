//测试链接：https://leetcode.cn/problems/path-sum-ii/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> list;
    void solve(vector<vector<int>>& ans, TreeNode* cur, int sum, const int& target)
    {
        sum+=cur->val;
        list.push_back(cur->val);
        if(cur->left==NULL && cur->right==NULL)
        {
            if(sum==target) ans.push_back(list);
            list.pop_back();
            return;
        }
        if(cur->left!=NULL)
            solve(ans,cur->left,sum,target);
        if(cur->right!=NULL)
            solve(ans,cur->right,sum,target);
        list.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        solve(ans,root,0,targetSum);
        return ans;
    }
};