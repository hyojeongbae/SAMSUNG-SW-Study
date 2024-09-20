#include<iostream>
#include <vector>
#include<queue>
#include <cmath>
#include<cfloat>

using namespace std;

struct Node {
	int nodeNum;
	double dist;
	bool operator < (const Node& o)const {
		return dist > o.dist;
	}
};

vector<vector<Node>> g;

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		g.clear();
		g.resize(N);

		vector<int> x(N), y(N);
		double E;

		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}

		cin >> E;

		for (int i = 0; i < N - 1; ++i) {
			for (int j = i + 1; j < N; ++j) {
				double dx = x[i] - x[j];
				double dy = y[i] - y[j];
				double dist = (dx * dx) + (dy * dy);
				g[i].push_back({ j, dist });
				g[j].push_back({ i, dist });
			}
		}

		priority_queue<Node> pq;
		vector<double> dist(N, DBL_MAX);
		vector<int> visit(N, 0);
		dist[0] = 0;
		pq.push({ 0, 0 });
		double totalCost = 0;

		while (!pq.empty()) {
			auto t = pq.top(); pq.pop();

			if (visit[t.nodeNum]) continue;

			visit[t.nodeNum] = 1;
			totalCost += t.dist;

			for (auto t2 : g[t.nodeNum]) {
				if (visit[t2.nodeNum]) continue;
				if (dist[t2.nodeNum] > t2.dist) {
					dist[t2.nodeNum] = t2.dist;
					pq.push({ t2.nodeNum, dist[t2.nodeNum] });
				}
			}

		}

		totalCost *= E;
		long long ans = round(totalCost);
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}