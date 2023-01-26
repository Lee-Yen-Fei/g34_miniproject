#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//this function works fine
bool login(bool loginStatus, string &typeOfUser, int &i){
    cout << "\nWelcome to the Hostel Reservation App. You will have to login before accessing the app\n";

    string username;
    vector<string> fileUsername;
    bool validUsername = false;

    ifstream userIDFile ("userID.txt");
    string fileLine;

    while (validUsername == false){
        cout << "\nPlease enter your username\n";
        cin >> username;
        int j = 0;

        while (getline (userIDFile, fileLine)){ //might contain errors
            fileUsername.push_back(fileLine);
            j += 1;
        }

        for(i = 0; i < j; i++){
            if (username == fileUsername[i]){
                validUsername = true;
                userIDFile.close();
                fileUsername.clear();
                break;
            } 
        }

        if (validUsername == false){
            cout << "\nInvalid username. Please try again. Note: Usernames are case-sensitive.";
        }
    } 

    ifstream passwordFile ("password.txt");
    int passwordTry = 4;
    string password;
    vector<string> filePassword; //dynamic array to store read values from file

    while (loginStatus == false){
        cout << "\nPlease enter your password.\n";
        cin >> password;

        while (getline (passwordFile, fileLine)){
            filePassword.push_back(fileLine); 
        }  

        if (password == filePassword[i]){ 
            loginStatus = true; //returns true for passwordTrue
            passwordFile.close();
        }

        if (loginStatus == false){
            passwordTry --;
            cout << "\nInvalid password. You have " << passwordTry << " tries left. Please try again.\n";

            if(passwordTry == 0){
                passwordFile.close();
                loginStatus = false;   //returns false for loginStatus
                break;
            }
        }
    }
    
    filePassword.clear();

    if(loginStatus == true){
        ifstream typeOfUserFile ("type_of_user.txt");
            vector<string> fileTypeOfUser;

        while (getline (typeOfUserFile, fileLine)){
            fileTypeOfUser.push_back(fileLine);
        }

        typeOfUser = fileTypeOfUser[i];
        fileTypeOfUser.clear();
        cout << "\nYou have logged in as " << typeOfUser << " "<< username <<endl;
    }

    return loginStatus;
}


//works fine
void logout(bool &loginStatus){
    loginStatus = false;
    cout << "You have logged out of the system.\n\n";
}


//works fine
void createNewUser(string typeOfUser){
    cout << "Please fill in the details to register a new account.\n";

    fstream userIDFile ("userID.txt", ios::app);
    fstream passwordFile ("password.txt", ios::app);
    fstream typeOfUserFile ("type_of_user.txt", ios::app);

    string input;
    cout << "\nPlease enter your username\n";
    cin >> input;
    userIDFile << input << endl;

    cout << "\nPlease enter your password\n";
    cin >> input;
    passwordFile << input << endl;

    if(typeOfUser == "ADMIN"){
        cout << "\nA new admin account has been created\n";
        input = "ADMIN";
    }

    else{
        cout << "Your new account has been created\n";
        input = "USER";
    }

    typeOfUserFile << input << endl;

    userIDFile.close();
    passwordFile.close();
    typeOfUserFile.close();
}

//works fine
void changePassword(int i){
    fstream passwordFile("password.txt");

    string fileLine;
    vector<string> filePassword;    
    while (getline (passwordFile, fileLine)){
        filePassword.push_back(fileLine); 
    }

    while (true){
        cout << "Please enter your original password\n";
        string originalPassword;
        cin >> originalPassword;

        if(originalPassword == filePassword[i]){
            cout << "Please enter your new password";
            cin >> filePassword[i];

            fstream passwordFile("password.txt");

            for(int j=0; j < size(filePassword); j++){
                passwordFile << filePassword[j] <<endl;
            }

            cout << "Your password has been changed\n\n";
            break;
        }
    }
}

//have not tested
/*
void addRooms(){

}
*/
