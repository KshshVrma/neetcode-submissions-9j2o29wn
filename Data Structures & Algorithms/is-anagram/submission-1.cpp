class Solution {
public:
    bool isAnagram(string s, string t) {
 vector<int>so(26,0);
 vector<int>to(26,0);
 for(int i=0;i<s.size();i++){so[s[i]-'a']++;
    }

    for(int i=0;i<t.size();i++){
        to[t[i]-'a']++;
    }
    int count=0;

    for(int i=0;i<26;i++){
        if(so[i]!=to[i])count++;
    }

    return count==0;
    }

};
