#include "../head.h"

class Solution1 {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int m = matrix.size(), n = matrix.back().size(), ans = 0;
		vector<vector<int>> nums(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					nums[i][j] = j != 0 ? nums[i][j - 1] + 1 : 1;
					int minWid = nums[i][j];
					for (int k = i; k >= 0; --k) {
						minWid = min(nums[k][j], minWid);
						ans = max(ans, minWid * (i - k + 1));
					}
				}
			}
		}
		return ans;
	}
};

class Solution2 {
public:
	int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int m = matrix.size(), n = matrix.back().size(), ans = 0;
		vector<vector<int>> nums(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					nums[i][j] = j != 0 ? nums[i][j - 1] + 1 : 1;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			stack<int> s;
			s.push(m);
			for (int j = m - 1; j >= 0; --j) {
				while (s.top() != m && nums[s.top()][i] > nums[j][i]) {
					int t = s.top();
					s.pop();
					ans = max(ans, nums[t][i] * (s.top() - j - 1));
				}
				s.push(j);
			}
			while (s.top() != m) {
				int t = s.top();
				s.pop();
				ans = max<int>(ans, nums[t][i] * (s.top()));
			}
		}
		return ans;
	}
};

class Solution {
public:
	int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int n = matrix.size(), m = matrix.back().size(), ans = 0;
		vector<int> left(m), right(m,m), height(m);
		for (int i = 0; i < n; i++) {
			int curRight = m;
			for (int j = m - 1; j >= 0; --j) {
				if (matrix[i][j] == '1') right[j] = min(right[j], curRight);
				else {
					right[j] = m;
					curRight = j;
				}
			}
			int curLeft = 0;
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == '1') {
					height[j] = height[j] + 1;
					left[j] = max(left[j], curLeft);
					ans = max(ans, height[j] * (right[j] - left[j]));
				}
				else {
					left[j] = height[j] = 0;
					curLeft = j + 1;
				}
			}
		}
		return ans;
	}                     
};

static auto s = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();

int main() {
	Solution s;
	s.maximalRectangle({
		{'1', '0', '1', '1', '1', '0', '0', '0', '1', '0'}, 
		{'0', '1', '0', '0', '0', '0', '0', '1', '1', '0'}, 
		{'0', '1', '0', '1', '0', '0', '0', '0', '1', '1'}, 
		{'1', '1', '1', '0', '0', '0', '0', '0', '1', '0'}, 
		{'0', '1', '1', '1', '0', '0', '1', '0', '1', '0'}, 
		{'1', '1', '0', '1', '1', '0', '1', '1', '1', '0'}});
	s.maximalRectangle({{'1', '0', '1', '0'}, {'1', '0', '1', '1'}, {'1', '0', '1', '1'}, {'1', '1', '1', '1'}});
	s.maximalRectangle({{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}});
	s.maximalRectangle({ {'0','1'},{'1','0'} });
	s.maximalRectangle({ {'1'} });
	return 0;
}