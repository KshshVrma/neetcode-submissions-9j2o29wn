class Solution {
public:
static bool cmp(pair<int,double>&a , pair<int,double>&b){
    return a.first>b.first;
}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>vec;

        for(int i=0;i<position.size();i++){
            double time=((double)(target-position[i])/(double)speed[i]);
            vec.push_back({position[i], time});
        }

        sort(vec.begin(), vec.end(), cmp);
double curr=0.0;
int count=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].second>curr){
                count++;
                curr=vec[i].second;
            }
        }
        return count;
    }
};
