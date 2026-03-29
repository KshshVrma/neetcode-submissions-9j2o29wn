class Solution {
public:
    bool checkValidString(string s) {
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
};
