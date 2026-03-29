class Solution {
public:
void dfs(vector<int>&vis, int i, vector<int>adj[]){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            
            dfs(vis,it,adj);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int one=edges[i][0];
            int two=edges[i][1];
            adj[one].push_back(two);
            adj[two].push_back(one);
        }
   
   vector<int>vis(n,0);
   int count=0;
   for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(vis, i, adj);
        
count++;
    }
   
   }
   return count;



    }
};
