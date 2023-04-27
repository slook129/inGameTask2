#include <iostream>
#include <vector>

std::vector<std::vector<bool> > g;
int n, m;
std::pair<int, int> moves[] = { {1, 0}, {0, 1}, {-1, 0 }, {0, -1} };

bool pos(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && g[x][y];
}

void dfs(int x, int y) {
	g[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int tox = x + moves[i].first;
		int toy = y + moves[i].second;
		if (pos(tox, toy))
			dfs(tox, toy);
	}
}

int main() {
	std::cin >> n >> m;
	n--;//???в примерах из условий 4 строки вместо 5
	g.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool a;
			std::cin >> a;
			g[i].push_back(a);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j]) {
				ans++;
				dfs(i, j);
			}
		}
	}
	std::cout << ans;
}