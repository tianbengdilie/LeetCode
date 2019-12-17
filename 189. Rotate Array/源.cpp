#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || (k %= nums.size()) == 0)return;
		vector<int> tmps(nums.begin(), nums.begin() + (nums.size() - k));
		int inter = nums.size() - k;
		for (int i = 0; i < k; i++)
			nums[i] = nums[i + inter];
		for (int i = 0; i < tmps.size(); ++i)
			nums[i + k] = tmps[i];
	}
};

void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	k = k % n;
	reverse(nums.begin(), nums.begin() + n - k);
	reverse(nums.begin() + n - k, nums.end());
	reverse(nums.begin(), nums.end());
}

#ifdef _DEBUG
int main() {
	Solution s;
	vector<int> nums{ 1,2,3,4,5,6};
	s.rotate(nums, 2);
	for (auto & num : nums) cout << num << " ";
	return 0;
}
#endif