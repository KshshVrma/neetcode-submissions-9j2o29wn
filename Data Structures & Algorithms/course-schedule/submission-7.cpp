class Solution {
public:
bool dfs(int i, vector<int>&pathvis, vector<int>&vis, vector<int>adj[]){
    vis[i]=1;
    pathvis[i]=1;
   cout<<i<<endl;
    for(auto it:adj[i]){
     cout<<it<<"->";
        if(pathvis[it])return false;
        if(dfs(it,pathvis, vis, adj)==false)return false;
    }
   cout<<endl;
   pathvis[i]=false;
    return true;
}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses, 0);
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int one=prerequisites[i][0];
            int two=prerequisites[i][1];
            adj[one].push_back(two);
        }
        

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                vector<int>pathvis(numCourses,0);
                if(dfs(i,pathvis,vis, adj)==false){
                    return false;
                };
            }
        }
        // int count=0;
        // for(int i=0;i<vis.size();i++){
        //     if(vis[i]==1)count++;

        // }
        // return count==numCourses;
        return true;
    }
};
