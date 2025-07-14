#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Coordinate {
    int row;
    int col;
};

vector<Coordinate> getNeighbors(const Coordinate& cell, int rowCount, int columnCount) {
    vector<Coordinate> neighbors;
    if(cell.row > 0)
        neighbors.push_back({ cell.row - 1, cell.col });
    if(cell.row + 1 < rowCount)
        neighbors.push_back({ cell.row + 1, cell.col });
    if(cell.col > 0)
        neighbors.push_back({ cell.row, cell.col - 1 });
    if(cell.col + 1 < columnCount)
        neighbors.push_back({ cell.row, cell.col + 1 });
    return neighbors;
}

void floodFillDFS(const Coordinate& startCell, const vector<vector<int>>& grid, vector<vector<bool>>& visitedCells) {
    int rowCount    = grid.size();
    int columnCount = grid[0].size();

    stack<Coordinate> _;
    _.push(startCell);
    visitedCells[startCell.row][startCell.col] = true;

    while(!_.empty()) {
        Coordinate currentCell = _.top();
        _.pop();

        for(Coordinate neighborCell : getNeighbors(currentCell, rowCount, columnCount)) {
            if(!visitedCells[neighborCell.row][neighborCell.col] && grid[neighborCell.row][neighborCell.col] == 1) {
                visitedCells[neighborCell.row][neighborCell.col] = true;
                _.push(neighborCell);
            }
        }
    }
}

int countIslands(const vector<vector<int>>& grid) {
    int rowCount    = grid.size();
    int columnCount = grid[0].size();
    vector<vector<bool>> visitedCells(rowCount, vector<bool>(columnCount, false));

    int islandCount = 0;
    for(int row = 0; row < rowCount; ++row) {
        for(int col = 0; col < columnCount; ++col) {
            if(!visitedCells[row][col] && grid[row][col] == 1) {
                ++islandCount;
                floodFillDFS({ row, col }, grid, visitedCells);
            }
        }
    }
    return islandCount;
}

int main() {
    vector<vector<int>> grid = {
        { 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 1 }
    };

    cout << "Number of islands (DFS): "
         << countIslands(grid) << "\n";
    return 0;
}
