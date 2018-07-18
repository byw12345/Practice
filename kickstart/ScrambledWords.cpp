#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

char *s = new char[1000001];
long long int *x = new long long int[1000001];

int main() {
	long long int t, count = 1;
	cin >> t;
	while (t--) {
		int L, N, A, B, C, D;
		memset(s, 0, sizeof(s));
		memset(x, 0, sizeof(x));
		vector<string> dict;
		cin >> L;
		for (long long int i = 0; i < L; i++) {
			string tmp;
			cin >> tmp;
			dict.push_back(tmp);
		}
		cin >> s[0] >> s[1] >> N >> A >> B >> C >> D;
		x[0] = (long long int)s[0];
		x[1] = (long long int)s[1];
		for (long long int i = 2; i < N; i++) {
			x[i] = (A * x[i - 1] + B * x[i - 2] + C) % D;
			s[i] = char(97 + x[i] % 26);
		}
		long long int result = 0;
		for (long long int i = 0; i < dict.size(); i++) {
			long long int hashcode1 = 0;
			for (long long int k = 1; k < dict[i].size() - 1; k++)
				hashcode1 ^= dict[i][k];
			for (long long int j = 0; j < N - dict[i].size(); j++) {
				if (s[j] != dict[i][0] || s[j + dict[i].size() - 1] != dict[i][dict[i].size() - 1])
					continue;
				long long int hashcode2 = 0;
				for (long long int k = 1; k < dict[i].size() - 1; k++)
					hashcode2 ^= s[j + k];
				if (hashcode1 == hashcode2) {
					result++;
					break;
				}
			}
		}
		printf("Case #%lld: %I64d\n", count++, result);
	}
	return 0;
}