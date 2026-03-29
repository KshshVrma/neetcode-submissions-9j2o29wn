class Solution {
public:
int check(vector<int>&one, vector<int>&two){

    for(int i=0;i<26;i++){
        if(two[i]!=one[i]){
            return 0;
        }
    }
    return 1;
}
    bool checkInclusion(string s1, string s2) {
       vector<int>one(26,0);
       vector<int>two(26,0);
       if(s2.size()<s1.size())return false;
       for(int i=0;i<s1.size();i++)one[s1[i]-'a']++;
       int i=0;
       while(i<s1.size()){
        two[s2[i]-'a']++;
        i++;
       }
       int j=0;
       if(check(one,two)){
    return true;
       }
       while(i<s2.size()){
        two[s2[i]-'a']++;
        two[s2[j]-'a']--;
        i++;
        j++;
        if(check(one,two))return true;
       }
       return false;

    }
};
