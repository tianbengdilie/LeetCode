#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	void wiggleSort(vector<int>& nums) {

		if (nums.size() < 2) return;

		//计算出中位数
		decltype(nums.begin()) midIter = nums.begin() + (nums.size() + 1) / 2;
		nth_element(nums.begin(), midIter, nums.end());
		int mid = *midIter; //

		cout << "here" << endl;

		int cur = 0, left = 0, right = nums.size() - 1, len = midIter - nums.begin();

		while (cur < right) {
			if (nums[cur] < mid)
				swap(nums[cur++], nums[left++]);
			else if (nums[cur] > mid)
				swap(nums[cur], nums[right--]);
			else
				cur++;
		}

		vector<int> tmp1(nums.begin(), midIter), tmp2(midIter, nums.end());
		for (int i = 0; i < tmp1.size(); ++i) {
			nums[2 * i] = tmp1[tmp1.size() - 1 - i];
		}
		for (int i = 0; i < tmp2.size(); ++i) {
			nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
		}
	}
};

#ifdef _DEBUG
int main() {
	vector<int> test{ 1,1,2,2,2,1 };
	Solution s;
	s.wiggleSort(test);
	for (auto i : test) cout << i << " ";
	cout << endl;
	return 0;
}
#endif