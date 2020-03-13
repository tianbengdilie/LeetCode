#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	string GetDivisorOfString(const string& str)
	{
		return str.substr(0, (str + str).find(str, 1));
	}
};
#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.GetDivisorOfString("aaaaaaaaaaaaaaaa") << endl;
	cout <<         s.GetDivisorOfString("abababab") << endl;
	cout <<			s.GetDivisorOfString("abababac") << endl;
	cout <<		   s.GetDivisorOfString("abcabcabc") << endl;
	return 0;
}
#endif