/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
*/

#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	vector<int> GetFactors(int num) {
		
	}
	bool repeatedSubstringPattern(string s) {
		if (s.size() < 2) return false;
		int subend = 1, subptr = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == s[subptr]) {
				subptr = (subptr + 1) % subend;
			}
			else {
				subend = i + 1;
				subptr = 0;
			}
		}
		vector<int > tmps;
		for (int i : tmps) {

		}
		return subend != s.size() && s.size() % subend == 0;
	}
};

#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.repeatedSubstringPattern("abacababacab") << endl;
	return 0;
}
#endif