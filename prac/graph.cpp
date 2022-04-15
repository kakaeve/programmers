#include "graph.h"

using namespace std;

void printv(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));


	vector<vector<int>>::iterator iter;

	
	queue<int> wait;
	vector<bool> visited(n + 1, false);
	vector<int> dist(n + 1, 0);
	for (iter = edge.begin(); iter != edge.end(); iter++) {
		graph[iter->front()][iter->back()] = true;
		graph[iter->back()][iter->front()] = true;
	}

	wait.push(1);
	visited[1] = true;
	dist[1] = 0;
	//printv(dist);

	while (wait.size() > 0) {
		int idx = wait.front();
		wait.pop();

		for (int i = 1; i < graph[idx].size(); i++) {
			if (graph[idx][i]) {
				if (!visited[i]) {
					visited[i] = true;
					dist[i] = dist[idx] + 1;
					wait.push(i);
				}
				/*else {
					if (dist[i] > dist[idx] + 1) {
						dist[i] = dist[idx] + 1;
					}
				}*/
				
			}
		}
		//printv(dist);
	}
	int max = -1;
	for (int i = 0; i < dist.size(); i++) {
		if (max < dist[i]) {
			max = dist[i];
			answer = 1;
		}
		else if (max == dist[i]) {
			answer++;
		}
	}

	return answer;
}

int solution2(int n, vector<vector<int>> results) {
	int answer = 0;

	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));



	return answer;
}