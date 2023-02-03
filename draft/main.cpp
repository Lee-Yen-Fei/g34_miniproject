//code by Lee Yen Fei. This only consists of the functions login(), createNewUser(), changePassword(), logout()
//this was a draft that was scrapped due to bugs. The initial goal was to ensure that every part of the code can reject spaces and newlines

#include <iostream>
#include <string>
#include <stdio.h>
#include "account_Management.cpp"

using namespace std;

int main(){
    string typeOfUser;
    bool loginStatus = false;
    int i = 0;

    while(loginStatus == false){
        cout << "Please select an action.\n1.Login\n2.Register an account\n";
        char selection = getchar();

        if(selection == '1'){
            loginStatus = login(loginStatus, typeOfUser, i);
        }

        else if (selection == '2'){
            createNewUser(typeOfUser);
        }

        else{ //this error prompts after the logging out
            cout << "\nError. Please enter either 1 or 2.\n";
        }

        while(loginStatus == true){
            cout << "1.Change Password\n2.Logout\n3.Add New Rooms\n4.Update Room Info\n\n";

            if(typeOfUser == "ADMIN"){
                cout << "5.Create new admin account\n";
            }

            selection = getchar();

            if(selection == '1'){
                changePassword(i);
            }

            if(selection == '2'){
                logout(loginStatus);
            }

/*
            if(selection == 3){

            }

            if(selection == 4){

            } */


            if(typeOfUser == "ADMIN"){
                if(selection == '5'){
                    createNewUser(typeOfUser);
                }
            }
        }  
    }
}