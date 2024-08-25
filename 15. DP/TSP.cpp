#include <iostream>
#include <vector>
using namespace std;

int n = 4;
// vector<vector<int>> dist(10, vector<int>(10));
int dist[4][4] = {{0, 20, 42, 25},
                  {20, 0, 30, 34},
                  {42, 30, 0, 10},
                  {25, 34, 10, 0}};

int VISITED_ALL = (1 << n) - 1;

vector<vector<int>> dp(n, vector<int>(pow(2, n), -1));

int tsp(int pos, int mask)
{
    if (mask == VISITED_ALL)
        return dist[pos][0];
    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = 1e8;

    // visit unvisited cities
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city));
            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}

int main()
{

    cout << tsp(0, 1);

    return 0;
}