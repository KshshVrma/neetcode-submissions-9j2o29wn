class MedianFinder {
public:

vector<int>vec;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        vec.push_back(num);
        sort(vec.begin(),vec.end());
    }
    
    double findMedian() {
        if(vec.size()%2){
            return double(vec[vec.size()/2]);
        }else{
            double one=vec[vec.size()/2];
            double two=vec[(vec.size()/2)-1];
            return (one+two)/2;
        }
        
    }
};
