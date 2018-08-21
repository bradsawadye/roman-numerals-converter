//
//  main.cpp
//  roman_numerals_converter
//
//  Created by the brad on 2017/04/08.
//  Copyright © 2017 The Brad. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string & converter(int number);
string & units(int number);
string & tens(int number);
string & hundreds(int number);

int main(int argc, const char * argv[]) {
    // insert code here...
    //cout << "Hello, World!\n";
    int number;
    cout << "Hi There."<<endl;
    cout << "Enter number: ";
    cin >> number;
    cout << "The number "<< number << " in roman numerals is "<<converter(number)<<endl;
    return 0;
}

string & converter(int number){
    static string x;

    x += hundreds(number);
    x += tens(number);
    x += units(number);

    return x;
}

string & units(int number) {
    static string x;
    int nuk = number%10;

    if (nuk != 0) {
        if (nuk == 9) {
            x += "IX";
        }
        if (nuk == 5){
            x += "V";
        }
        if (nuk == 4) {
            x += "IV";
        }
        if (nuk < 4 ){
            int vr = nuk - 4;

            for (int i = 0; i < vr; ++i) {
                x += "I";
            }
        }
        if (nuk > 5 && nuk < 9) {
            x += "V";
            for (int i = 0; i < (nuk-5); ++i) {
                x += "I";
            }

        }
    }

    return x;
}

string & tens(int number) {
    static string x;
    int tens = number%100;

    if (tens != 0 && tens >= 10) {
        if (tens >= 50 && tens < 90) {
            x += "L";
            for (int i =0; i < ceil(tens/10) -5; ++i) {
                x += "X";
            }
        }
        else if (tens < 50 && tens >= 40) {
            x += "XL";
        }
        else if (tens < 40 ) {

            for (int i = 0; i < round(tens/10); ++i) {
                x += "X";
            }
        }
        else {
            x += "XC";
        }
    }

    return x;
}

string & hundreds(int number) {
    static string x;
    int hundreds = number%1000;

    if (hundreds != 0 && hundreds >= 100) {
        if (hundreds < 400) {
            for (int i =0; i < round(hundreds/100); ++i) {
                x += "C";
            }
        }
        else if (hundreds < 500 && hundreds >= 400) {
            x += "CE";
        }
        else if (hundreds >= 500 && hundreds < 900) {
            x += "E";
            for( int i = 0; i < ceil(hundreds/100) -5; ++i) {
                x += "C";
            }
        }
        else {
            x += "CM";
        }
    }

    return x;
}
