#include "../head.h"

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty())  return 0;
		int maxIndex = 0;
		vector<int> water = height;
		for (int i = 1; i < height.size(); ++i) {
			water[i] = max(water[i - 1], height[i]);
			if (height[maxIndex] <= height[i])   //找出最后一个
				maxIndex = i;
		}
		water.back() = height.back();
		for (int i = height.size() - 2; i > maxIndex; --i) {
			water[i] = max(water[i + 1], height[i]);
		}
		int sum = 0;
		for (int i = 0; i < height.size(); ++i) {
			sum += water[i] - height[i];
		}
		return sum;
	}
};