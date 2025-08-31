#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

// Helper function for the initial setup
void setupInitialState(const vector<vector<int>>& grid, queue<pair<int, int>>& q, int& freshCount) {
    
    int row = grid.size();
    int col = grid[0].size();
    
    freshCount = 0;
    q = queue<pair<int, int>>();

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            } else if(grid[i][j] == 1) {
                freshCount++;
            }
        }
    }
}

int mainLogic(vector<vector<int>>& grid) {
    queue<pair<int, int>> rotten_q;
    int fresh_count = 0;

    setupInitialState(grid, rotten_q, fresh_count);
    
    if (fresh_count == 0) {
        return 0;
    }
    
    int minutes = 0; 
    int row = grid.size();
    int col = grid[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!rotten_q.empty()) {
        int level_size = rotten_q.size();

        // FIX: Added the missing 'for' loop to process the entire level (all oranges for the current minute)
        for (int i = 0; i < level_size; ++i) {
            pair<int, int> current = rotten_q.front();
            rotten_q.pop();

            for (auto& dir : directions) {
                int new_r = current.first + dir.first;
                int new_c = current.second + dir.second;

                if (new_r >= 0 && new_r < row && new_c >= 0 && new_c < col && grid[new_r][new_c] == 1) {
                    grid[new_r][new_c] = 2;
                    rotten_q.push({new_r, new_c});
                    fresh_count--;
                }
            }
        }
        
        if (!rotten_q.empty()) {
            minutes++;
        }
    }
    return fresh_count == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};

    cout << mainLogic(grid) << endl;
    return 0;
}