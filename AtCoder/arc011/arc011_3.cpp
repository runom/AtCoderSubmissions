#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    vector<string> words;//単語リスト
	string first,last,word;//入力用
	int n;//単語の数
	cin >> first >> last;
	cin >>n;
	
	words.reserve(n+2);
	int size = first.size();//単語の文字数
	words.push_back(first);words.push_back(last);
	
	for(int i = 0; i < n; ++i){
		cin >> word;
		words.push_back(word);
	}
    words.erase(unique(words.begin() + 2,words.end()),words.end());
	n = words.size();
	vector<vector<int> > graph(words.size());//グラフ
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			int count = 0;
			for(int k = 0; k < size; ++k){
				if(words[i][k] != words[j][k]){
					if(++count >= 2)break;
				}
			}
			if(count<=1){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	
	queue<int> q;//BFS
	q.push(1);
	vector<int> path(words.size(),-1);
	
	while(!q.empty()){
		int current = q.front();q.pop();
		for(int i = 0; i < static_cast<int>(graph[current].size()); ++i){
			int next = graph[current][i];
			if(path[next] != -1){
				continue;
			}
			path[next] = current;
			q.push(next);
		}
	}
	
	if(path[0] == -1){
		cout << -1 << endl;
		return 0;
	}
	
	vector<int> answer;
	answer.push_back(0);
	while(answer.back() != 1){
		answer.push_back(path[answer.back()]);
	}
	cout << answer.size() - 2 << endl;
	for(int i = 0; i < static_cast<int>(answer.size()); ++i){
		cout << words[answer[i]] << endl;
	}
}