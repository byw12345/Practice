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

using namespace std;

int main() {
	long long t;
	cin >> t;
	for (long long _ = 1; _ <= t; _++) {
		long long result = 0, n, k;
		cin >> n >> k;
		vector<long long> a(n, 0);
		map<long long, long long> dict;
		for (long long i = 0; i < n; i++) {
			cin >> a[i];
			dict[a[i]]++;
		}
		long long total = 0;
		for (auto p : dict) {
			long long tmp = k * p.first;
			if (tmp - total <= p.second)
				total = tmp;
			else
				total += p.second;
		}
		printf("Case #%d: %d\n", _, total);
	}
	return 0;
}