class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n + 1];

        dp[n - 1] = prices[n - 1];
        memset(dp, 0, sizeof(dp));
        int mx = 0;
        int mn = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mn = max(prices[i], mn);

            dp[i] = max(dp[i], mn - prices[i]);
            mx = max(dp[i], mx);
        }
        return mx;
    }
};