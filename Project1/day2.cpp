#include <stdio.h>

const int MOD = 1000000007;
const int MAXN = 100000;

bool is_prime[MAXN + 1];
int primes[MAXN];
int prime_count = 0;

void getPrime() {
    for (int i = 0; i <= MAXN; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
            primes[prime_count++] = i;
            for (int j = 2 * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int countFact(int n, int p) {
    int count = 0;
    while (n > 0) {
        n /= p;
        count += n;
    }
    return count;
}

int calculatePrimeCountInCombination(int n, int k, int p) {
    return countFact(n, p) - countFact(k, p) - countFact(n - k, p);
}

int main(void) {
    int test_case;
    int T;

    setbuf(stdout, NULL);
    scanf("%d", &T);

    getPrime();

    for (test_case = 1; test_case <= T; ++test_case) {
        int n, k;
        scanf("%d%d", &n, &k);

        int ans = 1;

        if (k == 0 || k == n) {
            printf("#%d %d\n", test_case, ans);
            continue;
        }

        for (int i = 0; i < prime_count; i++) {
            int p = primes[i];
            if (p > n) {
                break;
            }

            int count = calculatePrimeCountInCombination(n, k, p);
            ans = (int)(1LL * ans * (count + 1) % MOD);
        }

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}