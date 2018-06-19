/**
 * Filename : ContactManager.h
 * Author : Sachin Singh
 * Description : 
 * 
*/
#ifndef CONTACTSMANAGER_H_
#define CONTACTSMANAGER_H_
#include "Vector.h"
#include "Contact.h"
#include <fstream>
class ContactsManager {
    private:
        Vector<Contact> contacts_array;
        const char * contacts_file_path;
        void saveAllContactsToFile();
        void sort();
        ofstream outfile; // file output stream
        ifstream infile; // file input stream
    public:
        ContactsManager(const char *file_path);
        Contact getContactByIndex(int index);
        int addNewContact(Contact contact);
        void deleteContact(int index);
        void getSearchResult(const char *first_name , const char *last_name , Vector<Contact> &results ,int *index , int& size);
        int setEditedContact(Contact contact , int index);
        int getTotalContact();
};
#endif