class Solution {
public:
int  sumofsq(int n){
    int temp=0;
    while(n>0){
        temp+=(n%10)*(n%10);
        n/=10;
    }
    return temp;
}
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        int k=n;
        while(k!=1){
           
            if(mp.find(k)==mp.end()){
mp[k]=1;
 k=sumofsq(k);
            }
            else{
                return false;
            }
        }

       return true;

    }
};
