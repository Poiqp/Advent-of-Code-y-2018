#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;



char sw, ss;
string str, org;
int w = 0;
int s = 1; 
ifstream myfile;

char mala, duza;
int iter;





int main()
{
	myfile.open("input.txt");
	getline(myfile, org);
	myfile.close();
	
	iter = 65;

	while(iter != 91 ){
		
		str = org;

		duza = iter;
		mala = iter + 32;


		str.erase(std::remove(str.begin(), str.end(), duza), str.end());
		str.erase(std::remove(str.begin(), str.end(), mala), str.end());


		cout << duza << mala << endl;

		while (s < str.length()) {

			sw = str[w];
			ss = str[s];

			if (abs(sw - ss) == 32) {
				str.erase(w, 2);
				if (w != 0) { w--; s--; }
			}
			else { w++; s++; }

		}
		w = 0; s = 1;
		cout << str.length() << endl;
		iter++;
	}

	
	

	
}

