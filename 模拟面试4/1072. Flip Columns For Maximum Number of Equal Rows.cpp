#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		map<vector<int>, int> counts;
		int ans = 0;
		for (const auto& row : matrix) {
			vector<int> tmp;
			for (int i = 0; i < row.size(); ++i) {
				if(row[i] == 0)
				tmp.push_back(i);
			}
			ans = max(ans, ++counts[tmp]);
		}
		return ans;
	}
};
#ifdef _DEBUG
int main() {
	Solution s;
	return 0;
}
#endif