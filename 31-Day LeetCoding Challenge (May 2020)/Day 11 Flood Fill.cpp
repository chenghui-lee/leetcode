class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc]) return image; // if the image is same as the new color, we dont have to do anything with the image 
        paint(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void paint(vector<vector<int>>& grid,  int sr, int sc, int ori, int newColor){
        if (sr < 0 || sr >= grid.size() || sc <0 || sc >= grid[0].size()){
            return;
        }
        if (grid[sr][sc] == ori){
            grid[sr][sc] = newColor;
        }else{
            return;
        }

        paint(grid, sr,sc-1,ori,newColor); 
        paint(grid, sr, sc+1,ori,newColor); 
        paint(grid, sr+1,sc,ori,newColor);
        paint(grid, sr-1,sc,ori,newColor);


    }
};
