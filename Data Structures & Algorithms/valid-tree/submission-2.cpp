class Solution {
public:
bool dfs(vector<int>&vis, int i, vector<int>adj[],int parent){
    vis[i]=1;

    for(auto it:adj[i]){
        if(vis[it]==1 && it!=parent)return false;
        if(!vis[it]){
            if(dfs(vis,it,adj,i)==false)return false;

        }
    }
    return true;
}
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int one=edges[i][0];
            int two=edges[i][1];
            adj[one].push_back(two);
            adj[two].push_back(one);
        }
        int count=0;
        vector<int>vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(vis,  i,adj,-1)==false)return false;
                count++;
            }
        }
        return count==1;

    }
};
