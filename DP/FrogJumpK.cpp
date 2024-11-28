#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    // Base case: If we are at the beginning (index 0), no cost is needed.
    if (ind == 0) return 0;
    
    // If the result for this index has been previously calculated, return it.
    if (dp[ind] != -1) return dp[ind];
    
    int mmSteps = INT_MAX;
    
    // Loop to try all possible jumps from '1' to 'k'
    for (int j = 1; j <= k; j++) {
        // Ensure that we do not jump beyond the beginning of the array
        if (ind - j >= 0) {
            // Calculate the cost for this jump and update mmSteps with the minimum cost
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    
    // Store the result in the dp array and return it
    return dp[ind] = mmSteps;
}

int minCostToReachEnd(vector<int>& height, int k) {
    int n = height.size();
    vector<int> dp(n, -1);
    return solveUtil(n - 1, height, dp, k);
}

int main() {
    vector<int> height = {10, 30, 40, 50, 20};
    int k = 3;
    cout << "Minimum cost to reach the end: " << minCostToReachEnd(height, k) << endl;
    return 0;
}
