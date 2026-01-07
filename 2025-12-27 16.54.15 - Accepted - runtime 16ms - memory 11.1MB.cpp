class Solution {
    public:
        int minDifficulty(vector<int>& jobDifficulty, int d) {
                int n = jobDifficulty.size();
                        if (n < d) return -1;
                                vector<vector<int>> dp(d + 1, vector<int>(n + 1, 1e9));
                                        dp[0][0] = 0;
                                                for (int day = 1; day <= d; day++) {
                                                            for (int i = day; i <= n; i++) {
                                                                            int maxD = 0;
                                                                                            for (int j = i; j >= day; j--) {
                                                                                                                maxD = max(maxD, jobDifficulty[j - 1]);
                                                                                                                                    dp[day][i] = min(dp[day][i], dp[day - 1][j - 1] + maxD);
                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                                        }
                                                                                                                                                                                return dp[d][n];
                                                                                                                                                                                    }
                                                                                                                                                                                    };