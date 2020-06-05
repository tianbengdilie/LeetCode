#ifdef _WIN32
#include"../head.h"
#endif

class Solution {
	void quicksort(vector<int>& nums, int begin, int end)
	{
		//×óÓÒ±ÕÇø¼ä
		if (begin >= end)
			return;
		int left = begin + 1, right = end, mid = nums[begin];
		while (left < right)
		{
			while (left <= right && nums[left] <= mid)
				++left;
			while (left <= right && nums[right] >= mid)
				--right;
			if(left < right)
				swap(nums[left], nums[right]);
		}
		if(nums[begin] > nums[right])
			swap(nums[begin], nums[right]);
		for (auto i : nums)
			cout << i << " ";
		cout << endl;
		quicksort(nums, begin, right - 1);
		quicksort(nums, right + 1, end);
	}
public:
	vector<int> sortArray(vector<int>& nums) {
		quicksort(nums, 0, nums.size() - 1);
		return nums;
	}
};

#ifdef _WIN32
int main() {
	Solution s;
	vector<int> nums{ 5,1,1,2,0,0 };
	nums = s.sortArray(nums);
	for (auto i : nums)
		cout << i << " ";
	return 0;
}
#endif