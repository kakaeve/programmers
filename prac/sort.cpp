#include "sort.h"

using namespace std;

bool comparison(string a, string b) {
	return a + b > b + a;
}


string solution2(vector<int> numbers) {
	string answer = "";
	vector<string> temp;
	
	for (int i = 0; i < numbers.size(); i++) {
		temp.push_back(to_string(numbers[i]));
	}

	sort(temp.begin(), temp.end(), comparison);
	
	for (int i = 0; i < temp.size(); i++) {
		answer += temp[i];
	}

	if (answer[0] == '0') answer = '0';

	return answer;
}
