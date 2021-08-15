#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    string inp1;
    ll inp2;
    cin >> n;
    map<string, ll> mp;
    // unordered_multimap<string, ll> input_map;
    unordered_map<string, int> mp2;
    vector<pair<string, ll>> input_vec;
    for (ll i = 0; i < n; i++)
    {
        cin >> inp1 >> inp2;
        mp[inp1] += inp2;
        // input_map.insert(pair<string, int>(inp1, inp2));
        input_vec.push_back(make_pair(inp1, inp2));
    }
    ll max_value = INT_MIN;
    for (auto i : mp)
    {
        max_value = max(max_value, i.second);
    }
    // cout << max_value;

    for (auto i : input_vec)
    {
        mp2[i.first] += i.second;
        if (mp2[i.first] >= max_value && mp[i.first] >= max_value)
        {
            cout << i.first;
            break;
        }
    }

    return 0;
}