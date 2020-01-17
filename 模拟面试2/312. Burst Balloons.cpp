#ifdef _DEBUG
#include"../head.h"
#endif
/*
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。
*/
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

		//dp[i][j] 表示 范围 i ~ j 的气球能戳出来的最大值，记住，两边的气球是不会被戳破的
		//动态规划的状态转换方程式： dp[i][j] = max{ k ∈ (i , j) | dp[i][k] + [k][j] + nums[i] * nums[k] * nums[j]

		for (int len = 2; len < nums.size(); ++len) {  //长度从3开始，下面是 [i, j]，左右闭区间
			for (int i = 0; i < nums.size() - len; ++i) {
				int j = i + len;
				for (int k = i + 1; k < j; ++k) { 
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
				}
			}
		}
		return dp[0][nums.size() - 1];
	}
};
#ifdef _DEBUG
int main() {
	vector<int> nums{ 3,1,5,8 };
	//vector<int> nums{ 2,3,7,9,1 };
	Solution s;
	cout << s.maxCoins(nums) << endl;
	return 0;
}
#endif 