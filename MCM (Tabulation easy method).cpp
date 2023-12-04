//MCM tabulation easy

#include<bits/stdc++.h>
#define n 4

using namespace std;

int m[n][n];
int s[n][n];

void printMCM (int i, int j) {
    if (i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        printMCM( i, s[i][j]);
        printMCM( s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    //int n;

    //cin>>n; // change in Define

    int p[n];

    for(int i=0;i<n;i++) cin>>p[i];

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

    printMCM(1,n-1);
}
