#ifdef _DEBUG
#include"../head.h"
#endif

//���ݷ�
class Solution {
public:
	int len;
	int ans;
	vector<bool> hasrow, hasslash, hasanslash;
	void dfs(int y) {
		if (y > len)
			++ans;
		for (int x = 0; x <= len; ++x) {
			int slash = len - x + y, anslash = x + y;
			if (!hasrow[x] && !hasslash[slash] && !hasanslash[anslash]) {
				hasrow[x] = true;
				hasslash[slash] = true;
				hasanslash[anslash] = true;
				dfs(y + 1);
				hasanslash[anslash] = false;
				hasslash[slash] = false;
				hasrow[x] = false;
			}
		}
	}
	//���е���
	int totalNQueens(int n) {
		len = n - 1;
		hasrow = vector<bool>(n, false);
		hasslash = hasanslash = vector<bool>(2 * n - 1, false);
		ans = 0;
		dfs(0);
		return ans;
	}
};
#ifdef _DEBUG
int main2_2() {
	Solution s;
	cout << s.totalNQueens(4) << endl;
	return 0;
}
#endif