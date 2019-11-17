#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(const vector<int>& nums) {
	for (const auto& num : nums) {
		cout << num << ' ';
	}
	cout << endl;
}

void QuickSort(vector<int>& nums, int beg, int end) {
	if (end - beg < 2) return;	//如果少于两个元素就不必排了
	int low = beg + 1, high = end - 1;
	while (low < high) {
		while (low < high && nums[beg] >= nums[low]) {
			++low;
		}
		if (low == high) break;
		swap(nums[high--], nums[low]);
		while (low < high && nums[beg] < nums[high]) {
			--high;
		}
		if (low == high) break;
		swap(nums[low++], nums[high]);
	}
	if (nums[beg] < nums[low])
		swap(nums[beg], nums[--low]);
	else
		swap(nums[beg], nums[low]);
	QuickSort(nums, beg, low);
	QuickSort(nums, low + 1, end);
}

int main() {
	vector<int> nums{ 3,2,3,1,2,4,5,5,6 };
	QuickSort(nums, 0, nums.size());
	show(nums);
	return 0;
}