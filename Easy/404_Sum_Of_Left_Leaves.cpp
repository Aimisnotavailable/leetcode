//Definition for a binary tree node.
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
    int a;
    void trav(TreeNode* curr, bool is_left){
        if(curr == nullptr)
            return;
        if(curr->left == nullptr && curr->right == nullptr && is_left){
            a += curr->val;
        }
        trav(curr->left, true);
        trav(curr->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        trav(root, false);
        return a;
    }
};