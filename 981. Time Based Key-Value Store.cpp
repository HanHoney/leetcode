//981. Time Based Key-Value Store
//Medium

#include <unordered_map>
#include <map>
using namespace std;

class TimeMap {
	//map<key,value> �ڲ�����key���򣬲����ö��ַ���
	//upper_bound �� �Ҵ��ڸ���Ԫ�ص�key��Ӧ��iterator
	//prevȡԪ�ص�ǰһ��

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