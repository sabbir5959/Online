//mcm tabu hard

#include<bits/stdc++.h>
using namespace std;

void printMCM(int i, int j , vector<vector<int>>& s) {
    if (i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        printMCM( i, s[i][j] , s);
        printMCM( s[i][j] + 1, j , s);
        cout << ")";
    }
}

int main()
{
    int n;
    cin>>n;

    int p[n];

    for(int i=0;i<n;i++) cin>>p[i];

    int m[n][n];
    int s[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }

    int j,mini,q;

    for(int d=1;d < n-1;d++)
    {
        for(int i=1;i<n-d ;i++)
        {
            j=i+d;
            mini=INT_MAX;

            for(int k=i;k<=j-1;k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(q < mini)
                {
                    mini = q;
                    s[i][j] = k;
                }
            }
            m[i][j]=mini;
        }
    }

    cout<<m[1][n-1]<<endl;

    vector<vector<int>> s1(n, vector<int>(n, 0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            s1[i][j]=s[i][j];
        }
    }

    printMCM(1,n-1,s1);
}
