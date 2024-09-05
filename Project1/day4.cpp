#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case) {
		int N;
		scanf("%d", &N);

		vector<char> datas;
		char d;
		for (int i = 0; i < N; ++i) {
			scanf(" %c", &d);
			datas.push_back(d);
		}

		stack<char> operations;
		vector<char> formula;

		for (char& data : datas) {
			if (data - '0' >= 0 && data - '0' <= 9) {
				formula.emplace_back(data);
			}
			else if (data == '(') {
				operations.push(data);
			}
			else if (data == ')') {
				while (!operations.empty() && operations.top() != '(') {
					formula.emplace_back(operations.top());
					operations.pop();
				}
				operations.pop();
			}
			else {
				while (!operations.empty() &&
					((data == '+' && (operations.top() == '*' || operations.top() == '+')) ||
						(data == '*' && operations.top() == '*'))) {
					formula.emplace_back(operations.top());
					operations.pop();
				}

				operations.push(data);
			}
		}

		while (!operations.empty()) {
			formula.emplace_back(operations.top());
			operations.pop();
		}

		stack<int> calculate;
		for (char& data : formula) {
			if (data - '0' >= 0 && data - '0' <= 9) {
				calculate.push(data - '0');
			}
			else {
				int a = calculate.top(); calculate.pop();
				int b = calculate.top(); calculate.pop();

				if (data == '+') {
					calculate.push(a + b);
				}
				else {
					calculate.push(a * b);
				}
			}
		}
		int ans = calculate.top();


		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}