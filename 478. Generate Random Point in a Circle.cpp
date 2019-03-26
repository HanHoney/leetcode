//478. Generate Random Point in a Circle
//Medium

#include <iostream>
#include <math.h> 
#include <vector>
using namespace std;

class Solution {
	double R;
	double x;
	double y;

public:
	double uniform() {
		return (double)rand() / RAND_MAX;
	}
	Solution(double radius, double x_center, double y_center) {
		R = radius;
		x = x_center;
		y = y_center;
	}
	vector<double> randPoint() {
		double r = sqrt(uniform())*R;
		double theta = 2 * uniform() * acos(-1);   //arccos(-1)=¦Ð
		return vector<double>{x + r * cos(theta), y + r * sin(theta)};
	}
};

#if 0
int main() {
	Solution s(1, 0, 0);
	vector<double> ret = s.randPoint();
	cout << ret[0] << "," << ret[1] << endl;
	system("pause");
	return 0;
}
#endif