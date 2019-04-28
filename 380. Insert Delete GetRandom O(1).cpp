//380. Insert Delete GetRandom O(1)
//Medium
//hashtable + vector

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class RandomizedSet {

	vector<int> nums;
	unordered_map<int, int> hash;

public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (hash.find(val) != hash.end()) 
			return false;
		nums.emplace_back(val);
		hash[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (hash.find(val) == hash.end()) 
			return false;
		int loc = hash[val];      //在vector中删除，先将val和back()交换再删除back()，O(1)。
		if (loc != nums.size() - 1) {
			nums[loc] = nums.back();
			hash[nums.back()] = loc;
		}
		hash.erase(val);
		nums.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */