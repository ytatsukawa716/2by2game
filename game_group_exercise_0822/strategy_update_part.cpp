#include "two_by_twogame_class.h"

void Strategy_Update_part::update_strategy() {
	int n = N / 2;
	int c_number = 0;
	double total_gain = c_gain + d_gain;
	double c_ratio = c_gain / total_gain;
	for (int i = 0; i < N; i++) {
		double random_number = random(1.0);
		if (random_number < c_ratio) {
			agent[i].strategy = C;
			c_number++;
		}
		else agent[i].strategy = D;
	}
	fc = double(c_number) / N;
}

void Strategy_Update_part::initialize() {
	int n = N / 2;
	Agent _agent;
	_agent.gain = 0;
	_agent.strategy = D;
	agent = std::vector<Agent>(N, _agent);
	vector<int> list(N);
	for (int i = 0; i < N; i++)list[i] = i;
	for (int i = 0; i < n; i++) {
		int size = list.size() - 1;
		int xsize = random(size);
		int number = list[xsize];
		list.erase(list.begin() + xsize);
		agent[number].strategy = C;
	}
}
