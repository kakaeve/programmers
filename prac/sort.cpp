//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//#include <sstream>
//
//using namespace std;
//
//
//bool comparison(string a, string b) {
//	return a + b > b + a;
//}
//
//
//string solution1(vector<int> numbers) {
//	string answer = "";
//	vector<string> temp;
//	
//	for (int i = 0; i < numbers.size(); i++) {
//		temp.push_back(to_string(numbers[i]));
//	}
//
//	sort(temp.begin(), temp.end(), comparison);
//	
//	for (int i = 0; i < temp.size(); i++) {
//		answer += temp[i];
//	}
//
//	if (answer[0] == '0') answer = '0';
//
//	return answer;
//}
//
//int four(int n) {
//	if (n > 999)
//		return n;
//	else if (n > 99)
//		return n * 10 + n / 100;
//	else if (n > 9)
//		return n * 101;
//	else if (n > 0)
//		return n * 1111;
//	else
//		return 0;
//}
//
//string solution(vector<int> numbers) {
//	string answer = "";
//	int zero = 0;
//	for (int n : numbers)
//		if (!n) ++zero;
//	if (zero == numbers.size())
//		return "0";
//
//	for (int i = 1; i < numbers.size(); ++i) {
//		for (int j = 0; j < i; ++j) {
//			if (four(numbers[i]) > four(numbers[j]))
//				swap(numbers[i], numbers[j]);
//		}
//	}
//	for (int n : numbers) {
//		stringstream s;
//		s << n;
//		string c = s.str();
//		//answer += c;
//		answer += to_string(n);
//	}
//	return answer;
//}
//
//int main() {
//	vector<int> input_1;
//	vector<int> input_2;
//	vector<int> input_3;
//
//	input_1.push_back(6);
//	input_1.push_back(10);
//	input_1.push_back(2);
//
//	input_2.push_back(3);
//	input_2.push_back(30);
//	input_2.push_back(34);
//	input_2.push_back(5);
//	input_2.push_back(9);
//
//	input_3.push_back(3333);
//	input_3.push_back(3);
//	input_3.push_back(33);
//	input_3.push_back(333);
//	input_3.push_back(3332);
//	input_3.push_back(3331);
//	//input_3.push_back(3);
//	//input_3.push_back(3);
//
//
//
//
//
//
//	cout << solution(input_1) << endl;
//	cout << solution(input_2) << endl;
//	cout << solution(input_3) << endl;
//
//
//	return 0;
//}
