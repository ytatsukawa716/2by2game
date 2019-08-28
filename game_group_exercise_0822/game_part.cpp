#include "two_by_twogame_class.h"

void Game_part::select_people() {
	int n = N / 2;
	fight_pair = vector<vector<int>>(n, vector<int>(2));
	vector<int> list(N);
	for (int i = 0; i < N; i++) list[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			int size = list.size() - 1;
			int xsize = random(size);
			int num = list[xsize];
			list.erase(list.begin() + xsize);
			fight_pair[i][j] = num;
		}
	}
}

void Game_part::decide_gain() {
	int n = N / 2;
	c_gain = 0;
	d_gain = 0;
	for (int i = 0; i < n; i++) {
		int left = fight_pair[i][0];
		int right = fight_pair[i][1];
		if (agent[left].strategy == C and agent[right].strategy == C) {
			agent[left].gain = agent[right].gain = 1;
			c_gain += 2 + 2;
		}
		else if (agent[left].strategy == C and agent[right].strategy == D) {
			agent[left].gain = -dr;
			agent[right].gain = 1 + dg;
			c_gain += 1 - dr;
			d_gain += 2 + dg;
		}
		else if (agent[left].strategy == D and agent[right].strategy == C) {
			agent[left].gain = 1 + dg;
			agent[right].gain = -dr;
			c_gain += 1 - dr;
			d_gain += 2 + dg;
		}
		else if (agent[left].strategy == D and agent[right].strategy == D) {
			agent[left].gain = agent[right].gain = 0;
			d_gain += 1 + 1;
		}
	}
}
