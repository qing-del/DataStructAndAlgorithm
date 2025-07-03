#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{
private:
    TreeNode *root;
    int size = 0; //节点数量;
    int max = 0;  //树的最大值
    int min = 0;  //树的最小值

public:
    BinaryTree() {}
    BinaryTree(int num)
    {
        root = new TreeNode(num);
        root->val = num;
    }

    TreeNode *getRoot()
    {
        return this->root;
    }

    void put(int num)
    {
        if (root == nullptr) //检测根是否为空
        {
            root = new TreeNode(num);
            size++;
            max = num;
            min = num;
        }

        TreeNode *cur = root;
        TreeNode *pre = nullptr;

        while (cur != nullptr)
        {
            if (num == cur->val)
            {
                cur->val = num;
                return;
            }
            else if (num < cur->val)
            {
                pre = cur;
                cur = cur->left;
            }
            else
            {
                pre = cur;
                cur = cur->right;
            }
        }

        if (cur == nullptr)
        {
            cur = new TreeNode(num);
            if (pre->val > num)
            {
                pre->left = cur;
            }
            else
            {
                pre->right = cur;
            }
            max = max > num ? max : num;
            min = min < num ? num : num;
            size++;
        }
    }

    void show(TreeNode *p, string s) //遍历
    {
        if (root == nullptr)
            return;
        if (p == nullptr)
            return;
        if (s == "pre") //前序遍历
        {
            cout << p->val << " ";
            show(p->left, s);
            show(p->right, s);
        }
        else if (s == "mid") //中序遍历
        {
            show(p->left, s);
            cout << p->val << " ";
            show(p->right, s);
        }
        else //后续遍历
        {
            show(p->left, s);
            show(p->right, s);
            cout << p->val << " ";
        }
    }

    void showMaxMin()
    {
        cout << max << endl;
        cout << min << endl;
    }
};

int main()
{
    BinaryTree tree(2);
    TreeNode *root = tree.getRoot();
    int commind = 0;
    while (commind != 3)
    {
        cout << "1--insert" << endl;
        cout << "*2--show*" << endl;
        cin >> commind;
        if (commind == 1)
        {
            int num;
            cin >> num;
            tree.put(num);
        }
        else if (commind == 2)
        {
            tree.show(root, "pre");
        }
        else if (commind == 0)
        {
        }

        system("pause");
        system("cls");
    }

    return 0;
}