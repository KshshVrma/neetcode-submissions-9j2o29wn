class Solution {
public:
bool isPal(string s){
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
    bool validPalindrome(string s) {
        if(isPal(s))return true;
        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=0;j<s.size();j++){
                if(j!=i){
                    temp+=s[j];
                }
            }
            if(isPal(temp))return true;
        }


        return false;
    }
};