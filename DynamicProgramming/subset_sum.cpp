/*
Given an array and a number k, find out if there exists a subset whose sum is equal to k.
*/

#include <iostream>

using namespace std;

bool findIfSubsetExists(int* arr, int size, int k) {
	bool** storage = new bool*[size]();
	for (int i=0 ; i<size ; i++) {
		storage[i] = new bool[k+1]();
		storage[i][0] = true;
	}

	for (int i=1 ; i<=k ; i++) {
		if (i == arr[0]) {
			storage[0][i] = true;
		} else {
			storage[0][i] = false;
		}
	}

	for (int i=1 ; i<size ; i++) {
		for (int j=1 ; j<=k ; j++) {
			storage[i][j] = storage[i-1][j] | storage[i-1][j-arr[i]];
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

	 cout << findIfSubsetExists(arr, n, k) << endl;

	return 0;
}