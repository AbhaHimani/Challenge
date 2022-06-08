// } Driver Code Ends

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> span;
        stack<int> s;
        s.push(0);
        span.push_back(1);

        for (int i = 1; i <= n - 1; i++)
        {
            int current_price = price[i];
            while (!s.empty() and price[s.top()] <= current_price)
            {
                s.pop();
            }

            if (!s.empty())
            {
                int prev_highest = s.top();
                span.push_back(i - prev_highest);
            }
            else
            {
                span.push_back(i + 1);
            }
            s.push(i);
        }
        return span;
        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends