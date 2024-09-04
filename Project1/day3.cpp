#include<stdio.h>
#include<vector>
#include<algorithm>
#include <functional>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		scanf("%d", &N);

		vector<int> prices;
		int price;
		for (int i = 0; i < 2 * N; ++i) {
			scanf("%d", &price);
			prices.push_back(price);
		}

		//100 80 75 70 20 15
		sort(prices.begin(), prices.end(), greater<int>());

		vector<int> discountPrices;
		for (int i = 0; i < prices.size() - 1; i++) {
			for (int j = i + 1; j < prices.size(); j++) {
				if ((int)(prices[i] * 0.75) == prices[j]) {
					discountPrices.push_back(prices[j]);
					prices.erase(prices.begin() + j);
					break;
				}
			}
		}

		sort(discountPrices.begin(), discountPrices.end(), less<int>());

		printf("#%d ", test_case);
		for (int discountPrice : discountPrices) {
			printf("%d ", discountPrice);
		}
	}
	return 0;
}