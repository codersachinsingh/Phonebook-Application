/**
 * Filename : UserInterface.h
 * Author : Sachin Singh
 * Description : 
 * 
*/
#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include "HeadersAndLines.h"
#include "ContactsManager.h"
#include "Contact.h"
#include "structures.h"
#include "ContactDataInput.h"

class UserInterface {
    private:
        HeadersAndLines ui_headers;
        ContactsManager contact_manager;
        ContactDataInput data_input;
        bool mobile_number_validate(const char *num);
        bool email_validate(const char *email);
        UserInterface();
    public:
        static UserInterface *getInstance();
        void viewAllContact();
        void completeContactView(int index);
        void createNewContact();
        void editContact(int index);
        void search_edit_delete();    
        void mainMenu();
        void ui_settings();
        void about_application();
        void help_desk();
};

#endif