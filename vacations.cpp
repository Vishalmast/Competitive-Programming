#include <bits/stdc++.h>

#define ll long long

using namespace std;

// void print_arr(int a[])
// {
//     for (int i = 0; i < a.size(); i++)
//     {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

void print_vec(vector<ll> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

// void print_arr_arr(int a[][])
// {
//     for (int i = 0; i < a.size(); i++)
//     {
//         for (int j = 0; j < a[0].size(); j++)
//         {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    ll temp;
    cin >> n;
    vector<ll> inp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        inp.push_back(temp);
    }
    ll dp[101][2] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (!inp[i - 1])
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else if (inp[i - 1] == 1)
        {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][0];
        }
        else if (inp[i - 1] == 2)
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][0] + 1;
        }
    }

    cout << max(dp[n][0], dp[n][1]);
    return 0;
}