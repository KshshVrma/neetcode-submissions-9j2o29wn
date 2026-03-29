class Solution {
public:
vector<int> topo(vector<int>adj[], vector<bool>present){
    queue<int>q;
    vector<int>ans;
    vector<int>indegree(26,0);
    for(int i=0;i<26;i++){
        for(auto it:adj[i]){
            // cout<<char(i+'a')<<" "<<char(it+'a')<<endl;
            indegree[it]++;
        }
    }

   for(int i=0;i<26;i++)if(present[i] && indegree[i]==0)q.push(i);
    while(!q.empty()){

        int one=q.front();
        ans.push_back(one);
        q.pop();
        for(auto it:adj[one]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    return ans;
}
    string foreignDictionary(vector<string>& words) {
       
        vector<bool>present(26,0);
        for (auto &w : words) {
            for (char c : w) {
                present[c - 'a'] = true;
            }
        }

        if(words.size()==0)return "";
    
       int count2=0;
        vector<int>adj[26];
        for(int i=0;i<words.size()-1;i++){
            string one=words[i];
               int count=0;
            string two=words[i+1];

            if(one.size()!=two.size())count2++;
            int mini=min(one.size(),two.size());
            for(int j=0;j<mini;j++){
                if(one[j]!=two[j]){
                    count++;
                    adj[one[j]-'a'].push_back(two[j]-'a');
                  break;
                }
            }
            //to check if invalid
            if(count==0 && one.size()>two.size()){
                return "";
            }
            
        
        }

        // if(count==0 && count2!=0)return "";
        int start=words[0][0]-'a';
        
        vector<int> sot;

       sot= topo(adj,present);
       string ans="";
      
       for(int i=0;i<sot.size();i++){
        char c=sot[i]+'a';
       
        ans+=c;
       }
       int count3=0;
       for(int j=0;j<26;j++){
        if(present[j])count3++;
       }
       if(count3!=ans.size())return "";
       
    //    for(int i=0;i<26;i++){
    //     if(vis[i]==0)ans+=(i+'a');
    //    }
       return ans;
    }
};
