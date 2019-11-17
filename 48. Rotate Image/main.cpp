#include "../head.h"

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		for (int offset = 0; offset < matrix.size() / 2; ++offset) {
			int limit = matrix.size() - offset - 1;
			for (int i = 0; i < limit-offset; ++i) {
				int tmp = matrix[offset][offset + i];
				matrix[offset][offset + i] = matrix[limit - i][offset];
				matrix[limit - i][offset] = matrix[limit][limit - i];
				matrix[limit][limit - i] = matrix[offset + i][limit];
				matrix[offset + i][limit] = tmp;
			}
		}
	}
};
//[[2,29,20,26,16,28],[12,27,9,25,13,21],[32,33,32,2,28,14],[13,14,32,27,22,26],[33,1,20,7,21,7],[4,24,1,6,32,34]]
int main() {
	Solution s;
	vector<vector<int>> nums;
	nums.push_back({ 2,29,20,26,16,28 });
	nums.push_back({ 12,27,9,25,13,21 });
	nums.push_back({ 32,33,32,2,28,14 });
	nums.push_back({ 13,14,32,27,22,26 });
	nums.push_back({ 33,1,20,7,21,7 });
	nums.push_back({ 4,24,1,6,32,34 });
	s.rotate(nums);
	return 0;
}