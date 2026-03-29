class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int i=0,j=0;
        unordered_map<char,int>mp;
        while(j<s.size()){

char c=s[j];

auto it=mp.find(c);
if(it==mp.end()){
mp[c]=j;

}else{
    i=max(mp[c]+1,i);
mp[c]=j;
    
}
cout<<c<<" "<<j-i+1<<" "<<i<<"-"<<j<<endl;
maxi=max(maxi, j-i+1);
j++;

        }

        return maxi;
    }
};
