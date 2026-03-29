class Solution {
public:
bool ispal(string s){
    int i=0;int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }return true;
}
void fun(vector<vector<string>>&ans, vector<string>&temp, string &s, int ind){
  
   if(ind==s.size()){
        ans.push_back(temp);return;
    }

    for(int i=ind;i<s.size();i++){
        if(ispal(s.substr(ind, i-ind+1))){
        temp.push_back(s.substr(ind, i-ind+1));
        fun(ans, temp, s,i+1);
temp.pop_back();}

    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        fun(ans, temp, s, 0);
        return ans;
    }
};
