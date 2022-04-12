#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

void print(vector<int> v) {
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter<< ' ';
	cout << endl;
		
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
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

int main() {
	vector<int> input_1;
	vector<int> speeds_1;
	vector<int> input_2;
	vector<int> speeds_2;
	vector<int> input_3;
	vector<int> speeds_3;

	

	input_1.push_back(93);
	input_1.push_back(30);
	input_1.push_back(55);

	speeds_1.push_back(1);
	speeds_1.push_back(30);
	speeds_1.push_back(5);

	input_2.push_back(95);
	input_2.push_back(90);
	input_2.push_back(99);
	input_2.push_back(99);
	input_2.push_back(80);
	input_2.push_back(99);

	speeds_2.push_back(1);
	speeds_2.push_back(1);
	speeds_2.push_back(1);
	speeds_2.push_back(1);
	speeds_2.push_back(1);
	speeds_2.push_back(1);

	input_3.push_back(5);
	input_3.push_back(5);
	input_3.push_back(5);

	speeds_3.push_back(21);
	speeds_3.push_back(25);
	speeds_3.push_back(20);
	

	//input_3.push_back(3);
	//input_3.push_back(3);




	print(solution(input_1, speeds_1));
	print(solution(input_2, speeds_2));
	print(solution(input_3, speeds_3));

	//cout << solution(input_3) << endl;


	return 0;
}

