#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

struct Tree {

	int val;
	Tree* left = nullptr;
	Tree* right = nullptr;


};

Tree* merge(Tree* t1, Tree* t2)
{
	Tree* t = new Tree();
	t->val = t1->val + t2->val;

	if(t1->left != nullptr && t2->left != nullptr) {
		t->left = merge(t1->left, t2->left);
	}

	if(t1->right != nullptr && t2->right != nullptr) {
		t->right = merge(t1->right, t2->right);
	}

	return t;
}

Tree* parse(string& s, int& cur)
{
	//cout << cur << endl;
	Tree* t = new Tree();

	if(s[cur + 1] == ')') {
		t->left = nullptr;
		cur += 2;
	} else {
		++cur;
		t-> left = parse(s, cur); 
	}

	cur++;
	int val = 0;
	while(isdigit(s[cur])) {
		val = val * 10 + s[cur] - '0';
		cur++;
	}

	t->val = val;

	cur++;

	if(s[cur + 1] == ')') {
		t->right = nullptr;
		cur += 2;
	} else {
		++cur;
		t->right = parse(s, cur);
	}
	
	cur++;
	return t;
}

void output(Tree* t) {
	if(t->left == nullptr) {
		cout << "()";
	} else {
		cout << "(";
		output(t->left);
		cout << ")";
	}
	cout << "[" << t->val << "]";

	if(t->right == nullptr) {
		cout << "()";
	} else {
		cout << "(";
		output(t->right);
		cout << ")";
	}
}

int main(void) {
	
	string a, b;
	cin >> a >> b;

	int cur = 0;
	Tree* t1 = parse(a, cur);
	cur = 0;
	Tree* t2 = parse(b, cur);
	//output(t1);
	//cout << endl;

	//output(t2);
	//cout << endl;

	Tree* t = merge(t1, t2);
	output(t);
	cout << endl;
	return 0;
}
