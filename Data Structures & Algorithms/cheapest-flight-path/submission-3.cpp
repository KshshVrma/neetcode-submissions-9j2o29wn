class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int ori=flights[i][0];
            int des=flights[i][1];
            int dis=flights[i][2];
            adj[ori].push_back({des, dis});
        }
        vector<int>help(n, 1e8);    
        help[src]=0;
queue<pair<int,int>>q;
        q.push({src, 0});
int count=0;
int ans=1e8;
        while(!q.empty() && count<=k){
            int p=q.size();
            cout<<p<<" "<< count<<endl;
            while(p--){
                int dest=q.front().first;
                int dist=q.front().second;
                q.pop();

                for(auto it:adj[dest]){
                    int newdest=it.first;
                    int newdist=it.second;
                    if(help[newdest]>newdist+ dist){
                        q.push({newdest,newdist+dist});
                        help[newdest]=newdist+dist;
                        if(newdest==dst){
                            ans=min(ans,newdist+dist);
                        }
                    }
                }
            }      
            count++;
        }

        return ans==1e8? -1 : help[dst];

    }
};
