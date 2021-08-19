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
    int n;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        string temp;
        temp = to_string(i);
        ll max_ele = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            max_ele = max(max_ele, (ll)temp[j] - '0');
        }
        dp[i] = dp[i - max_ele] + 1;
    }
    // print(dp);
    cout << dp[n];
    return 0;
}