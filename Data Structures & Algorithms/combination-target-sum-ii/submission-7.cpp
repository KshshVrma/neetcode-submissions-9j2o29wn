class Solution {
public:

void fun(set<vector<int>>&ans, vector<int>nums, int target, int i, int sum, vector<int>temp){
    if(i==nums.size()){
        if(sum==target){
            sort(temp.begin(),temp.end());
     
            ans.insert(temp);
            }
        return;
    }
    temp.push_back(nums[i]);
    fun(ans, nums, target, i+1, sum+nums[i], temp);
     
    temp.pop_back();
     fun(ans, nums, target, i+1, sum, temp);
    
    
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
     
          set<vector<int>>ans;
        vector<int>temp;
        fun(ans, nums,target,0,0,temp);
        vector<vector<int>>ande(ans.begin(),ans.end());
        return ande;
    }
};
