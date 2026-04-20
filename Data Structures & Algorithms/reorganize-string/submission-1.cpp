class Solution {
public:
bool fined(string s){
    bool temp=true;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            return false;
        }
    }
    return temp;
}
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>q;
        // priority_queue<char, vector<char>, greater<char>>p;
        // string temp1="",temp2="";
        // for(int i=0;i<s.size();i++){
        //     q.push(s[i]);
        //     p.push(s[i]);
        // }
        // while(temp1.size()!=s.size()&& temp2.size()!=s.size() && q.size()!=0 && p.size()!=0){
        //     char c1=q.top();
        //     char c2=p.top();
        //     q.pop();
        //     p.pop();

        //     temp1+=c1;
        //     temp2+=c2;
        //     if(temp1.size()!=s.size()&& temp2.size()!=s.size()){
        //         temp1+=c2;
        //         temp2+=c1;
        //     }
        // }

        // if(fined(temp1) ){
        //     return temp1;
        // }
        // if(fined(temp2)){
        //     return temp2;
        // }
        // return "";

        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            q.push({it.second, it.first});
            
        }
        string temp="";
        while(temp.size()!=s.size() && q.size()!=0){
            char c1=q.top().second,  c2='_';
            int one=q.top().first;
           
            q.pop();
            if(q.size()!=0){
                c2=q.top().second;
                int two=q.top().first;
                
                q.pop();
                if(two>1)
                q.push({two-1,c2});

            }
             if(c2!='_'){
                if(temp[temp.size()-1]!=c1){
                    temp+=c1;
                    temp+=c2;
                }else{
  temp+=c2;
                    temp+=c1;
                }
             }else{
                temp+=c1;
             }
             if(one>1)
            q.push({one-1,c1});
        }
        if(fined(temp)){
            return temp;
        }
        return "";

    }
};