#include "DFS_BFS.h"

using namespace std;

void print(queue<int> a) {
    while (!a.empty()) {
        cout << a.front() << ", ";
        a.pop();
    }
    cout << endl;
}

int solution1(vector<int> numbers, int target) {
    int answer = 0;

    int result = 0;


    queue<int> q;
    queue<int> temp;
    q.push(numbers.back());
    q.push(-numbers.back());
    numbers.pop_back();
    while (numbers.size() > 0) {
        
        int num = numbers.back();
        numbers.pop_back();
        while (!q.empty()) {
            temp.push(q.front() + num);
            temp.push(q.front() - num);
            q.pop();
        }
        q = temp;
        while (!temp.empty()) {
            temp.pop();
        }
        //print(q);
    }
   // cout << target << endl;
    while (!q.empty()) {
        //cout << q.front() << endl;
        if (q.front() == target) {
            answer++;
        }
        q.pop();
    }
    return answer;
}