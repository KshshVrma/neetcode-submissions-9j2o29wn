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
int fun(TreeNode* root,int maxi){
     if(root==NULL){
            return 0;
        }

    int curr=(root->val>=maxi)?1:0;
        int maxtillnow=max(maxi,root->val);
    return curr+fun(root->left,maxtillnow)+fun(root->right,maxtillnow);
    
}
    int goodNodes(TreeNode* root) {
        return fun(root,INT_MIN);
    }
};
