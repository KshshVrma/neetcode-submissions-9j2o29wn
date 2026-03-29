class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int n=nums.size()-1;
        while(i<=n){
            int mid=(i+n)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                i=mid+1;
            }else{
                n=mid-1;
            }
        }
        return -1;
    }
};
