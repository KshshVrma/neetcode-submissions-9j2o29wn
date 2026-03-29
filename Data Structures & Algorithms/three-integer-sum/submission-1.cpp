class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        // vector<vector<int>>ans;

        for(int i=0;i<nums.size()-2;i++){
            int sum1=nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum2=nums[j]+nums[k];
                int temp2=nums[j];
                int temp3=nums[k];
                if(sum2==(-1*sum1)){
                   st.insert({nums[i], nums[j], nums[k]});
                    
                    while(nums[j]==temp2 && j<k)j++;
                    while(nums[k]==temp3 && j<k)k--;

                }
                else if(sum2>(-1*sum1)){
k--;
                }else{
                    j++;
                }
            }

        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};
