class Solution {
public:
void bfs(int i,vector<pair<int,int>>adj[],vector<int>&weights,
 priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
 greater<pair<int,pair<int,int>>>> &q ){
weights[i]=0;

for(auto it:adj[i]){
    int node=it.first;
    int w=it.second;
    if(weights[node]>w){

        weights[node]=w;
    q.push({w,{i,node}});
    }
}
while(!q.empty()){
    int wt=q.top().first;
    int edgeo=q.top().second.first;
    int edgt=q.top().second.second;
    cout<<wt<<" "<<edgeo<<" "<<edgt<<endl;
    q.pop();

for(auto it:adj[edgt]){
    int node=it.first;
    int w=it.second;
   if(weights[node]>w+wt){
        weights[node]=wt+w;
    q.push({wt+w,{edgt,node}});
    }
}


}

 }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,pair<int,int>>,
         vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>p;
        vector<int>weights(n+1, INT_MAX);
        weights[k]=0;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            int one=times[i][0];
            int two=times[i][1];
            int w=times[i][2];

            adj[one].push_back({two,w});
        }

weights[0]=-1;
        bfs(k, adj, weights, p);
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            if(maxi<weights[i]){
                maxi=weights[i];
            }

        }
        if(maxi==INT_MAX)return -1;
        return maxi;

    }
};
