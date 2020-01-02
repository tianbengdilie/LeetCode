#ifdef _DEBUG
#include"../head.h"
#endif

static int dirX[4] = { 0,0,1,-1 };
static int dirY[4] = { 1,-1,0,0 };

class Solution {
	vector<vector<int>> memo;
	int row, col;
	int GetPathLen(const vector<vector<int>>& matrix, int x, int y) {
		if (memo[x][y] != 0) return memo[x][y];
		memo[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nextX = x + dirX[i], nextY = y + dirY[i];
			if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col)
				continue;
			if (matrix[nextX][nextY] > matrix[x][y]) {
				memo[x][y] = max(memo[x][y], 1 + GetPathLen(matrix, nextX, nextY));
			}
		}
		return memo[x][y];
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;
		row = matrix.size(), col = matrix.front().size();
		memo = vector<vector<int>>(row, vector<int>(col));
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
	vector<vector<int>> matrix = { {1,2} };
	Solution s;

	cout << s.longestIncreasingPath(matrix) << endl;
	return 0;
}
#endif