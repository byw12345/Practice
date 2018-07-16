#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int t, count = 1;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		double result = 0;
		vector<int> value(n);
		for (int i = 0; i < n; i++) {
			cin >> value[n];
		}
		printf("Case #%d: %.6lf", count++, result);
	}
	return 0;
}