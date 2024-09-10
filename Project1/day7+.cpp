#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int T;
int K;

using namespace std;

int calLCP(const string& str1, const string& str2) {
	int minLen = min(str1.length(), str2.length());
	int i;
	for (i = 0; i < minLen; ++i) {
		if (str1[i] != str2[i]) {
			return i;
		}
	}
	return minLen;
}

int main(int argc, char** argv)
{

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		string str;

		cin >> K >> str;

		vector<string> subStr;
		string ans = "none";

		int len = str.length();
		for (int i = 0; i < len; ++i) {
			subStr.emplace_back(str.substr(i, len - i));
		}
		sort(subStr.begin(), subStr.end());

		int count = 0;
		string prev = "";

		int size = subStr.size();
		for (int i = 0; i < size; ++i) {
			if (i > 0) {
				int lcp = calLCP(prev, subStr[i]);
				count += (subStr[i].length() - lcp);
			}
			else {
				count += subStr[i].length();
			}

			if (count >= K) {
				ans = subStr[i].substr(0, subStr[i].length() - (count - K));
				break;
			}

			prev = subStr[i];
		}

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}