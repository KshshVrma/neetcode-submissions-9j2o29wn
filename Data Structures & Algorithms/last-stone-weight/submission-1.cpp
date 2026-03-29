class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i=0;i<stones.size();i++)q.push(stones[i]);
        while(q.size()>1){
            int first=q.top();
            q.pop();
            int second=q.top();
            q.pop();
            q.push(abs(first-second));
        }
        return q.top();
    }
};
