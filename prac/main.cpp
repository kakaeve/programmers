#include "DFS_BFS.h"

using namespace std;

int main() {

	//DFS_BFS
	{
		vector<int> input = { 1,1,1,1,1 };
		int target = 3;
		cout << solution1(input, target) << endl;
		input = { 4,1,2,1 };
		target = 4;
		cout << solution1(input, target) << endl;
	}

	//heap solution
	/*{
		vector<vector<int>> input = {{0,3},{1,9},{2,6}};

		cout << solution3(input) << endl;

		input = { {3,3},{1,9},{2,6} };

		cout << solution3(input);

	}*/


	//hash solution
	/*{
		vector<string> input1;
		vector<int> input2;

		input1.push_back("classic");
		input1.push_back("pop");
		input1.push_back("classic");
		input1.push_back("classic");
		input1.push_back("pop");

		input2.push_back(500);
		input2.push_back(600);
		input2.push_back(150);
		input2.push_back(800);
		input2.push_back(2500);

		vector<int> print = solution4(input1, input2);

		for_each(print.begin(), print.end(), [](const int& n){cout << n << ", ";});
		cout << endl;
	}*/


	//sort solution
	/*{
		vector<int> input_1;
		vector<int> input_2;
		vector<int> input_3;

		input_1.push_back(6);
		input_1.push_back(10);
		input_1.push_back(2);

		input_2.push_back(3);
		input_2.push_back(30);
		input_2.push_back(34);
		input_2.push_back(5);
		input_2.push_back(9);

		input_3.push_back(3333);
		input_3.push_back(3);
		input_3.push_back(33);
		input_3.push_back(333);
		input_3.push_back(3332);
		input_3.push_back(3331);

		cout << solution2(input_1) << endl;
		cout << solution2(input_2) << endl;
		cout << solution2(input_3) << endl;
	}*/


	//stack_queue solution
	/*{
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

	print(solution1(input_1, speeds_1));
	print(solution1(input_2, speeds_2));
	print(solution1(input_3, speeds_3)); }*/


	return 0;
}