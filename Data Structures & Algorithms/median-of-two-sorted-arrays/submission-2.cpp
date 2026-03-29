class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>temp;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
if(nums1[i]<nums2[j]){
    temp.push_back(nums1[i]);
    i++;
}else{
    temp.push_back(nums2[j]);
    j++;
}
        }

        while(i<nums1.size()){
            temp.push_back(nums1[i]);
            i++;
        }
          while(j<nums2.size()){
            temp.push_back(nums2[j]);
            j++;
        }

        double ans;
        int k=temp.size();
        if(k%2){
            return temp[k/2];
        }else{
            int one=(k-1)/2;
            int two=k/2;
            ans= (temp[one]+ temp[two])/2;
        }
        return ans;
    }
};
