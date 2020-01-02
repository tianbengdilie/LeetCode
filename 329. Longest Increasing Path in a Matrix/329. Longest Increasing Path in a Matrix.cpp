#ifdef _DEBUG
#include"../head.h"
#endif

static int dirX[4] = { 0,0,1,-1 };
static int dirY[4] = { 1,-1,0,0 };

class Solution {
	vector<vector<int>> memo;
	int row, col;
	int GetPathLen(const vector<vector<int>>& matrix, int x, int y) {
		if (memo[x][y] != -1) return memo[x][y];
		for (int i = 0; i < 4; i++) {

		}
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;
		row = matrix.size(), col = matrix.front().size();
		memo = vector<vector<int>>(row, vector<int>(col, -1));
		int ans = 0;
		for (int x = 0; x < row; ++x) {
			for (int y = 0; y < col; ++y) {
				ans = max(ans, GetPathLen(matrix, x, y));
			}
		}
		return ans;
	}
};


#ifdef _DEBUG
int main() {
	Solution s;
	return 0;
}
#endif