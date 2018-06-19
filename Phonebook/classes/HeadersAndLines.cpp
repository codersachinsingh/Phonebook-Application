/**
 * Filename : HeadersAndLines.cpp
 * Author : Sachin Singh
 * Description : 
 * 
*/
#include "headersandlines.h"
#include <cstring>
#include <iostream>
using namespace std;

// DEFAULT CONSTRUCTOR
HeadersAndLines::HeadersAndLines() {
    cout<<"Initializing UI.."<<endl;
    this->width = 80;
    this->ch = '-';
}
HeadersAndLines::HeadersAndLines(int width) {
    this->width = width;
    this->ch = '*';
}

// CONSTRUCTOR WITH WIDTH AND CHARACHTER
HeadersAndLines::HeadersAndLines(int width , char ch) {
    this->width = width;
    this->ch = ch;
}
// set width
void HeadersAndLines::setWidth(int line_width) {
    this->width = line_width;
}
// DEFAULT HAEDER
void HeadersAndLines::header(const char *str) {
    header(str,this->width,this->ch);
}

void HeadersAndLines::header(const char *str , int line_width) {
    header(str,line_width,this->ch);
}

void HeadersAndLines::header(const char *str , int line_width , char line_char) {
    int str_len = strlen(str);
    int space = line_width - str_len;
    //print above line of dashes.
    for (int i = 0 ; i < line_width ; i++) {
        cout<<line_char;
    }
    //new line
    cout<<endl;

    //white space before string
    for (int i = 0 ; i < space/2 ; i++) {
        cout<<' ';
    }

    //print string
    cout<<str;

    //white space before string
    for (int i = 0 ; i < space/2 ; i++) {
        cout<<' ';
    }

    //new line
    cout<<endl;

    //print below line of dashes.
    for (int i = 0 ; i < line_width ; i++) {
        cout<<line_char;
    }
    //new line
    cout<<endl;
}


void HeadersAndLines::header(const char *str1 , const char *str2 , int value) {
    int len_str_1 = strlen(str1);
    int len_str_2 = strlen(str2);
    int space = this->width - (len_str_1 + len_str_2 + 4);
    for (int i = 0 ; i < this->width ; i++)
        cout<<this->ch;
    cout<<endl;
    int p  = this->width - len_str_1;
    for (int i = 0 ; i < p/2; i++)
        cout<<" ";
    cout<<str1;
    int s = (p/2) - (len_str_2 + 4);
    for (int i = 0 ; i < s ; i++)
        cout<<" ";
    cout<<str2<<value<<".";
    cout<<endl;
    for (int i = 0 ; i < this->width ; i++)
        cout<<this->ch;
    cout<<endl;

}

void HeadersAndLines::header(const char *str1 , const char *str2 , const char *str3) {
    int space = this->width - (strlen(str1) + strlen(str2) + strlen(str3) + 1);
    for (int i = 0 ; i < this->width ; i++)
        cout<<this->ch;
    cout<<endl;
    for (int i = 0 ; i < space/2 ; i++)
        cout<<" ";
    cout<<str1<<str2<<" "<<str3;
    for (int i = 0 ; i < space/2 ; i++)
        cout<<" ";
    cout<<endl;
    for (int i = 0 ; i < this->width ; i++)
        cout<<this->ch;
    cout<<endl;
}
void HeadersAndLines::printCenter(const char *str) {
    printCenter(str,this->width);
}
void HeadersAndLines::printCenter(const char *str , int line_width) {
    int space = line_width - strlen(str);
    for (int i = 0 ; i < space /2 ; i++ ) {
        cout<<' ';
    }
    cout<<str;
    for (int i = 0 ; i < space / 2 ; i++) {
        cout<<' ';
    }
    cout<<endl;
}

void HeadersAndLines::printCenter(const char *str1 , const char *str2) {
    int len = strlen(str1) + strlen(str2) + 1;
    int space = this->width - len;
    for (int i = 0 ; i < space/2 ; i++)
        cout<<" ";
    cout<<"*** "<<str1<<" "<<str2<<" ***";
    for (int i = 0 ; i < space/2 ; i++)
        cout<<" ";
    cout<<endl;
}

void HeadersAndLines::line() {
    line(this->width , this->ch);
}
void HeadersAndLines::line(int line_width) {
    line(line_width,this->ch);
}
void HeadersAndLines::line(char ch) {
    line(this->width,ch);
}
void HeadersAndLines::line(int line_width , char ch) {
    for (int i = 0 ; i < line_width ; i++) {
        cout<<ch;
    }
    cout<<endl;
}

void HeadersAndLines::clrscr() {
    for (int i = 0 ; i < 30 ; i++)
        cout<<endl;
}