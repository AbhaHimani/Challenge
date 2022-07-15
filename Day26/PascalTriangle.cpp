class Solution
{
public:
    vector<int> helper(vector<int> m)
    {
        vector<int> x;
        x.push_back(1);
        for (int j = 0; j < m.size() - 1; j++)
        {
            x.push_back(m[j] + m[j + 1]);
        }
        x.push_back(1);
        return x;
    }

    vector<vector<int>> generate(int numRows)
    {
        int n = numRows;
        vector<vector<int>> ans;
        vector<int> m;
        m.push_back(1);
        ans.push_back(m);
        if (n == 1)
        {
            return ans;
        }
        ans.push_back({1, 1});
        if (n == 2)
        {
            return ans;
        }

        for (int i = 2; i < n; i++)
        {
            int o = ans.size();
            vector<int> p = helper(ans[o - 1]);
            ans.push_back(p);
        }
        return ans;
    }
};