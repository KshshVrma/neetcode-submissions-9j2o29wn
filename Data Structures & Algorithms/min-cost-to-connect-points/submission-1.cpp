class Solution {
public:
// int ans(int i, vector<int>&vis, priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
//         greater<pair<int,pair<int,int>>>>&q, vector<pair<int,int>>adj[]){

           
// return 0;

//         }

        bool cycle(vector<pair<int,int>>adj[],int x, vector<int>&vis,int parent){
vis[x]=1;

for(auto it: adj[x]){
    int y=it.first;
    int one=it.second;
    
    if(!vis[y]){if(cycle(adj, y, vis, x))return true;}
    else{
        if( y!=parent)return true;
    }
    
}

return false;
        }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;

        vector<pair<int,int>>adj[points.size()];
        for(int i=0;i<points.size()-1;i++){

            for(int j=i+1;j<points.size();j++){
                int onex=points[i][0];
                int twoy=points[i][1];
                int threex=points[j][0];
                int foury=points[j][1];

                int delx=abs(onex-threex);
                int dely=abs(twoy-foury);
                // adj[i].push_back(delx+dely);
                q.push({(delx+dely),{i,j}});
            }
        }

    
        int sum=0;
        
        while(!q.empty()){
            int one =q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            adj[x].push_back({y, one});
            adj[y].push_back({x, one});
             cout<<x<<" "<<y<<" "<<one<<endl;
        vector<int>vis(points.size(),0);
            if(!cycle(adj, x, vis, -1)){
               
                sum+=one;
            }else{
                 adj[x].pop_back();
            adj[y].pop_back();
            }

        }



    //    int ans= bfs(vis,q, adj);

       return sum;


    }
};
