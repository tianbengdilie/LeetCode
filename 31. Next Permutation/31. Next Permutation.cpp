#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(), right = n - 1;
		while (right > 0 && nums[right - 1] >= nums[right])
			--right;
		if (right > 0) {
			int tmp = nums[right - 1], next = n - 1;
			while (next >= right - 1 && nums[next] <= tmp) --next;
			swap(nums[right - 1], nums[next]);
		}
		sort(nums.begin() + right, nums.end());
	}
};

#ifdef _DEBUG
void test(const vector<int>& nums) {
	Solution s;
	vector<int> tmp(nums);
	s.nextPermutation(tmp);
	cout << "origin: {";
	for (auto n : nums) cout << n << " ";
	cout << "}\ncurrent: {";
	for (auto n : tmp) cout << n << " ";
	cout << "}\n";
}

void show(const vector<int>& nums) {
	for (auto n : nums) cout << n << " ";
	cout << endl;
}

void test2(const vector<int>& nums) {
	vector<int> tmp(nums);
	Solution s;
	do {
		show(tmp);
		s.nextPermutation(tmp);
	} while (nums != tmp);
}

int main() {
	Solution s;
	test2({ 1,2,3,4 });
	return 0;
}
#endif