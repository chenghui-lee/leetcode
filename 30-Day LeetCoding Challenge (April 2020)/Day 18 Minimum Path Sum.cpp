class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
	if (grid.size() == 0){
		return 0;
	}
    int result[grid.size()][grid[0].size()];
	result[0][0] = grid[0][0];
    for (int i = 0; i<grid.size(); i++){
    	for (int j = 0; j < grid[i].size(); j++){
    		if (i > 0 && j > 0){
    			result[i][j] = min(result[i-1][j], result[i][j-1]) + grid[i][j];
    		}else if (j > 0){ // first row
    			result[i][j] = result[i][j-1] + grid[i][j];
    		}else if (i > 0){ // first col
    			result[i][j] = result[i-1][j] + grid[i][j];
    		}
    	}
    }
  
    return result[grid.size()-1][grid[0].size()-1];
}
};
