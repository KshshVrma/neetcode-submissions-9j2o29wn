class Solution {
public:
unordered_map<string, vector<string>> adj;
vector<string>ans;
int numtick=0;
bool dfs(string origin,vector<string>& path){
path.push_back(origin);
if(path.size()==numtick+1){
    ans=path;
    return true;
}
for(int i=0;i<adj[origin].size();i++){
string target=adj[origin][i];
adj[origin].erase(adj[origin].begin()+i);
if(dfs(target,path)==true)return true;
adj[origin].insert(adj[origin].begin()+i, target);
}
path.pop_back();
return false;

}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto &it:adj){
            sort(it.second.begin(),it.second.end());
        }
        vector<string>path;
numtick=tickets.size();
       dfs("JFK",path );
       return ans;
    }
};
