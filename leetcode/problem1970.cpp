#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < day; ++i) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;
        for (int c = 0; c < col; ++c) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = -1;
            }
        }

        vector<int> directions = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1) return true;

            for (int i = 0; i < 4; ++i) {
                int nr = r + directions[i];
                int nc = c + directions[i + 1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    q.push({nr, nc});
                    grid[nr][nc] = -1;
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCross(row, col, cells, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};