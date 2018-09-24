#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++) {
		int n, m, p;
		cin >> n >> m >> p;
		vector<bitset<11>> a;
		unordered_set<bitset<11>> save;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			a.push_back(bitset<11>(s));
		}
		for (int i = 0; i < m; i++) {
			cin >> s;
			save.insert(bitset<11>(s));
		}
		int total = INT_MAX, upbound = 1 << p;
		for (int i = 0; i < upbound; i++) {
			auto b = bitset<11>(i);
			if (save.count(b) != 0)
				continue;
			int tmp = 0;
			for (auto x : a) {
				tmp += (x ^ b).count();
			}
			total = min(tmp, total);
		}
		printf("Case #%d: %d\n", _, total);
	}
	//system("pause");
	return 0;
}