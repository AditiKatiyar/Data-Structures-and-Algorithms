#include <iostream>
#include <vector>

using namespace std;

void colorGraph(vector<vector<int> > graph, int n, vector<int>& color, int node) {
	int c = 1;
	bool flag;

	while (true) {
		flag = false;

		for (int i=0 ; i<graph[node].size() ; i++) {
			if (color[graph[node][i]] == c) {
				c++;
				flag = true;
				break;
			}
		}

		if (!flag) {
			break;
		}
	}

	color[node] = c;
}

void printGraph(vector<vector<int> > graph) {
	for (int i=0 ; i<graph.size() ; i++) {
		cout << i << " : ";
		for (int j=0 ; j<graph[i].size() ; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	
	int n;
	cin >> n;
	vector<vector<int> > graph;
	for (int i=0 ; i<n ; i++) {
		vector<int> v;
		graph.push_back(v);
	}

	int e;
	cin >> e;
	while (e--) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1); 
	}

	printGraph(graph);

	vector<int> color(n, 0);

	for (int i=0 ; i<n ; i++) {
		if (color[i] == 0) {
			colorGraph(graph, n, color, i);
		}
	}

	for (int i=0 ; i<n ; i++) {
		cout << color[i] << " ";
	}
	cout << endl;

	return 0;
}