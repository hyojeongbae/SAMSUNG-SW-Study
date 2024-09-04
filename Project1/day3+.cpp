#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>

const int MAXA = 100000000;

using namespace std;

int main(int argc, char** argv) {

	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int K;
		scanf("%d %d", &N, &K);

		vector<int> counts;
		int count;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &count);
			counts.push_back(count);
		}

		sort(counts.begin(), counts.end(), less<int>());

		int ans = 0;
		int len = counts.size();
		if (K == counts.size()) {
			ans = counts[len - 1] - counts[0];
		}
		else {
			int min_diff = counts[K - 1] - counts[0];
			for (int i = 1; i < N - K + 1; i++) {
				int temp = counts[i + K - 1] - counts[i];
				if (temp < min_diff) {
					min_diff = temp;
				}
			}
			ans = min_diff;
		}

		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}