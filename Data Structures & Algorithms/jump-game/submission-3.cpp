class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currMax=0;
        if(nums.size()==0)return true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && i!=nums.size()-1){
                if(currMax<=i){
return false;
                }
            }
            currMax=max(currMax,i+nums[i]);
        }
        if(currMax>=nums.size()-1)return true;

        return false;
        
    }
};
