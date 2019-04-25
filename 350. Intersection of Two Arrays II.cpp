//350. Intersection of Two Arrays II
//Easy


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

	//hashtable 
	//TC:O(m+n)	SC:O(min(m,n))

	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> umap;
		if (nums1.size() > nums2.size()) {
			return intersect(nums2, nums1);
		}
		for (int num : nums1) {
			++umap[num];
		}
		vector<int> ret;
		for (int num : nums2) {
			if (umap[num] > 0) {
				ret.emplace_back(num);
				--umap[num];
			}
		}
		return ret;
	}
	
	//sort‘§¥¶¿Ì
	//TC:O(nlogn)	SC:O(1) 

	vector<int> intersect_1(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		int p=0,q=0;
		vector<int> ret;
		while(p<nums1.size()&&q<nums2.size()){
			if(nums1[p]==nums2[q]){
				ret.emplace_back(nums1[p]);
				++p;
				++q;
			}
			else if(nums1[p]<nums2[q]){
				++p;
			}
			else{
				++q;
			}
		}
		return ret;
	}
	

};