#ifdef _DEBUG
#include"../head.h"
#endif

static int movX[4] = { 0,0,-1,1 };
static int movY[4] = { -1,1,0,0 };
static unordered_set<string> results;
static int boundX, boundY;
static string result = "";

struct Node {
	unordered_map<char, Node*> nexts;
	bool isEnd;
	Node() : isEnd(false) {}
	void Insert(const string& word, int index) {
		if (word.size() == index) {
			this->isEnd = true;
			return;
		}
		char v = word[index];
		if (!nexts.count(v)) {
			nexts[v] = new Node();
		}
		nexts[v]->Insert(word, index+1);
	}
	void Find(const vector<vector<char>>& board, vector<vector<bool>> &visited, int x, int y, string& result)const {
		if (isEnd) {
			results.insert(result);
		}
		for (int i = 0; i < 4; ++i) {
			int nX = x + movX[i], nY = y + movY[i];
			if (nX < boundX && nX >= 0 && nY < boundY && nY >= 0 &&
				visited[nX][nY] && nexts.count(board[nX][nY])) {
				result.push_back(board[nX][nY]);
				visited[nX][nY] = false;
				nexts.at(board[nX][nY])->Find(board, visited, nX, nY, result);
				visited[nX][nY] = true;
				result.pop_back();
			}
		}
	}
};

void Build(Node* root, const string& word) {
	if (word.empty()) return;
	if (!root->nexts.count(word[0])) {
		root->nexts[word[0]] = new Node();
	}
	root->nexts[word[0]]->Insert(word, 1);
}

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if (board.empty()) return vector<string>();
		Node* root = new Node();
		for (const string& word : words)
			Build(root, word);
		results.clear();
		boundX = board.size(), boundY = board[0].size();
		vector<vector<bool>> visited(boundX, vector<bool>(boundY, true));
		for (int x = 0; x < boundX; ++x) {
			for (int y = 0; y < boundY; ++y) {
				if (root->nexts.count(board[x][y])) {
					visited[x][y] = false;
					result.push_back(board[x][y]);
					root->nexts[board[x][y]]->Find(board, visited, x, y, result);
					visited[x][y] = true;
					result.pop_back();
				}
			}
		}
		return vector<string>(results.begin(), results.end());
	}
};

#ifdef _DEBUG
int main() {
	vector<vector<char>> board = { {'a','a'} };
		//{{'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}};
	vector<string> words = { "a","aa","aaa","aaaa" };
	Solution s;
	words = s.findWords(board, words);
	for (auto& word : words)
		cout << word << endl;
	return 0;
}
#endif