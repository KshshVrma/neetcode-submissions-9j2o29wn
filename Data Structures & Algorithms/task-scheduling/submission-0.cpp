class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int>q;
        vector<int>vec(26,0);
        for(int i=0;i<tasks.size();i++){
            vec[tasks[i]-'A']++;
        }

        for(int i=0;i<26;i++){
            if(vec[i]>0)
            q.push(vec[i]);
        }

        int count=0;
        while(!q.empty()){
            vector<int>temp;

            for(int i=0;i<n+1;i++){
                if(!q.empty()){
                int fr=q.top();
                q.pop();
                fr--;
                temp.push_back(fr);
                }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i]>0)
                    q.push(temp[i]);
            }

            if(q.empty()){
                count+=temp.size();
            }else{
                count+=n+1;
            }
        }
        return count;
    }
};
