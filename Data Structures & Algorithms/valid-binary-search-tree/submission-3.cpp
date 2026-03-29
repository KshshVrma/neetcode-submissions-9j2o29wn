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
public:
bool fun(TreeNode* root){
    if(root==NULL)return true;

    
    if(root->left!=NULL){
        TreeNode* templ=root->left;
        while(templ->right!=NULL){
            templ=templ->right;
        }
        if(templ->val >= root->val){
            return false;

        }
    }

  
    if(root->right!=NULL){
        TreeNode* templ=root->right;
        while(templ->left!=NULL){
            templ=templ->left;
        }
        if(templ->val <= root->val){
            return false;
      
        }
    }

    return fun(root->left) && fun(root->right);
}

    bool isValidBST(TreeNode* root) {
        return fun(root);
    }
};
