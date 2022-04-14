#include "stack_queue.h"

using namespace std;

void print(vector<int> v) {
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter<< ' ';
	cout << endl;
		
}

vector<int> solution1(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

	stack<int> p;
	stack<int> s;
	for (int i = 0; !progresses.empty(); i++) {
		p.push(progresses.back());
		progresses.pop_back();
		s.push(speeds.back());
		speeds.pop_back();
	}
	
	int time = 0;

	while (!p.empty()) {
		int count = 1;
		int pros = p.top();
		p.pop();
		time = ceil((100 - pros) / (float)s.top())>=time? ceil((100 - pros) / (float)s.top()):time;
		cout<< (100 - pros) <<endl;
		cout<< (100 - pros) / (float)s.top() <<endl;
		cout<< ceil((100 - pros) / (float)s.top()) <<endl;
		//cout<< <<endl;
		//cout<< <<endl;

		cout << time << endl;
		s.pop();

		while (!p.empty()&&p.top() + s.top() * time >= 100) {
			count++;
			p.pop();
			s.pop();
		}
		answer.push_back(count);
		
	}

    return answer;
}
