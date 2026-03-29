class Solution {
public:
int binary_search(int i,int j, int target,vector<int>&nums){
    while(i<=j){
        int mid=(i+j)/2;
        if(nums[mid]==target){return mid;}
        else if(nums[mid]>target){
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int i=0;
        int r=nums.size()-1;
        int start=0;
        if(is_sorted(nums.begin(),nums.end())){
            return binary_search(0,nums.size()-1, target,nums);
        }
        while(i<=r){
            if(nums[i]<=nums[r]){
                start=i;
                break;
            }
            int mid=(i+r)/2;
            if(nums[mid]>=nums[i]){
                i=mid+1;

            }else{
                r=mid;
            }
        }
        int ind1=binary_search(0, start-1,target,nums);
        int ind2=binary_search(start,nums.size()-1,target,nums);
        if(ind1 ==-1 && ind2==-1)return -1;
        if(ind1>-1)return ind1;
        return ind2;
    }
};
