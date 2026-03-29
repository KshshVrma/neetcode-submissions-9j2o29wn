class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool>temp(nums.size()+1,false);
        for(int i=0;i<nums.size();i++){
        temp[nums[i]]=true;
        }
        for(int i=0;i<=nums.size();i++){
        if(temp[i]==false)return i;
        }
        return 0;
    }
};
