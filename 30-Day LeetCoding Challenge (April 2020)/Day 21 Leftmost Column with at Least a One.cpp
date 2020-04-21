/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int result = 1000;
        int i = binaryMatrix.dimensions()[0];
        int j = binaryMatrix.dimensions()[1];
        int col = j-1, row = 0;
        while (true){
            if (row>=i || col<0){
                break;
            }
            int tmp = binaryMatrix.get(row,col);            
            if (tmp == 1){
                result = min(result, col);
                col--;                
            }else{ // if zero
                row++;
            }
        }
        if (result >= j){
            return -1;
        }
        
        return result;
    }
};
