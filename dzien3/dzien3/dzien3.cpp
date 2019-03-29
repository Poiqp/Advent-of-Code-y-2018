#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


ifstream myfile, myfile2;
string line;
int material[2000][2000];
int amount = 0;
int wspx = 0;
int wspy = 0;
int id_samotnika = 0;

class claim {
public:
	int id;
	int L;
	int T;
	int W;
	int H;
	int p1x;
	int p1y;
	claim() { ; }
};

claim parse_c(string str) {
	claim claim_;
	int position_start = str.find('#');
	int position_end = str.find('@');
	string fragment = str.substr(position_start+1, position_end - position_start-1);
	claim_.id = stoi(fragment);

	position_start = position_end;
	position_end = str.find(',');
	fragment = str.substr(position_start + 1, position_end - position_start - 1);
	claim_.L = stoi(fragment);

	position_start = position_end;
	position_end = str.find(':');
	fragment = str.substr(position_start + 1, position_end - position_start - 1);
	claim_.T = stoi(fragment);

	position_start = position_end;
	position_end = str.find('x');
	fragment = str.substr(position_start + 1, position_end - position_start - 1);
	claim_.W = stoi(fragment);

	position_start = position_end;
	position_end = str.length();
	fragment = str.substr(position_start + 1, position_end - position_start - 1);
	claim_.H = stoi(fragment);

	claim_.p1x = claim_.L;
	claim_.p1y = claim_.T;

	return claim_;
}




int main()
{
	myfile.open("input.txt");
	

	while (getline(myfile, line)) {
		claim k = parse_c(line);

		for (int i = k.p1y; i < k.p1y + k.H; i++) {
			for (int j = k.p1x; j < k.p1x + k.W; j++) {
				material[i][j]++;
			}
		}
	}


	myfile.close();

	myfile2.open("input.txt");

	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			if (material[i][j] == 1) { 
				//cout <<"y: " << i << "     x: " << j  << endl;
			}
		}
	}

	myfile2.close();



	cout << "ID SAMOTNIKA " << id_samotnika << endl;

}




	/*
	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			if (material[i][j] > 1) { amount++; }
		}
	}
*/
