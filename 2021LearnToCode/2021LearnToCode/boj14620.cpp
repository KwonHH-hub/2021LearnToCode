#include "boj14620.h"
// 같은 줄에 같은 가격이 존재하면 못 찾는 문제가 있음...
// 근데 어차피 주변을 1000인지 확인하고, 아닌 경우에만 선정하는데 문제될게 있나..?
using namespace std;
vector<vector<int>> cost(vector<vector<int>> m, int n) {
	vector<vector<int>>cost;
	vector<int>temp1;
	for (int i = 0; i < n; i++) {
		temp1.push_back(0);
	}
	cost.push_back(temp1);
	int sum = 0;
	for (int i = 1; i < n - 1; i++) {
		vector<int>temp2;
		for (int j = 0; j < n - 1; j++) {
			if (j == 0) {
				temp2.push_back(0);
				continue;
			}
			sum = 0;
			sum += m[i][j] + m[i + 1][j] + m[i - 1][j] + m[i][j + 1] + m[i][j - 1];
			temp2.push_back(sum);
		}
		temp2.push_back(0);
		cost.push_back(temp2);
	}
	cost.push_back(temp1);
	return cost;
}

int find_appordable(vector<vector<int>> c) {
	vector<int> srt;
	int times = 0;
	int c_idx = 0;
	int result = 0;
	for (int i = 1; i < c.size() - 1; i++) {
		for (int j = 1; j < c.size() - 1; j++) {
			srt.push_back(c[i][j]);
		}
	}
	sort(srt.begin(), srt.end());

	for (int i = 1; i < c.size() - 1; i++) {
		if (times == 3) break;
		if (find(c[i].begin(), c[i].end(), srt[times]) != c[i].end()) {
			c_idx = find(c[i].begin(), c[i].end(), srt[times]) - c[i].begin();
			if (c[i][c_idx - 1] == 1500) continue;
			if (c[i][c_idx + 1] == 1500) continue;
			if (c[i - 1][c_idx] == 1500) continue;
			if (c[i + 1][c_idx] == 1500) continue;
			else {
				result += srt[times];
				times++;

				c[i][c_idx] = 1500;
				c[i][c_idx - 1] = 1500;
				c[i][c_idx + 1] = 1500;
				c[i - 1][c_idx] = 1500;
				c[i + 1][c_idx] = 1500;
			}
		}
	}
	return result;
}
void run14620() {
	int n = 0;
	int temp = 0;
	int result = 0;
	vector<vector<int>> m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int>tmp;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			tmp.push_back(temp);
		}
		m.push_back(tmp);
	}
	vector<vector<int>>c = cost(m, n);
	result = find_appordable(c);

	cout << result;
}

