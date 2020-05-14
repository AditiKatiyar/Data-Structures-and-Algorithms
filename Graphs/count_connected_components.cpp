#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Pair{
    public:
        int x;
        int y;
        Pair(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

void getShape(vector<string>& A, vector<vector<bool> >& visited, int x, int y){
    visited[x][y] = true;
    queue<Pair> q;
    Pair start(x, y);
    q.push(start);
    int n = A.size();
    int m = A[0].size();
    
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        
        if (p.x-1 >= 0 && A[p.x-1][p.y] == 'X' && !visited[p.x-1][p.y]) {
            visited[p.x-1][p.y] = true;
            Pair t(p.x-1, p.y);
            q.push(t);
        }
        if (p.x+1 < n && A[p.x+1][p.y] == 'X' && !visited[p.x+1][p.y]) {
            visited[p.x+1][p.y] = true;
            Pair t(p.x+1, p.y);
            q.push(t);
        }
        if (p.y-1 >= 0 && A[p.x][p.y-1] == 'X' && !visited[p.x][p.y-1]) {
            visited[p.x][p.y-1] = true;
            Pair t(p.x, p.y-1);
            q.push(t);
        }
        if (p.y+1 < m && A[p.x][p.y+1] == 'X' && !visited[p.x][p.y+1]) {
            visited[p.x][p.y+1] = true;
            Pair t(p.x, p.y+1);
            q.push(t);
        }
    }
}

int getConnectedComponents(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    
    int shapes = 0;
    vector<vector<bool> > visited;
    for (int i=0 ; i<n ; i++) {
        vector<bool> v(m, false);
        visited.push_back(v);
    }
    
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            if (A[i][j] == 'X' && !visited[i][j]) {
                getShape(A, visited, i, j);
                shapes++;
            }
        }
    }
    
    return shapes;
}

int main() {

	int n;
	cin >> n;
	vector<string> image;
	for (int i=0 ; i<n ; i++) {
		string line;
		cin >> line;
		image.push_back(line);
	}

	cout << getConnectedComponents(image) << endl;

	return 0;
}