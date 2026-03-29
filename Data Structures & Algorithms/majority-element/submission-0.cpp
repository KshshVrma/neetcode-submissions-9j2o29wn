class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currMaxi=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==currMaxi){
                count++;
            }else{
                if(count==0){
                    currMaxi=nums[i];
                    count=1;
                }else{
                    count--;
                }
            }
        }
        return currMaxi;
    }
};