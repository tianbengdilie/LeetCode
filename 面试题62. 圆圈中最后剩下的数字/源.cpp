#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	int lastRemaining(int n, int m) {
		int f = 0;
		for (int i = 2; i <= n; ++i)
			f = (f + m) % n;
		return f;
	}
};

#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.lastRemaining(70866, 116922) << endl;
	return 0;
}
#endif