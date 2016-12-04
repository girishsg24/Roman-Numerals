#include "RomanNumeral.h"
#include <iostream>
#include<string.h>
using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}
/**
* When input parameter is a string, initialize roman & decimal
*/
RomanNumeral::RomanNumeral(string roman1)
{
    roman=roman1;
    toDecimal();
}
/**
* When input parameter is int
*  initialize roman="" & decimal=input
*/
RomanNumeral::RomanNumeral(int value)
{
    decimal=value;
    toRoman();
}

int RomanNumeral::getDecimal()
{
 return decimal;   
}

string RomanNumeral::getRoman()
{
 return roman;   
}

int RomanNumeral:: getCharValue(char t)
{
    if (t=='X')
        return X;
    if(t=='V')
        return V;
    else if (t=='I')
        return I;
    else if (t=='L')
        return L;
    else if (t=='C')
        return C;
    else if (t=='D')
        return D;
    else if (t=='M')    
        return M;
}




/**
 * Convert Decimal to Roman value & store it in 'decimal' member variable
 */
void RomanNumeral:: toRoman()
{   string result="";
    int wholeNum=decimal;
    while(wholeNum>0)
    {
        if (wholeNum>1000)
        {
            result=result+'M';
            wholeNum=wholeNum-M;
        }
        else if (wholeNum>=500)
        {
            if (wholeNum>=900)
            {
                result=result+'C'+'M';
                wholeNum=wholeNum-900;
            }
            else
            {
                result=result+'D';
                wholeNum=wholeNum-500;
            }
        }
       
        else if(wholeNum>=100)
        {
            if(wholeNum>=400)
            {
                result=result+'C'+'D';
                wholeNum=wholeNum-400;
            }
            else
            {
                result=result+'C';
                wholeNum=wholeNum-100;
            }
        }
        else if(wholeNum>=50)
        {
            if(wholeNum>=(90))
            {
                result=result+'X'+'C';
                wholeNum=wholeNum-90; 
            }
            else
            {
                result=result+'L';
                wholeNum=wholeNum-50;   
            }
        }
        
        else if(wholeNum>=10)
        {
            if(wholeNum>=40)
            {
                result=result+'X'+'L';
                wholeNum=wholeNum-40;
            }
            else
            {
                result=result+'X';
                wholeNum=wholeNum-10;
            }
        }
        
        else if(wholeNum>=5)
        {
            if(wholeNum>=9)
            {
                result=result+'I'+'X';
                wholeNum=wholeNum-9;
            }
            else
            {
                result=result+'V';
                wholeNum=wholeNum-5;
            }
        }
        
        else if(wholeNum>=1)
        {
            if(wholeNum>=4)
            {
                result=result+'I'+'V';
                wholeNum=wholeNum-4;
            }
            else
            {
                result=result+'I';
                wholeNum=wholeNum-1;
            }
        }
    }    
    
roman= result;
}

/**
 * Convert Roman to decimal value & store it in 'roman' member variable
 */
void RomanNumeral:: toDecimal()
{   
    
    int prevChar=getCharValue(roman[0]);
    int curChar=0;
    decimal=getCharValue(roman[0]);
    for(int i=1,len=roman.length();i<len;i++)
    {
        curChar=getCharValue(roman[i]);
        if (prevChar<curChar)
            decimal=decimal-2*prevChar+curChar;
        else 
            decimal=decimal+curChar;
        prevChar=curChar;    
    }
    
}

RomanNumeral operator+( RomanNumeral r1, RomanNumeral r2)
{
    int pDecimal=r1.getDecimal()+r2.getDecimal();
    RomanNumeral result(pDecimal);
    return result;
}

RomanNumeral operator-( RomanNumeral r1, RomanNumeral r2)
{
    int pDecimal=r1.getDecimal()-r2.getDecimal();
    RomanNumeral result(pDecimal);
    return result;
}

RomanNumeral operator*( RomanNumeral r1,RomanNumeral r2)
{
    int pDecimal=r1.getDecimal()*r2.getDecimal();
    RomanNumeral result(pDecimal);
    return result;
}

RomanNumeral operator/( RomanNumeral r1,RomanNumeral r2)
{
    int pDecimal=r1.getDecimal()/r2.getDecimal();
    RomanNumeral result(pDecimal);
    return result;
}

bool operator==(RomanNumeral r1, RomanNumeral r2)
{
    if (r1.getDecimal()==r2.getDecimal())
    return true;
    return false;
}

bool operator!=( RomanNumeral r1, RomanNumeral r2)
{
    if (r1.getDecimal()!=r2.getDecimal())
    return true;
    return false;
}

istream& operator>>(istream& ins, RomanNumeral& r)
{
    ins>>r.roman;
    r.toDecimal();
    return ins;
}

ostream& operator<<(ostream& outs, RomanNumeral& r1)
{
   
    outs <<'['<< r1.getDecimal()<<':'<< r1.getRoman()<<']';
    return outs;
}