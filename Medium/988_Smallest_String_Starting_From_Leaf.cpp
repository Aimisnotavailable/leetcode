#include<string>
#include<algorithm>
 // Definition for a binary tree node.
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
    std::string res;
    void trav(TreeNode* root, std::string current){
        if(!root)
            return;
        current.push_back(char(root->val + 97));
        if(!root->left && !root->right){
            int i = res.size() - 1;
            int j = current.size() - 1;
            if(res.size() == 0){
                res = current;
            }
            while(i >= 0 && j>= 0){
                if(res[i] == current[j]){
                    i--;
                    j--;
                    continue;
                }
                if(res[i--] < current[j--] )
                    return;
                else{
                    res = current;

                    return;
                }
            }
            res = (i >= 0) ? current : res;
            return;
        }
        trav(root->left, current);
        trav(root->right, current);
        current.pop_back();
    }
    std::string smallestFromLeaf(TreeNode* root) {
        trav(root, "");
        std:reverse(res.begin(), res.end());
        return res;
    }
};