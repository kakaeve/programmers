#include "hash.h"

using namespace std;

void print(vector<pair<string, int>>& v) {
	for (vector<pair<string, int>>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->first << ", "<< iter->second<<" ";
	}
	cout << endl;
}

void print(vector<pair<string, pair<int, int>>>& v) {
	vector<pair<string, pair<int, int>>>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->first << " : " << iter->second.first << ", " << iter->second.second << endl;
	}
}

vector<int> solution4(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	vector<pair<string, int>> count;

	vector<pair<string, pair<int, int>>> song;



	for (int i = 0; i < genres.size(); i++) {
		string s = genres[i];
		vector<pair<string, int>>::iterator iter = find_if(count.begin(), count.end(), [s](const pair<string, int>& e) {return e.first == s; });
		if (iter!=count.end()) {
			iter->second += plays[i];
			int idx = iter - count.begin();
			if (song.at(idx*2).second.first < plays[i]) {
				//cout << "prev" << endl;
				//print(song);
				song.at(idx * 2 +1).first = song.at(idx * 2).first;
				song.at(idx * 2 + 1).second = song.at(idx * 2).second;
				song.at(idx * 2).first = genres[i];
				song.at(idx * 2).second.first = plays[i];
				song.at(idx * 2).second.second = i;
				//cout << "after" << endl;
				//print(song);
			}
			else if (song.at(idx * 2 + 1).second.first < plays[i]) {
				//cout << "prev" << endl;
				//print(song);
				song.at(idx * 2 +1).first = genres[i];
				song.at(idx * 2 +1).second.first = plays[i];
				song.at(idx * 2 +1).second.second = i;
				//cout << "after" << endl;
				//print(song);
			}
		}
		else {
			//cout << "prev" << endl;
			//print(song);
			count.push_back(make_pair(genres[i], plays[i]));
			song.push_back(make_pair(genres[i],make_pair(plays[i], i)));
			song.push_back(make_pair(genres[i], make_pair(-1, -1)));
			//cout << "after" << endl;
			//print(song);
		}
	}
	//print(count);
	sort(count.begin(), count.end(), [](const pair<string, int> a, const pair<string, int> b) {return a.second > b.second; });
	//print(count);
	//print(song);
	for (vector<pair<string, int>>::iterator iter = count.begin(); iter!=count.end(); iter++) {
		vector<pair<string, pair<int, int>>>::iterator it = find_if(song.begin(), song.end(), [&iter](const pair<string, pair<int, int>>& s) {return iter->first == s.first; });
		answer.push_back(it->second.second);
		//cout << it->second.second << endl;
		if ((it + 1)->second.second != -1) {
			answer.push_back((it+1)->second.second);
			//cout << (it+1)->second.second << endl;
		}
	}
	

	return answer;
}