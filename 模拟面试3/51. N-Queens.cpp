#ifdef _DEBUG
#include"../head.h"
#endif

//回溯法
class Solution {
public:
	int len;
	vector<vector<string>> ans;
	vector<string> tmp;
	vector<bool> hasrow, hasslash, hasanslash;
	void dfs(int y) {
		if (y > len)
			ans.push_back(tmp);
		for (int x = 0; x <= len; ++x) {
			int slash = len - x + y, anslash = x + y;
			if (!hasrow[x] && !hasslash[slash] && !hasanslash[anslash]) {
				hasrow[x] = true;
				hasslash[slash] = true;
				hasanslash[anslash] = true;
				tmp[x][y] = 'Q';
				dfs(y + 1);
				tmp[x][y] = '.';
				hasanslash[anslash] = false;
				hasslash[slash] = false;
				hasrow[x] = false;
			}
		}
	}
	//按列迭代
	vector<vector<string>> solveNQueens(int n) {
		len = n - 1;
		hasrow = vector<bool>(n, false);
		hasslash = hasanslash = vector<bool>(2 * n - 1, false);
		tmp = vector<string>(n, string(n, '.'));
		ans.clear();
		dfs(0);
		return ans;
	}
};
#ifdef _DEBUG
void show(const vector<vector<string>> & matrix) {
	cout << "------------------------------------" << endl;
	for (auto row : matrix) {
		for (auto item : row) {
			cout << item << endl;
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;
}

int main2_1() {
	Solution s;
	show(s.solveNQueens(4));
	return 0;
}
#endif