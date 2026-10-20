class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheNodes.contains(key)) {
            cache.splice(cache.begin(), cache, cacheNodes[key]);
            return cacheNodes[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if (cacheNodes.contains(key)){
            cacheNodes[key]->second = value;
            cache.splice(cache.begin(), cache, cacheNodes[key]);
            return;
        }

        if (cache.size() == capacity) {
            cacheNodes.erase(cache.back().first);
            cache.pop_back();
        }
        
        cache.push_front({key, value});
        cacheNodes[key] = cache.begin();
    }

private:
    int capacity = 0;
    unordered_map<int, list<pair<int, int>>::iterator> cacheNodes;
    list<pair<int, int>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
