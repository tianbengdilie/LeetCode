#include "../head.h"

class Solution1 {
	//”√µ›πÈ
private:
	vector<vector<int>> resultList;
	vector<int> path;
	vector<bool> isVisited;
	vector<int> * nums;
public:
	void dfs(int count) {
		if (count == nums->size()) {
			resultList.push_back(path);
			return;
		}
		for (int i = 0; i < nums->size(); ++i) {
			if (isVisited[i] == false) {
				isVisited[i] = true;
				path.push_back(nums->operator[](i));
				dfs(count + 1);
				path.pop_back();
				isVisited[i] = false;
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		resultList.clear();
		isVisited = vector<bool>(nums.size(), false);
		this->nums = &nums;
		dfs(0);
		return resultList;
	}
};

class Solution {
private:
	vector<vector<int>> resultList;
	vector<int>* nums;
	void BackTrack(int n) {
		if (n == nums->size() - 1) {
			resultList.push_back(*nums);
			return;
		}
		for (size_t i = n; i < nums->size(); i++)
		{
			swap((*nums)[i], (*nums)[n]);
			BackTrack(n+1);
			swap((*nums)[i], (*nums)[n]);
		}
	}
public:

	vector<vector<int>> permute(vector<int>& nums) {
		resultList.clear();
		this->nums = &nums;
		BackTrack(0);
		return resultList;
	}
};

static auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

int main() {
	Solution s;
	vector<int> nums{ 1,2,3 };
	s.permute(nums);
	return 0;
}