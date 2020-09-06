#ifdef _WIN32
#include"../head.h"
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	void dfs(TreeNode* node, string& encoded) {
		if (!encoded.empty())
			encoded.push_back(',');
		if (!node) {
			encoded += "null";
			return;
		}
		encoded += to_string(node->val);
		dfs(node->left, encoded);
		dfs(node->right, encoded);
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string ans = "";
		dfs(root, ans);
		cout << ans << endl;
		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "null") return nullptr;
		TreeNode* head = nullptr;
		queue<TreeNode*> que;
		string word;
		bool left = true;
		for (auto ch : data) {
			if (ch == ',') {
				if (word != "null") {
					TreeNode* tmp = new TreeNode(stoi(word));
					if (head)
						left ? que.front()->left = tmp : que.front()->right = tmp;
					else
						head = tmp, que.push(tmp);
					que.push(tmp);
					que.push(tmp);
				}
				left = !left;
				que.pop();
				word.clear();
			}
			else
				word.push_back(ch);
		}
		return head;
	}
};

#ifdef _WIN32
int main() {
	Codec code;
	cout << code.deserialize("1,2,null,null,3,4,null,null,5,null,null") << endl;
	return 0;
}
#endif