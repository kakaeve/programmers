#include "heap.h"

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

struct cmp2 {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first+a.second > b.first+b.second;
    }
};

void move_pq(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>* a, priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2>* b) {
    while (a->size() > 0) {
        b->push(a->top());
        a->pop();
    }
}

void move_pq(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2>* a, priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>* b) {
    while (a->size() > 0) {
        b->push(a->top());
        a->pop();
    }
}



void print(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq) {
    while (pq.size()>0) {
        cout << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
}

void print(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq) {
    while (pq.size() > 0) {
        cout << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
}


int solution3(vector<vector<int>> jobs) {
    int answer = 0;
    
    //priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq2;

    vector<pair<int, int>> save;
    vector<vector<int>>::iterator iter;
    for (iter = jobs.begin(); iter != jobs.end(); iter++) {
        //pq.push(make_pair(iter->front(), iter->back()));
    }
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {return a.front()> b.front(); });

    //print(pq);
    int time = 0;
    int during = 0;
    int sum = 0;
    int count = jobs.size();

    vector<pair<int, int>> pros;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    while (jobs.size() > 0 || pq.size() > 0) {
        
        pair<int, int> p;

        while (jobs.size()>0 && time >= jobs.back().front()) {
            p = make_pair(jobs.back().front(), jobs.back().back());
            //cout << p.first << ", " << p.second << endl;
            jobs.pop_back();
            pq.push(p);
        }
        if (pq.size() == 0) {
            time = jobs.back().front();
        }
        else {
            sum += time - pq.top().first + pq.top().second;
            time += pq.top().second;
            pq.pop();
        }
        //cout << "time : " << time << endl;
       // cout << "sum : " << sum << endl;

    }
    
	//while (pq.size() > 0) {
	//	during = 0;
	//	if (time >= pq.top().first) {
	//		during = time - pq.top().first + pq.top().second;
	//		time += pq.top().second;
	//		move_pq(&pq2, &pq);

	//		sum += during;
	//		pq.pop();
	//	}
	//	else {
	//		if (pq.size() == 1) {
	//			if (time > pq.top().first) {
	//				during = time - pq.top().first + pq.top().second;
	//				time += pq.top().second;
	//				move_pq(&pq2, &pq);

	//				sum += during;
	//				pq.pop();
	//			}
	//			else {
	//				during = pq2.top().second;
	//				time = pq2.top().first + pq2.top().second;
	//				sum += during;
	//				pq2.pop();

	//				move_pq(&pq2, &pq);
	//			}
	//		}
	//		else {
	//			pq2.push(pq.top());
	//			pq.pop();
	//		}
	//	}

 //       //cout << "time : " << time << endl;
 //      // cout << "during : " << during << endl;
 //       
 //   }
   // cout << sum << ", " << jobs.size() << endl;
    answer = sum / count;

    return answer;
}