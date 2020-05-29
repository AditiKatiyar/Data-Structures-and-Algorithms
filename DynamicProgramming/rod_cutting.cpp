/*
given a set of lengths 'p' and their values, and a length 'L', find the maximum profit that can be gained by cutting 
the rod only in pieces 'p'.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Rod {
public:
	int length;
	int value;

	Rod() {}

	Rod(int l, int v) {
		length = l;
		value = v;
	}
};

// assuming if there is a length of rod that that does not exists in 'p', then its value is 0.
int maximumProfit(Rod* arr, int size, int L) {
	int** storage = new int*[size]();
	for (int i=0 ; i<size ; i++) {
		storage[i] = new int[L+1]();
	}

	for (int i=1 ; i<=L ; i++) {
		if (i % arr[0].length == 0) {
			storage[0][i] = arr[0].value * (i / arr[0].length);
		}
	}

	for (int i=1 ; i<size ; i++) {
		int j=1;
		while (j<=L && j<arr[i].length) {
			storage[i][j] = storage[i-1][j];
			j++;
		}
		while (j<=L) {
			storage[i][j] = max(storage[i-1][j], storage[i][j-arr[i].length] + arr[i].value);
			j++;
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<size ; i++) {
		for (int j=0 ; j<=L ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	return storage[size-1][L];
}

int main() {

	int n;
	cin >> n;
	Rod* arr = new Rod[n]();
	for (int i=0 ; i<n ; i++) {
		cin >> arr[i].length >> arr[i].value;
	}
	int totalLength;
	cout << "enter total length ";
	cin >> totalLength;

	cout << maximumProfit(arr, n, totalLength) << endl;

	return 0;
}