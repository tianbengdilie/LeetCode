#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
	int gcd(int lhs, int rhs)
	{
		return rhs ? gcd(rhs, lhs % rhs) : lhs;
	}
public:
	string gcdOfStrings(string str1, string str2) {
		return str1 + str2 == str2 + str1 ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
	}
};
#ifdef _DEBUG
#define asdf "BBACBBABCCADDDBDCDAB BBACBBABCCADDDBDCDAB"
int main() {
	Solution s;
	//cout << s.getrepeat("BBACBBABCCADDDBDCDAB BBACBBABCCADDDBDCDAB") << endl;  //40
	//cout << s.gcdOfStrings("OBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNO", "OBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNOOBCNO") << endl;
	cout << s.gcdOfStrings("BBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDAB"
		, "BBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDABBBACBBABCCADDDBDCDAB") << endl;
	return 0;
}
#endif