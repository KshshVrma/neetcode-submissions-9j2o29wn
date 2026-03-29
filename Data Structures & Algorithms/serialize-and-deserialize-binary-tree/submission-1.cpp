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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p=q.front();
            if(p->val==-1001){
                ans+="%,";
                q.pop();
                continue;
            }
            ans+=to_string(p->val);
            ans+=',';
            q.pop();
            if(p->left==NULL){
                
             q.push(new TreeNode(-1001));
            }else{
               
                q.push(p->left);
            }
              if(p->right==NULL){ 
               q.push(new TreeNode(-1001));
            }else{
                
                q.push(p->right);
            }
        }
  
        return ans; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
vector<int>vec;
string temp="";
for(int i=0;i<data.size();i++){
if(data[i]==','){
    if(temp=="%"){
        vec.push_back(-10001);
    }else{
       vec.push_back(stoi(temp));
    }
    temp="";
}else{
    temp+=data[i];
}
}


        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(vec[0]);
        int var=1;
        q.push(root);
        while(!q.empty() && var<vec.size()){
            TreeNode* p=q.front();
            q.pop();

            if(vec[var]==-10001){
                p->left= NULL;
                  
            }else{
TreeNode* le=new TreeNode(vec[var]);
p->left=le;
q.push(le);
            }
             var++;

             if(vec[var]==-10001){
                p->right= NULL;
                  
            }else{
TreeNode* re=new TreeNode(vec[var]);
p->right=re;
q.push(re);
            }
             var++;
        }

        return root;
        
    }
};
