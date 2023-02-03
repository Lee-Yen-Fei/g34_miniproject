//code by Lee Yen Fei
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//this function works fine
bool login(bool loginStatus, string &typeOfUser, int &i){
    cout << "\nWelcome to the Hostel Reservation App. You will have to login before accessing the app\n";

    vector<string> fileUsername;
    bool validUsername = false;

    ifstream userIDFile ("userID.txt");
    string fileLine;
    string username;
    char stringInput [25];

    int j = 0;
        
    while (getline (userIDFile, fileLine)){ //might contain errors
        fileUsername.push_back(fileLine);
        j += 1;
    }

    cin.ignore();

    while (validUsername == false){
        cout << "\nPlease enter your username.\n";//prevent weird user inputs
        cin.getline(stringInput, 25);
        username = stringInput;

        if(username.find(" ") != string::npos){ //continue the loop for weird user inputs
            cout << "Please do not enter whitespaces and newlines";
            continue;
        }

        else if(username != ""){
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
    } 

    ifstream passwordFile ("password.txt");
    int passwordTry = 4;
    vector<string> filePassword; //dynamic array to store read values from file

    while (getline (passwordFile, fileLine)){
        filePassword.push_back(fileLine); 
    }  
    
    while (loginStatus == false){
        cout << "\nPlease enter your password.\n";
        cin.getline(stringInput, 25);
        string password = stringInput;

        if(password.find(" ") != string::npos){ //continue the loop for weird user inputs
            cout << "Please do not enter whitespaces and newlines";
            continue;
        }

        else if (password == filePassword[i]){ 
            loginStatus = true; //returns true for passwordTrue
            passwordFile.close();
        }

        else if (loginStatus == false){
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
    vector<string> fileUsername;
    fstream userIDFile ("userID.txt", ios::app);
    fstream passwordFile ("password.txt", ios::app);
    fstream typeOfUserFile ("type_of_user.txt", ios::app);

    char placeholder [25];
    string fileLine;
    string input;
    cin.ignore();
    int j = 0;

    while (getline (userIDFile, fileLine)){ //might contain errors
        fileUsername.push_back(fileLine);
        j += 1;
    }

    while(true){
        cout << "\nPlease enter your username\n";
        cin.getline(placeholder, 25);
        input = placeholder;

        if(input.find(" ") != string::npos){ //continue the loop for weird user inputs
            cout << "Please do not enter whitespaces and newlines\n";
            continue;
        }

        bool breakCondition = true;

        while(true){
            for(int i = 0; i < j; i++){
                if(input == fileUsername[i]){
                    breakCondition = false;
                    cout << "Username is already in use\n";
                    break;
                }
            }
            
            if(breakCondition == true){
                break;
            }
        }

        break;
    }

    userIDFile << input << endl;
    cin.ignore();

    while(true){
        cout << "\nPlease enter your password\n";
        cin.getline(placeholder, 25);
        input = placeholder;

        if(input.find(" ") != string::npos){ //continue the loop for weird user inputs
            cout << "Please do not enter whitespaces and newlines";
            continue;
        }
        
        else{
            break;
        }
    }

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
    char placeholder[25];
    vector<string> filePassword;    
    while (getline (passwordFile, fileLine)){
        filePassword.push_back(fileLine); 
    }

    while (true){
        cin.ignore();

        while(true){
            cout << "\nPlease enter your original password\n";
            cin.getline(placeholder, 25);
            fileLine = placeholder;

            if(fileLine.find(" ") != string::npos){ //continue the loop for weird user inputs
                cout << "Please do not enter whitespaces and newlines";
                continue;
            }
        
            else if(fileLine == filePassword[i]){
                break;
            }
        }

        cin.ignore();

        while(true){
            cout << "Please enter your new password\n";
            cin.getline(placeholder, 25);
            fileLine = placeholder;

            if(fileLine.find(" ") != string::npos){ //continue the loop for weird user inputs
                cout << "Please do not enter whitespaces and newlines";
                continue;
            }

            else{
                break;
            }
        }

        filePassword[i] = fileLine;

        fstream passwordFile("password.txt");

        for(int j=0; j < size(filePassword); j++){
            passwordFile << filePassword[j] <<endl;
        }

        cout << "Your password has been changed\n\n";
        break;
    }    
}
