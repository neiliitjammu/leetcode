class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int k = 0;
        int row = 0;
        int column = grid[0].size() - 1;
        while(row < grid.size() and column >= 0)
        {
            if(grid[row][column] < 0)
            {
              k += grid.size() - row;
              column--;
            }
            else
            {
                row++;
            }
        }
        return k;
    }
};