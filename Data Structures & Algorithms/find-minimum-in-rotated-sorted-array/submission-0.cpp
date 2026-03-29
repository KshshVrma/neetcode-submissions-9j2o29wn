class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int i=0;
        int r=nums.size()-1;
        while(i<=r){

            if(nums[i]<=nums[r])return nums[i];
            int mid=(i+r)/2;
            if(nums[mid]>=nums[i]){
                i=mid+1;
            }else{
                r=mid;
            }

        }
        return -1;

    }
};
