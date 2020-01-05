#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
private:
	vector<int> ans, tmp, indexs;
	void mergeSort(const vector<int>& nums, int left, int right) {
		if (left >= right)
			return;
		int mid = (left + right) / 2;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
	void merge(const vector<int>& nums, int left, int mid, int right) {
 		if (nums[indexs[mid]] < nums[indexs[mid + 1]]) return;  //ÒÑ¾­ÓÐÐò
		for (int i = left; i <= right; ++i)
			tmp[i] = indexs[i];
		int p1 = left, p2 = mid + 1, p3 = left;
		for (int k = left; k <= right; ++k) {
			if (p1 > mid)
				indexs[k] = tmp[p2++];
			else if (p2 > right) {
				indexs[k] = tmp[p1++];
				ans[indexs[k]] += right - mid;
			}
			else if (nums[tmp[p1]] <= nums[tmp[p2]]) {
				indexs[k] = tmp[p1++];
				ans[indexs[k]] += p2 - mid - 1;
			}
			else
				indexs[k] = tmp[p2++];
		}
	}
public:
	vector<int> countSmaller(vector<int>& nums) {
		indexs = tmp = ans = vector<int>(nums.size(), 0);
		for (int i = 0; i < nums.size(); ++i) indexs[i] = i;
		mergeSort(nums, 0, nums.size() - 1);
		return ans;
	}
};

#ifdef _DEBUG
int main() {
	Solution s;
	vector<int> nums{26, 78, 27, 100, 33, 67, 90, 23, 66, 5, 38, 7, 35, 23, 52, 22, 83, 51, 98, 69, 81, 32, 78, 28, 94, 13, 2, 97, 3, 76, 99, 51, 9, 21, 84, 66, 65, 36, 100, 41};
	cout << nums.size() << endl;
	auto res = s.countSmaller(nums);
	for (auto a : res)
		cout << a << " ";
	cout << endl;
	return 0;
}
#endif