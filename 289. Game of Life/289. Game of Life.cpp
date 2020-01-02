#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		/**
		利用一个 two bits 的状态机来记录细胞状态, 第一位表示
		下一状态, 第二位表示当前状态:
		00: dead (next state) <- dead (current state)
		01: dead (next state) <- live (current state)
		10: live (next state) <- dead (current state)
		11: live (next state) <- live (current state)
		初始情况对应就是 00 和 01 (默认下一状态是 dead state)
		统计每个位置周围的 live 细胞数决定高位置 1 (live)还是
		0 (dead), 最后右移一位即为最终状态, 注意不需要考虑 01
		以及 00 的情况, 因为已经默认下一状态为 dead.
		**/
		if (board.size() < 1) return;
		// 更新矩阵
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				int lives = countLives(board, i, j);
				// live -> live
				if ((board[i][j] & 1) == 1) {
					if (lives >= 2 && lives <= 3)
						board[i][j] = 3;
				}
				// dead -> live
				else {
					if (lives == 3)
						board[i][j] = 2;
				}
			}
		}
		// 重置矩阵
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j)
				board[i][j] >>= 1;
		}
	}

	int countLives(vector<vector<int>>& b, int i, int j) {
		int count = 0;
		static vector<vector<int>> dirs = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
		for (const auto& dir : dirs) {
			int x = i + dir[0];
			int y = j + dir[1];
			if (x < 0 || x > b.size() - 1 || y < 0 || y > b[0].size() - 1)
				continue;
			count += (b[x][y] & 1);
		}
		return count;
	}
};

class Solution111 {
public:
	void Judge(int& state, int value) {
		if (state) {
			if (value < 2 || value > 3)
				state = 0;
		}
		else if (value == 3)
			state = 1;
	}
	void gameOfLife(vector<vector<int>>& board) {
		int colSize = board.front().size(), rowSize = board.size();
		if (colSize < 2 || rowSize < 2) {
			board = vector<vector<int>>(rowSize, vector<int>(colSize, 0));
			return;
		}
		vector<vector<int>> counts(rowSize, vector<int>(colSize, 0));
		if (board.front().front()) counts[0][0] = 1;
		for (int i = 1; i < colSize; ++i) { //第一行
			counts[0][i] = counts[0][i - 1] + board[0][i];
		}
		for (int i = 1; i < rowSize; ++i) { //第一列
			counts[i][0] = counts[i - 1][0] + board[i][0];
		}
		for (int i = 1; i < rowSize; ++i) {
			for (int j = 1; j < colSize; ++j) {
				counts[i][j] = -counts[i - 1][j - 1] + board[i][j] + counts[i-1][j] + counts[i][j-1];
			}
		}
		// getvalue = counts[i][j] + counts[i-3][j-3] - counts[i][j-3] - counts[i-3][j]
		for (auto row : counts) {
			for (auto cel : row)
				cout << cel << " ";
			cout << endl;
		}
		//计算四个角
		Judge(board[0][0], counts[1][1]);
		Judge(board[0][colSize - 1], counts[1][colSize - 1] - (colSize > 2 ? counts[1][colSize - 2] : 0));
		Judge(board[rowSize - 1][0], counts[rowSize - 1][1] - (rowSize > 2 ? counts[rowSize - 3][1] : 0));
		Judge(board[rowSize - 1][colSize - 1], counts[rowSize - 1][colSize - 1] - (colSize > 2 ? counts[rowSize - 1][colSize - 3] : 0) - (rowSize > 2 ? counts[rowSize - 3][colSize - 1] : 0));
		//计算四个边边
		--rowSize, --colSize;
		for(int i = 1; i < colSize; ++i)
			Judge(board[0][i], counts[1][1]);


		for (int i = 0; i < rowSize; ++i) {
			for (int j = 0; j < colSize; ++j) {
				int value = -board[i][j];
				value += counts[i + 1][j + 1] - counts[i + 1][j - 2] - counts[i - 2][j + 1] + (i >= 2 && j >= 2 ? counts[i - 2][j - 2] : 0);
				Judge(board[i][j], value);
			}
		}
	}
};


#ifdef _DEBUG
int main() {
	vector<int> row1{0, 1, 0}, row2{0, 0, 1}, row3{1, 1, 1}, row4{0, 0, 0};
	vector<vector<int>> board{ row1 ,row2,row3,row4 };
	Solution s;
	for (auto row : board) {
		for (auto cel : row)
			cout << cel << " ";
		cout << endl;
	}
	cout << "---" << endl;
	s.gameOfLife(board);
	cout << "---" << endl;
	for (auto row : board) {
		for (auto cel : row)
			cout << cel << " ";
		cout << endl;
	}
	return 0;
}
#endif