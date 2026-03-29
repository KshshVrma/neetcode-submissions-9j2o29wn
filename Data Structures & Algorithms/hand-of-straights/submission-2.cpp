class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_set<int> st(hand.begin(), hand.end());

if(hand.size()%groupSize!=0)return false;

map<int,int> mp;
for(int i=0;i<hand.size();i++){
    mp[hand[i]]++;
}

while(mp.size()!=0){
auto it=mp.begin();
int curr=it->first;
mp[curr]--;
int val=it->second;
if(val==0){
    mp.erase(curr);
}
int count=1;
for(int j=1;j<groupSize;j++){
    if(mp.find(curr+j)!=mp.end()){
    mp[curr+j]--;
    if(mp[curr+j]==0){
        mp.erase(curr+j);
    }
    count++;
    }else{
        return false;
    }
    }
    if(count!=groupSize)return false;
}

return true;

    }
};
