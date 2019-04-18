//146. LRU Cache
//Least Recently Used cache
//Hard

//list::splice 拼接	
//void splice ( iterator position, list<T,Allocator>& x, iterator i );
//把i从x中移除，并且插入position位置

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {

	unordered_map<int, list<pair<int, int>>::iterator> hash;
	list<pair<int, int>> cache;
	int size;

public:
	LRUCache(int capacity) {
		size = capacity;
	}
	int get(int key) {
		auto it = hash.find(key);
		if (it == hash.end()) return -1;
		cache.splice(cache.begin(), cache, it->second);
		return cache.front().second;
//		return cache.begin()->second;
//		return it->second->second;
	}
	void put(int key, int value) {
		auto it = hash.find(key);
		if (it != hash.end()) {
			cache.splice(cache.begin(), cache, it->second);
			it->second->second = value;
		}
		else {
			if (cache.size() == size) {
				hash.erase(cache.back().first);
				cache.pop_back();
			}
			cache.push_front({ key,value });
			hash[key] = cache.begin();
		}
	}
};

#if 0
int main() {

	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // returns 1
	cache.put(3, 3);					// evicts key 2
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cache.put(4, 4);					// evicts key 1
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4

	system("pause");
	return 0;
}
#endif
