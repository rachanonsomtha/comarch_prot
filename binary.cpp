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

// if(num<=7){
//  if(num<=1)binary="00";
//  else if(num<=3)binary="0";
//  else binary="";
//
// }
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
 cout<<word<<endl;
 cout<<endl;
  return word;
}


// convert string n to dicimal
unsigned long long convertBinaryToDecimal(string  n) {
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

int main() {

 std::vector<string> ans (31);

 int number1;

 int number2;

 int number3;
 
 int number4;

 string inst;

/// test input
 cout << "input your instruction :";
 cin >> inst;

 cout << "input your rd :";
 cin  >>number1;
 while(number1 >= 8){
  cout << "rd must least than 8";
  cout << endl;
  cout << "input your rd :";
  cin >> number1;
 }

 cout << "input your rs :";
 cin  >>number2;
 while(number2 >= 8){
  cout << "rs must least than 8";
  cout << endl;
  cout << "input your rs :";
  cin >> number2;
 }

 cout << "input your rt :";
 cin  >>number3;
 while(number3 >= 8){
  cout << "rt must least than 8";
  cout << endl;
  cout << "input your rt :";
  cin >> number3;
 }
 
 cout << "input your im :";
 cin  >>number4;
 while(number4 >= 32768 || number4 <= -32769){
  cout << "wrong im";
  cout << endl;
  cout << "input your im :";
  cin >> number3;
 }



 if(inst =="add" || inst =="nand") {
  for(int j =0; j<7 ; j++) {   //fill 0 25-31
   ans.push_back("0");
  }

  for(int j =0; j<3 ; j++) {  // opcode=000
   ans.push_back("0");
  }
  ans.push_back(binary(number3));
  ans.push_back(binary(number2));

  for(int i =0; i<13 ; i++) {
   ans.push_back("0");
  }
  ans.push_back(binary(number1));
  
 } else if(inst =="jalr" ) { // j-type

  for(int j =0; j<7 ; j++) {   //fill 0 25-31
   ans.push_back("0");
  }
  ans.push_back("101");// opcode=101
  ans.push_back(binary(number3));
  ans.push_back(binary(number1));
  for(int i =0; i<16 ; i++) {
   ans.push_back("0");
  }

 }else if(inst == "halt" || inst =="noop") {
  for(int j =0; j<7 ; j++) {   //fill 0 25-31
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
  
 }else if(inst == "lw" || inst =="sw" || inst == "beq"){
  for(int j =0; j<7 ; j++) {   //fill 0 25-31
   ans.push_back("0");
  }
  if(inst == "lw") {
   ans.push_back("010");// opcode=010
  }
  if(inst == "sw") {
   ans.push_back("011");// opcode=011
  }
  if(inst == "beq") {
   ans.push_back("100");// opcode=100
  }
  ans.push_back(binary(number2));
  ans.push_back(binary(number3));
  if(number4 < 0){ 
   int con = number4 * (-1);
   con = con - 1;   
   string neg;
   string im = (binary(con));
   ans.push_back("1");
   if(binary(con).length()<15){
    for(int i=14 ; i>=binary(con).length() ; i--){
     ans.push_back("1");
    }
   }

   for(int i=0 ; i <= im.length() ; i++){
    if(im.substr(i,1) == "0"){
     neg += '1';
    }else
    if(im.substr(i,1) == "1"){
     neg += '0';
    }
   }
   ans.push_back(neg);
   
  }
  if(number4 >= 0){
   ans.push_back("0");
   if(binary(number4).length()<15){
    for(int i=14 ; i>=binary(number4).length() ; i--){
     ans.push_back("0");
    }
   }
   ans.push_back(binary(number4));
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

 ifstream file("C:/Users/Aorjornor/Desktop/comarch/test1.txt");
 string str;
 while (std::getline(file, str)) {
  printWords(str);
 }


 return 0;
}
