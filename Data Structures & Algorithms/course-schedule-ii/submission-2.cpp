class Solution {
public:
bool dfs(int i, vector<int>&vis, vector<int>adj[], stack<int>&st,vector<int>&pathvis){
    vis[i]=1;
    pathvis[i]=1;
    for(auto it:adj[i]){
        if(pathvis[it]==1)return false;
        
        if(!vis[it]){
            if(dfs(it, vis, adj, st,pathvis)==false)return false;
        }
    }
    st.push(i);
    pathvis[i]=0;
    return true;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>vis(numCourses, 0);
        for(int i=0;i<prerequisites.size();i++){
            int one=prerequisites[i][0];
            int two=prerequisites[i][1];
            adj[two].push_back(one);
        }
        vector<int>pathvis(numCourses,0);
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i, vis, adj, st,pathvis)==false)return ans;
            }
        }
        
        while(!st.empty()){
            int k=st.top();
            st.pop();
            ans.push_back(k);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
