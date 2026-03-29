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
int fun(TreeNode* root, int &maxi){
    if(root==NULL)return 0;

    int lefti=fun(root->left, maxi);
    int righti=fun(root->right, maxi);

    maxi=max(maxi, max(root->val + lefti + righti, 
    max(root->val + lefti, max(root->val+righti,root->val))));

    return max(root->val, root->val + max(lefti, righti));
}
    int maxPathSum(TreeNode* root) {
if(root==NULL)return 0;

int maxi=root->val;
fun(root, maxi);
return maxi;



    }
};
