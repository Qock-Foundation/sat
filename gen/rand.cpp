#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Use program correctly!\n";
		return 1;
	}
	int cnt_var, cnt_cl, cl_size;
	cout << "Number of variables: ";
	cin >> cnt_var;
	cout << "Clause size: ";
	cin >> cl_size;
	cout << "Number of clauses: ";
	cin >> cnt_cl;
	vector<vector<int>> prob;
	mt19937 rng(time(0));
	for (int i = 0; i < cnt_cl; ++i) {
		prob.emplace_back();
		for (int j = 0; j < cl_size; ++j) {
			prob.back().push_back((rng() % cnt_var + 1) * (rng() % 2 ? 1 : -1));
		}
	}
	ofstream fout(argv[1]);
	fout << "p cnf " << cnt_var << ' ' << cnt_cl << '\n';
	for (const auto& clause : prob) {
		for (auto var : clause) {
			fout << var << ' ';
		}
		fout << 0 << '\n';
	}
}
