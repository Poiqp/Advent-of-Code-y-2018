#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

ifstream myfile;
string stmp;
vector<char> wektor_l{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<int>  wektor_w{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };


vector<char> mini_l{ 'a','b','c' };
vector<int>  mini_w{  0 , 0 , 0 };

int main()
{
	myfile.open("input.txt");

	while (myfile >> stmp) {





	}
   
}