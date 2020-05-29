#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int editDistance(string str, string target) {
	int len1 = str.length();
	int len2 = target.length();
	int** storage = new int*[len2+1]();
	for (int i=0 ; i<=len2 ; i++) {
		storage[i] = new int[len1+1]();
	}

	for (int i=1 ; i<=len1 ; i++) {
		storage[0][i] = i;
	}

	for (int i=1 ; i<=len2 ; i++) {
		storage[i][0] = i;
	}

	for (int i=0 ; i<len2 ; i++) {
		for (int j=0 ; j<len1 ; j++) {
			if (target[i] == str[j]) {
				storage[i+1][j+1] = storage[i][j];
			} else {
				storage[i+1][j+1] = min(storage[i][j], min(storage[i+1][j], storage[i][j+1])) + 1;
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

	string str, target;
	cin >> str >> target;
	cout << editDistance(str, target) << endl;

	return 0;
}