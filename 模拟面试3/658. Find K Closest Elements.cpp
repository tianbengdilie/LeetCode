#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		if (k > arr.size()) return arr;
		arr.insert(arr.begin(), INT32_MIN);  //添加个边界
		auto mid = upper_bound(arr.begin(), arr.end(), x);
		if (mid == arr.begin()+1) return vector<int>(mid, mid + k);
		if (mid == arr.end()) return vector<int>(mid - k, mid);
		auto left = mid - 1, right = mid;
		while (k--) {//这个应该用二分法找左右两个边界，才是正确的做法
			if (*right - x < x - *left) {
				if (++right == arr.end()) break;
			}
			else {
				if (--left == arr.begin()) break;
			}
		}
		if (k >= 0) {
			if (right == arr.end()) 
				left -= k;
			else
				right += k;
		}
		return vector<int>(++left, right);
	}
};
#ifdef _DEBUG
int main1() {
	vector<int> nums{ 1,2,3,4,6,7,8 };
	Solution s;
	auto ans = s.findClosestElements(nums, 4, 7);
	return 0;
}
#endif