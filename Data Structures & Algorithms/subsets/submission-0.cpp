class Solution {
public:
void fun(vector<vector<int>>& vec, vector<int>&nums, int i, int n, vector<int>temp){
    if(i>n)vec.push_back(temp);
    if(i>n)return ;
    fun(vec,nums, i+1, n,temp);
    temp.push_back(nums[i]);
    fun(vec,nums,i+1,n, temp);
    return;
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
       fun(ans, nums, 0, nums.size()-1,{});
       return ans;
    }
};
