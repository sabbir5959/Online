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


// job sequencing

#include <bits/stdc++.h>
using namespace std;


struct Job {

	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};

// Comparator function for sorting jobs
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of profit
	sort(arr, arr + n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) {
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			// Free slot found
			if (slot[j] == false) {
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}


int main()
{
    int n;

    cin>> n ;

    Job arr[n];

    for(int i=0 ; i<n ; i++)
    {
        char id;
        int dline,profit;

        cin>>id>>dline>>profit;

        arr[i].id = id;
        arr[i].dead = dline;
        arr[i].profit = profit;
    }


	//int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Following is maximum profit sequence of jobs "
			"\n";

	// Function call
	printJobScheduling(arr, n);
}

/*
5
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15
*/



//Activity selection


#include <bits/stdc++.h>
using namespace std;

// A job has a start time, finish time and profit.
struct Activitiy {
	int start, finish;
};


bool activityCompare(Activitiy s1, Activitiy s2)
{
	return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr + n, activityCompare);

	cout << "Following activities are selected :\n";

	// The first activity always gets selected
	int i = 0;
	cout << arr[i].start << ", " << arr[i].finish << endl;

	for (int j = 1; j < n; j++) {  // If this activity has start time greater than or equal to the finish time of previously selected activity, then select it
		if (arr[j].start >= arr[i].finish)
        {
			cout << arr[j].start << ", " << arr[j].finish << endl;
			i = j;
		}
	}
}

int main()
{
   int n;

    cin>> n ;

    Activitiy arr[n];

    for(int i=0 ; i<n ; i++)
    {
        int s,f;

        cin>>s>>f;

        arr[i].start = s;
        arr[i].finish = f;
    }

	//int n = sizeof(arr) / sizeof(arr[0]);

	printMaxActivities(arr, n);
}

/*
6
5 9
1 2
3 4
0 6
5 7
8 9
*/



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
