// SEARCH A 2D MATRIX
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int rLen = matrix[0].size() - 1;

        while(top <= bottom) {
            int midVert = top + (bottom - top) / 2;
            vector<int> &curRow = matrix[midVert];
            if (target < curRow[0]) {
                bottom = midVert - 1;
            }
            else if(target >= curRow[0] && 
                    target <= curRow[rLen]) {
                int l = 0, r = rLen;
                while(l <= r) {
                    int m = l + (r - l) / 2;
                    if (curRow[m] == target) {
                        return true;
                    }
                    if (curRow[m] > target) {
                        r = m - 1;
                    }
                    else {
                        l = m + 1;
                    }
                }
                return false;
            }
            else {
                top = midVert + 1;
            }
        }
        return false;
    }
};