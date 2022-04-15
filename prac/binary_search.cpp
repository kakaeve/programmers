#include "binary_search.h"

using namespace std;

struct cmp {
	bool operator()(pair<long long, int>a, pair<long long, int>b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};

long long solution1(int n, vector<int> times) {
	long long answer = 0;
	
	/*priority_queue<pair<long long, int>,vector<pair<long long,int>>,cmp> pq;

	vector<int>::iterator iter;

	for (iter = times.begin(); iter != times.end(); iter++) {
		pq.push(make_pair(*iter, *iter));
	}

	while (!pq.empty()) {
		pair<long long,int> pros = pq.top();
		pq.pop();
		if (n != 0) {
			pq.push(make_pair(pros.first + pros.second, pros.second));
			n--;
		}
		else {
			if (answer < pros.first-pros.second)
				answer = pros.first - pros.second;
		}
			
	}*/
	


	vector<pair<long long, int>> tables;
	vector<int>::iterator iter;
	vector<pair<long long, int>>::iterator it;

	sort(times.begin(), times.end());

	long long start = 1;
	long long end = (long long)times[times.size() - 1] * n;

	long long mid;

	while (start <= end) {
		mid = (start + end) / 2;

		long long count = 0;

		for (int i = 0; i < times.size(); i++) {
			count += mid / times[i];
		}

		if (count < n) {
			start = mid + 1;
		}
		else {
			if (mid <= end) {
				answer = mid;
			}
			end = mid - 1;
		}

	}

	
	/*for (iter = times.begin(); iter != times.end(); iter++) {
		tables.push_back(make_pair(*iter, *iter));
	}
	sort(tables.begin(), tables.end(), [](pair<long long, int> a, pair<long long, int> b) {return a.first < b.first; });
	while (n > 0) {
		it = lower_bound(tables.begin(), tables.end(), make_pair(0, 0), [](pair<long long, int> a, pair<long long, int> b) {return a.first < b.first; });
		it->first = it->first + it->second;
		//long i = lower_bound(tables.begin(), tables.end(), make_pair(0, 1), [](pair<long long, int> a, pair<long long, int> b) {return a.first > b.first; }) - tables.begin();
		//tables[i].first = tables[i].first + tables[i].second;
		
		n--;
		sort(tables.begin(), tables.end(), [](pair<long long, int> a, pair<long long, int> b) {return a.first < b.first; });
	}
	for (it = tables.begin(); it != tables.end(); it++) {
		if (answer < it->first - it->second)
			answer = it->first - it->second;
	}*/
	


	return answer;
}