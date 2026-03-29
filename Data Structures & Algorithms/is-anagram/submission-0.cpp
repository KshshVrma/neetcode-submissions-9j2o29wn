class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>so(26,0);
        vector<int>to(26,0);
        for(int i=0;i<s.size();i++){
            so[s[i]-97]++;
        }
        for(int j=0;j<t.size();j++){
            to[t[j]-97]++;
        }
        for(int i=0;i<26;i++){
            if(so[i]!=to[i])return false;
        }
        return true;
    }
};
