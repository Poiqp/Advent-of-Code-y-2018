#include "pch.h"
#include <fstream>
#include <algorithm>
#include <list>
#include <iostream>


using namespace std;


string dane;
list<int> listasum = { 0 };
ifstream myfile;

int sum = 0;
int znalezionko = 0;
int num;




bool contains(int & element)
{
	auto it = std::find(listasum.begin(), listasum.end(), element);
	//return if iterator points to end or not. It points to end then it means element
	// does not exists in list
	if (it != listasum.end()) { return (true); }
	else  {return (false); }

}




int main()
{
	myfile.open("input.txt");

	while (znalezionko == 0 ) {
		
		if ( myfile.eof()) {
			cout << "zapetlilem sie" << endl;
			myfile.seekg(0); 
		}

		myfile >> num;
		sum += num;

		if (contains(sum) == true) { znalezionko = sum; }
		else { listasum.push_front(sum); }

	}

	myfile.close();

/*	for (auto v : listasum)
		std::cout << v << "\n";  */


	cout << "\nOto znalezionko  " << znalezionko;

	return(0);
}

