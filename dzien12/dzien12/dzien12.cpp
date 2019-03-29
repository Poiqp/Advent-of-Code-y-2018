#include "pch.h"
#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main()
{
	std::set<int> myset;
	std::set<int>::iterator it;
	std::pair<std::set<int>::iterator, bool> ret;
	ifstream myfile;

	int sum=0 ;
	int num;
	int znalezionko = 0;
	bool czy = false;



	myfile.open("input.txt");

	while (czy==false) {

		if (myfile.eof()) {
			cout << "zapetlilem sie" << endl;
			myfile.seekg(0);
		}

		myfile >> num;
		sum += num;

		ret = myset.insert(sum);

		if (ret.second == false) {
			znalezionko = sum;
			czy = true;
		}
	}

	myfile.close();


	cout << "\nOto znalezionko  "<<sum;

	return(0);


	}
