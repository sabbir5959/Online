//bunch and bound

#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int weight;
    int value;
};

class Node
{
public:
    int level;
    int profit;
    int ub;
    int weight;
};

bool custom(Item u, Item v)
{
    float a = (float)u.value / (float)u.weight;
    float b = (float)v.value / (float)v.weight;
    return a > b;
}

int knapsack(int W, Item a[], int n)
{
    sort(a, a + n, custom);

    queue<Node> q;
    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.ub = 0;
    q.push(u);

    int value = 0;

    while (!q.empty())
    {
        u = q.front();
        q.pop();
        ///out of bound hoya theke rokkha
        if (u.level == n - 1)
            continue;
        ///object nile
        v.level = u.level + 1;
        v.weight = u.weight + a[v.level].weight;
        v.profit = u.profit + a[v.level].value;
        ///profit update kortesi
        if (v.weight <= W && v.profit > value)
            value = v.profit;
        ///upperbound er shutro
        v.ub = v.profit + (W - v.weight) * (a[v.level + 1].value / (float)a[v.level + 1].weight);

        if (v.ub > value)
            q.push(v);
        ///object na nile
        v.weight = u.weight;
        v.profit = u.profit;
        v.ub = v.profit + (W - v.weight) * (a[v.level + 1].value / (float)a[v.level + 1].weight);

        if (v.ub > value)
            q.push(v);
    }

    return value;
}

int main()
{
    int W, n, w, v;
    cin >> W >> n;

    Item a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].weight >> a[i].value;
    }

    cout << knapsack(W, a, n);

    return 0;
}
/*
5
3
2 3
1 2
3 4
*/
