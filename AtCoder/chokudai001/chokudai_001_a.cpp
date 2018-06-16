#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <functional>
#include <deque>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;
 
const int Height = 30, Width = 30;
 
using Stage = array<array<int, Width>, Height>;
using Answer = vector<tuple<int, int>>;
enum {Y, X};
 
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
 
mt19937 rnd;
 
bool checkEnd(const Stage& stage) {
	
	for(int i = 0; i < Height; ++i) {
		for(int j = 0; j < Width; ++j) {
			if(stage[i][j] != 0) return false;
		}
	}
	
	return true;	
}
 
tuple<int, int, int> selectMax(Stage& stage) {
	tuple<int, int, int> maxi(0, 0, 0); //num, y, x
	
	for(int i = 0; i < Height; ++i) {
		for(int j = 0; j < Width; ++j) {
			if(stage[i][j] > get<0>(maxi)) {
				maxi = make_tuple(stage[i][j], i, j);
			}
		}
	}
	
	return maxi;
}
 
void chain(Stage& stage, tuple<int, int> p, Answer& answer) {
	int n = --stage[get<Y>(p)][get<X>(p)];
	answer.push_back(p);
	if(n == 0) return;
	
	int index[] = {0, 1, 2, 3};
	
	shuffle(index, index + 4, rnd);
	
	for(int k = 0; k < 4; ++k) {
		int nx = get<X>(p) + dx[index[k]], ny = get<Y>(p) + dy[index[k]];
		
		if(0 <= nx && nx < Width && 0 <= ny && ny < Height) {
			if(stage[ny][nx] == n) {
				chain(stage, make_tuple(ny, nx), answer);
				break;
			}
		}
	}
}
 
tuple<Answer, int> solve(Stage stage) {
	Answer answer;
	int cnt = 0;
	while(true) {
		auto maxi = selectMax(stage);
		if(get<0>(maxi) == 0) break;
		cnt++;
		chain(stage, make_tuple(get<1>(maxi), get<2>(maxi)), answer);
	}
	return make_tuple(answer, 100000 - cnt);
}
 
int main() {
	rnd.seed(random_device{}());
	Stage stage;
	
	for(int i = 0; i < Height; ++i) {
		for(int j = 0; j < Width; ++j) {
			cin >> stage[i][j];
		}
	}
	
	int maxScore = 0;
	Answer bestAnswer;
	
	auto start = system_clock::now();
	
	while(duration_cast<milliseconds>(system_clock::now() - start) < 8000ms) {
		for(int i = 0; i < 10; ++i) {
			Answer answer;
			int score;
			tie(answer, score) = solve(stage);
			
			if(score > maxScore) {
				maxScore = score;
				bestAnswer = answer;
			}
		}
	}
	
	//cout << maxScore << endl;
	for(auto& ans: bestAnswer) {
		cout << get<Y>(ans) + 1 << ' ' << get<X>(ans) + 1 << endl;
	}
	
	
	return 0;
}