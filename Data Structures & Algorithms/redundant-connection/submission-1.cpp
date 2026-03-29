class DSU{
    public:
vector<int> size, parent;

DSU(int n){
size.resize(n+1,0);
for(int i=0;i<=n;i++){
    parent.push_back(i);
}
}

int findUpar(int i){
    if(parent[i]==i)return i;
    return parent[i]=findUpar(parent[i]);
}

void unionbysize(int i, int j){
    if(findUpar(i)==findUpar(j))return ;

    if(size[findUpar(i)]>size[findUpar(j)]){
        size[findUpar(i)]+=size[findUpar(j)];
        parent[findUpar(j)]=findUpar(i);
        
    }else{
            size[findUpar(j)]+=size[findUpar(i)];
        parent[findUpar(i)]=findUpar(j);
    }
}

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(int i=0;i<edges.size();i++){
            int one=edges[i][0];
            int two=edges[i][1];
            if(dsu.findUpar(one)==dsu.findUpar(two)){
                return {one,two};
            }
            dsu.unionbysize(one,two);
        }
        vector<int>ans;
        return ans;
    }
};
