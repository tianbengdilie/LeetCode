#ifdef _DEBUG
#include"../head.h"
class MountainArray {
public:
	int get(int index);
	int length();

};
#endif
//¶þ·Ö·¨
class Solution {
public:
	class Solution {
	public:
		int findInMountainArray(int target, MountainArray &mountainArr) {
			if (mountainArr.length() < 3) return -1;
			int right = mountainArr.length() - 1, left = 0;
			while (left + 2 != right) {
				int mid = (right - left) / 2 + left;
				int value1 = mountainArr.get(mid), value2 = mountainArr.get(mid + 1);
				if (value1 < value2)
					left = mid;
				else
					right = mid + 1;
			}
			int mid = left + 1;
			//×ó±ß
			left = 0, right = mid;
			while (left <= right) {
				int mid = (right - left) / 2 + left;
				int midvalue = mountainArr.get(mid);
				if (midvalue < target)
					left = mid + 1;
				else if (midvalue > target)
					right = mid - 1;
				else
					return mid;
			}
			//ÓÒ±ß
			right = mountainArr.length() - 1, left = mid;
			while (left <= right) {
				int mid = (right - left) / 2 + left;
				int midvalue = mountainArr.get(mid);
				if (midvalue > target)
					left = mid + 1;
				else if (midvalue < target)
					right = mid - 1;
				else
					return mid;
			}
			return -1;
		}
	};
};
#ifdef _DEBUG
int main() {
	Solution s;
	return 0;
}
#endif