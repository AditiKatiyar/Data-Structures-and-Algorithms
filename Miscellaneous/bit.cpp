#include <iostream>

using namespace std;


void bin(unsigned n) 
{ 
    if (n > 1)
    	bin(n >> 1);
    cout << (n & 1);
}

int main() {
	
	int n;
	cin >> n;

	int nReverse = n;
	int s = sizeof(n) * 8;

	bin(n);
	cout<<endl;

	while (n) {
		nReverse <<= 1;
		nReverse |= (n & 1);
		s--;
		n >>= 1;
	}

	nReverse <<= s;

	bin(nReverse);

	cout << endl;

	return 0;
}