class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};
        deque<pair<int, int>> dq;
        visited[0][0] = 0;
        dq.push_front({0, 0});
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int i = 0; i < 4; i++) {
                int x_ = dx[i] + x;
                int y_ = dy[i] + y;
                if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m)
                    continue;

                int cost = (grid[x][y] == i + 1) ? 0 : 1;

                if (visited[x][y] + cost < visited[x_][y_]) {
                    visited[x_][y_] = visited[x][y] + cost;
                    if (cost == 0)
                        dq.push_front({x_, y_});
                    else
                        dq.push_back({x_, y_});
                }
            }
        }
        return visited[n - 1][m - 1];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
