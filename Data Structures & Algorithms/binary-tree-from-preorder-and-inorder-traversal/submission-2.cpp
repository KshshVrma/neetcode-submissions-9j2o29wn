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
TreeNode * fun(vector<int>&preorder, vector<int>& inorder, int prestart, int preend, int inostart, 
int inoend){

    if(inostart>inoend || prestart>preend){
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[prestart]);
    int k=preorder[prestart];
    int ind=-1;
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==k){
            ind=i;
        }
    }
    int wow =ind-inostart;

    root->left=fun(preorder, inorder, prestart+1,prestart+wow, inostart, ind-1);
    root->right=fun(preorder, inorder, prestart+wow+1,preend, ind+1, inoend);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre=preorder.size();
        int ino=inorder.size();

        return fun(preorder,inorder, 0,pre-1, 0, ino-1);
    }
};
