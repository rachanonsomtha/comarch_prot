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


template <class N> N ToNumber(string string_number) {
	N number;
	istringstream iss(string_number);
	iss >> number;
	return number;
}



string ReverseString(string str) {
	string new_string = "";
	for(int i=(str.length()-1); i>=0; i--)
		new_string += str.at(i);
	return new_string;
}




string binary(int num) {
	int coefficient = -1, numerator  = num;
	string binary;
	string result;



	if(num <=7) {
		result= "";
		if(num <=3) {
			result="0";
			if(num <=1) {
				result="00";
			}
		}
	}

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



string printWords(string str) {
	string word;
	stringstream iss(str);

	while (iss >> word)
		return word;
}


unsigned long long convertBinaryToDecimal(string  n) {
	string reverse = ReverseString(n);
	char cstr[n.size()];
	strcpy(cstr, reverse.c_str());
	unsigned int decimalNumber = 0, i = 0, remainder;
	while (i!=sizeof(cstr)) {
		remainder = (int)cstr[i] -48;
		decimalNumber += (remainder*(pow(2,i)));
		++i;
	}
	return decimalNumber;
}

int main() {

	std::vector<string> ans (31);

	int number1;

	int number2;

	int number3;

	string inst;

/// test input
	cout << "input your instruction :";
	cin >> inst;

	cout << "input your rd :";
	cin  >>number1;

	cout << "input your rs :";
	cin  >>number2;

	cout << "input your rt :";
	cin  >>number3;



	if(inst =="add" || inst =="nand") { // i-type


		/*	ans.push_back(binary(number1));


			for(int i =0; i<14 ; i++) {
				ans.push_back("0");
			}


			ans.push_back(binary(number2));
			ans.push_back(binary(number3));


			for(int j =0; j<3 ; j++) {	 // opcode=000
				ans.push_back("0");
			}
			for(int j =0; j<8 ; j++) {	 	//fill 0 25-31
				ans.push_back("0");
			}*/

		for(int j =0; j<7 ; j++) {	 	//fill 0 25-31
			ans.push_back("0");
		}

		for(int j =0; j<3 ; j++) {	 // opcode=000
			ans.push_back("0");
		}
		ans.push_back(binary(number3));
		ans.push_back(binary(number2));

		for(int i =0; i<13 ; i++) {
			ans.push_back("0");
		}
		ans.push_back(binary(number1));



	} else

		if(inst =="jalr" ) { // j-type

			for(int j =0; j<7 ; j++) {	 	//fill 0 25-31
				ans.push_back("0");
			}
			ans.push_back("101");// opcode=101
			ans.push_back(binary(number2));
			ans.push_back(binary(number1));
			for(int i =0; i<16 ; i++) {
				ans.push_back("0");
			}

		}

	if(inst == "halt" || inst =="noop") {
		for(int j =0; j<7 ; j++) {	 	//fill 0 25-31
			ans.push_back("0");
		}
		if(inst == "halt") {
			ans.push_back("110");// opcode=110
		}
		if(inst == "noop") {
			ans.push_back("111");// opcode=111
		}
		for(int i =0; i<22 ; i++) {
			ans.push_back("0");
		}
	}


	string ansz;
	unsigned long long int_ans=0;
	for(int i =0; i<ans.size() ; i++) { // print out the result!!
		ansz+= ans.at(i);
	}

	int_ans= convertBinaryToDecimal(ansz);
	cout << ansz.length();
	cout <<endl;
	cout <<ansz;
	cout <<endl;
	cout << int_ans;
	cout <<endl;
	cout << binary(number1);
	cout <<endl;
	cout << binary(number2);
	cout <<endl;
	cout << binary(number3);
	cout <<endl;

	ifstream file("C:/Users/LuckyCat/Desktop/comarch/test1.txt");
	string str;
	while (std::getline(file, str)) {
		printWords(str);
	}


	return 0;
}
