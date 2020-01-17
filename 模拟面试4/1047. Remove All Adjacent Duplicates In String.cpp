#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	string removeDuplicates(string S) {
		if (S.size() < 2) return S;
		int left = 0, right = 1;
		while (right < S.size()) {
			if (S[left] == S[right]) {
				S[left--] = S[right] = ' ';
				while (left >= 0 && S[left] == ' ') left--;
				if(left < 0)
					left = (++right)++;
				else 
					++right;
			}
			else {
				while (++left < S.size() && S[left] == ' ');
				++right;
			}
		}
		auto end = remove(S.begin(), S.end(), ' ');
		return string(S.begin(), end);
	}
};
#ifdef _DEBUG
int main1() {
	Solution s;
	cout << s.removeDuplicates("abbaca") << endl;
	cout << s.removeDuplicates("ibfjcaffccadidiaidchakchchcahabhibdcejkdkfbaeeaecdjhajbkfebebfea") << endl;
	cout << s.removeDuplicates("aaaa") << endl;
	cout << s.removeDuplicates("adaadc") << endl;
	return 0;
}
#endif