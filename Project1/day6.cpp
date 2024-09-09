#include <stdio.h>

int T;
double mA;
double mB;
int N = 18;
double ans;
int primeNum[] = { 2, 3, 5, 7, 11, 13, 17 };

long long combination(int n, int k) {
	if (k == 0 || k == n)
		return 1;
	return combination(n - 1, k - 1) + combination(n - 1, k);
}

double square(double p, int n) {
	double ap = 1.0;
	for (int i = 0; i < n; ++i) {
		ap *= p;
	}
	return ap;
}

int main(int argc, char** argv)
{
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {
		scanf("%lf%lf", &mA, &mB);

		mA /= 100;
		mB /= 100;

		double mAp = 0.0;
		double mBp = 0.0;

		for (int i = 0; i < 7; ++i) {
			mAp += combination(N, primeNum[i]) * square(mA, primeNum[i]) * square(1 - mA, N - primeNum[i]);
			mBp += combination(N, primeNum[i]) * square(mB, primeNum[i]) * square(1 - mB, N - primeNum[i]);
		}

		ans = mAp * mBp + (1 - mAp) * mBp + mAp * (1 - mBp);

		printf("#%d %.6f\n", test_case, ans);
	}

	return 0;
}