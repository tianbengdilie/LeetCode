#include "../head.h"

class Solution1 {
	int largestRectangleArea(vector<int>::iterator beg, vector<int>::iterator end) {
		if (beg == end)	return 0;
		auto minIter = min_element<decltype(beg)>(beg, end);
		return max(largestRectangleArea(beg, minIter), max(largestRectangleArea(minIter + 1, end), *minIter * (end-beg)));
	}
public:
	int largestRectangleArea(vector<int>& heights) {
		return largestRectangleArea(heights.begin(), heights.end());
	}
};

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> s;
		s.push(-1);
		int maxSq = -1;
		for (int i = 0; i < heights.size(); i++) {
			while (s.top() != -1 && heights[s.top()] > heights[i]) {
				int t = s.top();
				s.pop();
				maxSq = max(maxSq, (i - s.top() - 1) * heights[t]);
			}
			s.push(i);
		}
		while (s.top() != -1) {
			int t = s.top();
			s.pop();
			maxSq = max<int>(maxSq, (heights.size() - s.top() - 1) * heights[t]);
		}
		return maxSq;
	}
};

int main() {
	Solution s;
	vector<int> nums{2,1,5,6,2,3};
	auto ans = s.largestRectangleArea(nums);
	return 0;
}