class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<nums.size();i++){
mp[nums[i]]++;
        }
        for(auto it:mp){
            q.push({it.second,it.first});
        }
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
