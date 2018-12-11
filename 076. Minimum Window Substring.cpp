//76. Minimum Window Substring
//Hard
//��˫ָ��	TC:O(|S|+|T|)	SC:O(|S|+|T|)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		string ret;
		if (s.size() == 0 || t.size() == 0 || t.size() > s.size()) return ret;
		unordered_map<char, int> mp;
		for (int i = 0; i < t.size(); i++) {   //����ֱ��������ʼ��
			mp[t[i]]++;
		}
		unordered_map<char, int> tmp;   //������¼�Ѿ��ҵ����ַ�������
		for (auto it:mp) {      
			tmp.insert({ it.first,0 }); //��ʼ��
		}
		int count = t.size();           //��ҪѰ�ҵ��ַ���
		int minStart = 0;
		int minWin = INT_MAX;
		int left = 0, right = 0;
		while (right < s.size()) {
			if (mp.find(s[right]) != mp.end()) {      //�ַ���T�д���
				if (tmp[s[right]] < mp[s[right]]) {   //����Ч����չ
					count--;
				}
				tmp[s[right]]++;
			}
			while (count == 0) {   //����ʱ�Ѿ�����T�����е��ַ�����¼�������Խ�left����
				if (right - left + 1 < minWin) {
					minWin = right - left + 1;
					minStart = left;
					if (minWin == t.size()) {
						ret = s.substr(minStart, minWin);
						return ret;
					}
				}
				//��left����
				if (mp.find(s[left]) != mp.end()) {
					if (tmp[s[left]] <= mp[s[left]]) {  //������һ��s[left]Ӱ��������count++������ѭ��
						count++;
					}
					tmp[s[left]]--;
				}
				left++;
			}
			right++;
		}
		if (minWin != INT_MAX) {
			ret = s.substr(minStart, minWin);
		}
		return ret;				//û��ƥ��Ĵ���,Ҳ����""
	}
};
//
//int main() {
//	Solution s;
//	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
//	system("pause");
//	return 0;
//}