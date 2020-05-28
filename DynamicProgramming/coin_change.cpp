/*
given a coin denomiations and sum k, find minimum number of coins to sum up to k.
e.g. 1, 5, 6, 8 and k=11, we need a minimum of 2 coins, i.e., 5

inspiration for correct solution : https://ide.geeksforgeeks.org/VivacD
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
return INT_MAX, if the ans is impossible; else returns a valid integer value
*/
int minimumCoins(int* arr, int size, int k) {
	int** storage = new int*[size]();
	for (int i=0 ; i<size ; i++) {
		storage[i] = new int[k+1]();
	}

	for (int i=1 ; i<=k ; i++) {
		if (i % arr[0] == 0) {
			storage[0][i] = i / arr[0];
		} else {
			storage[0][i] = INT_MAX;
		}
	}

	for (int i=1 ; i<size ; i++) {
		int j=1;
		while (j<=k && j<arr[i]) {
			storage[i][j] = storage[i-1][j];
			j++;
		}
		while (j<=k) {
			int x = storage[i-1][j]; // ans excluding current coin
			int y = storage[i][j-arr[i]]; // ans including current coin
			
			if (y == INT_MAX) {
				storage[i][j] = x;
			} else {
				storage[i][j] = min(x, y+1);
			}

			j++;
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<size ; i++) {
		for (int j=0 ; j<=k ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	return storage[size-1][k];
}

int main() {

	int n;
	cin >> n;
	int* arr = new int[n]();
	for (int i=0 ; i<n ; i++) {
		cin >> arr[i];
	}
	int k;
	cout << "enter k ";
	cin >> k;

	cout << minimumCoins(arr, n, k) << endl;

	return 0;
}