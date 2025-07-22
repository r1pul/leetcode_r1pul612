class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        auto safe = [&](int& x1, int& y1) {
            return x1 >= 0 && x1 < m && y1 >= 0 && y1 < n;
        };
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        res[0][0] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            int x = node.first;
            int y = node.second;
            for (auto di : dir) {
                int x1 = x + di[0];
                int y1 = y + di[1];
                if (safe(x1, y1)) {
                    int ad = abs(heights[x][y] - heights[x1][y1]);
                    int maxdiff = max(d, ad);
                    if (res[x1][y1] > maxdiff) {
                        res[x1][y1] = maxdiff;
                        pq.push({maxdiff, {x1, y1}});
                    }
                }
            }
        }
        return res[m - 1][n - 1];
    }
};