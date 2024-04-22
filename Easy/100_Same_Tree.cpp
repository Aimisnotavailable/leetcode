#include<vector>
#include<climits>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> trav(TreeNode* root, std::vector<int> a){
        if(!root){
            a.push_back(INT_MIN);
            return a;
        }
        a.push_back(root->val);
        a = trav(root->left, a);
        a = trav(root->right, a);
        return a;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::vector<int> a;
        std::vector<int> b;
        a  = trav(p, a);
        b = trav(q, b);
        int i = 0,  j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i++] != b[j++])
                return false;
        }

        return true;
    }
};