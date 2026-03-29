class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>ans(temperatures.size(),0);

        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i]>st.top().first){
                pair<int,int>pt=st.top();
                st.pop();
                int ind=pt.second;
                ans[ind]=(i-ind);
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
