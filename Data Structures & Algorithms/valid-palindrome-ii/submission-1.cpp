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

bool isPal(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
    bool validPalindrome(string s) {
        // if(isPal(s))return true;
        // for(int i=0;i<s.size();i++){
        //     string temp="";
        //     for(int j=0;j<s.size();j++){
        //         if(j!=i){
        //             temp+=s[j];
        //         }
        //     }
        //     if(isPal(temp))return true;
        // }

int i=0;int j=s.size()-1;
if(isPal(s))return true;

while(i<j){
    if(s[i]!=s[j]){
        if(isPal(s, i,j-1) || isPal(s, i+1, j))return true;
        return false;
    }
    i++;
    j--;
}

        return false;
    }
};