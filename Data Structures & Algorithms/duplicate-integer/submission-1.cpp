class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])!=0){
                return true;
            }
            mp.insert(nums[i]);
        }
        return false;
    }
};