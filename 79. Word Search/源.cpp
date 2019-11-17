#include "../head.h"

static const int dirX[] = { 0,0,1,-1 };
static const int dirY[] = { 1,-1,0,0 };
class Solution {
public:
	bool exist(vector<vector<char>>& board, const string & word) {
		vector<vector<bool>> isVisit(board.size(), vector<bool>(board.back().size(), false));
		for (int x = 0; x < board.size(); x++) {
			for (int y = 0; y < board.back().size(); ++y) {
				if (Move(board, word, isVisit, 0, x, y))
					return true;
			}
		}
		return false;
	}
	bool Move(const vector<vector<char>>& board, const string & word, vector<vector<bool>>& isVisit, int index, int curX, int curY) {
		if (word[index] != board[curX][curY])  return false;
		if (index == word.size() - 1) return true;
		isVisit[curX][curY] = true;
		for (int i = 0; i < 4; i++) {
			int movX = dirX[i] + curX, movY = dirY[i] + curY;
			if (movX < 0 || movX >= board.size() || movY < 0 || movY >= board.back().size() || isVisit[movX][movY])
				continue;
			if (Move(board, word, isVisit, index + 1, movX, movY))
				return true;
		}
		isVisit[curX][curY] = false;
		return false;
	}
};
int main() {
	vector<vector<char>> board;
	//board.push_back({ 'A', 'B', 'C', 'E' });
	//board.push_back({ 'S', 'F', 'C', 'S' });
	//board.push_back({ 'A', 'D', 'E', 'E' });
	board.push_back({ 'A' });
	Solution s;
	cout << s.exist(board, "A");
	return 0;
}