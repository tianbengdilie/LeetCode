#include "../head.h"

class LRUCache {
private:
	int cap, cur;
	list<pair<int, int>> datas;
	unordered_map<int, list<pair<int, int>>::iterator> places;
public:
	LRUCache(int capacity) :cap(capacity), places(capacity * 2), cur(0) {

	}

	int get(int key) {
		auto iter = places.find(key);
		if (iter == places.end())return -1;
		datas.push_front(*(iter->second));
		datas.erase(iter->second);
		iter->second = datas.begin();
		return iter->second->second;
	}

	void put(int key, int value) {
		auto iter = places.find(key);
		if (iter != places.end()) {
			datas.push_front(*(iter->second));
			datas.erase(iter->second);
			iter->second = datas.begin();
			iter->second->second = value;
			return;
		}
		if (++cur > cap) {
			--cur;
			places.erase(datas.back().first);
			datas.pop_back();
		}
		datas.push_front(make_pair(key, value));
		places.insert(make_pair(key, datas.begin()));
	}
};