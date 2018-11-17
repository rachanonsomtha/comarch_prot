#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;



string ReverseString(string str) {
	string new_string = "";
	for(int i=(str.length()-1); i>=0; i--)
		new_string += str.at(i);
	return new_string;
}


unsigned long long convertBinaryToDecimal(string  n) {
	string reverse = ReverseString(n);
	char cstr[n.size()];
	strcpy(cstr, reverse.c_str());
	unsigned int decimalNumber = 0, i = 0, remainder;
	while (i!=sizeof(cstr)) {
		remainder = (int)cstr[i] -48;
		//  cout<<decimalNumber <<endl;
		decimalNumber += (remainder*(pow(2,i)));
		cout<<decimalNumber<<endl;
		cout <<endl;
		//  cout<<i <<endl;

		//  cout<<decimalNumber <<endl;

		//  cout<<endl;
		++i;
	}
	return decimalNumber;
}


string binary(int num) {
	int coefficient = -1, numerator  = num;
	string binary;
	string result;



//	if(num <=7) {
//		result= "";
//		if(num <=3) {
//			result="0";
//			if(num <=1) {
//				result="00";
//			}
//		}
//	}

//	if(num<=7){
//		if(num<=1)binary="00";
//		else if(num<=3)binary="0";
//		else binary="";
//
//	}
	while(coefficient != 0) {
		binary += to_string(numerator % 2);
		coefficient = numerator / 2;
		numerator = coefficient;
	}
	binary =  ReverseString(binary);
	result+=binary;
	return result;
}




int main() {


	ofstream myfile;
	myfile.open ("C:/Users/LuckyCat/Desktop/comarch/example.txt");


	myfile <<setfill('0') <<setw(32)<<binary(8454151)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(9043971)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(655361)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(16842754)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(16842749)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(29360128)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(25165824)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(5)<<endl;
	myfile <<setfill('0') <<setw(32)<<binary(2)<<endl;

	myfile.close();

	return 0;




}

