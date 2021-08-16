// cses

#include <bits/stdc++.h>

#define ll long long
#define ld long double
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

void print(vector<vector<ll>> v)
{
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print(vector<ll> v)
{
    for (auto i : v)
    {
        cout << i << " ";
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

    // Your code here
    ll n, target;
    cin >> n >> target;
    vector<ll> coins(n);
    vector<ll> dp(target + 1, 0);

    for (ll &i : coins)
    {
        cin >> i;
    }

    dp[0] = 1;
    for (int j = 1; j < target + 1; j++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (j - coins[i - 1] >= 0)
            {
                (dp[j] += dp[j - coins[i - 1]]) %= mod;
            }
        }
        // print(dp);
    }
    // print(dp);
    cout << dp[target];
    return 0;
}