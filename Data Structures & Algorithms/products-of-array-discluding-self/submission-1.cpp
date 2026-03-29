class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
long long int prod=1;
int count=0;
for(int i=0;i<nums.size();i++){
if(nums[i]==0)count++;
else{
    prod*=nums[i];
}
}
vector<int>ans(nums.size(),0);
if(count>1){
return ans;
}

for(int i=0;i<nums.size();i++){
    if(nums[i]==0)ans[i]=(prod);
    else{
        if(count==0)
        ans[i]=(prod/nums[i]);
        else ans[i]=0;
    }
}
return ans;
    }
};
