/**
 * Filename : phonebook.cpp
 * Author : Sachin Singh.
 * Date : 14-june-2018
 * Description : starting point of the Phonebook Application. Creates a instance of UserInterface
 * class and calls its mainMenu() function.
 * 
*/

#include <iostream>
#include <fstream>
#include "classes\\UserInterface.h"

using namespace std;
int main() {
    cout<<"Starting Application..."<<endl;
    UserInterface *ui = UserInterface::getInstance();
    ui->mainMenu();
    return 0;
}