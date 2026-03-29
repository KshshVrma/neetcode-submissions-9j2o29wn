class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mp(256,0);
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int si=-1;
        int mini=INT_MAX;
        int l=0,r=0;
int count=0;
        while(r<s.size()){
            
            if(mp[s[r]]>0){
              
                count++;
            }
              mp[s[r]]--;
            while(l<s.size() && count==t.size()){
               if(mini>r-l+1){
                si=l;
                mini=r-l+1;
               }
                
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count--;
                    
                }
                l++;
            }
            r++;
        }
        if(si==-1)return "";
        return s.substr(si, mini);
    }
};
