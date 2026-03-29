class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        set<int>st;
        for(int i=0;i<nums.size();i++){
st.insert(nums[i]);
        }
        int maxi=1;
        int curr=1;
        int count=0;
        int prev=*st.begin();
        for(auto it=++st.begin(); it!=st.end();it++){
           
                if(*it==prev+1){
                    curr++;
                    if(curr>maxi)maxi=curr;
                }else{
                    curr=1;
                }
            
            prev=*it;
           
        }
        return maxi;
      
    }
};
