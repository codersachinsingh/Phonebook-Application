/**
 * Filename : Structures.h
 * Author : Sachin Singh
 * Description : 
 * 
*/
#ifndef STRUCTURES_H_
#define STRUCTURES_H_

struct Name {
    char first_name[20];
    char last_name[20];
};

struct Number {
    bool isWhatsApp;
    char mobile[12];
    char home[12];
    char office[12];
};

struct Email {
    char office[30];
    char personal[30];
};

struct SocialNetwork {
    char facebook[25];
    char twitter[25];
    char instagram[25];
    char website[30];
};

struct DateOfBirth {
    int date;
    int month;
    int year;
};

struct Address {
    char house_no[6];
    char street_no[6];
    char locality[16];
    char city[16];
    char state[16];
    char pin_address[11];
};

struct ShortNote {
    char note[50];
};

#endif