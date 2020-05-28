#include <iostream>
#include <cmath>

using namespace std;

class Matrix {
public:
	int N;
	int M;

	Matrix() {}

	Matrix(int n, int m) {
		N = n;
		M = m;
	}
};

int lowest_cost_possible(Matrix* arr, int size) {
	int** storage = new int*[size]();
	for (int i=0 ; i<size ; i++) {
		storage[i] = new int[size]();
	}

	for (int i=1 ; i<size ; i++) {
		int j = i-1;
		int x = arr[j].N * arr[i].N * arr[i].M;
		storage[j][i] = x;
	}

	int minimum, smallAns;
	for (int l=2 ; l<size ; l++) {
		for (int i=0 ; i<size-l ; i++) {
			int j = i+l;
			minimum = INT_MAX;
			for (int k=i ; k<j ; k++) {
				smallAns = arr[i].N * arr[k].M * arr[j].M + storage[i][k] + storage[k+1][j];
				minimum = min(minimum, smallAns);
			}
			storage[i][j] = minimum;
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<size ; i++) {
		for (int j=0 ; j<size ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	return storage[0][size-1];
}

int main() {

	int n;
	cin >> n;

	Matrix* arr = new Matrix[n]();
	for (int i=0 ; i<n ; i++) {
		int n, m;
		cin >> n >> m;
		arr[i].N = n;
		arr[i].M = m;
	}

	cout << lowest_cost_possible(arr, n) << endl;

	return 0;
}