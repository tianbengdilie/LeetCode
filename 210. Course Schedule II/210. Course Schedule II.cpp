#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> counts(numCourses, 0), result;
		vector<vector<int>> sati(numCourses);
		//calc
		for (const auto& pre : prerequisites) {
			counts[pre[0]]++;
			sati[pre[1]].push_back(pre[0]);
		}
		for (int i = 0; i < numCourses; ++i) if (!counts[i]) result.push_back(i);
		for (int i = 0; i < result.size(); ++i) {
			for (auto& adj : sati[result[i]]) {
				if (!--counts[adj])
					result.push_back(adj);
			}
		}
		return result.size() != numCourses ? vector<int>() : result;
	}
};
#ifdef _DEBUG
int main() {
	Solution s;
	return 0;
}
#endif