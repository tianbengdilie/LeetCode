#ifdef _DEBUG
#include"../head.h"
#endif

class Solution {
	enum {
		x,y
	};
	ostringstream sout;
private:
	string GetEquation(const vector<int>& p1, const vector<int>& p2) {
		if (p1[x] == p2[x]) {
			sout.str("");
			sout << p1[x] << "@@";
			return sout.str();
		}
		else {
			int k = (p1[y] - p2[y]) / (p1[x] - p2[x]);
			int b = p1[y] - k * p1[x];
			sout.str("");
			sout << k << "@" << b;
			return sout.str();
		}
	}
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.empty()) return 0;
		int len = points.size();
		unordered_map<string, unordered_set<int>> counts;
		int res = 1;
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; j++){
				string equation = GetEquation(points[i], points[j]);
				cout << equation << endl;
				if (counts.count(equation)) {
					if (counts[equation].count(i) && counts[equation].count(j))
						continue;
					counts[equation].insert(i);
					counts[equation].insert(j);
				}
				else
					counts.insert(make_pair(equation, unordered_set<int>{i, j}));
				res = max(counts[equation].size(), res);
			}
		}
		return res;
	}
};


#ifdef _DEBUG
int main() {
	vector<vector<int>> points{ {3, 10}, {0, 2}, {0, 2}, {3, 10} };
	Solution s;
	cout << s.maxPoints(points) << endl;
	return 0;
}
#endif