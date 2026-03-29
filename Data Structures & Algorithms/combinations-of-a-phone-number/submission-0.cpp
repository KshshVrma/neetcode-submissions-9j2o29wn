class Solution {
public:
void fun(string digits, int i, vector<string> &ans, unordered_map<char, vector<char>>&mp, string temp){
if(i==digits.size()){
ans.push_back(temp);
return ;
}
char c=digits[i];
for(int j=0;j<mp[c].size();j++){
    char t=mp[c][j];
    temp+=t;
    fun(digits, i+1, ans, mp, temp);
    temp.pop_back();
  
}

}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string>ans;
        unordered_map<char, vector<char>>mp;
        mp['2']={'a', 'b','c'};
        mp['3']={'d', 'e','f'};
        mp['4']={'g', 'h','i'};
        mp['5']={'j', 'k','l'};
        mp['6']={'m', 'n','o'};
        mp['7']={'p', 'q','r','s'};
        mp['8']={'t', 'u','v'};
        mp['9']={'w', 'x','y','z'};

        fun(digits, 0, ans, mp,"");
        return ans;

    }
};
