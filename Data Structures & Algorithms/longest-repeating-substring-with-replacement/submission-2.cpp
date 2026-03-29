class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int i=0;
        int j=0;
        int maxi=0;
        int maxcount=0;
        while(i<s.size()){
            freq[s[i]-'A']++;
              int tempmax=0;
                for(int i=0;i<26;i++){
                    tempmax=max(tempmax,freq[i]);
                }
                maxcount=tempmax;
            int window_size=i-j+1;

            while( window_size-maxcount>k){
                freq[s[j]-'A']--;
             tempmax=0;
                for(int i=0;i<26;i++){
                    tempmax=max(tempmax,freq[i]);
                }
                maxcount=tempmax;
                j++;
                window_size=i-j+1;

            }
            window_size=i-j+1;
            maxi=max(maxi,window_size=i-j+1 );


            i++;
        }
        return maxi;
    }
};
