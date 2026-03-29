class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        for(int i=0;i<points.size();i++){
            int sum= points[i][0]*points[i][0]+ points[i][1]*points[i][1];
            q.push({sum, i});

        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            int one= q.top().second;
            q.pop();
            ans.push_back({points[one][0], points[one][1]});
        }

        return ans;
    }
};
