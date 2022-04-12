#include <string>
#include <vector>
#include<iostream>
#include<cmath>

using namespace std;


size_t count_digit(int n) {
    string temp = to_string(n);

    return temp.size() == 0 ? 1 : temp.size();
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<float> temp;
    for (int i = 0; i < numbers.size(); i++) {
        try {
            temp.push_back(numbers[i] / pow(10, count_digit(numbers[i])-1) );
        }
        catch (overflow_error& e) {
            cout << e.what() << endl;
        }
        
    }
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    
    int target = 0;
    while (temp.size() > 0) {
        int max = -1;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] > max) {
                target = i;
                max = temp[i];
            }
            else if (temp[i] == max) {
                if (numbers[target] < numbers[i]) {
                    target = i;
                    max = temp[i];
                }
            }
        }
        answer += (to_string(numbers[target]));
        temp.erase(temp.begin() + target);
        numbers.erase(numbers.begin() + target);
    }
    
    return answer;
}

int main() {
    vector<int> input_1;
    vector<int> input_2;

    input_1.push_back(6);
    input_1.push_back(10);
    input_1.push_back(2);

    input_2.push_back(3);
    input_2.push_back(30);
    input_2.push_back(34);
    input_2.push_back(5);
    input_2.push_back(9);





    cout<< solution(input_1) << endl;
    cout<< solution(input_2) << endl;
    

    return 0;
}