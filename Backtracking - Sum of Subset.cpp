// Sum of Subset

#include<bits/stdc++.h>
using namespace std;

int a[4];
int n,ts;
vector <int> b;

void back_track(int i,int s,vector<int> b)
{
    if(s==0)
    {
        for(int j=0; j<b.size(); j++)
        cout<<b[j]<<" ";
        cout<<endl;

        while (!b.empty())
        {
            b.pop_back();
        }
    }

    if (i == n)
        return;

    if (a[i] <= s)
    {
        b.push_back(a[i]);
        back_track(i + 1, s - a[i], b);
        b.pop_back();
    }

    back_track(i + 1, s, b);
}


int main()
{
    cin>>n>>ts;  // ts - target sum

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    back_track(0,ts,b);
}
