
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
    if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == '1'){
        visited[i-1][j] = true;
        dfs(grid, visited, i-1, j);
    }
    if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == '1'){
        visited[i][j-1] = true;
        dfs(grid, visited, i, j-1);
    }
    if(i + 1 < grid.size() && !visited[i+1][j] && grid[i+1][j] == '1'){
        visited[i+1][j] = true;
        dfs(grid, visited, i+1, j);
    }
    if(j + 1 < grid[0].size() && !visited[i][j+1] && grid[i][j+1] == '1'){
        visited[i][j+1] = true;
        dfs(grid, visited, i, j+1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int result = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                visited[i][j] = true;
                dfs(grid, visited, i, j);
                result++;
            }
            visited[i][j] = true;
        }
    }
    return result;
}

int main() {
    // 11110
    // 11010
    // 11000
    // 00000
    vector<vector<char>> grid(4,vector<char>(5,'0'));
    grid[0][0] = '1';
    grid[0][1] = '1';
    grid[0][2] = '1';
    grid[0][3] = '1';
    grid[1][0] = '1';
    grid[1][1] = '1';
    grid[1][3] = '1';
    grid[2][1] = '1';
    grid[2][2] = '1';
    cout << numIslands(grid) << endl;
    // 11000
    // 11000
    // 00100
    // 00011
    vector<vector<char>> grid1(4,vector<char>(5,'0'));
    grid1[0][0] = '1';
    grid1[0][1] = '1';
    grid1[1][0] = '1';
    grid1[1][1] = '1';
    grid1[2][2] = '1';
    grid1[3][3] = '1';
    grid1[3][4] = '1';
    cout << numIslands(grid1) << endl;
    std::cout << "Hello World!\n";
}