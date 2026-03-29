class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>vec(n+1, 0);
        vector<int>tec(n+1,0);
        for(int i=0;i<trust.size();i++){
            vec[trust[i][0]]++;
            tec[trust[i][1]]++;
        }
        int it=0;
        int count=0;
        int count2=0;
        for(int i=1;i<vec.size();i++){
            if(vec[i]==0){
                it=i;
                count++;
            }
            if(tec[i]!=0){
                count2++;
            }

        }
        if(count!=1 || it==0 || count2!=1)
        return -1;
        return it;
    }
};