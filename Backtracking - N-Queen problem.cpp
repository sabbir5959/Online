//n queen

#include<bits/stdc++.h>
using namespace std;
int N;
int cnt;
int a[100][100];
void init()
{
    cnt=0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
            a[i][j]=0;
    }
}
int isSafe(int i,int j)
{
    int row=i;
    int col=j;
    while(1)
    {
        if(a[i][j]==1)
            return 0;
        i--;
        if(i==0)    break;
    }
    i=row;
    j=col;
    while(1)
    {
         if(a[i][j]==1)
            return 0;
        i--;
        j--;
        if(i==0 || j==0)    break;
    }
    i=row;
    j=col;
    while(1)
    {
         if(a[i][j]==1)
            return 0;
        i--;
        j++;
        if(i==0 || j==N+1)    break;

    }
    return 1;
}
void print_board()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void N_Queen(int i)
{
    if(i==N+1)
    {
        cnt++;
        print_board();
        return;
    }
    for(int j=1;j<=N;j++)
    {
        if(isSafe(i,j)==1)
        {
            a[i][j]=1;
            N_Queen(i+1);
            a[i][j]=0;
        }
    }
}
int main()
{
    init();
    cin>>N;
    N_Queen(1);
    cout<<cnt;

}
