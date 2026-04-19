class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=nums.size();
        int unique=0;
        for(int i=0;i<nums.size();i++){
            if(upper_bound(nums.begin(),nums.end(),nums[i])>lower_bound(nums.begin(),nums.end(), nums[i])+1){
                nums.erase(nums.begin()+i);
                i--;
            }else{
                unique++;
            }
        }
        return unique;
    }
};