#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	string key;
	int value;
	Node(string key, int value) {
		this->key = key;
		this->value = value;
	}
};

class LRUCache {
public:
	int maxSize;
	list<Node>dll;//doubly linked list
	unordered_map<string, list<Node>::iterator>lookupTable;

	LRUCache(int maxSize) {
		this->maxSize = maxSize > 1 ? maxSize : 1;
	}

	void insertKeyValue(string key, int value) {
		//2 cases:

		if (lookupTable.count(key) != 0) {
			//replace the old value and update
			auto it = lookupTable[key];
			it->value = value;
		}
		else {
			//check if cache is full or not
			//remove the least recently used item from cache
			if (dll.size() == maxSize) {
				Node last = dll.back();
				lookupTable.erase(last.key);
				dll.pop_back();
			}

			Node node(key, value);
			dll.push_front(node);//inserting in the linked list
			lookupTable[key] = dll.begin(); //stores the {key,address} in the hashmap
		}
	}
	int* getValue(string key) {

		if (lookupTable.count(key) != 0) {
			auto it = lookupTable[key];
			int value = it->value;
			dll.push_front(*it);
			dll.erase(it);
			lookupTable[key] = dll.begin();
			return &dll.begin()->value;
		}
		return NULL;
	}

	string mostRecentKey() {
		return dll.front().key;
	}
};

int main() {
	LRUCache lru(3);

	lru.insertKeyValue("mango", 10);
	lru.insertKeyValue("apple", 20);
	lru.insertKeyValue("guava", 30);

	cout << lru.mostRecentKey() << endl;

	lru.insertKeyValue("mango", 40);

	cout << lru.mostRecentKey() << endl;

	int *orders = lru.getValue("mango");
	if (orders != NULL) {
		cout << "orders of Mango " << *orders << endl;
	}

	lru.insertKeyValue("banana", 50);

	if (lru.getValue("apple") == NULL) {
		cout << "apple does not exist.";
	}

	if (lru.getValue("guava") == NULL) {
		cout << "guava does not exist.";
	}

	if (lru.getValue("banana") == NULL) {
		cout << "banana does not exist";
	}
	if (lru.getValue("mango") == NULL) {
		cout << "mango does not exist";
	}

	return 0;
}