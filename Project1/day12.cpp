#include<unordered_map>
#include<string>
#define MAXN 12020
#define MAXD 1000001

using namespace std;

int fenwickT[MAXD];
int parent[MAXN];
int depth[MAXN];
unordered_map<string, int> m;
int idx;

void update(int mDay, int diff) {
	while (mDay <= MAXD) {
		fenwickT[mDay] += diff;
		mDay += (mDay & -mDay);
	}
}

int sum(int mDay) {
	int sum = 0;

	while (mDay) {
		sum += fenwickT[mDay];
		mDay -= (mDay & -mDay);
	}

	return sum;
}

void init(char mAncestor[], int mDeathday)
{
	memset(fenwickT, 0, sizeof(fenwickT));
	memset(parent, 0, sizeof(parent));
	memset(depth, 0, sizeof(depth));
	m.clear();
	idx = 0;

	m[mAncestor] = ++idx;
	parent[1] = 0;
	depth[1] = 0;

	update(1, 1);
	update(mDeathday + 1, -1);

	return;
}

int add(char mName[], char mParent[], int mBirthday, int mDeathday)
{
	int pIdx = m[mParent];
	int myIdx = ++idx;
	m[mName] = myIdx;
	parent[myIdx] = pIdx;
	depth[myIdx] = depth[pIdx] + 1;

	int dist = 0;
	while (parent[myIdx]) {
		++dist;
		myIdx = parent[myIdx];
	}

	update(mBirthday, 1);
	update(mDeathday + 1, -1);

	return dist;
}

int distance(char mName1[], char mName2[])
{
	int dist = 0;
	int idx1 = m[mName1];
	int idx2 = m[mName2];

	while (idx1 != idx2) {
		if (depth[idx1] > depth[idx2]) {
			idx1 = parent[idx1];
		}
		else {
			idx2 = parent[idx2];
		}

		dist++;
	}

	return dist;
}

int count(int mDay)
{
	int cnt = 1;

	if (mDay != 0) {
		cnt = sum(mDay);
	}

	return cnt;
}
