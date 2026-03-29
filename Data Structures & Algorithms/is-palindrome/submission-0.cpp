class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i]))t+=s[i];
        }
        cout<<t<<endl;
        for(int i=0;i<t.size();i++){
            if(t[i]>=97){
                t[i]-=32;
            }
        }
        
        int i=0;
        int j=t.size()-1;
        while(i<j){
            if(t[i]!=t[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
