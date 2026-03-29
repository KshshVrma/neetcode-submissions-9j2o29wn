class Solution {
public:
int fun(string s, int l, int r){
    int n=s.size();
    while(l>=0 && r<n && s[l]==s[r]){
        r++;
        l--;
    }
    return r-l-1;
}

    string longestPalindrome(string s) {
        string ans="";
        int start=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            int len1=fun(s,i,i);
            int len2=fun(s,i,i+1);
            int len=max(len1,len2);

            if(len>maxi){
                start=i-(len-1)/2;
                maxi=len;
            }
        }
        return s.substr(start,maxi);
    }
};
