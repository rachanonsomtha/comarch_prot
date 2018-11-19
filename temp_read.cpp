#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;


string inst[20];
string num[5][100];

int n = 0;

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
	string binary="";
	string result="";

	if(num <=7) {
		result= "";
		if(num <=3) {
			result="0";
			if(num <=1) {
				result="00";
			}
		}
	}
	while(coefficient != 0) {
		binary += to_string(numerator % 2);
		coefficient = numerator / 2;
		numerator = coefficient;
	}
	binary =  ReverseString(binary);
	result+=binary;
	return result;
}



void printWords(string str) {
	string word;
	stringstream iss(str);
	int nLine = 0;
	while (iss >> word) {
		if((word == "start" || word == "done" || word == "five"  || word == "neg" || word == "stAddr" )&& nLine == 0) {
			num[3][n] = word;
			nLine--;
		}
		if(nLine == 0) {
			inst[n] = word;
		}
		if(nLine > 0) {
			num[nLine-1][n] = word;
		}
		nLine++;
	}
	n++;

}

string printWords_in(string str) {
	string word;
	stringstream iss(str);

	while (iss >> word)
		cout<<word<<endl;
	cout<<endl;
	return word;
}


// convert string n to dicimal
int convertBinaryToDecimal(string  n) {
	string reverse = ReverseString(n);
	char cstr[n.size()];
	strcpy(cstr, reverse.c_str());
	unsigned int decimalNumber = 0, i = 0, remainder;
	while (i!=sizeof(cstr)) {
		remainder = (int)cstr[i] -48;
		// cout<<decimalNumber <<endl;
		decimalNumber += (remainder*(pow(2,i)));
		// cout<<i <<endl;
		// cout<<decimalNumber <<endl;
		// cout<<endl;
		++i;
	}
	return decimalNumber;
}


void splitString(string str) {
	// Used to split string around spaces.
	istringstream ss(str);
	std::vector<string> ans (31);
	string str_ans[100];
	// Traverse through all words
	do {
		// Read a word
		string word;
		ss >> word;
		cout <<word<<endl;
		//R-type////////////////////////////////
		// Print the read word
		// While there is more to read
	} while (ss);
}
int main () {

//	for(int j = 0; j < 10; j++){
//		for(int i = 0; i < 4; i++){
//			cout << num[i][j] <<endl;
//		}
//	}
//	for(int j = 0; j < 10; j++){
//		cout << inst[j] <<endl;
//	}
	int numLines = 0;


	ifstream fileNum("C:/Users/LuckyCat/Desktop/jom/comarch_prot/test1.txt");
	std::string unused;
	while ( std::getline(fileNum, unused) ) {
		++numLines;
	}
	numLines -=1 ;

	///////////////////////////////
	ifstream file("C:/Users/LuckyCat/Desktop/jom/comarch_prot/test1.txt");
	string str;

	while (std::getline(file, str)) {
		printWords(str);
	}

	std::vector<string> ans (31);
	string ans_pos[numLines];
	string mem_addr[numLines];

	int start_addr;
	int done_addr;
	int five_addr;
	int stAddr;

	for(int i =0; i<numLines; i++) {
		if(num[3][i]=="start" ||num[3][i]=="done" ||num[3][i]=="five"||num[3][i]=="stAddr") {

			if(num[3][i]=="start") {
				start_addr=i;
			}
			if(num[3][i]=="done") {
				done_addr=i;
			}
			if(num[3][i]=="five") {
				five_addr=i;
			}
			if(num[3][i]=="stAddr") {
				stAddr=start_addr;
			}

		}

	}

	for(int i =0; i<numLines; i++) {
		// with start bla bla bla~
		if(inst[i] =="add" || inst[i]=="nand") { //with out calculation

			for(int j =0; j<7 ; j++) {   //fill 0 25-31
				ans.push_back("0");
			}
			if(inst[i] =="add") {

				ans.push_back("000"); //opcode =000
			}
			if(inst[i] =="nand") {
				ans.push_back("001"); // opcode =001
			}

			ans.push_back(binary(stoi(num[2][i]))); //rt
			ans.push_back(binary(stoi(num[1][i]))); //rs

			for(int i =0; i<13 ; i++) {
				ans.push_back("0");
			}

			ans.push_back(binary(stoi(num[0][i])));  //rd

			string ansz;
			int int_ans;
			for(int i =0; i<ans.size() ; i++) { // print out the result!!
				ansz+= ans.at(i);
			}

			if(num[3][i] =="start") {
				ans_pos[start_addr]=to_string(convertBinaryToDecimal(ansz));
			} else ans_pos[i]=to_string(convertBinaryToDecimal(ansz));

			ans.clear();


		}

		if(inst[i] =="lw" || inst[i]=="sw"||inst[i]=="beq") { // with calculation


			for(int j =0; j<7 ; j++) {   //fill 0 25-31
				ans.push_back("0");
			}
			if(inst[i] == "lw") {
				ans.push_back("010");// opcode=010
			}
			if(inst[i] == "sw") {
				ans.push_back("011");// opcode=011
			}
			if(inst[i] == "beq") {
				ans.push_back("100");// opcode=100
			}
			ans.push_back(binary(stoi(num[0][i])));
			ans.push_back(binary(stoi(num[1][i])));

			int number4; // default offset num

			if(num[2][i]=="start"|| num[2][i]=="five" || num[3][i]=="stAddr") { //find offset field num
				if(num[2][i]=="five") {
					number4 = five_addr - stoi(num[0][i]);
				}
				if(num[2][i]=="start") {
					if(inst[i]=="beq") {
						number4 = start_addr - i -1;
					}else number4 = start_addr - stoi(num[0][i]);
				}
				if(num[2][i]=="stAddr") {
					number4 = stAddr - stoi(num[0][i]);
				}
			} else number4  = stoi(num[2][i]) - stoi(num[0][i]);


			if(number4 < 0) {
				int con = number4 * (-1);
				con = con - 1;
				string neg;
				string im = (binary(con));
				ans.push_back("1");
				if(binary(con).length()<15) {
					for(int i=14 ; i>=binary(con).length() ; i--) {
						ans.push_back("1");
					}
				}

				for(int i=0 ; i <= im.length() ; i++) {
					if(im.substr(i,1) == "0") {
						neg += '1';
					} else if(im.substr(i,1) == "1") {
						neg += '0';
					}
				}
				ans.push_back(neg);

			}
			if(number4 >= 0) {
				ans.push_back("0");
				if(binary(number4).length()<15) {
					for(int i=14 ; i>=binary(number4).length() ; i--) {
						ans.push_back("0");
					}
				}

				int temp = number4;
				ans.push_back(binary(temp));
			}

			string ansz;
			int int_ans;
			for(int i =0; i<ans.size() ; i++) { // print out the result!!
				ansz+= ans.at(i);
			}

			if(num[3][i] =="start") {
				ans_pos[start_addr]=to_string(convertBinaryToDecimal(ansz));
			} else ans_pos[i]=to_string(convertBinaryToDecimal(ansz));

			ans.clear();

		}

		if(inst[i] =="jalr") { // no offset calculation yet

			for(int j =0; j<7 ; j++) {   //fill 0 25-31
				ans.push_back("0");
			}
			ans.push_back("101");// opcode=101
			ans.push_back(binary(stoi(num[0][i])));
			ans.push_back(binary(stoi(num[1][i])));
			for(int i =0; i<16 ; i++) {
				ans.push_back("0");
			}

			string ansz;
			int int_ans;
			for(int i =0; i<ans.size() ; i++) { // print out the result!!
				ansz+= ans.at(i);
			}

			if(num[3][i] =="start") {
				ans_pos[start_addr]=to_string(convertBinaryToDecimal(ansz));
			} else ans_pos[i]=to_string(convertBinaryToDecimal(ansz));

			ans.clear();

		}


		if(inst[i] == "halt" || inst[i] =="noop") {

			for(int j =0; j<7 ; j++) {   //fill 0 25-31
				ans.push_back("0");
			}
			if(inst[i] == "halt") {
				ans.push_back("110");// opcode=110
			}
			if(inst[i] == "noop") {
				ans.push_back("111");// opcode=111
			}
			for(int i =0; i<22 ; i++) {
				ans.push_back("0");
			}

			string ansz;
			int int_ans;
			for(int i =0; i<ans.size() ; i++) { // print out the result!!
				ansz+= ans.at(i);
			}

			if(num[3][i] =="start") {
				ans_pos[start_addr]=to_string(convertBinaryToDecimal(ansz));
			} else ans_pos[i]=to_string(convertBinaryToDecimal(ansz));
			ans.clear();

		}

		if(inst[i] ==".fill") { // no offset calculation yet

			if(num[3][i]=="stAddr") {
				ans_pos[i]=to_string(stAddr);
			} else ans_pos[i]=num[0][i];
		}

	}





	ofstream fileAns;
	fileAns.open ("C:/Users/LuckyCat/Desktop/jom/comarch_prot/ans.txt");
	for(int i =0; i<10; i++) {
		fileAns<<ans_pos[i]<<endl;
	}

	fileAns.close();

	for(int i =0; i<11; i++) {
		cout << ans_pos[i] <<endl;
	}

	return 0;
}
