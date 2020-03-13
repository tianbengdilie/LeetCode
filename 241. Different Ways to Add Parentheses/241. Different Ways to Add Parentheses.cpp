#ifdef _DEBUG
#include"../head.h"
#endif

constexpr const char* symbol = "+-*/";

int(*funcs[4])(int lhs, int rhs) = {
	[](int lhs, int rhs) { return lhs + rhs; },
	[](int lhs, int rhs) { return lhs - rhs; },
	[](int lhs, int rhs) { return lhs * rhs; },
	[](int lhs, int rhs) { return lhs / rhs; }
};


class Solution {
public:
	vector<int> diffWaysToCompute(const string& input) {
		if (input.empty())
			return vector<int>();

		int si = input.find_first_of(symbol);
		if (si == string::npos)
		{
			return vector<int>{ stoi(input) };
		}

		vector<int> ans;
		while (si != string::npos)
		{
			vector<int> lhs = diffWaysToCompute(input.substr(0, si));
			vector<int> rhs = diffWaysToCompute(input.substr(si + 1));

			int(*func)(int, int) = nullptr;
			switch (input[si])
			{
			case '+':
				func = funcs[0];
				break;
			case '-':
				func = funcs[1];
				break;
			case '*':
				func = funcs[2];
				break;
			case '/':
				func = funcs[3];
				break;
			}

			for (auto l : lhs)
			{
				for (auto r : rhs)
				{
					ans.push_back(func(l, r));
				}
			}

			si = input.find_first_of(symbol, si + 1);
		}
		return ans;
	}
};

#ifdef _DEBUG
int main() {
	Solution s;
	auto ret = s.diffWaysToCompute("2*3-4*5");
	for (auto r : ret)
		cout << r << " ";
	cout << endl;
	return 0;
}

#endif