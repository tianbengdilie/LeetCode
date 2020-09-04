#ifdef _WIN32
#include"../head.h"
#endif

class Solution {
	bool helper(const string& s, const string& p, int si, int pi) {
		if (p.size() == pi && s.size() == si) return true;
		if (p.size() == pi) return false;
		bool flag = false;
		if (p[pi] == '.' && si != s.size() || p[pi] == s[si]) {
			flag = helper(s, p, si + 1, pi + 1);
			if (!flag && pi + 1 < p.size() && p[pi + 1] == '*')
				flag = helper(s, p, si + 1, pi);
		}
		if (!flag && pi + 1 < p.size() && p[pi + 1] == '*')
			flag = helper(s, p, si, pi + 2);
		return flag;
	}
public:
	bool isMatch(string s, string p) {
		return helper(s, p, 0, 0);
	}
};


#ifdef _WIN32
int main() {
	Solution s;
	cout << std::boolalpha << s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;
	cout << std::boolalpha << s.isMatch("ab", ".*") << endl;
	cout << std::boolalpha << s.isMatch("aa", "a*") << endl;
	cout << std::boolalpha << s.isMatch("aab", "c*a*b") << endl;
	cout << std::boolalpha << s.isMatch("mississippi", "mis*is*p*.") << endl;
	cout << std::boolalpha << s.isMatch("ab", "a*b*") << endl;
	return 0;
}
#endif