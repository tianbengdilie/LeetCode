#ifdef _WIN32
#include"../head.h"
#endif

class Solution {
public:
	int countDigitOne(int n) {
		long count = 0, ass = 1, cur = 1;
		while (cur <= n) {
			int tmp = n / cur % 10;
			count += n / cur / 10 * cur;
			if (tmp == 0) {

			}
			else if (tmp == 1) {
				count += n % cur + 1;
			}
			else {
				count += cur;
			}
			cur *= 10;
		}
		return count;
	}
};

#ifdef _WIN32
int main() {
	Solution s;
	cout << s.countDigitOne(1410065408) << endl;
	return 0;
}
#endif