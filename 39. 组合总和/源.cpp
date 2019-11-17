#include "../head.h"

class Solution {
private:
	vector<vector<int>> resultList;
	vector<int> tmpResult;
public:
	Solution() {
		tmpResult.reserve(1000);
		resultList.reserve(1000);
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		resultList.clear();
		calcul(candidates.begin(), candidates.end(), target);
		return resultList;
	}
	void calcul(vector<int>::iterator beg, vector<int>::iterator end, int target) {
		if (target == 0) {
			resultList.insert(resultList.begin(), tmpResult);
			return;
		}
		if (target < 0) {
			return;
		}
		for (auto iter = beg; iter != end; iter++) {
			tmpResult.push_back(*iter);
			calcul(iter, end, target - *iter);
			tmpResult.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums{ 2,3,6,7 };
	s.combinationSum(nums, 7);
	return 0;
}