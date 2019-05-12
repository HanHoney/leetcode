//981. Time Based Key-Value Store
//Medium

#include <unordered_map>
#include <map>
using namespace std;

class TimeMap {
	//map<key,value> 内部按照key排序，查找用二分法。
	//upper_bound 是 找大于给定元素的key对应的iterator
	//prev取元素的前一项

	unordered_map<string, map<int, string>> timeMap;
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		timeMap[key].insert({ timestamp,value });
	}

	string get(string key, int timestamp) {
		auto it = timeMap[key].upper_bound(timestamp);
		return it == timeMap[key].begin() ? "" : prev(it)->second;
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */