#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case) {
		int N;
		vector<char> ans;
		scanf("%d", &N);

		vector<char> code;
		char c;
		for (int i = 0; i < N; ++i) {
			scanf(" %c", &c);
			code.push_back(c);
		}

		stack<char> password;

		for (char& cd : code) {
			if (!password.empty() && cd == password.top()) {
				password.pop();
			}
			else {
				password.push(cd);
			}
		}

		while (!password.empty()) {
			ans.emplace_back(password.top());
			password.pop();
		}

		reverse(ans.begin(), ans.end());

		printf("#%d ", test_case);
		for (char& a : ans) {
			printf("%c", a);
		}
		puts("");
	}
	return 0;
}