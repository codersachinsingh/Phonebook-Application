/**
 * Filename : HeadersAndLines.h
 * Author : Sachin Singh
 * Description : 
 * 
*/

#ifndef HEADERSANDLINES_H_
#define HEADERSANDLINES_H_
class HeadersAndLines {
    private:
        int width;
        char ch;
    public:
        HeadersAndLines();
        HeadersAndLines(int width);
        HeadersAndLines(int width , char ch);
        void setWidth(int line_width);
        void header(const char *str);
        void header(const char *str , int width);
        void header(const char *str , int width , char ch);
        void header(const char *str1 , const char *str2 , const char *str3);
        void header(const char *str1 , const char *str2 ,int value);
        void line();
        void line(int width);
        void line(char ch);
        void line(int width , char ch);
        void printCenter(const char *str);
        void printCenter(const char *str1 , const char *str2);
        void printCenter(const char *str , int line_width);
        void clrscr();
};
#endif