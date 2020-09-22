#ifdef _WIN32
#include"../head.h"
#endif

class Solution {
public:
	int findLatestStep(const vector<int>& arr, int m) {
		if (arr.size() == m) return m;

		// links[i]��ʾ��/��˵���±�
		vector<int> links(arr.size(), -1);
		// counts[i]��ʾ����Ϊi���ж��ٶ�
		vector<int> counts(arr.size() + 1, 0);
		int ans = -1;

		for (int i = 0; i < arr.size(); ++i) {
			int pos = arr[i] - 1;

			// �鿴 pos �����������Ƿ�ɶ�
			// �����������1.���Ҿ��ޣ�2.����ֻ��һ�飬3.���Ҿ��ɶ�
			int left = pos, right = pos;
			if (pos > 0 && links[pos - 1] != -1) {
				//�����
				left = links[pos - 1];
				--counts[pos - left];
			}
			if (pos + 1 < arr.size() && links[pos + 1] != -1) {
				//���ұ�
				right = links[pos + 1];
				--counts[right - pos];
			}
			links[left] = right;
			links[right] = left;

			++counts[right - left + 1];
			if (counts[m])
				ans = i;
		}

		return ans + 1;
	}
};

#ifdef _WIN32
int main() {
	Solution s;

	cout << s.findLatestStep({ 3,5,1,2,4 }, 1) << endl;
	cout << s.findLatestStep({ 1,2,3,4,5 }, 2) << endl;
	return 0;
}
#endif