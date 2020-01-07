#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	bool increasingTriplet(const vector<int>& nums) {
		if (nums.size() < 3) return false;
		vector<int> indexs;
		for (int i = 0; i < nums.size(); ++i) {
			if (indexs.empty() || nums[indexs.back()] < nums[i])
				indexs.push_back(i);
			else{
				if (nums[indexs.front()] > nums[i])
					indexs.front() = i;
				else if (nums[indexs.front()] < nums[i] && indexs.size() == 2 && nums[indexs[1]] > nums[i])
					indexs[1] = i;
			}
			if (indexs.size() == 3)
				return true;
		}
		return false;
	}
};
#ifdef _DEBUG
int main() {
	vector<int> nums{ 1,2,1,2,1,2,1,2,1,2};
	Solution s;
	cout << s.increasingTriplet(nums) << endl;
	return 0;
}
#endif