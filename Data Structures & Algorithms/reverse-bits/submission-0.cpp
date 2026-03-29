class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i=32;
       
        uint32_t temp=0;
        while(i>0){
             uint32_t t=n;
             int ind=32-i;
             if(t &(1<<ind)){
                temp|= 1<<(i-1);
             }
           
            i--;
        }
        return temp;
    }
};
