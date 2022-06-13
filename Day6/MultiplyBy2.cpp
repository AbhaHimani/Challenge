class Solution
{
public:
    int findFinalValue(vector<int> &arr, int original)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == original)
            {
                original = original * 2;
            }
        }
        return original;
    }
};