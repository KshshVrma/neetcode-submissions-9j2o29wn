class Solution {
public:
bool ispal(string temp){
    if(temp.size()==1)return true;
    int i=0;
    int j=temp.size()-1;
    while(i<j){
        if(temp[i]!=temp[j])return false;
    i++;
    j--;
    }
    return true;
}

int fun(string s, int i, string temp){
   int count = 0;
int n = s.size();

// Odd-length palindromes
for(int center = 0; center < n; center++){
    int left = center;
    int right = center;
    while(left >= 0 && right < n && s[left] == s[right]){
        count++;
        left--;
        right++;
    }
}

// Even-length palindromes
for(int center = 0; center < n-1; center++){
    int left = center;
    int right = center + 1;
    while(left >= 0 && right < n && s[left] == s[right]){
        count++;
        left--;
        right++;
    }
}
    return count;
}
    int countSubstrings(string s) {
        return fun(s, 0,"");
    }
};
