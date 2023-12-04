//m coloring

#include <bits/stdc++.h>
using namespace std;

#define V 5

int g[V][V];
int color[V];


bool isSafe(int v,int c)
{
	for (int i = 0; i < V; i++)
		if (g[v][i]==1 && c == color[i]) return false;

	return true;
}


bool graph_coloring(int m,int v)
{

	if (v == V) return true;      // If all vertices are assigned a color then return true


	for (int c = 0; c < m; c++)
        {

            if ( isSafe(v,c) == true )   		// Check if assignment of color c to v is fine
                {
                    color[v] = c;

                    if (graph_coloring(m, v + 1) == true) return true;  // recur to assign colors to rest of the vertices

                    color[v] = -1;   // If assigning color c doesn't lead to a solution then remove it
                }
        }

	return false; 	// If no color can be assigned to this vertex then return false
}



int main()
{

    for(int i=0;i<V;i++)
    {
        color[i]=-1;

        for(int j=0;j<V;j++)
        {
            g[i][j]=0;
        }
    }


    int m,e;    	//m = Number of colors  e = edge

    cin>>e;

    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x][y]=1;
        g[y][x]=1;
    }

    cin>>m;

    if (graph_coloring(m,0) == false)
        {
            cout << "Solution does not exist";
            return 0;
        }


    for (int i = 0; i < V; i++)   //Ans printing
    cout << color[i] << " ";
}

