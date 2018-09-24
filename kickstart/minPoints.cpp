#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void dfs(int now, int start, vector<vector<int>> &edges, unordered_set<int> &visit1, unordered_set<int> visit2, unordered_set<int> &result) {
	if (visit2.find(now) != visit2.end())
		return;
	visit2.emplace(now);
	visit1.emplace(now);
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i][0] == now) {
			int next = edges[i][1];
			if (result.find(next) != result.end() && next != start)
				result.erase(next);
			dfs(next, start, edges, visit1, visit2, result);
		}
	}
}

void traverse(vector<vector<int>> &edges) {
	unordered_set<int> points, result, visit1;
	for (auto e : edges) {
		points.emplace(e[0]);
		points.emplace(e[1]);
	}
	for (auto p : points) {
		if (visit1.find(p) == visit1.end()) {
			result.emplace(p);
			unordered_set<int> visit2;
			dfs(p, p, edges, visit1, visit2, result);
		}
	}
	for (auto num : result)
		cout << num << " ";
}

void nomeetings(vector<vector<int>> &meetings) {
	set<pair<int, int>> dict;
	for (auto m : meetings) {
		dict.emplace(m[0], 1);
		dict.emplace(m[1], -1);
	}
	int cnt = 0, start, end;
	bool flag = false;
	for (auto d : dict) {
		cnt += d.second;
		if (cnt == 0) {
			flag = true;
			start = d.first;
		}
		else if (cnt != 0 && flag) {
			end = d.first;
			flag = false;
			cout << "[" << start << "," << end << "] ";
		}
	}
}

void pourWater(vector<int> &height, int p, int x) {
	int n = height.size();
	vector<int> water(n, 0);
	while (x--) {
		int left = p, position = p;
		while (left > 0 && height[left - 1] + water[left - 1] <= height[left] + water[left])
			left--;
		if (height[left] + water[left] < height[p] + water[p])
			position = left;
		else {
			int right = p;
			while (right < n - 1 && height[right + 1] + water[right + 1] <= height[right] + water[right])
				right++;
			if (height[right] + water[right] < height[p] + water[p])
				position = right;
		}
		water[position]++;
	}
	for (auto w : water)
		cout << w << " ";
	cout << endl;
	int maxh = 0;
	for (int i = 0; i < n; i++)
		maxh = max(maxh, height[i] + water[i]);
	for (int h = maxh; h >= 0; h--) {
		for (int i = 0; i < n; i++) {
			if (height[i] >= h)
				cout << "+";
			else if (height[i] + water[i] >= h)
				cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}

void csvPaser(string input) {
	bool flag = false;
	string result = "";
	int i = 0, len = input.size(), state = 0;
	for (; i < len; i++) {
		char c = input[i];
		switch (state) {
		case 0:
			if (c == '"') {
				state = 1;
				continue;
			}
			state = 2;
			break;
		case 1:
			if (c == '"') {
				state = 3;
				continue;
			}
			break;
		case 2:
			if (c == ',') {
				c = '|';
				state = 0;
			}
			break;
		case 3:
			if (c == '"') {
				state = 1;
			}
			else if (c == ',') {
				state = 0;
				c = '|';
			}
			else
				state = 2;
			break;
		}
		result += c;
	}
	cout << result << endl;
}

void wizzard(vector<vector<int>> &input) {

}

long long ipToint(string ip) {
	long long result = 0;
	int i = 0, n = ip.size(), tmp = 0;
	for (; i <= n; i++) {
		if (i == n || ip[i] == '.') {
			result = (result << 8) + tmp;
			tmp = 0;
		}
		else
			tmp = tmp * 10 + ip[i] - '0';
	}
	return result;
}

string intToip(long long ip) {
	string result = to_string((ip >> 24) & 0xff) + "." + to_string((ip >> 16) & 0xff) + "." + to_string((ip >> 8) & 0xff) + "." + to_string(ip & 0xff);
	return result;
}

void ipToCidr(string startIP, string endIP) {
	auto start = ipToint(startIP), end = ipToint(endIP);
	if (start > end)
		return;
	vector<string> result;
	while (start <= end) {
		long long lastbit = start & (-start);
		long long val = min(lastbit, end - start + 1);
		int cnt = 0;
		for (; val != 1; val >>= 1)
			cnt++;
		int mask = 32 - cnt;
		result.emplace_back(intToip(start) + '/' + to_string(mask));
		start += 1 << cnt;
	}
	for (auto s : result)
		cout << s << " ";
	cout << endl;
}

int main() {
	//vector<vector<int>> edges = { {2,9},{3,3},{3,5},{3,7},{4,8},{5,8},{6,6},{7,4},{8,7},{9,3},{9,6} };
	//traverse(edges);
	//vector<vector<int>> meetings = { {1,3},{6,7},{2,4},{2,3},{9,12} };
	//nomeetings(meetings);
	//vector<int> height = { 5,4,2,1,3,2,2,1,0,1,4,3 };
	//pourWater(height, 5, 8);
	/*vector<string> ss = { "John,Smith,john.smith@gmail.com,Los Angeles,1", "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1" , "\"\"\"Alexandra Alex\"\"\"" , "Jane,Roberts,janer@msn.com,\"San Francisco, CA\",0","Jane,Roberts,janer@msn.com,\"\"San Francisco, CA\"\",0\n"  };
	for (auto s : ss) {
		csvPaser(s);
	}*/
	//ipToCidr("255.0.0.7", "255.0.0.16");
	vector<vector<int>> wizzards = { {1, 5, 9}, {2, 3, 9}, {4}, {}, {}, {9}, {}, {}, {}, {} };
	system("pause");
	return 0;
}