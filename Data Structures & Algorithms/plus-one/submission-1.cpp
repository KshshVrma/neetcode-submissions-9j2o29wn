class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count=0;
        vector<int>ans;
        int carry=1;
        int newdig=0;
      for(int i=digits.size()-1;i>=0;i--){
        if(carry==1){
            if(digits[i]!=9){
                carry=0;
            }
            digits[i]=(digits[i]+1)%10;
        }
        if(i==0 && carry==1){
            newdig=1;
        }
      }
      if(newdig){
        digits.insert(digits.begin(),1);
      }
      return digits;
    }
};
