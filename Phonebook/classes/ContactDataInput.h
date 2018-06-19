/**
 * Filename : ContactDataInput.h
 * Author : Sachin Singh
 * Description : 
 * 
*/
#ifndef CONTACTDATAINPUT_H_
#define CONTACTDATAINPUT_H_
#include "structures.h"

class ContactDataInput {
    private:
        bool mobileValidate(const char *num);
        bool emailValidate(const char *email);
        bool dobValidate(int date , int month , int year);
        char *inputString(char *str , int size);
    public:
        ContactDataInput();
        Name inputName();
        Number inputNumber();
        Email inputEmail();
        SocialNetwork inputSocialNetwork();
        DateOfBirth inputDateOfBirth();
        Address inputAddress();
        ShortNote inputShortNote();
};
#endif