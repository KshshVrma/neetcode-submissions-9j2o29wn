class Solution {
public:
int count(int it){
    int i=0;
    int temp=0;
    while(i<32){
        if(1<<i & it){
            temp++;
        }
        i++;

    }
    return temp;
}
    vector<int> countBits(int n) {
        vector<int>temp;
        for(int i=0;i<=n;i++){
temp.push_back(count(i));
        }
        return temp;
    }
};
