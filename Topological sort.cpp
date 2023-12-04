//topological


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e,x,y;
    cin>>v>>e;
    int a[v][v];
    int o[v];

    for(int i=0;i<v;i++)
    {
        o[i]=0;
        for(int j=0;j<v;j++)
        {
            a[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        a[x][y]=1;
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(a[i][j]==1)
            {
                o[j]++;
            }
        }
    }


    int p;

    queue<int> q;
    vector<int> r;
    for(int j=0;j<v;j++)
    {
        if(o[j]==0) {
            q.push(j);
            break;
        }
    }

    while(!q.empty())
    {
        int w = q.front();
        q.pop();

        o[w]=-1;

        r.push_back(w);

        for(int j=0;j<v;j++)
        {
            if(a[w][j]==1) {
                o[j]--;
            }
        }

        for(int j=0;j<v;j++)
        {
            if(o[j]==0) {
                q.push(j);
                break;
            }
        }
    }

    for(int j=0;j<r.size();j++)
    {
        cout<<r[j]<<" ";
    }


}
