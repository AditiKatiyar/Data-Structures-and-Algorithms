#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int lcs(string a, string b) {
	int len1 = a.length(); // horizontal
	int len2 = b.length(); // vertical

	int** storage = new int*[len2+1]();
	for (int i=0 ; i<=len2 ; i++) {
		storage[i] = new int[len1+1]();
	}

	for (int j=1 ; j<=len2 ; j++) {
		for (int i=1 ; i<=len1 ; i++) {
			if (b[j-1] == a[i-1]) {
				storage[j][i] = storage[j-1][i-1] + 1;
			} else {
				storage[j][i] = max(storage[j-1][i], storage[j][i-1]);
			}
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<=len2 ; i++) {
		for (int j=0 ; j<=len1 ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	return storage[len2][len1];
}

int main() {

	string a, b;
	cin >> a >> b;

	cout << lcs(a, b) << endl;

	return 0;
}