/**
 * Filename : ContactManager.cpp
 * Author : Sachin Singh
 * Description : 
 * 
*/
#include "ContactsManager.h"
#include "Contact.h"
#include <iostream>
#include <cstring>
using namespace std;

ContactsManager::ContactsManager(const char *file_path) : contacts_file_path(file_path) {
    infile.open(contacts_file_path,ios::binary | ios::in);
    if (infile.is_open()) {
        cout<<"Reading File Data..."<<endl;
        while(true) {
            Contact c;
            infile.read((char*) &c , sizeof(c));
            if (infile.eof()) break;
            else
                contacts_array.insert(c);
            }
        sort();
        cout<<"Reading File Data Complete..Found "<<contacts_array.size()<<" Contacts"<<endl;
    }
    else {
        cout<<"Contacts File Not Found..."<<endl;
        cout<<"Creating New File..."<<endl;
        outfile.open(contacts_file_path,ios::trunc | ios::binary | ios::out);
        outfile.close();
        cout<<"Contact File Created.."<<endl;
        cout<<"Phonebook is Empty..."<<endl;
    }

}
/**
 * 
*/
void ContactsManager::saveAllContactsToFile() {
    outfile.open(contacts_file_path,ios::trunc | ios::binary | ios::out);
    if (outfile.is_open()) {
        for (int i = 0 ; i < contacts_array.size() ; i++) {
            Contact temp = contacts_array.get(i);
            outfile.write((char*) &temp , sizeof(Contact));
        }
        outfile.close();
    }
    else {
        cout<<"Error : Can't write to file."<<endl;
    }
}
/**
 * 
*/
void ContactsManager::sort()
{
    if (contacts_array.size() > 1)
    {
        for (int i = 0; i < contacts_array.size(); i++)
        {
            for (int j = 0; j < contacts_array.size() - i - 1; j++)
            {
                char name1[40] ="", name2[40] = "";
                strcat(name1, contacts_array[j].getName().first_name);
                strcat(name1, " ");
                strcat(name1, contacts_array[j].getName().last_name);
                strupr(name1);

                strcat(name2, contacts_array[j + 1].getName().first_name);
                strcat(name2, " ");
                strcat(name2, contacts_array[j + 1].getName().last_name);
                strupr(name2);
                if (strcmp(name1, name2) > 0)
                {
                    Contact temp;
                    temp = contacts_array[j];
                    contacts_array[j] = contacts_array[j + 1];
                    contacts_array[j + 1] = temp;
                }
            }
        }
    }
    else {
        return;
    }
}


void ContactsManager::deleteContact(int index) {
    contacts_array.remove(index);
    sort();
    saveAllContactsToFile();
}
int ContactsManager::setEditedContact(Contact contact , int index) {
    contacts_array.insert(index,contact);
    sort();
    saveAllContactsToFile();
}

int ContactsManager::addNewContact(Contact contact) {
    // insert contact to the array
    contacts_array.insert(contact);
    sort();
    // save contact to the file
    outfile.open(contacts_file_path,ios::app | ios::binary | ios::out);
    if (outfile.is_open()) {
        outfile.write((char*) &contact , sizeof(Contact));
        outfile.close();
    }
    else {
        cout<<"Error : Cant insert new contact"<<endl;
    }
}

void ContactsManager::getSearchResult(const char *first_name , const char *last_name ,Vector<Contact> &results, int *index , int &size) {
    int n = 0;
    
    for (int i = 0 ; i < contacts_array.size() ; i++) {
        char name1[40] = "", name2[40] = "";
        strcat(name1, contacts_array[i].getName().first_name);
        strcat(name1, " ");
        strcat(name1, contacts_array[i].getName().last_name);
        strupr(name1);

        strcat(name2,first_name);
        strcat(name2, " ");
        strcat(name2,last_name);
        strupr(name2);
        /*Match Full Name*/
        if (strcmp(name1,name2) == 0) {
            results.insert(contacts_array[i]);
            index[n++] = i;
            size++;
            continue;
        }
        /*Match First Name and Last Name */
        if (strcmp(first_name,contacts_array[i].getName().first_name)==0 || strcmp(last_name,contacts_array[i].getName().last_name)==0) {
            results.insert(contacts_array[i]);
            index[n++] = i;
            size++;
        }
    }
}
int ContactsManager::getTotalContact() {
    return contacts_array.size();
}

Contact ContactsManager::getContactByIndex(int index) {
    return contacts_array.get(index);
}