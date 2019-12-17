#ifdef _DEBUG
#include"../head.h"
#endif

static vector<bool> flags(128);


class Solution {
public:
	int calculate(string s) {
		//È¥µô¿Õ¸ñ
		static unordered_set<char> opera{ '+','-','*','/' };
		int i = 0, left = 0;
		while (i < s.size()) {
			while (i < s.size() && s[i] == ' ')
				++i;
			if (i < s.size())
				s[left++] = s[i++];
		}
		s = s.substr(0, left);
		stack<int> nums;
		stack<char> operas;
		int index = 0;
		while (index < s.size()) {
			if (opera.count(s[index])) {
				if (operas.empty() ||
					(operas.top() == '+' || operas.top() == '-') && (s[index] == '*' || s[index] == '/')) {
					operas.push(s[index]);
				}
				else {
					char cur_opera = operas.top();
					operas.pop();
					int num1 = nums.top(); nums.pop();
					int num2 = nums.top(); nums.pop();
					int result;
					switch (cur_opera) {
					case '+':
						result = num1 + num2;
						break;
					case '-':
						result = num2 - num1;
						break;
					case '*':
						result = num1 * num2;
						break;
					case '/':
						result = num2 / num1;
						break;
					}
					nums.push(result);
				}
				operas.push(s[index]);
				++index;
			}
			else {
				int endIndex = s.find_first_of("+-*/",index+1);
				if (endIndex == -1) 
					endIndex = s.size();
				int tmp_num = stoi(s.substr(index, endIndex - index));
				nums.push(tmp_num);
				index = endIndex;
			}
		}
		while (operas.size()) {
			char cur_opera = operas.top();
			operas.pop();
			int num1 = nums.top(); nums.pop();
			int num2 = nums.top(); nums.pop();
			int result;
			switch (cur_opera) {
			case '+':
				result = num1 + num2;
				break;
			case '-':
				result = num2 - num1;
				break;
			case '*':
				result = num1 * num2;
				break;
			case '/':
				result = num2 / num1;
				break;
			}
			nums.push(result);
		}
		return nums.top();
	}
};
#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.calculate("1+1+1") << endl;
	return 0;
}
#endif