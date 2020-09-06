#pragma once
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <ctime>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <Windows.h>
//#include <semaphore.h>  这个是linux的
#include <cmath>
#include <mutex>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

void printFoo();
void printBar();