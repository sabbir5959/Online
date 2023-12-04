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

