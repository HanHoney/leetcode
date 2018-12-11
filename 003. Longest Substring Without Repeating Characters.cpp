//3. Longest Substring Without Repeating Characters

#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {      //û��map��˫��ѭ��
public:
	int lengthOfLongestSubstring(string s) {
		int maxlen = 0;
		int cnt = 0;
		int flag[256] = { 0 };       //ASCII��+��չASCII��
		for(int i = 0; i < s.size(); i++) {
			cnt = 0;
			memset(flag, 0, sizeof(flag));   //ÿ������
			for (int j = i; j < s.size(); j++) {
				if (flag[s[j]] == 0) {
					flag[s[j]] = 1;
					cnt++;
				}
				else break;
			}
			if (cnt > maxlen) {
				maxlen = cnt;
			}
		}
		return maxlen;
	}

	// �� һ�α��� ��
	//ͬʱά����������
	int lengthOfLongestSubstring1(string s) {
		int pos = -1;
		int maxlen = 0;
		int flag[256];
		memset(flag, -1, sizeof(flag));
		for (int i = 0; i < s.size(); i++) {
			if (flag[s[i]] != -1 && pos < flag[s[i]]) {
				pos = flag[s[i]];     //�������һ���ظ�Ԫ�ص�λ��
			}
			if (i - pos > maxlen) {
				maxlen = i - pos;
			}
			flag[s[i]] = i;
		}
		return maxlen;
	}
};

