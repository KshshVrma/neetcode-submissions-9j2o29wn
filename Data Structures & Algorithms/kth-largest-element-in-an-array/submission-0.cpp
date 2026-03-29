class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans=INT_MIN;
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }

        while(k--){
            ans=q.top();
            q.pop();
        }
        return ans;
    }
};
