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

int getP(int sum1, int sum2, int sum3, vector<int> &b) {
	int count = (sum1 > b[0]) + (sum2 > b[1]) + (sum3 > b[2]);
	return count >= 2;
}

void dfs(vector<int> &b, vector<vector<int>> &per, vector<bool> &visit, int count, int sum, vector<int> tmp) {
	if (count % 3 == 0 && count != 0) {
		tmp.push_back(sum);
		sum = 0;
	}
	if (count == 9) {
		per.push_back(vector<int>(tmp));
		return;
	}
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 8; j++) {
			for (int k = j + 1; k < 9; k++) {
				if (visit[i] == false && visit[j] == false && visit[k] == false) {
					visit[i] = visit[j] = visit[k] = true;
					dfs(b, per, visit, count + 3, b[i] + b[j] + b[k], tmp);
					visit[i] = visit[j] = visit[k] = false;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++) {
		double result = 0;
		int n;
		cin >> n;
		vector<int> a, b;
		for (int i = 0; i < 3 * n; i++) {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 0; i < 3 * n; i++) {
			int tmp;
			cin >> tmp;
			b.push_back(tmp);
		}
		sort(a.begin(), a.end());
		int sum1 = a[0] + a[1] + a[2], sum = 0;
		for (auto num : a)
			sum += num;
		map<pair<int, int>, int> save;
		vector<vector<int>> per;
		vector<bool> visit(9, false);
		vector<int> tmp;
		dfs(b, per, visit, 0, 0, tmp);
		for (int i = 3; i < 7; i++) {
			for (int j = i + 1; j < 8; j++) {
				for (int k = j + 1; k < 9; k++) {
					int sum2 = a[i] + a[j] + a[k], sum3 = sum - sum1 - sum2;
					if (save.count({ sum2, sum3 }))
						continue;
					save[{sum2, sum3}] = 1;
					double tmp = 0;
					for (auto v : per)
						tmp += getP(sum1, sum2, sum3, v);
					result = max(result, tmp / per.size());
				}
			}
		}
		printf("Case #%d: %.9lf\n", _, result);
	}
	//system("pause");
	return 0;
}