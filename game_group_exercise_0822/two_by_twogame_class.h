#ifndef TOW_BY_TOWGAME_CLASS_H
#define TOW_BY_TOWGAME_CLASS_H
#include<vector>
#include "random.h"
#include <iostream>

#define C 0
#define D 1

using namespace std;

struct Agent {
	double gain;
	int strategy;
};

class Game_part{
public:
	int N;
	double dg;
	double dr;
	double c_gain;
	double d_gain;
	vector<Agent> agent;
	vector<vector<int>> fight_pair;
	void select_people();
	void decide_gain();
};

class Strategy_Update_part : public Game_part {
public:	
	double fc;
	void update_strategy();
	void initialize();
};

class Loop : public Strategy_Update_part {
public:
	void loop();
};

#endif // !TOW_BY_TOWGAME_CLASS_H
