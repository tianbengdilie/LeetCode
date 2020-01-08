#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		len = matrix.size();
		int left = matrix[0][0], right = matrix[len - 1][len - 1];
		while (left < right) {
			int mid = (left + right) / 2;
			int count = Count(matrix, mid);
			if (count < k) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return right;
	}
private:
	int len;
	int Count(const vector<vector<int>>& matrix, int mid) {
		int i = len - 1, j = 0, count = 0;
		while (i >= 0 && j < len) {
			if (matrix[i][j] > mid) {
				i--;
			}
			else {
				count += i + 1;
				j++;
			}
		}
		return count;
	}
};
#ifdef _DEBUG
int main() {
	int k = 8;
	vector<vector<int>> matrix
		{
			{1, 5, 9},
			{10, 11, 13},
			{12, 13, 15}
		}
	;
	Solution s;
	cout << s.kthSmallest(matrix, k);
	return 0;
}
#endif