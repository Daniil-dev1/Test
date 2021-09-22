#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <time.h>

using namespace std;

template <typename T >
class Hashset {
private:
	vector<list<int>> keys;
	size_t max_col = 3;
	size_t max_cap = 100;

public:
	Hashset() {}

	void rehash() {
		vector<int> temp;
		for (int i = 0; i < keys.size(); i++) {
			while (keys[i].size() != 0) {
				temp.push_back(keys[i].front());
				keys[i].pop_front();
			}
		}
		keys.resize(keys.size() + 5);
		for (int i = 0; i < temp.size(); i++){
			insert(temp[i]);
		}
	}

	bool insert(int value) {
		if (keys.capacity() == 0)
			keys.resize(7);
		int h = hash_function(keys.size(), value);
		if (keys[h].size() >= max_col && keys.size() == max_cap) {
			cout << "Set is filled up\n";
			return 0;
		}
		else if (keys[h].size() >= max_col) {
			if (keys.size() == max_cap)
				max_col += 2;
			if (keys.size() + 5 <= max_cap) {
				rehash();
				h = hash_function(keys.size(), value);
				keys[h].remove(value);
				keys[h].push_back(value);
			}
		}
		else{
			keys[h].remove(value);
			keys[h].push_back(value);
		}
		return 1;
	}

	friend ostream& operator << (ostream& os, Hashset& arr) {
		for (int i = 0; i < arr.keys.size(); i++){
			os <<" " << i << " :";
			for (auto tmp : arr.keys[i])
				os << " " << tmp;
			os << endl;
		}
		return os;
	};

	bool find(int value) {
		int h = hash_function(keys.size(), value);
		for (int i = 0; i != keys[h].size(); i++) {
			if (keys[h][i] == value){
				return 1;
			}
		}
		return 0;
	}

	void erase(int value) {
		int h = hash_function(keys.size(), value);
		keys[h].remove(value);
	}

 	int hash_function(int size, int value) {
		if ((value % size) >= 0)
			return (value % size);
		else {
			int k = value % size;
			return (size + value % size);
		}
	}
};