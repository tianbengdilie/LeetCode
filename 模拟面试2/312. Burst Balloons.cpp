#ifdef _DEBUG
#include"../head.h"
#endif
/*
�� n �����򣬱��Ϊ0 �� n-1��ÿ�������϶�����һ�����֣���Щ���ִ������� nums �С�

����Ҫ����������е�����ÿ�������һ������ i ʱ������Ի�� nums[left] * nums[i] * nums[right] ��Ӳ�ҡ� ����� left �� right ����� i ���ڵ������������š�ע�⵱����������� i ������ left ������ right �ͱ�������ڵ�����

�����ܻ��Ӳ�ҵ����������
*/
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

		//dp[i][j] ��ʾ ��Χ i ~ j �������ܴ����������ֵ����ס�����ߵ������ǲ��ᱻ���Ƶ�
		//��̬�滮��״̬ת������ʽ�� dp[i][j] = max{ k �� (i , j) | dp[i][k] + [k][j] + nums[i] * nums[k] * nums[j]

		for (int len = 2; len < nums.size(); ++len) {  //���ȴ�3��ʼ�������� [i, j]�����ұ�����
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