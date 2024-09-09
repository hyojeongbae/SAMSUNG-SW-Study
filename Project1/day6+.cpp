#include <stdio.h>

int T;
int N;
int x[10];
int m[10];
double ans[9];


int main(int argc, char** argv)
{
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &x[i]);
		}

		for (int i = 0; i < N; ++i) {
			scanf("%d", &m[i]);
		}

		for (int i = 0; i < N - 1; ++i) {
			double left = x[i];
			double right = x[i + 1];

			while (right - left > 0.000000000001) {
				double l_f = 0.0;
				double r_f = 0.0;
				double mid = (left + right) / 2;
				for (int j = 0; j <= i; ++j) {
					double d = mid - x[j];
					l_f += m[j] / (d * d);
				}
				for (int j = i + 1; j < N; ++j) {
					double d = mid - x[j];
					r_f += m[j] / (d * d);
				}
				if (l_f > r_f) {
					left = mid;
				}
				else {
					right = mid;
				}
			}

			ans[i] = (left + right) / 2;
		}

		printf("#%d ", test_case);

		for (int i = 0; i < N - 1; ++i) {
			printf("%.10f ", ans[i]);
		}
		puts("");
	}

	return 0;
}