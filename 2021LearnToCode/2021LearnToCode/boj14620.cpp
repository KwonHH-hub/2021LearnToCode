#include "boj14620.h"
// 같은 줄에 같은 가격이 존재하면 못 찾는 문제가 있음...
// 근데 어차피 주변을 1000인지 확인하고, 아닌 경우에만 선정하는데 문제될게 있나..?
using namespace std;
vector<vector<int>> cost(vector<vector<int>> m, int n) {
	vector<vector<int>>cost(0);
	int sum = 0;
	for (int i = 1; i < n - 1; i++) {
		vector<int>temp;
		for (int j = 1; j < n - 1; j++) {
			sum = 0;
			sum += m[i][j] + m[i + 1][j] + m[i - 1][j] + m[i][j + 1] + m[i][j - 1];
			temp.push_back(sum);
		}
		cost.push_back(temp);
	}
	return cost;
}

int find_appordable(vector<vector<int>> c) {
	vector<int> srt;
	int times = 0;
	int c_idx = 0;
	int result = 0;
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c.size(); j++) {
			srt.push_back(c[i][j]);
		}
	}
	sort(srt.begin(), srt.end());
	for (int s = 0; s < srt.size(); s++) {
		if (times == 3) break;
		for (int i = 0; i < c.size(); i++) {
			if (find(c[i].begin(), c[i].end(), srt[s]) != c[i].end()) {
				c_idx = find(c[i].begin(), c[i].end(), srt[s]) - c[i].begin();
				if (c_idx > 0 && c[i][c_idx - 1] == 1000)continue;
				if (c_idx < c.size() - 1 && c[i][c_idx + 1] == 1000)continue;
				if (i > 0 && c[i - 1][c_idx] == 1000)continue;
				if (i < c.size() - 1 && c[i + 1][c_idx] == 1000)continue;
				else {
					result += srt[s];
					times++;
					//cout << "n = " << srt[srt_idx - 1] << endl;
					c[i][c_idx] = 1000;
					if (c_idx > 0) c[i][c_idx - 1] = 1000;
					if (c_idx < c.size() - 1) c[i][c_idx + 1] = 1000;
					if (i > 0) c[i - 1][c_idx] = 1000;
					if (i < c.size() - 1) c[i + 1][c_idx] = 1000;
				}
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