class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        for(int i=0;i<trust.size();i++){
            int one=trust[i][0];
            int two=trust[i][1];
            adj[one].push_back(two);
        }
        int count=0;
        int num=0;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0){
count++;
num=i;
            }
        }
        if(count>1){
            return -1;
        }
        for(int i=1;i<n;i++){
            if(i!=num){
                bool has=false;
                for(int j=0;j<adj[i].size();j++){
                    if(adj[i][j]==num){
                        has=true;
                    }
                }
                if(!has)return -1;
            }
        }
        return num;
    }
};