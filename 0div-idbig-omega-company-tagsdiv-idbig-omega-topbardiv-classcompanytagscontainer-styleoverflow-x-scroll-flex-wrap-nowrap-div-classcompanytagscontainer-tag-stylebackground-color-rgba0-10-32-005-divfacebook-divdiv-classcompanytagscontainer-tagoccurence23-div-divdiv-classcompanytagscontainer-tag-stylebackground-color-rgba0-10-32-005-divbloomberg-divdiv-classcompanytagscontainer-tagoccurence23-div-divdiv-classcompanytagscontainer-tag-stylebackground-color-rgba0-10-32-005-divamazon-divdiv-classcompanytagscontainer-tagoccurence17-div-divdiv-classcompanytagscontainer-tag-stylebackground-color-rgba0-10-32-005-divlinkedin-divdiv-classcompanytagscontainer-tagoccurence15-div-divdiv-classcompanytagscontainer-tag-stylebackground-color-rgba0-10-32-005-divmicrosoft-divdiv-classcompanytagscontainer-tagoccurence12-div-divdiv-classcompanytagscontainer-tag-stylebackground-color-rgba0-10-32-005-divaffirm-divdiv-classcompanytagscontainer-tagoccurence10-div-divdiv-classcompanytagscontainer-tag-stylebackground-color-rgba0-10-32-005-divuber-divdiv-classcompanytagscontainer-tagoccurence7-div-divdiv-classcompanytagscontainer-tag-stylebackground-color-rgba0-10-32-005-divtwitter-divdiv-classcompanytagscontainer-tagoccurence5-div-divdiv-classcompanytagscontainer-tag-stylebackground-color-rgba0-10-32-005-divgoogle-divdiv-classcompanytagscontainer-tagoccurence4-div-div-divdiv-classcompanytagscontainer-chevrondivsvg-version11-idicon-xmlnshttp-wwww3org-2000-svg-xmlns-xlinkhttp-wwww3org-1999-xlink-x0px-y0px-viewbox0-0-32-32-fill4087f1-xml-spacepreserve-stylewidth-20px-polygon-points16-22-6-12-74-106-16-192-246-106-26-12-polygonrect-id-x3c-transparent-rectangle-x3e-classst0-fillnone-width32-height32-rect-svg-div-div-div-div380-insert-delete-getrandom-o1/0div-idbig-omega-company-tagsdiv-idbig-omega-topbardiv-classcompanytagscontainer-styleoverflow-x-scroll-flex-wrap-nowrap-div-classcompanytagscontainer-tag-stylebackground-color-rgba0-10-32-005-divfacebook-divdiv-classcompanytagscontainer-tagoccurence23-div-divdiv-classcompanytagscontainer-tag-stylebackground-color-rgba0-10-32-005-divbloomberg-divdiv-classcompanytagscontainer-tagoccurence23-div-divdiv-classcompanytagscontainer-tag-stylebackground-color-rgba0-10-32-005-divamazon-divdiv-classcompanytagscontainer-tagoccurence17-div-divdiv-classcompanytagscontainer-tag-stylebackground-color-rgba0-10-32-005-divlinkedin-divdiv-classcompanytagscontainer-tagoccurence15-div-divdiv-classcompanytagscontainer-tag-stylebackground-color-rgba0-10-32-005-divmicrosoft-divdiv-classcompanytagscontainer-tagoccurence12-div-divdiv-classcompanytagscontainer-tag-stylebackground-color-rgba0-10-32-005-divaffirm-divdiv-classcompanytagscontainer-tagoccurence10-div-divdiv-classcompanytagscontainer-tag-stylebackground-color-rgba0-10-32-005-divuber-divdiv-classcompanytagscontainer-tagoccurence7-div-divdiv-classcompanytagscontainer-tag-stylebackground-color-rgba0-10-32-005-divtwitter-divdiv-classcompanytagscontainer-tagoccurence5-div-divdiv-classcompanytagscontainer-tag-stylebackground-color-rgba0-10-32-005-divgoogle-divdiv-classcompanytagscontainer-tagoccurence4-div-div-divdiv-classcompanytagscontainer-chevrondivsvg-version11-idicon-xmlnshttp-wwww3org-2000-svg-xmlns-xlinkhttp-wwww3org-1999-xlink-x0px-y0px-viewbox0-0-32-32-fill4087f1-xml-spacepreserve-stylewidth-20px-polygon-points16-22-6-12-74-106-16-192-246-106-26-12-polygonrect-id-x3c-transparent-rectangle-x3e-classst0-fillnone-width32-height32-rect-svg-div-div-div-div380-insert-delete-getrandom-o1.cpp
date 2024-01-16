class RandomizedSet {
public:
    vector<int>a;
    unordered_map<int, int> mp;
    RandomizedSet(){ }
    bool insert(int val){
        if(mp.find(val)==mp.end()){
            a.push_back(val);
            mp[val]=a.size()-1;
            return 1;
        }
        return 0;
    }
    bool remove(int val){
        if(mp.find(val)!=mp.end()){
            a[mp.find(val)->second]=a.back();
            a.pop_back();
            mp[a[mp.find(val)->second]]=mp.find(val)->second;
            mp.erase(val);
            return 1;
        }
        return 0;
    }
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */