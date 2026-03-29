class Solution {
public:
    int jump(vector<int>& nums) {
        int ans;
        int currmax=0;
        int jumps=0;
        int currend=0;
        for(int i=0;i<nums.size()-1;i++){
          
                currmax=max(currmax,i+nums[i]);

                if(i==currend){
                    jumps++;
                    currend=currmax;
                }

        }
        return jumps;
    }
};
