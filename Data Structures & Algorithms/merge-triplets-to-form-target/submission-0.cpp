class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>temp(3,0);

        for(int i=0;i<triplets.size();i++){
if(target[0]==triplets[i][0]){
    if(triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
        temp[0]=1;
    }
}
        }
          for(int i=0;i<triplets.size();i++){
            if(target[1]==triplets[i][1]){
    if(triplets[i][0]<=target[0] && triplets[i][2]<=target[2]){
        temp[1]=1;
    }
        }}
          for(int i=0;i<triplets.size();i++){
            if(target[2]==triplets[i][2]){
    if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1]){
        temp[2]=1;
    }
        }}
        for(int i=0;i<3;i++){
            if(temp[i]==0){
                return false;
            }
        }
        return true;

    
    }
};
