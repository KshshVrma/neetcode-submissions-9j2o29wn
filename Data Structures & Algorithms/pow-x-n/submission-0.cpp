class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int neg=0;
        if(n<0){
neg=1;
n=abs(n);
        }
        while(n--){
            ans*=x;

        }
        if(neg)return 1/ans;
        return ans;
    }
};
