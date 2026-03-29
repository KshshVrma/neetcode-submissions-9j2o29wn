class LRUCache {
public:
list<int>lst;
unordered_map<int, pair<list<int>::iterator, int>> mp;
int n;
    LRUCache(int capacity) {
        n=capacity;
    }

    void recent(int key, int val){
        if(mp.find(key)!=mp.end()){
        lst.erase(mp[key].first);
        lst.push_front(key);
        mp[key]={lst.begin(), val};
        }else{
            lst.push_front(key);
            mp[key]={lst.begin(), val};
        }
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
int val=mp[key].second;
recent(key, val);
return val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int val) {
        if(mp.find(key)!=mp.end()){
recent(key,val);
        }else{
n--;
    recent(key,val);}

if(n<0){
    auto it=lst.back();
    mp.erase(it);
    lst.pop_back();
    n++;
}
        }
    
};
