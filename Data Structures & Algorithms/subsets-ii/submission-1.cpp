class Solution {
public:
 void fun(set<vector<int>>&st, vector<int>&nums, vector<int>&temp, int i){
    if(i==nums.size()){
        vector<int>tt=temp;
        sort(tt.begin(),tt.end());
        st.insert(tt);
        return ;
    }
    temp.push_back(nums[i]);
    fun(st,nums, temp, i+1);
    temp.pop_back();
    fun(st,nums, temp, i+1);
 }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        fun(st, nums, temp, 0);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
