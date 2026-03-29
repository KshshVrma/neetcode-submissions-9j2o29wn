class Solution {
public:
    int reverse(int x) {
        int neg=0;
        if(x<0){neg=1;

        }
        string t=to_string(x);
      std::reverse(t.begin(),t.end());
        long temp=stol(t);
        if(temp>=INT_MAX){
            return 0;
        }
        return (neg==1)?-1*(stoi(t)):stoi(t);
    }
};
