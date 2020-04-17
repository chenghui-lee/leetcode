class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    for (int i = 0; i<grid.size(); i++){
    	for (int j = 0; j<grid[i].size(); j++){
    		if (grid[i][j] == '1'){
    			result++;
    			islandSearch(grid, i , j);
    		}
    	}
    }
    return result;
}
    void islandSearch(vector<vector<char>> &grid, int i, int j){
	if (i < 0 || j < 0 || i >=grid.size() || j>=grid[i].size() || grid[i][j] == '0'){
		return;
	}
	grid[i][j] = '0';
	islandSearch(grid, i+1, j); // up
	islandSearch(grid, i-1, j); // down
	islandSearch(grid, i, j+1); // right
	islandSearch(grid, i, j-1); // left

}
};
