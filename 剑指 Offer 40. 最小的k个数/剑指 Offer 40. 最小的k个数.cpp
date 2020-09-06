#ifdef _WIN32
#include"../head.h"
#endif

class Solution {
	void hardquicksort(vector<int>& arr, int beg, int end, int k) {
		if (end - beg < 1) return;
		int low = beg + 1, high = end;
		int pivot = arr[beg];
		while (low < high) {
			while (low < high && arr[low] < arr[beg]) ++low;
			while (low < high && arr[high] >= arr[beg]) --high;
			swap(arr[low], arr[high]);
		}
		if (arr[low] > arr[beg]) --low;
		swap(arr[low], arr[beg]);
		printf("(%d,%d): ", pivot, low);
		for (auto n : arr) cout << n << ",";
		cout << endl;
		if (k < low) hardquicksort(arr, beg, low - 1, k);
		if (k > low) hardquicksort(arr, low + 1, end, k);
	}
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (!k) return {};
		hardquicksort(arr, 0, arr.size() - 1, k - 1);
		return vector<int>(arr.begin(), arr.begin() + k);
	}
};

#ifdef _WIN32
int main() {
	Solution s;
	vector<int> nums{ 0, 1, 1, 2, 4, 4, 1, 3, 3, 2 };
	auto tmp = s.getLeastNumbers(nums, 6);
	nums = vector<int>{ 3,2,1,5,0,0,0,0,0 };
	tmp = s.getLeastNumbers(nums, 3);
	return 0;
}
#endif