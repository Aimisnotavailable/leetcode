
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
    TreeNode* add_row(TreeNode* root, TreeNode* prev, int val, int depth, bool is_left){
        if(depth == 1){
            TreeNode* t1 = new TreeNode(val);
            if(!prev){
                t1->left = root;
                return t1;
            }
            
            TreeNode* t = (is_left) ? prev->left : prev->right;
            if(is_left){
                prev->left = t1;
                t1->left = t;
            }
            else{
                prev->right = t1;
                t1->right = t;
            }
            return root;
        }
        if(!root){
            return root;
        }
        depth--;

        add_row(root->left, root, val, depth, true);
        add_row(root->right, root, val, depth, false);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return add_row(root, nullptr, val, depth, false);
    }
};