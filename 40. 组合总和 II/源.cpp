#include "../head.h"

class Solution {
private:
	vector<vector<int>> resultList;
	vector<int> path;
	vector<int> *nums;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		resultList.clear();
		sort(candidates.begin(), candidates.end());
		nums = &candidates;
		dfs(0, target);
		return resultList;
	}
	void dfs(int start, int target) {
		if (target == 0) {
			resultList.push_back(path);
			return;
		}
		for (int i = start; i < (*nums).size() && (*nums)[i] <= target; ++i) {
			if (i != start && (*nums)[i] == (*nums)[i - 1])
				continue;
			path.push_back((*nums)[i]);
			dfs(i + 1, target - (*nums)[i]);
			path.pop_back();
		}
	}
};

static auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

int main() {
	vector<int> nums{ 2,5,2,1,2 };
	Solution s;
	s.combinationSum2(nums, 5);
	return 0;
}