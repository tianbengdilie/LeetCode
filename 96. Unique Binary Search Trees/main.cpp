#include"../head.h"

class Solution {
private:
	vector<int> nums;

public:
	Solution() {
		nums = vector<int>{ 1,1,2,5 };
	}
	int numTrees(int n) {
		while (n >= nums.size()) {
			int tol = 0, border = (nums.size() + 1) / 2;
			for (int i = 0; i < border; ++i) {
				int tmp = n - i - 1;
				if (tmp != i) {
					tol += nums[tmp] * nums[i] * 2;
				}
				else {
					tol += nums[tmp] * nums[i];
				}
			}
			nums.push_back(tol);
		}
		return nums[n];
	}
};

static auto s = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();

int main() {
	Solution s;
	s.numTrees(5);
	return 0;
}