#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include<iostream>
#include<string.h>
using namespace std;
class RomanNumeral
{
public:
    RomanNumeral();
    RomanNumeral(string roman1);
    RomanNumeral(int value);
    int getDecimal();
    string getRoman();
    friend RomanNumeral operator +( RomanNumeral r1, RomanNumeral r2);
    friend RomanNumeral operator -( RomanNumeral r1,RomanNumeral r2);
    friend RomanNumeral operator *( RomanNumeral r1, RomanNumeral r2);
    friend RomanNumeral operator /( RomanNumeral r1, RomanNumeral r2);
    friend bool operator ==( RomanNumeral r1, RomanNumeral r2);
    friend bool operator !=( RomanNumeral r1, RomanNumeral r2);
    friend istream& operator >>(istream& ins, RomanNumeral& bd);
    friend ostream& operator<<(ostream& outs, RomanNumeral& r1);
    
private:
    string roman;      // Roman numeral as a string
    int decimal;    // decimal value of the Roman numeral
    int I=1;
    int V=5;
    int X=10;
    int L=50;
    int C=100;
    int D=500;
    int M=1000;
    int getCharValue(char t);
    void toRoman();    // calculate string from decimal value
    void toDecimal();  // calculate decimal value from string
};
#endif /* ROMANNUMERAL_H_ */