/**
 * Filename : Contact.h
 * Author : Sachin Singh
 * Description : 
 * 
*/

#ifndef CONTACT_H_
#define CONTACT_H_
#include "structures.h"

/**
 *  class Contact 
 */
class Contact {
    private:
        // Comman Details of a Person
        Name name;
        Number contact_number;
        Email email;
        SocialNetwork social_network;
        DateOfBirth dob;
        Address address;
        ShortNote note;
    public:
        //Getters and Setters for all fields
        Contact();
        Contact(Name name , Number number);
        void setName(Name name);
        Name getName();
        void setNumber(Number number);
        Number getNumber();
        void setEmail(Email email);
        Email getEmail();
        void setSocialNetwork(SocialNetwork sn);
        SocialNetwork getSocialNetwork();
        void setDateOfBirth(DateOfBirth dob);
        DateOfBirth getDateOfBirth();
        void setAddress(Address address);
        Address getAddress();
        void setShortNote(ShortNote note);
        ShortNote getShortNote();
};


#endif