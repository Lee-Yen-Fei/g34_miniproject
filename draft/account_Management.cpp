#include <fstream>
#include <iostream>
#include <string>
#include "account_Management.hpp"

using namespace std;

bool login(bool loginStatus){
//if loginStatus = true means that the username & password have matched

    while(loginStatus == false){
        int selection;  //requesting for the type of user
        cout << "Which type of user are you?";
        cin >> selection;

        if(selection == 0 || selection == 1 || selection == 2){
            loginStatus = checkUserDetails(selection, loginStatus);
        //this function will call checkUserDetails(int selection, bool loginStatus)
        }

        else{
            cout << "Please enter a valid selection (1 or 2)";
        }
    }

    return true;
}

bool checkUserDetails(int selection, bool loginStatus){   
    //to check whether the password and username matches
    ifstream userFile ("admin_lvl1.txt");

    if(selection == 1){
          //the admin and customer files are separated
    }

    else if(selection == 2){
        ifstream userFile ("customer.txt");
    }

    string username;
    string fileUsername;
    bool validUsername = false;

    while (validUsername == false){
        cout << "Please enter your username";
        cin >> username;

        while (getline (userFile, fileUsername)){
            if (fileUsername == username){
                validUsername = true;
                break;
            }
        }

        if (validUsername = false){
            cout << "Invalid username. Please try again. Note: Usernames are case-sensitive.";
        }
    } 

    int passwordTry = 3;
    string password;
    string filePassword;

    while (loginStatus == false){
        cout << "Please enter your password.";
        cin >> password;

        while (getline (userFile, filePassword)){
            if (filePassword == password){
                loginStatus = true;
                return loginStatus;   //returns true for passwordTrue
                userFile.close();
                break;
            }   
        }  

        if (loginStatus = false){
            cout << "Invalid password. " << passwordTry << "Please try again.";
            passwordTry --;

            if(passwordTry == 0){
                userFile.close();
                return false;   //returns false for loginStatus
            }
        }
}

