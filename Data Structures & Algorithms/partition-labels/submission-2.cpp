class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>>mp;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]].second=i;
            }else{
                mp[s[i]]={i,i};
            }
        }
int curr=0;

        for(int i=0;i<s.size();i++){
        
            string k=s.substr(curr, i-curr+1);
            cout<<k<<endl;
int flag=0;
            for(int j=0;j<k.size();j++){
                char c=k[j];
                pair<int,int>temp=mp[c];
                cout<<temp.first<<" "<<temp.second<<endl;
                if(temp.second>i){
                    flag=1;
                    break;
                }

            }
            if(flag==0){
                ans.push_back(i-curr+1);
                curr=i+1;
            }
        }


        return ans;
    }
};
