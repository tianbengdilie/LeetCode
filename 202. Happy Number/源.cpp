#ifdef _DEBUG
#include"../head.h"
#endif

string Int2Str(long long num) {
	static ostringstream sout;
	sout.str("");
	sout << num;
	return sout.str();
}

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<string> strs;
		string str = Int2Str(n);
		while (str != "0" && str != "1") {
			if (strs.insert(str).second==false) return 0;
			int tmp = 0;
			for (const auto& ch : str)
				tmp += pow(ch - '0', 2);
			str = Int2Str(tmp);
		}
		return str == "1";
	}
};
#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.isHappy(19) << endl;
	return 0;
}
#endif