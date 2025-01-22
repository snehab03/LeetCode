// 2017. Grid Game
// Link: https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21
// The problem involves two robots, Robot1 and Robot2, navigating through a 2D grid. Robot1 moves first and selects a column in the grid, 
// while Robot2 moves afterward and tries to minimize the remaining sum in the second row of the grid. The goal is to minimize the sum that 
// Robot2 has to deal with after Robot1 has made its move.

// Thought Process:

// Initial Setup: The sum of all elements in the first row (firstRowRemainSum) is calculated at the start. This helps track the remaining sum 
// for Robot1's strategy.
// Iterative Strategy: For each column, Robot1 "takes" that column by subtracting the value from firstRowRemainSum. This simulates Robot1's 
//   choice.
// Robot2's Best Response: After Robot1's choice, Robot2 attempts to minimize the remaining sum in the second row by selecting the best 
// possible outcome (max between remaining sums of the first and second rows).
// Tracking the Minimum: The goal is to track the minimum possible sum for Robot2 by updating minimizedRobot2Sum at each step.
// Approach:

// Accumulation: The sum of the first row is accumulated at the start, and then progressively updated as Robot1 moves.
// Max/Min Operations: For each column, the maximum of the remaining sum of the first row and the accumulated sum of the second row is 
// calculated, and the minimum of these values is tracked.
// Efficiency: The algorithm processes each column once, resulting in a time complexity of O(col), where col is the number of columns in 
the grid.
  
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long remainSumRow1 = accumulate(begin(grid[0]), end(grid[0]), 0LL);

        long long remainSumRow2 = 0;
        long long minimizedRobo2Sum = LONG_LONG_MAX;
        for(int col=0;col<grid[0].size();col++){
            remainSumRow1 -= grid[0][col];
            long long bestMaxForRobo2 = max(remainSumRow1,remainSumRow2);
            minimizedRobo2Sum = min(minimizedRobo2Sum, bestMaxForRobo2);
            remainSumRow2 += grid[1][col];
        }
        return minimizedRobo2Sum;
    }
};
