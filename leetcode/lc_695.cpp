#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = static_cast<int>(grid.size());
        int COLS = static_cast<int>(grid[0].size());

        vector<int> verticalMoves{1, 0, -1, 0};
        vector<int> horizontalMoves{0, 1, 0, -1};

        int maxArea = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    deque<pair<int, int>> nextCells;
                    nextCells.push_back({r, c});
                    int localMax = 0;
                    grid[r][c] = 0;

                    while (!nextCells.empty()) {
                        pair<int, int> curNeighbor = nextCells.front();
                        nextCells.pop_front();

                        localMax++;

                        for (int moveInd = 0; moveInd < 4; moveInd++) {

                            int nextY = curNeighbor.first + verticalMoves[moveInd];
                            int nextX = curNeighbor.second + horizontalMoves[moveInd];

                            if (nextY >= 0 && nextY < ROWS && nextX >= 0 && nextX < COLS
                                && grid[nextY][nextX] == 1) {
                                nextCells.push_back({nextY, nextX});
                                grid[nextY][nextX] = 0;
                            }
                        }
                    }
                    maxArea = max(maxArea, localMax);
                }
            }
        }
        return maxArea;
    }
};