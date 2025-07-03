#include <bits/stdc++.h>
using namespace std;
//求二叉树最近公共祖先
//测试链接：https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;

        root->left = lowestCommonAncestor(root->left, p, q);
        root->right = lowestCommonAncestor(root->right, p, q);
       //两个节点出现 |分叉关系| 情况会使用这个分支
        if (root->left != NULL && root->right != NULL)
            return root;
        //说明在root往下的树中没找到 p、q 其中一个节点
        if (root->left == NULL && root->right == NULL)
            return NULL;
        //说明只找到了其中一个节点 或者 出现了 |包含关系|
        return root->left == NULL ? root->right : root->left;
    }
};