#include "two_by_twogame_class.h"
#include <cmath>
#include <fstream>
#include <string>

void Loop::loop() {
	N = 10000;
	string file_name = "result.csv";
	ofstream ofs(file_name);
	ofs << "dg,dr,fc" << endl;
	for (int i = -10; i < 11; i++) {
		dg = i * 0.1;
		for (int j = -10; j < 11; j++) {
			dr = j * 0.1;
			double fc_result = 0;
			double fc_sum = 0;
			int ensemble = 100;
			for (int k = 0; k < ensemble; k++) {
				double error = pow(10, -2.0);
				double fc_old = 0;
				double fc_new = 0;
				initialize();
				for (int i = 0; i < 20; i++) {
					select_people();
					decide_gain();
					update_strategy();
				}
				do {
					fc_old = fc_new;
					double _fc_sum = 0;
					bool fg = false;
					for (int i = 0; i < 100; i++) {
						select_people();
						decide_gain();
						update_strategy();
						if (fc == 0 or fc == 1) {
							_fc_sum = fc * 100;
							fg = true;
							break;
						}
						else _fc_sum += fc;
					}
					fc_new = _fc_sum / 100;
					if (fg) break;
				} while (abs(fc_old - fc_new) > error);
				fc_sum += fc_new;
			}
			fc_result = fc_sum / ensemble;
			ofs << dg << "," << dr << "," << fc_result << endl;
			cout << "dg:" << i * 0.1 << "  dr:" << j * 0.1 << "  finish!" << endl;
		}
	}
	ofs.close();
}