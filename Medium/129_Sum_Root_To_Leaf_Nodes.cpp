#include <string>
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
    int trav(TreeNode* root, std::string num, int sum){
        if(root){
            num.push_back(char(root->val + 48));
            if(!root-> left && !root-> right) return sum + std::stoi(num);
            sum = trav(root->left, num, sum);
            sum = trav(root->right, num, sum);
            num.pop_back();
        }
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return trav(root, "", 0);
    }
};