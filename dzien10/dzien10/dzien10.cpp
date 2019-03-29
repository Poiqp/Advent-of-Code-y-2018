#include "pch.h"
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

class elf {
public:
	int X;
	int Y;
	int Vx;
	int Vy;

	elf() { X = 60000; Y = 60000; Vx = 0; Vy = 0; }

	void move(int sek) {
		X = X + Vx * sek;
		Y = Y + Vy * sek;
	}
};


elf parse_c(string str) {
	elf elf_;
	int pos;
	int position_start = str.find('<');
	int position_end = str.find(',');
	string fragment = str.substr(position_start + 1, position_end - position_start - 1);
	elf_.X = stoi(fragment);

	position_start = position_end;
	position_end = str.find('>');
	fragment = str.substr(position_start + 1, position_end - position_start - 1);
	elf_.Y = stoi(fragment);

	pos = position_end+1;
	position_start = str.find('<', pos);
	position_end = str.find(',',pos);
	fragment = str.substr(position_start + 1, position_end - position_start - 1);
	elf_.Vx = stoi(fragment);

	position_start = position_end;
	position_end = str.find('>',pos);
	fragment = str.substr(position_start + 1, position_end - position_start - 1);
	elf_.Vy = stoi(fragment);

	return elf_;
}




int main() {

	ifstream myfile;
	string line;
	list<elf> l = {};
	char tab_final[10000][10000] = {};



	myfile.open("input.txt");

	getline(myfile,line);
	elf k = parse_c(line);
	tab_final[k.X][k.Y] = '#';

	for (int i = 0; i < 5000; ++i)
	{
		for (int j = 0; j < 5000; ++j)
		{
			if (tab_final[j][i] == '#') { cout << "#"; }
			else { cout << "."; }

		}
	}


	//while (getline(myfile, line)) {
	////tworz kolejne elfy
	//}



	myfile.close();
}







	//cout << k.X << "   " << k.Y << "   " <<  k.Vx << "     " << k.Vy << endl;
	//k.move(1);
	//cout << "po 1 sek " << endl;
	//cout << k.X << "   " << k.Y << "   " <<  k.Vx << "     " << k.Vy << endl;
	//k.move(5);
	//cout << "po 5 sek " << endl;
	//cout << k.X << "   " << k.Y << "   " << k.Vx << "     " << k.Vy << endl;







//class janek {
//public:
//	int k;
//	int z;
//	void dodawanie(int m) { k = k + m; }
//
//	janek() {
//		k = 0;
//		z = 0;
//	}
//};
//
//
//
//int main()
//{
//	janek J;
//	cout << J.k << endl;
//	J.dodawanie(2);
//	cout << J.k << endl;
// 
//}
