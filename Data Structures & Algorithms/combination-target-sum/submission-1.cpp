class Solution {
public:
void fun(vector<vector<int>>&ans, vector<int>nums, int target, int i, int sum, vector<int>&temp){
    if(sum>target)return ;
    if(i==nums.size()){
        if(sum==target)ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    fun(ans, nums, target, i, sum+nums[i], temp);
    temp.pop_back();
    fun(ans, nums, target, i+1, sum, temp);
    
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        fun(ans, nums,target,0,0,temp);
        return ans;

    }
};
