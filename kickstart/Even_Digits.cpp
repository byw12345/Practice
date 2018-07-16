#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> GetSepNum(long long int n) {
	vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	return digits;
}

int main() {
	int t, count = 1;
	cin >> t;
	while (t--) {
		long long int n, result = 0;
		cin >> n;
		vector<int> sepNum = GetSepNum(n);
		long long int cur = 0, base = 1;
		for (int i = 0; i < sepNum.size(); i++) {
			cur = sepNum[i] * base + cur;
			base *= 10;
			if (sepNum[i] % 2 != 0) {
				long long int lower = sepNum[i] - 1, upper = 0;
				if (sepNum[i] < 9) {
					upper = (sepNum[i] + 1) * pow(10, i);
				}
				int j = i - 1;
				for (; j >= 0; j--)
					lower = lower * 10 + 8;
				result = upper == 0 ? cur - lower : min(upper - cur, cur - lower);
			}
		}
		printf("Case #%lld: %lld\n", count++, result);
	}

	return 0;
}