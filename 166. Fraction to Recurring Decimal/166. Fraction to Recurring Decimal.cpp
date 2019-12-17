#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	ostringstream sin;
	string fractionToDecimal(long long numerator, long long denominator) {
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
		if (ret.empty() || ret.back() == '-') ret.push_back('0');
		//处理小数部分
		ret.push_back('.');
		int dotindex = ret.size() - 1;
		unordered_set<long long> flags;
		flags.insert(numerator);
		while (numerator) {
			numerator *= 10;
			if (numerator >= denominator) {
				ret.push_back(numerator / denominator + '0');
				numerator %= denominator;
				if (flags.count(numerator)) {
					string cycle;
					numerator *= 10;
					long long cursor = numerator;
					do {
						while (cursor < denominator) cursor *= 10, cycle.push_back('0');
						cycle.push_back(cursor / denominator + '0');
						cursor = (cursor % denominator) * 10;
					} while (cursor != numerator);
					int index = ret.find(cycle, dotindex);
					ret.insert(ret.begin() + index, '(');
					ret.push_back(')');
					return ret;
				}
				flags.insert(numerator);
			}
			else
				ret.push_back('0');
		}
		return ret;
	}

	string Int2Str(long long num) {
		sin.str("");
		sin << num;
		return sin.str();
	}
};

#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.fractionToDecimal(-1ll, -2147483648ll) << endl;
	return 0;
}
#endif
