// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int nums[], int n)
    {
        long long mx = 0;
        long long sum = 0;
        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            long long a = max(nums[0], nums[1]);
            int ans = a;
            if (nums[0] + nums[1] > a)
            {
                ans = nums[0] + nums[1];
            }

            return ans;
        }
        long long mini = *max_element(nums, nums + n);
        if (mini < 0)
        {
            return mini;
        }

        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            if (sum > 0)
            {

                mx = max(sum, mx);
            }
            else
            {
                sum = 0;
            }
        }
        return mx;

        // Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends