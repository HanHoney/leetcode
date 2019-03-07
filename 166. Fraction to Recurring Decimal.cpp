//166. Fraction to Recurring Decimal
//Medium
//hashtable

//��Hint��Notice that once the remainder starts repeating, so does the divided result.
//ע��ȫ�濼�Ǹ����������������0������������ѭ�������߲�ѭ����

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	long long gcd(long long m, long long n) {
		if (n == 0) return m;
		return gcd(n, m%n);
	}
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		string res("");
		if (numerator > 0 ^ denominator > 0) {
			res += '-';
		}
		long long n = abs((long long)numerator);
		long long d = abs((long long)denominator);
		long long g = gcd(n, d);
		n /= g;
		d /= g;
		res += to_string(n / d);
		long long r = n % d;
		if (r == 0) {
			return res;
		}
		res += '.';
		r *= 10;
		unordered_map<long long, long long> map;	//��¼�����Ͷ�Ӧ��λ��
		while (r) {
			long long q = r / d;
			if (map.find(r) != map.end()) {
				res.insert(map[r], "(");
				res += ')';
				break;
			}
			map[r] = res.size();
			res += to_string(q);
			r = (r % d) * 10;
		}
		return res;
	}
};