#include <stdio.h>
#define MAXN 50
#define MAXM 100

int code[10] = { 0x0D, 0x19, 0x13, 0x3D, 0x23, 0x31, 0x2F, 0x3B, 0x37, 0x0B };

char data[MAXN][MAXM + 1];

int main() {

    int test_case;
    int T;
    int N, M;
    int sX, eX, eY;
    int tempNum[8];
    int ansNum[8];

    scanf("%d", &T);

    for (test_case = 1; test_case <= T; test_case++) {

        scanf("%d%d", &N, &M);

        for (int i = 0; i < N; i++) {
            scanf("%s", data[i]);
        }

        for (int i = 0; i < N; i++) {
            for (int j = M - 1; j >= 0; j--) {
                if (data[i][j] == '1') {
                    eY = i;
                    eX = j;
                    goto exit;
                }
            }
        }

    exit: 

        sX = eX - 55;

        int len = 0;
        int num, res;
        for (int i = sX; i <= eX; i += 7) {
            num = 0;
            res = 0;
            for (int j = 0; j < 7; j++) {
                num = data[eY][i + j] - '0';

                num = num << (7 - j - 1);
                res = res | num;
            }

            tempNum[len++] = res;
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                if (tempNum[i] == code[j]) {
                    ansNum[i] = j;
                    break;
                }
            }
        }

        int result = (ansNum[0] + ansNum[2] + ansNum[4] + ansNum[6]) * 3 + ansNum[1] + ansNum[3] + ansNum[5] + ansNum[7];

        int ans = 0; 
        if (result % 10 == 0) {
            for (int i = 0; i < 8; i++) {
                ans += ansNum[i];
            }
        }

        printf("#%d %d\n", test_case, ans);
    }

    return 0;
}

