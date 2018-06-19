/**
 * Filename : ContactDataInput.cpp
 * Author : Sachin Singh
 * Description : 
 * 
*/
#include "ContactDatainput.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

ContactDataInput::ContactDataInput() {

}

Name ContactDataInput::inputName() {
    cout<<"* Enter Full Name : ";
    Name name;
    cin>>name.first_name>>name.last_name;
    cout<<endl;
    return name;
}

Number ContactDataInput::inputNumber() {
    bool flag = true;  // flag set to true.
    Number numbers;
    cout<<"* Enter Contact Number "<<endl;
    do {
        /*LABEL MOBILE*/
        mobile:
        cout<<endl;
        cout<<"\t ==> Mobile Number : ";
        cin>>numbers.mobile;
        if(!mobileValidate(numbers.mobile)) {
            cout<<endl<<"***INVALID MOBILE NUMBER. PLEASE ENTER AGAIN***"<<endl<<endl;
            goto mobile;
        }
        /*LABEL HOME*/
        home:
        cout<<endl;
        cout<<"\t ==> Home Number : ";
        cin>>numbers.home;
        if (!mobileValidate(numbers.home)) {
            cout<<endl<<"***INVALID MOBILE NUMBER. PLEASE ENTER AGAIN***"<<endl<<endl;
            goto home;
        }
        /*LABEL OFFICE*/
        office:
        cout<<endl;
        cout<<"\t ==> Office Number : ";
        cin>>numbers.office;
        if (!mobileValidate(numbers.office)) {
            cout<<endl<<"***INVALID MOBILE NUMBER. PLEASE ENTER AGAIN***"<<endl<<endl;
            goto office;
        }
        break;
    }while(flag);
    return numbers;
}
char *ContactDataInput::inputString(char *str , int size) {
    char buffer[1024];
    fflush(stdin);
    fgets(buffer,1024,stdin);
    for (int i = 0 ; buffer[i] || i < size ; i++) {
        if (buffer[i] != '\n')
        str[i] = buffer[i];
        else {
            str[i] = '\0';
            break;
        }
    }
    str[size-1] = '\0'; // terminate string.
    fflush(stdin);
    return str;
}
Email ContactDataInput::inputEmail() {
    bool flag = true;
    Email email;
    cout<<"* Enter Email Address "<<endl;
    do {
        /*LABEL PERSONAL*/
        personal:
        cout<<endl;
        cout<<"\t ==> Personal Email : ";
        cin>>email.personal;
        if(!emailValidate(email.personal)) {
            cout<<endl<<"***INVALID EMAIL ADDRESS PLEASE ENTER AGAIN***"<<endl<<endl;
            goto personal;
        }
        /*LABEL OFFICE*/
        office:
        cout<<endl;
        cout<<"\t ==> Office Email : ";
        cin>>email.office;
        if (!emailValidate(email.office)) {
            cout<<endl<<"***INVALID EMAIL ADDRESS PLEASE ENTER AGAIN***"<<endl<<endl;
            goto office;
        }
        break;
    }while(flag);
    return email;
}

SocialNetwork ContactDataInput::inputSocialNetwork() {
    bool flag = true;  // flag set to true.
    SocialNetwork social_network;
    cout<<"* Social Network Profiles "<<endl;

        /*LABEL FACEBOOK*/
        cout<<endl;
        cout<<"\t ==> Facebook Username : www.facebook.com/";
        cin>>social_network.facebook;

        /*LABEL TWITTER*/
        cout<<endl;
        cout<<"\t ==> Twitter Handle : @";
        cin>>social_network.twitter;
        
        /*LABEL INSTAGRAM*/
        cout<<endl;
        cout<<"\t ==> Instagram Username : www.instagram.com/";
        cin>>social_network.instagram;

        /*LABEL WEBSITE*/
        cout<<endl;
        cout<<"\t ==> Website : http://";
        cin>>social_network.website;

    return social_network;
}

DateOfBirth ContactDataInput::inputDateOfBirth() {
    DateOfBirth dob;
    while(true) {
        cout<<"* Enter Date of Birth : ";
        cin>>dob.date>>dob.month>>dob.year;
        if (dobValidate(dob.date,dob.month,dob.year))
            return dob;
        else
            cout<<endl<<"*** INVALID DATE. PLEASE ENTER AGAIN ***"<<endl;
    }
}

Address ContactDataInput::inputAddress() {
    Address address;
    cout<<"* Address "<<endl;
        /*LABEL Home*/
        cout<<endl;
        cout<<"\tHouse Number : ";
        inputString(address.house_no,6);
        /*LABEL Street number*/

        cin.clear();
        cout<<endl;
        cout<<"\tStreet Number : ";
        inputString(address.street_no,6);
        /*LABEL Locality*/
        cout<<endl;
        cout<<"\tLocality : ";
        inputString(address.locality,16);
        /*LABEL City*/
        cout<<endl;
        cout<<"\tCity : ";
        inputString(address.city,16);

        /*LABEL State*/
        cout<<endl;
        cout<<"\tState : ";
        inputString(address.state,16);


        /*LABEL Pin code*/
        cout<<endl;
        cout<<"\tPIN Code : ";
        inputString(address.pin_address,11);

    return address;
}

ShortNote ContactDataInput::inputShortNote() {
    ShortNote note;
    cout<<"* Note About This Contact :  ";
    inputString(note.note,51);
    return note;
}

bool ContactDataInput::emailValidate(const char *str) {
     int len;
    // check for null value
    char *temp = new char[len = strlen(str)];
    strcpy(temp,str);
    if (strcmp("NULL",strupr(temp))==0)
        return true;

    bool at_flag = false;
    bool dot_flag = false; 
    while(*str++) {
        if (*str == '@')
            at_flag = true;
        else if (*str == '.' && at_flag)
            dot_flag = true;
        if (at_flag && dot_flag)
            return true;
    }
    return false;
}
bool ContactDataInput::mobileValidate(const char *num) {
    int len;
    // check for null value
    char *temp = new char[len = strlen(num)];
    strcpy(temp,num);
    if (strcmp("NULL",strupr(temp))==0)
        return true;
    // check for length range 10 to 13.   
    else if (len != 10)
        return false;
    // check for alphanumeric character.
    for (int i = 0 ; num[i] ; i++) {
        if (num[i] < '0' || num[i] > '9')
            return false;
    }
    return true;
}

bool ContactDataInput::dobValidate(int date, int month , int year) {
    if (year < 1800 || year > 2200)
        return false;
    switch(month) {
        /*Month with 31 days*/
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
                return (date < 1 || date > 31)?false:true;
        }
        break;
        /*Month with 30 days*/
        case 4:
        case 6:
        case 9:
        case 11: {
                return (date < 1 || date > 30)?false:true;
        }
        break;
        /*Feburary month*/
        case 2: {
                if (year%4==0) {
                    return (date < 1 || date > 29)?false:true;
                }
                else
                    return (date < 1 || date > 28)?false:true;
        }
        break;
        /*Invalid month*/
        default:
            return false;
    }
}