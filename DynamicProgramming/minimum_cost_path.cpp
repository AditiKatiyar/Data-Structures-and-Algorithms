#include <iostream>
#include <cmath>

using namespace std;

int minimumCost(int** arr, int n, int m) {
	int** storage = new int*[n]();
	for (int i=0 ; i<n ; i++) {
		storage[i] = new int[m]();
	}
	storage[0][0] = arr[0][0];

	for (int i=1 ; i<m ; i++) {
		storage[0][i] = arr[0][i] + storage[0][i-1];
	}

	for (int i=1 ; i<n ; i++) {
		storage[i][0] = arr[i][0] + storage[i-1][0];
	}

	for (int i=1 ; i<n ; i++) {
		for (int j=1 ; j<m ; j++) {
			storage[i][j] = arr[i][j] + min(storage[i-1][j], storage[i][j-1]);
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<m ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	return storage[n-1][m-1];
}

int main() {

	int n, m;
	cin >> n >> m;
	int** arr = new int*[n]();
	for (int i=0 ; i<n ; i++) {
		arr[i] = new int[m]();
	}

	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<m ; j++) {
			cin >> arr[i][j];
		}
	}

	cout << minimumCost(arr, n, m) << endl;

	return 0;
}