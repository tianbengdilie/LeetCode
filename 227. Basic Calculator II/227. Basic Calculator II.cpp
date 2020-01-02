#ifdef _DEBUG
#include"../head.h"
#endif

static vector<bool> flags(128);

class Solution {
public:
	int calculate(string s) {
		stack<int> nums;
		s.push_back('+');
		char sign = '+';
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ') continue;
			int num = 0, tmp;
			while (isdigit(s[i])) {
				num = num * 10 + (s[i++] - '0');
			}

			switch (sign) {
			case '+':
				nums.push(num);
				break;
			case '-':
				nums.push(-num);
				break;
			case '*':
				tmp = nums.top(); nums.pop();
				nums.push(tmp * num);
				break;
			case '/':
				tmp = nums.top(); nums.pop();
				nums.push(tmp / num);
				break;
			}
			sign = s[i];
		}
		int num = 0;
		while (nums.size()) {
			num += nums.top(); nums.pop();
		}
		return num;
	}
};

class Solution11 {
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
		s.push_back('+');
		stack<int> nums;
		stack<char> operas;
		int index = 0;
		while (index < s.size()) {
			if (opera.count(s[index])) {
				while (!(operas.empty() ||
					(s[index] == '*' || s[index] == '/') && (operas.top() == '+' || operas.top() == '-'))){
					int num2 = nums.top(); nums.pop();
					int num1 = nums.top(); nums.pop();
					int result;
					char ope = operas.top(); operas.pop();
					switch (ope)
					{
					case '+':
						result = num1 + num2;
						break;
					case '-':
						result = num1 - num2;
						break;
					case '*':
						result = num1 * num2;
						break;
					case '/':
						result = num1 / num2;
						break;
					default:
						break;
					}
					nums.push(result);
				}
				operas.push(s[index++]);
			}
			else {
				int nextIndex = s.find_first_of("+-*/", index);
				nums.push(stoi(s.substr(index, nextIndex - index)));
				index = nextIndex;
			}
		}
		return nums.top();
	}
};
#ifdef _DEBUG
int main() {
	Solution s;
	cout << s.calculate("1*2-3/4+5*6-7*8+9/10") << endl;
	cout << s.calculate("2*1+1") << endl;
	cout << s.calculate("2/2+2*2") << endl;
	cout << s.calculate("2*2/2+1") << endl;
	cout << s.calculate("2*2/2+1") << endl;
	return 0;
}
#endif