class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string one=q.front().first;
            cout<<one<<endl;
            int two=q.front().second;
            if(st.find(one)!=st.end() && endWord==one){
                return two;
            }
            q.pop();
            for(int i=0;i<one.size();i++){
                string temp=one;
                for(int j=0;j<26;j++){
                    temp[i]='a'+j;
                    if(st.find(temp)!=st.end()){
                        if(endWord==temp)return two+1;
                        st.erase(temp);
                        q.push({temp,two+1});
                    }
                }
            }

        }

        return 0;
    }
};
