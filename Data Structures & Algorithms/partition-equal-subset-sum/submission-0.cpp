class Solution {
public:
bool fun(vector<int>&nums, int i,int sum,int total){
    if(i==nums.size()-1){
        if(sum==(total/2)){
            return true;
        }
        return false;
    }
    bool take=fun(nums,i+1,sum+nums[i], total);
    bool ntake=fun(nums,i+1,sum,total);
    return take||ntake;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1)return false;

        return fun(nums,0,0,sum);
    }
};
