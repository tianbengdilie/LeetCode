#include"../head.h"

class Solution {
public:
	ostringstream sin;
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		string ret;
		//处理负数情况
		if (numerator < 0 && denominator < 0) numerator = -numerator, denominator = -denominator;
		else if (numerator < 0) numerator = -numerator, ret.push_back('-');
		else if (denominator < 0) denominator = -denominator, ret.push_back('-');
		//处理整数部分
		if (numerator > denominator) {
			ret += Int2Str(numerator / denominator);
			numerator %= denominator;
		}
		if (!numerator) return ret;
		//处理小数部分
		if (ret.empty() || ret.back() == '-') ret.push_back('0');
		ret.push_back('.');
		while (numerator) {
			numerator *= 10;
			if (numerator > denominator) {
				ret.push_back(numerator / denominator + '0');
				numerator %= denominator;
			}
		}
		return ret;
	}

	string Int2Str(int num) {
		sin.str("");
		sin << num;
		return sin.str();
	}
};

int main() {
	Solution s;
	cout << s.fractionToDecimal(1, 8) << endl;
	return 0;
}