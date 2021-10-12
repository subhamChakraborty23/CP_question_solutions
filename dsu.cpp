#include <bits/stdc++.h>
using namespace std;

void cpc() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}


class DSU {
private:
	vector<int>parent, size;
public:
	DSU(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);
		}
	}
public:
	void unionDSU(int u, int v) {
		int pu = findParent(u);
		int pv = findParent(v);

		if (pu = pv)return;

		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pu] = size[pv];
		} else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}

	}


public:
	int findParent(int node) {
		if (parent[node] == node) {
			return node;
		}
		//Disjoint union : path compression + size compare:O(log n) -> O(4*Alpha)
		return parent[node] = findParent(parent[node]);
	}

};
//number of Islans 2 LC Hard(305)
//after every query howmany islands are there?
//Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
// Output: [1,1,2,2]
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  00000
//     01000
//     00000
//     00000
// 2.  01000
//     01000
//     00000
//     00000
// 3.  01000
//     01000
//     00000
//     00010
// 4.  01000
//     01000
//     00000
//     00011
vector<int> numIslands2(int n, int m, vector<vector<int>> &positions) {
	// write your code here
	swap(m, n);
	int dx[] = { -1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	DSU dsu(n * m + 1);
	int cnt = 0;
	vector<vector<int>>grid(n, vector<int>(m, 0));
	vector<int>ans;
	for (auto it : positions) {
		int x = it[0], y = it[1];

		if (grid[x][y] == 1) {
			ans.push_back(cnt);
			continue;
		}
		cnt++;

		grid[x][y] = 1;
		//2d to 1d
		int ind1 = x * m + (y + 1);
		for (int dir = 0; dir < 4; dir++) {
			int newx = x + dx[dir];
			int newy = y + dy[dir];

			int ind2 = newx * m + (newy + 1);
			if (newx >= 0 and newy >= 0 and newx < n and newy < m and grid[newx][newy] == 1 and
			        dsu.findParent(ind1) != dsu.findParent(ind2))
			{
				cnt--;
				dsu.unionDSU(ind1, ind2);
			}
		}
		ans.push_back(cnt);

	}
	return ans;
}


void solveQ1() {

	cout << "DSU" << endl;
	// 4 5 4
	// 1 1
	// 0 1
	// 3 3
	// 3 4
	int n, m, p;
	cin >> n >> m >> p;
	vector<vector<int>>pos;
	for (int i = 0; i < p; i++) {
		vector<int>temp(2);
		cin >> temp[0] >> temp[1];
		pos.push_back(temp);
	}
	vector<int>res = numIslands2(n, m, pos);
	for (int n : res) {
		cout << n << " ";
	}
	cout << endl;

}
//Roads not only in berland codeforces D
/*
no of components = n no of new roads = n - 1;
take those roads wich does not break the connection : old roads
take the grand parent of all the components and connect them together
- store extra roads if parent differ while connecting
- find the no of components by using set and parents
- use adjacent unique parent to build new roads

*/
void roadsInBerland() {
	int n, m;
	cin >> n;
	m = n - 1;
	DSU dsu(n + 1);
	vector<pair<int>>extraRoad;
	for (int i = 0; i < m; i++) {
		in u, v;
		cin >> u >> v;
		if (dsu.findParent(u) == dsu.findParent(v)) {
			extraRoad.push_back({u, v});
		} else {
			dsu.unionDSU(u, v);
		}
	}

	set<int>st;
	for (int i = 1; i <= n; i++) {
		st.insert(dsu.findParent(i));
	}
	int x = st.size();
	cout << x - 1 << endl;
	vector<int>vec(st.begin(), st.end());
	int j = 0;
	for (int i = 1; i <= x - 1; i++) {
		cout << extraRoad[j].first << " " << extraRoad[j].second << " " << vec[i] << " " << vec[i - 1] << endl;
		j++;
	}
}

int main() {
	clock_t begin = clock();

	cpc();

	// solveQ1();
	roadsInBerland();

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\n Executed In: " << double(end - begin) << " secs" << endl;
#endif // !ONLINE_JUDGE

	return 0;
}