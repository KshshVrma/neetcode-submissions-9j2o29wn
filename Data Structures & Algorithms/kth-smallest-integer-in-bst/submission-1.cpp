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
int count=0;
int ans=-1;
int inorder(TreeNode* root, int k){
    if(root==NULL)return -1;
    int one=inorder(root->left,k);
    count++;
    if(count==k){
        ans=root->val;
          return root->val;
    }
    int two=
    inorder(root->right,k);
    if(one!=-1)return one;
    if(two!=-1)return two;
    return -1;
}
    int kthSmallest(TreeNode* root, int k) {

    inorder(root, k);
    return ans;
        
    }
};
