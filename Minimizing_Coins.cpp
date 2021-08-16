// cses

#include <bits/stdc++.h>

#define ll long long int
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
    ll n;
    ll target;
    cin >> n >> target;
    ll temp;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    // vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, INT_MAX));
    vector<ll> dp(target + 1, INT_MAX);
    // for (ll i = 0; i < n + 1; i++)
    // {
    //     dp[i][0] = 0;
    // }
    dp[0] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < target + 1; j++)
        {
            // dp[i][j] = dp[i - 1][j];
            if (j - v[i - 1] >= 0 and dp[j - v[i - 1]] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - v[i - 1]] + 1);
            }
        }
    }
    if (dp[target] == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << dp[target];
    }

    return 0;
}