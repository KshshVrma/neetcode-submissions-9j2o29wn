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
TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL){
        return NULL;
    }
    if(p==NULL || q==NULL)return NULL;
    int k=root->val;
    if(p->val<k && q->val< k){
        return fun(root->left, p, q);
    }
      if(p->val>k && q->val> k){
        return fun(root->right, p, q);
    }
    if((p->val<=k && q->val>=k)|| (q->val<=k && p->val>=k))return root;
    // if((p->val<k && q->val==k) || (p->val==k && q->val>k) || (q->val<k && p->val==k) ||
    //  (q->val==k && p->val>k) || (p->val==k && q->val ==k)){
    //     return root;
    // }  
    return NULL;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        return fun(root, p, q);
  
    }
};
