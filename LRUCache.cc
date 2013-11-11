class LRUCache{
public:
    LRUCache(int capacity) {
        _cache_map.clear();
        _cache_list.clear();
        _max_size = capacity;
    }
    
    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator >::iterator p = _cache_map.find(key);
        if (p != _cache_map.end()) {
            //_cache_list.erase(p->second);
            //_cache_list.push_front(pair<int, int>(key, ret));
            _cache_list.splice(_cache_list.begin(), _cache_list, p->second);
            p->second = _cache_list.begin();
            return (p->second)->second;
        }
        return -1;
    }
    
    void set(int key, int value) {
        unordered_map<int, list<pair<int, int> >::iterator >::iterator p = _cache_map.find(key);
        if (p != _cache_map.end()) {
            //_cache_list.erase(p->second);
            //_cache_list.push_front(pair<int, int>(key, value));
            ((p->second))->second = value;
            _cache_list.splice(_cache_list.begin(), _cache_list, p->second);
            p->second = _cache_list.begin();
        } else {
            if (_cache_map.size() >= _max_size) {
                _cache_map.erase(_cache_list.rbegin()->first);
                _cache_list.pop_back();
            }
            _cache_list.push_front(pair<int, int>(key, value));
            _cache_map[key] = _cache_list.begin();
        }
    }
private:
    unordered_map<int, list<pair<int, int> >::iterator > _cache_map; //key, _cache_list iterator
    list<pair<int, int> > _cache_list; // KV pair container
    int _max_size;
};
