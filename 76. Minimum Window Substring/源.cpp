#include "../head.h"
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> counts(128, 0);
		for (char ch : t) counts[ch]++;
		int minLen = INT32_MAX, minLeft = -1, right = 0, left = 0, count = 0;
		while (right < s.size()) {
			if (--counts[s[right++]] >= 0) {
				++count;
			}
			while (count == t.size()) {
				if (minLen > right - left) {
					minLen = right - left;
					minLeft = left;
				}
				if (++counts[s[left++]] > 0) {
					--count;
				}
			}
		}
		return (minLeft == -1) ? "" : s.substr(minLeft, minLen);
	}
};
class Solution1 {
	bool fit(const unordered_map<char, int>& need, const vector<int>& has) {
		for (const auto& p : need) {
			if (has[p.first] < p.second)
				return false;
		}
		return true;
	}
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> need(128);
		vector<int> has(128, 0);
		int left = 0, right = 0, minLen = INT32_MAX, head = -1;
		for (char c : t) need[c]++;
		while (right < s.size()) {
			has[s[right++]]++;
			while (fit(need, has)) {
				if (minLen > right - left) {
					minLen = right - left;
					head = left;
				}
				has[s[left++]]--;
			}
		}
		return minLen == INT32_MAX ? "" : s.substr(head, minLen);
	}
};

int main() {
	Solution s;
	auto str = s.minWindow("ab", "a");
	str = s.minWindow("ADOBECODEBANC", "ABC");
	return 0;
}