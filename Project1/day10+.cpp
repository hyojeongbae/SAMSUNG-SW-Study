#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int T;
vector<int> _rank;
vector<int> parent;

struct Node {
	int sn;
	int en;
	double dist;
	bool operator < (const Node& o)const {
		return dist > o.dist;
	}
};

void make_set(int N) {
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
		_rank[i] = 0;
	}
}

int find_set(int n) {
	if (parent[n] != n) {
		parent[n] = find_set(parent[n]);
	}
	return parent[n];
}

void union_set(int n, int m) {
	int nP = find_set(n);
	int mP = find_set(m);
	if (nP != mP) {
		if (_rank[nP] < _rank[mP]) {
			parent[nP] = mP;
		}
		else {
			parent[mP] = nP;
			if (_rank[nP] == _rank[mP]) _rank[mP]++;
		}
	}
}

int main(int argc, char** argv)
{
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<int> x(N), y(N);
		double E;

		for (int i = 0; i < N; ++i) {
			cin >> x[i];
		}

		for (int i = 0; i < N; ++i) {
			cin >> y[i];
		}

		cin >> E;

		priority_queue<Node> src;

		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				double dx = x[i] - x[j];
				double dy = y[i] - y[j];
				double dist = (dx * dx) + (dy * dy);
				src.push({ i,j, dist });
			}
		}

		parent.resize(N);
		_rank.resize(N);

		make_set(N);

		double totalCost = 0;

		while (!src.empty()) {
			auto t = src.top(); src.pop();

			if (find_set(t.sn) != find_set(t.en)) {
				union_set(t.sn, t.en);
				totalCost += t.dist;
			}
		}

		long long ans = round(totalCost * E);

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}