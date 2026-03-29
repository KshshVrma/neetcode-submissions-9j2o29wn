class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string one=words[i];
            string two=words[i+1];
            
            for(int j=0;j<one.size();j++){
                if(j>=two.size()){
                    return false;
                }
                if(one[j]!=two[j]){
                    if(mp[one[j]]>mp[two[j]]){
                        cout<<one[j]<<two[j]<<" "<<mp[one[j]]<<" "<<mp[two[j]]<<endl;
                        return false;
                    }else{
                       break;
                    }
                }
            }
            
        }
        
        return true;
    }
};