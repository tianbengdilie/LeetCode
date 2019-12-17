#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = n & 0x80000000 ? 1 : 0;
		int tmp = n & 0x7fffffff;
		while (tmp) {
			++count, tmp = tmp - (tmp & -tmp);
		}
		return count;
	}
};

#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.hammingWeight(0b11111111111111111111111111111101) << endl;
	return 0;
}
#endif