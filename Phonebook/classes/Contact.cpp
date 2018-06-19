/**
 * Filename : Contact.cpp
 * Author : Sachin Singh
 * Description : 
 * 
*/

#include "contact.h"
#include <cstring>

// Default Constructor
Contact::Contact() {

}

Contact::Contact(Name name , Number number) {
    this->name = name;
    this->contact_number = number;
}
void Contact::setName(Name name) {
    this->name = name;
}
Name Contact::getName() {
    return name;
}
void Contact::setNumber(Number number) {
    this->contact_number = number;
}
Number Contact::getNumber() {
    return contact_number;
}
void Contact::setEmail(Email email) {
    this->email = email;
}
Email Contact::getEmail() {
    return email;
}
void Contact::setSocialNetwork(SocialNetwork sn) {
    this->social_network = sn;
}
SocialNetwork Contact::getSocialNetwork() {
    return social_network;
}
void Contact::setDateOfBirth(DateOfBirth dob) {
    this->dob = dob;
}
DateOfBirth Contact::getDateOfBirth() {
    return this->dob;
}

void Contact::setAddress(Address address) {
    this->address = address;
}

Address Contact::getAddress() {
    return this->address;
}
void Contact::setShortNote(ShortNote note) {
    this->note = note;
}
ShortNote Contact::getShortNote() {
    return this->note;
}