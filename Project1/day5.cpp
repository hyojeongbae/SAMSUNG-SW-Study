#include <stdio.h>

#define MAXN 5

using namespace std;

int T;
int count;
int v[MAXN];
int minAns;
int maxAns;
int N;

int findMax(int v[]) {
	int max = 0;
	int idx;
	for (int i = 0; i < N; ++i) {
		if (max < v[i]) {
			max = v[i];
			idx = i;
		}
	}
	return idx;
}

int findMin(int v[]) {
	int min = 5;
	int idx;
	for (int i = 0; i < N; ++i) {
		if (min > v[i]) {
			min = v[i];
			idx = i;
		}
	}
	return idx;
}

int main(int argc, char** argv)
{
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {

		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &v[i]);
		}


		bool isSorted = 0;
		int max;
		int min; // 1 5 3 
		for (int i = 0; i < N - 1; i++) {
			if (v[i] < v[i + 1]) {
				isSorted = true;
				max = v[i + 1];
			}
			else {
				isSorted = false;
				max = v[i];

			}
		}

		int maxIdx = findMax(v);
		int minIdx = findMin(v);
		if (isSorted) {
			minAns = 1;
			maxAns = 1;
		}
		else {  // 3214
			for (int i = 0; i < N; i++) {
				if (maxIdx == 0) {
					maxAns = N;
					if (minIdx = N - 1) {
						minAns = N;
					}
				}
				else if (maxIdx == N - 1) {

				}
				else if ((i == maxIdx) && (maxIdx > minIdx)) {
					maxAns = N - i;
					minAns = 1;
					for (int j = 0; i < maxIdx; ++j) {
						if (v[j] > v[j + maxIdx + 1]) {
							maxAns += 1;
						}
					}
					break;
				}
				else if ((i == maxIdx) && (maxIdx < minIdx)) {
					maxAns = N;
				}
			}
		}

		printf("%d %d\n", minAns, maxAns);
	}

	return 0;
}