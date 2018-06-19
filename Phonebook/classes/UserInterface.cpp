/**
 * Filename : UserInterface.cpp
 * Author : Sachin Singh
 * Description : 
 * 
*/

#include "userinterface.h"
#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <cstring>

using namespace std;

UserInterface::UserInterface() : contact_manager("contact_file.phb") {
    ui_headers.setWidth(100);
}

UserInterface* UserInterface::getInstance() {
    return new UserInterface();
}


/**
 * MAIN MENU FUNCTION : DISPLAYS THE INITIAL MENU OF THE APPLICATION
*/
void UserInterface::mainMenu() {
    int option = 0;
    do {
        ui_headers.header(":: Phonebook : Main Menu ::");
        cout << "1. View All Contacts."<<endl<<
                "2. Add New Contact."<<endl<<
                "3. Search , Edit and Delete."<<endl<<
                "4. UI Settings."<<endl<<
                "5. User Manual and Help."<<endl<<
                "6. About Application"<<endl<<
                "7. Exit."<<endl<<endl;
        ui_headers.line();
        cout<<"Enter Your Choice : ";
        cin>>option;
        cin.clear();
        cout<<endl;
        ui_headers.line();
        switch(option) {
            /*VIEW ALL CONTACT*/
            case 1: {
                viewAllContact();
            }
                break;
            /*ADD NEW CONTACT*/
            case 2: {
                createNewContact();
            }
                break;
            /*SEARCH EDIT DELELTE*/
            case 3: {
                search_edit_delete();
            }
                break;
            case 4: {
                    ui_settings();
            }
                break;
            /*USER MANUAL*/
            case 5: {
                help_desk();
            }
                break;
            /* ABOUT APPLICATION*/
            case 6: {
                  about_application();
            }
                break;
            /*EXIT*/
            case 7 : {
                cout<<"Closing Application"<<endl;
                cout<<"Good Bye"<<endl;
            }
                break;
            default: {
                ui_headers.clrscr();
                ui_headers.line(50,'*');
                cout<<"YOU ENTERED A WRONG INPUT. PLEASE TRY AGAIN."<<endl;
                ui_headers.line(50,'*');
                cin.ignore();
                cin.sync();
            }
        }
    }while(option != 7);
}

void UserInterface::createNewContact() {
    ui_headers.header(":: Phonebook : Create New Contact ::");
    // Take Contact Fields Data from user
    
    Name name = data_input.inputName();
    Number number = data_input.inputNumber();
    Email email = data_input.inputEmail();
    Address address = data_input.inputAddress();
    SocialNetwork social_network = data_input.inputSocialNetwork();
    DateOfBirth dob = data_input.inputDateOfBirth();
    ShortNote note = data_input.inputShortNote();

    // Construct a New Contact
    Contact newContact(name,number);
    newContact.setEmail(email);
    newContact.setSocialNetwork(social_network);
    newContact.setDateOfBirth(dob);
    newContact.setAddress(address);
    newContact.setShortNote(note);

    // save the contact to file
    contact_manager.addNewContact(newContact);
    cout<<"*** NEW CONTACT ADDED TO PHONEBOOK ***"<<endl;
}

void UserInterface::viewAllContact() {
    ui_headers.header(":: Phonebook : All Contacts ::","Total Contact : ",contact_manager.getTotalContact());

    if (contact_manager.getTotalContact() != 0)
    {
        int option = -1;

        do
        {
            for (int i = 0; i < contact_manager.getTotalContact(); i++)
            {
                Contact contact = contact_manager.getContactByIndex(i);
                cout << i + 1 << ". " << contact.getName().first_name << " " << contact.getName().last_name << endl;
                cout << "\t" << (char)16 << " Contact Number " << endl;
                cout << "\t\tMobile : " << contact.getNumber().mobile << endl;
                cout << "\t\tOffice : " << contact.getNumber().office << endl;
                cout << "\t" << (char)16 << " Email Address  " << endl;
                cout << "\t\tPersonal : " << contact.getEmail().personal << endl;

                ui_headers.line('.');
            }

            

            ui_headers.line();
            cout << "1. Enter Contact Index For Complete Details." << endl
                 << "2. Enter 0 For Previous Menu" << endl;
            ui_headers.line();
            cout << "Enter Your Choice : ";
            cin >> option;
            /* CLEAR THE INPUT STREAM */
            cin.clear();
            cin.ignore();
            cin.sync();
            cout << endl;
            ui_headers.line();

            if (option >= 1 && option <= contact_manager.getTotalContact())
            {
                completeContactView(option - 1);
                if (contact_manager.getTotalContact() == 0)
                    viewAllContact();
            }
            else
            {
                if (option != 0)
                    cout << "*** INVALID INPUT ***" << endl;
            }

        } while (option != 0);
    }

    else
    {
        cout << "*** THERE IS NO CONTACTS IN PHONEBOOK ***" << endl;
    }
}
void UserInterface::completeContactView(int index) {
    

    int option = 0;
    do
    {
        Contact contact = contact_manager.getContactByIndex(index);
        Name name = contact.getName();
        Number number = contact.getNumber();
        Email email = contact.getEmail();
        SocialNetwork social_network = contact.getSocialNetwork();
        DateOfBirth dob = contact.getDateOfBirth();
        Address address = contact.getAddress();
        ShortNote note = contact.getShortNote();

        ui_headers.header(":: Phonebook : Contact View :: ", name.first_name, name.last_name);
        cout << (char)16 << " Name : " << name.first_name << " " << name.last_name << endl
             << endl;
        cout << (char)16 << " Contact Numbers : " << (char)25 << endl;
        cout << "\tMobile : " << number.mobile << endl;
        cout << "\tHome : " << number.home << endl;
        cout << "\tOffice : " << number.office << endl
             << endl;
        cout << (char)16 << " Email Address : " << (char)25 << endl;
        cout << "\tPersonal : " << email.personal << endl;
        cout << "\tOffice : " << email.office << endl
             << endl;
        cout << (char)16 << " Address : " << (char)25 << endl;
        cout << "\tHouse No. : " << address.house_no << " , Street No. : " << address.street_no << endl;
        cout << "\tLocality : " << address.locality << endl;
        cout << "\tCity : " << address.city << ", State : " << address.state << endl;
        cout << "\tPIN Code : " << address.pin_address << endl
             << endl;
        cout << (char)16 << " Date of Birth : " << dob.date << "-" << dob.month << "-" << dob.year << endl
             << endl;
        cout << (char)16 << " Social Network Profiles : " << (char)25 << endl;
        cout << "\tFacebook : " << social_network.facebook << endl;
        cout << "\tTwitter Handle : " << social_network.twitter << endl;
        cout << "\tInstagram : " << social_network.instagram << endl;
        cout << "\tWebsite : " << social_network.website << endl
             << endl;
        cout << (char)16 << " Note : " << endl;
        cout << "\t" << note.note << endl;

        ui_headers.line();
        cout << "1. Edit This Contact." << endl
             << "2. Delete This Contact." << endl
             << "3. Back." << endl;
        ui_headers.line();
        cout << "Enter Your Choice : ";
        cin >> option;
        /* CLEAR THE INPUT STREAM */
        cin.clear();
        cin.ignore();
        cin.sync();
        cout << endl;
        ui_headers.line();
        switch (option)
        {
        case 1:
        {
            editContact(index);
        }
        break;
        /* BACK CASE*/
        case 2:
        {
            contact_manager.deleteContact(index);
            cout << "*** CONTACT REMOVED FROM PHONEBOOK *** " << endl;
        }
        break;
        case 3:
        {
            cout << "*** GOING TO PREVIOUS MENU ***" << endl;
            ui_headers.line();
        }
        break;
        default:
        {
            ui_headers.clrscr();
            ui_headers.line(50, '*');
            cout << "YOU ENTERED A WRONG INPUT. PLEASE TRY AGAIN." << endl;
            ui_headers.line(50, '*');
        }
        }

    } while (option != 3);
}

void UserInterface::search_edit_delete() {
    ui_headers.header(":: Phonebook : Search ::");
    char first_name[20] , last_name[20];
    cout<<"Enter Full Name : ";
    cin>>first_name>>last_name;
    int *index_of_result = new int[contact_manager.getTotalContact()];
    int size = 0;
    Vector<Contact> results;
    contact_manager.getSearchResult(first_name,last_name,results,index_of_result,size);
    
    ui_headers.header(":: Phonebook : All Contacts ::","Total Contact : ",results.size());

    if (results.size() != 0)
    {
        int option = -1;

        do
        {
            for (int i = 0; i < results.size(); i++)
            {
                Contact contact = results.get(i);
                cout << i + 1 << ". " << contact.getName().first_name << " " << contact.getName().last_name << endl;
                cout << "\t" << (char)16 << " Contact Number " << endl;
                cout << "\t\tMobile : " << contact.getNumber().mobile << endl;
                cout << "\t\tOffice : " << contact.getNumber().office << endl;
                cout << "\t" << (char)16 << " Email Address  " << endl;
                cout << "\t\tPersonal : " << contact.getEmail().personal << endl;

                ui_headers.line('.');
            }

            

            ui_headers.line();
            cout << "1. Enter Contact Index For Complete Details." << endl
                 << "2. Enter 0 For Previous Menu" << endl;
            ui_headers.line();
            cout << "Enter Your Choice : ";
            cin >> option;
            /* CLEAR THE INPUT STREAM */
            cin.clear();
            cin.ignore();
            cin.sync();
            cout << endl;
            ui_headers.line();

            if (option >= 1 && option <= results.size())
            {
                completeContactView(index_of_result[option-1]);
                
            }
            else
            {
                if (option != 0)
                    cout << "*** INVALID INPUT ***" << endl;
            }

        } while (option != 0);
    }

    else
    {
        cout << "*** NO RESULTS FOUND FOR  "<<first_name<<" "<<last_name<<"***" << endl;
    }
    
}
void UserInterface::editContact(int index) {
    Contact contact = contact_manager.getContactByIndex(index);
   int option = 0;
    do {
        ui_headers.header(":: Phonebook : Edit Contact :: ",contact.getName().first_name,contact.getName().last_name);
        cout << "1. Change Name."<<endl<<
                "2. Change Number."<<endl<<
                "3. Change Email."<<endl<<
                "4. Change Social Network Info."<<endl<<
                "5. Change Address."<<endl<<
                "6. Change Short Note."<<endl<<
                "7. Back."<<endl;
        ui_headers.line();
        cout<<"Enter Your Choice : ";
        cin>>option;
        /* CLEAR THE INPUT STREAM */
        cin.clear();
        cin.ignore();
        cin.sync();
        cout<<endl;
        ui_headers.line();
        switch(option) {
            /*Change Name*/
            case 1: {
                    Name name = data_input.inputName();
                    contact.setName(name);
                    contact_manager.deleteContact(index);
                    contact_manager.setEditedContact(contact,index);
            }
                break;
            /*Change Number*/
            case 2: {
                    Number number = data_input.inputNumber();
                    contact.setNumber(number);
                    contact_manager.deleteContact(index);
                    contact_manager.setEditedContact(contact,index);
            }
                break;
            /*Change Email*/
            case 3: {
                    Email email = data_input.inputEmail();
                    contact.setEmail(email);
                    contact_manager.deleteContact(index);
                    contact_manager.setEditedContact(contact,index);
            }
                break;
            /*Change Name*/
            case 4: {
                    SocialNetwork social_network = data_input.inputSocialNetwork();
                    contact.setSocialNetwork(social_network);
                    contact_manager.deleteContact(index);
                    contact_manager.setEditedContact(contact,index);
            }
                break;
            /*Change Name*/
            case 5: {
                    Address address = data_input.inputAddress();
                    contact.setAddress(address);
                    contact_manager.deleteContact(index);
                    contact_manager.setEditedContact(contact,index);
            }
                break;
            /*Change Name*/
            case 6: {
                    ShortNote note = data_input.inputShortNote();
                    contact.setShortNote(note);
                    contact_manager.deleteContact(index);
                    contact_manager.setEditedContact(contact,index);
            }
                break;
            case 7: {
                    cout<<"*** GOING TO PREVIOUS MENU *** "<<endl;
            }
                break;
            default: {
                ui_headers.clrscr();
                ui_headers.line(50,'*');
                cout<<"YOU ENTERED A WRONG INPUT. PLEASE TRY AGAIN."<<endl;
                ui_headers.line(50,'*');
            }
        }
        
    }while(option != 7);

}

/**
 * FUNCTION TO CHANGE THE LINE WIDTH OF THE APPLICATION
*/
void UserInterface::ui_settings() {
    int option = 0;
    do {
        ui_headers.header(":: Phonebook : UI Settings ::");
        cout << "1. Change Line Width."<<endl<<
                "2. Back."<<endl;
        ui_headers.line();
        cout<<"Enter Your Choice : ";
        cin>>option;
        /* CLEAR THE INPUT STREAM */
        cin.clear();
        cin.ignore();
        cin.sync();
        cout<<endl;
        ui_headers.line();
        switch(option) {
            case 1: {
                cout<<"Enter New Line Width : ";
                int line_width = 0;
                cin>>line_width;
                if (line_width >= 50) {
                    ui_headers.setWidth(line_width);
                    ui_headers.line();
                    cout<<"DONE! LINE WIDTH SET TO "<<line_width<<endl;  
                }
                else {
                    ui_headers.line();
                    cout<<"Error : Valid Range 50 - 120"<<endl;
                }
                return;
            }
                break;
            /* BACK CASE*/
            case 2: {
                ui_headers.line();
                cout<<"GOING TO MAIN MENU"<<endl;
                return;  
            }
                break;
            default: {
                ui_headers.clrscr();
                ui_headers.line(50,'*');
                cout<<"YOU ENTERED A WRONG INPUT. PLEASE TRY AGAIN."<<endl;
                ui_headers.line(50,'*');
            }
        }
        
    }while(option != 2);

}


void UserInterface::about_application() {
    ui_headers.header(":: Phonebook : About Application ::");
    cout<<"Application Name : Phonebook"<<endl;
    cout<<"Version : v1.0"<<endl;
    cout<<"Build Date : 06-June-2018"<<endl;
    cout<<"Build By : Sachin Singh"<<endl;
    cout<<"Written In : C++"<<endl;
    ui_headers.line();
    cout<<"Hey Friends , I'm Devloper of this Phonebook Application."<<endl<<
            "by using this application you can save a contact number with other"<<endl<<
            "related information"<<endl;
    ui_headers.line();
    getch();
    
}

void UserInterface::help_desk() {
    ui_headers.header(":: Phonebook : Help Desk ::");
    cout<<"*** HOW I VIEW MY SAVED CONTACTS? ***"<<endl;
        cout<<"\t\tIn the main menu select option \"1\" and hit enter. You got your all \n\t\t saved contacts."<<endl;
    cout<<"*** HOW I ADD A NEW CONTACT TO PHONEBOOK? ***"<<endl;
        cout<<"\t\t Here is Some instructions for you--"<<endl;
        cout<<"\t\t\t 1. select option 2 in main menu ";
}