class Solution {
public:
    bool checkValidString(string s) {
return fun(s);
        
        int high=0;
        int low=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                high++;
                low++;
            }else if(s[i]==')'){
                low--;high--;
            }else{
                high++;
                low--;
            }

           if(high<0)return false;
           if(low<0)low=0;
        }
        return low==0;
    }

    bool fun(string s){
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        return f(s, 0, 0,dp);
    }

    bool f(string &s, int i, int count, vector<vector<int>>&dp){
        if(i==s.size()){
            return count==0;
        }
        if(count<0)return false;
        if(dp[i][count]!=-1){
            return dp[i][count];
        }
        if(s[i]!='*'){
              if(s[i]=='(')count++;
        else if(s[i]==')')count--; 

        return f(s,i+1, count,dp);
        }
       return f(s, i+1, count-1,dp) || f(s, i+1, count+1,dp)|| f(s, i+1, count,dp);
    
    }
};
