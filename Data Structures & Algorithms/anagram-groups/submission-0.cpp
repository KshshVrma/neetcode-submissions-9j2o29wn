class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int>mp;
        int curr=0;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)==mp.end()){
                mp[temp]=curr;
                vector<string>one;
                one.push_back(strs[i]);
                ans.push_back(one);
                curr++;
            }else{
                int ind=mp[temp];
                ans[ind].push_back(strs[i]);

            }
        }
        return ans;


    }
};
