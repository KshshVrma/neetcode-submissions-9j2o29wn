class Solution {
public:
void fun( vector<string>&ans,int n,string temp,int open, int close){
    if(temp.size()==n*2){
       
ans.push_back(temp);
        
        return ;
    }

if(open<n){
  
     fun(ans, n, temp+'(',open +1, close );

}
   
   
if(close<open){
        


      fun(ans,n,temp+')',open, close+1);
}}

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
   
      fun(  ans,n,"",0,0);
      return ans;
    }
};
