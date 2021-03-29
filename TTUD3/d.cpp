/*
There are n passengers 1,2,…,n. The passenger i want to travel from point i to point i+n(i=1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0 without visiting any point more than once (except for the point 0).

Input
Line 1 contains n and k(1≤n≤11,1≤k≤10). Line i+1(i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).

Output
Unique line contains the length of the shortest route.

Example
inputCopy
3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
outputCopy
25
*/
#include<iostream>
using namespace std;

const int N = 25;
const int INF = 1000000000;


int n, k;
int c[N][N];

bool visited[N];
int curLength = 0;
int ans = INF;
int nPassengerInBus = 0;

int minCost = INF;

void backtrack(int nVisited, int curPassenger) {

	if (nVisited == 2 * n + 1) {
		ans = min(ans, curLength + c[curPassenger][0]);
		return;
	}

	// don khach 
	if (nPassengerInBus < k) {
		for (int i = 1; i <= n; i++) {
			if (visited[i])
				continue;

			int bound = curLength + c[curPassenger][i];
			// nVisited + 1 dinh -> da di qua nVisited canh
			bound += (2 * n + 1 - nVisited) * minCost;
			if (bound >= ans) {
				continue;
			}

			visited[i] = true;
			curLength = curLength + c[curPassenger][i];
			nPassengerInBus++;
			backtrack(nVisited + 1, i);
			nPassengerInBus--;
			curLength = curLength - c[curPassenger][i];
			visited[i] = false;
		}
	}

	// tra khach

	for (int i = n + 1; i <= 2 * n; i++) {
		if (visited[i])
			continue;

		if (visited[i - n] == false)
			continue;

		int bound = curLength + c[curPassenger][i];
		// nVisited + 1 dinh -> da di qua nVisited canh
		bound += (2 * n + 1 - nVisited) * minCost;
		if (bound >= ans) {
			continue;
		}

		visited[i] = true;
		curLength = curLength + c[curPassenger][i];
		nPassengerInBus--;
		backtrack(nVisited + 1, i);
		nPassengerInBus++;
		curLength = curLength - c[curPassenger][i];
		visited[i] = false;
	}

}


int main() {

	cin >> n >> k;

	for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			cin >> c[i][j];
			if (i != j)
				minCost = min(minCost, c[i][j]);
		}
	}


	visited[0] = true;

	backtrack(1, 0);

	cout << ans << endl;

	return 0;
}

// #include <iostream>
// using namespace std;

// int n, k, cMin = 1e9;
// int c[30][30];
// bool visited[30];
// int x[30];
// int passengerOnBus = 0;
// bool passengerOnbus[30];
// int best = 1e9;
// int cur_sum = 0;

// void Try(int t)
// {
//     if (cur_sum + cMin * (2 * n - t + 1) >= best)
//         return;
//     //
//     int it = 1;
//     int limit_it = 2 * n;
//     if (passengerOnBus == k)
//     {
//         it = n + 1;
//         limit_it = 2 * n;
//     }
//     else if (passengerOnBus == 0)
//     {
//         it = 1;
//         limit_it = n;
//     }

//     //

//     for (; it <= limit_it; it++)
//     {

//         if (!visited[it])
//         {
//             //Neu ko co hanh khach (it-n) thi ko di den it
//             if (it >= n + 1 && !passengerOnbus[it - n])
//                 continue;
//             //
//             visited[it] = true;
//             cur_sum += c[x[t - 1]][it];
//             x[t] = it;
//             int pre = passengerOnBus;
//             bool flag1 = false;
//             bool flag2 = false;

//             //
//             if (it <= n)
//             {
//                 passengerOnbus[it] = true;
//                 passengerOnBus++;
//                 flag2 = true;
//             }
//             else
//             {
//                 passengerOnbus[it - n] = false;
//                 passengerOnBus--;
//                 flag1 = true;
//             }
//             //
//             if (t == 2 * n)
//                 best = min(best, cur_sum + c[x[t]][0]);
//             else
//                 Try(t + 1);
//             //
//             visited[it] = false;
//             cur_sum -= c[x[t - 1]][it];
//             x[t] = 0;
//             passengerOnBus = pre;
//             if (flag1)
//                 passengerOnbus[it - n] = true;
//             else if (flag2)
//                 passengerOnbus[it] = false;
//         }
//     }
// }

// int main()
// {
//     cin >> n >> k;
//     for (int i = 0; i <= 2 * n; i++)
//         for (int j = 0; j <= 2 * n; j++)
//         {
//             cin >> c[i][j];
//             cMin = min(cMin, c[i][j]);
//         }
//     visited[0] = true;
//     x[0] = 0;
//     Try(1);
//     cout << best << "\n";

//     return 0;
// }

