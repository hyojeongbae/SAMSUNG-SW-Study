#include<string>
#include<string.h>
#include<unordered_map>

#define MAXL 11
#define MAXN 50050

using namespace std;

unordered_map<string, int> m;
int parent[MAXN];
int depth[MAXN];
int cnt[MAXN][5];
int idx = 0;

void init(char mRootSpecies[MAXL])
{
	memset(parent, 0, sizeof(parent));
	memset(depth, 0, sizeof(depth));
	memset(cnt, 0, sizeof(cnt));
	m.clear();

	m[mRootSpecies] = ++idx;
	parent[idx] = 0;
	depth[1] = 0;
}

void add(char mSpecies[MAXL], char mParentSpecies[MAXL])
{
	int parentIdx = m[mParentSpecies];
	m[mSpecies] = ++idx;
	parent[idx] = parentIdx;
	depth[idx] = depth[parentIdx] + 1;

	cnt[parentIdx][1]++;

	//cnt 처리 못해서 해결 못했음
	int dist = 1;
	while (dist < 5 && parent[parentIdx]) {
		cnt[parentIdx][dist]++;
		parentIdx = parent[parentIdx];
		dist++;
	}
}

int getDistance(char mSpecies1[MAXL], char mSpecies2[MAXL])
{
	int idx1 = m[mSpecies1];
	int idx2 = m[mSpecies2];
	int dist = 0;

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

//bfs 돌리지 않기
//count배열 미리 만들어서 add될 때 미리 저장해놓기 어차피 최대 거리 4ㅇ니까
int getCount(char mSpecies[MAXL], int mDistance)
{
	int myIdx = m[mSpecies];
	int dist = 0;

	if (mDistance == 1) {
		dist = cnt[myIdx][1];
		if (parent[myIdx]) {
			dist++;
		}
	}
	else if (mDistance == 2) {
		dist = cnt[myIdx][2];
		if (parent[myIdx]) {
			dist += (cnt[parent[myIdx]][1] - 1);
			if (parent[parent[myIdx]]) {
				dist++;
			}
		}
	}
	else if (mDistance == 3) {
		dist = cnt[myIdx][3];
		if (parent[myIdx]) {
			dist += (cnt[parent[myIdx]][2] - cnt[myIdx][1]);
			if (parent[parent[myIdx]]) {
				dist += (cnt[parent[parent[myIdx]]][1] - 1);
				if (parent[parent[parent[myIdx]]]) {
					dist++;
				}
			}
		}
	}
	else if (mDistance == 4) {
		dist = cnt[myIdx][4];
		if (parent[myIdx]) {
			dist += (cnt[parent[myIdx]][3] - cnt[myIdx][2]);		
			if (parent[parent[myIdx]]) {
				dist += (cnt[parent[parent[myIdx]]][2] - cnt[parent[myIdx]][1]);
				if (parent[parent[parent[myIdx]]]) {
					dist += (cnt[parent[parent[parent[myIdx]]]][1] - 1);
					if (parent[parent[parent[parent[myIdx]]]]) {
						dist++;
					}
				}
			}
		}
	}

	return dist;
}