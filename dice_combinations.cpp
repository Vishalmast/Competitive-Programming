// cses

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i > a; i--)
#define mod 1000000007

using namespace std;

void print_arr(ll *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ll dp[1000002];
    int n;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j > 0)
                dp[i] += dp[i - j];
            if (i == j)
                dp[i]++;
            dp[i] %= mod;
        }
    }

    cout << dp[n];
    return 0;
}
