#include <iostream>
#include <string>
#include <set>

int T;
int K;

using namespace std;

int main(int argc, char** argv)
{

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		string str;

		cin >> K;
		cin >> str;

		set<string> subStr;
		string ans;

		int len = str.length();
		for (int i = 0; i < len; ++i) {
			for (int j = 1; j <= len - i; ++j) {
				string temp = str.substr(i, j);
				subStr.insert(temp);
			}
		}

		int size = subStr.size();
		if (K > size) {
			ans = "none";
		}
		else {
			auto idx = subStr.begin();
			for (int i = 1; i < K; ++i) {
				++idx;
			}
			ans = *idx;
		}

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}