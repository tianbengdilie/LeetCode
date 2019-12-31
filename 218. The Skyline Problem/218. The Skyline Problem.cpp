#ifdef _DEBUG
#include"../head.h"
#endif

//class Solution {
//public:
//	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//		multiset<pair<int, int>> all;
//		vector<vector<int>> ret;
//		for (auto& b : buildings) {
//			all.insert(make_pair(b[0], -b[2]));
//			all.insert(make_pair(b[1], b[2]));
//		}
//
//		multiset<int> heights{ 0 };
//		for (auto& a : all) {
//			if (a.second >= 0) heights.erase(heights.find(a.second));
//			else heights.insert(-a.second);
//
//			int maxHeight = *heights.rbegin();
//
//			if (ret.empty() || maxHeight != ret.back()[1]) {
//				ret.push_back(vector<int>{a.first, maxHeight});
//			}
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<vector<int>>> skylines;
		for (auto& building : buildings) {
			vector<vector<int>> tmp;
			tmp.push_back(vector<int>{building[0], building[2]});
			tmp.push_back(vector<int>{building[1], 0});
			skylines.push_back(move(tmp));
		}
		return Divide(skylines, 0, skylines.size() - 1);
	}

	vector<vector<int>> Divide(const vector<vector<vector<int>>>& skylines, int left, int right) {
		if (left > right) {
			return vector<vector<int>>();
		}
		if (left == right) { //只剩一个了
			return skylines[left];
		}
		else if (left + 1 == right) {//只剩两个
			return Merge(skylines[left], skylines[right]);
		}
		else {
			int mid = (left + right) / 2;
			return Merge(Divide(skylines, left, mid), Divide(skylines, mid + 1, right));
		}
	}

	vector<vector<int>> Merge(const vector<vector<int>>& left, const vector<vector<int>>& right) {
		int curY = 0, leftY = 0, rightY = 0;
		int nL = left.size(), nR = right.size(), pL = 0, pR = 0;
		vector<vector<int>> ret;
		while (pL < nL && pR < nR) {
			int x;
			if (left[pL][0] < right[pR][0]) {
				x = left[pL][0];
				leftY = left[pL++][1];
			}
			else if(left[pL][0] == right[pR][0]) {
				x = left[pL][0];
				leftY = left[pL++][1];
				rightY = right[pR++][1];
			}
			else {
				x = right[pR][0];
				rightY = right[pR++][1];
			}
			int maxY = max(leftY, rightY);
			if (maxY != curY) {
				curY = maxY;
				ret.push_back(vector<int>{x, curY});
			}
		}
		ret.insert(ret.end(), left.begin() + pL, left.end());
		ret.insert(ret.end(), right.begin() + pR, right.end());
		return ret;
	}
};

#ifdef _DEBUG
int main() {
	vector<vector<int>> buildings{{3, 7, 8}, {3, 8, 7}, {3, 9, 6}, {3, 10, 5}, {3, 11, 4}, {3, 12, 3}, {3, 13, 2}, {3, 14, 1}};
	Solution s;
	auto ret = s.getSkyline(buildings);
	for (auto row : ret) {
		for (auto cell : row)
			cout << cell << " ";
		cout << endl;
	}
	return 0;
}
#endif