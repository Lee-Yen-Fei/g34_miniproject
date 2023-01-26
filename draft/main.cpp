#include <iostream>
#include <string>
#include "account_Management.cpp"

using namespace std;

int main(){
    string typeOfUser;
    bool loginStatus = false;
    int selection;
    int i = 0;

    while(loginStatus == false){
        cout << "Please select an action.\n1.Login\n2.Register an account\n";
        cin >> selection;

        if(selection == 1){
            loginStatus = login(loginStatus, typeOfUser, i);
        }

        else if (selection == 2){
            createNewUser(typeOfUser);
        }

        else{
            cout << "\nError. Please enter either 1 or 2.\n";
        }

        while(loginStatus == true){
            cout << "1.Change Password\n2.Logout\n3.Add New Rooms\n4.Update Room Info\n";

            if(typeOfUser == "ADMIN"){
                cout << "5.Create new admin account\n";
            }

            cin >> selection;

            if(selection == 1){
                changePassword(i);
            }

            if(selection == 2){
                logout(loginStatus);
            }

/*
            if(selection == 3){

            }

            if(selection == 4){

            }
*/

            if(typeOfUser == "ADMIN"){
                if(selection == 5){
                    createNewUser(typeOfUser);
                }
            }
        }  
    }
}