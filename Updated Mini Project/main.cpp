/*
Program Title: Hotel Reservation System
Program Purpose: A system for user to make a reservation of any rooms at Hotel G34
*/

#include <iostream>
#include "main.hpp"
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

bool login(bool loginStatus, int &i){ //login system
    cout << "\nWelcome to the Hotel G34 Reservation System!\nYou will have to login.\n";

    string username;
    vector<string> fileUsername; //dynamic array (vector) to store usernames
    bool validUsername = false;

    ifstream userIDFile ("userID.txt");
    string fileLine;
    while (getline (userIDFile, fileLine)){ 
        fileUsername.push_back(fileLine);   //vector append function
    }

    while (validUsername == false){
        cout << "\nPlease enter your username\n";
        cin >> username;

        for(i = 0; i < size(fileUsername); i++){
            if (username == fileUsername[i]){
                validUsername = true;
                userIDFile.close();
                fileUsername.clear();
                break;
            } 
        }

        if (validUsername == false){
            cout << "\nInvalid username. Please try again. Note: Usernames are case-sensitive.";
        } //error message when user input is invalid
    } 

    ifstream passwordFile ("password.txt");
    int passwordTry = 4;
    string password;
    vector<string> filePassword; //dynamic array to store read values from file

    while (getline (passwordFile, fileLine)){
        filePassword.push_back(fileLine); 
    }  

    while (loginStatus == false){
        cout << "\nPlease enter your password.\n";
        cin >> password;

        if (password == filePassword[i]){ 
            loginStatus = true; //returns true for passwordTrue
            passwordFile.close();
        }

        else{
            passwordTry --;
            cout << "\nInvalid password. You have " << passwordTry << " tries left. Please try again.\n";

            if(passwordTry == 0){
                passwordFile.close();
                loginStatus = false;   //to avoid unauthourised use of account
                cout << "You have entered the wrong password 4 times. \nReturning to the login menu...\n";
                break;
            }
        }
    }
    
    filePassword.clear();   //deletes the vector

    return loginStatus;
}

void createNewUser(){ //Creates a new user account
    cout << "Please fill in the details to register a new account.\n";

    ifstream userIDFile ("userID.txt");
    fstream passwordFile ("password.txt", ios::app);
    //ios::app to add new data to the end of the file

    vector<string> fileUsername;
    string fileLine;
    string input;
    bool newUser = false;

    while(getline(userIDFile, fileLine)){
        fileUsername.push_back(fileLine);
    }

    userIDFile.close();

    while(newUser == false){
        cout << "\nPlease enter your username\n";
        cin >> input;

        for(int j = 0; j < size(fileUsername); j++){
            if(input == fileUsername[j]){
                cout << "This username is already taken.\n Please try again.\n";
                newUser = false;
                break;
            }

            newUser = true;
        }
    }

//the file is opened twice to avoid errors
    fstream userIDFile1("userID.txt", ios::app);    

    userIDFile1 << input << endl; 
    cout << "\nPlease enter your password\n";
    cin >> input;
    passwordFile << input << endl;

    cout << "\nYour new account has been created =)\n\n";

    fileUsername.clear();
    userIDFile1.close();
    passwordFile.close();
}

void changePassword(int i){ //Changing password to a new one function
    fstream passwordFile("password.txt");

    string fileLine;
    vector<string> filePassword;    
    while (getline (passwordFile, fileLine)){
        filePassword.push_back(fileLine); 
    }

    passwordFile.close();

    while (true){
        cout << "Please enter your original password\n";
        string originalPassword;
        cin >> originalPassword;

        if(originalPassword == filePassword[i]){
            cout << "Please enter your new password\n";
            cin >> filePassword[i];
//changes the original password into the new password

            fstream passwordFile("password.txt");

            for(int j=0; j < size(filePassword); j++){
                passwordFile << filePassword[j] <<endl;
            }

            cout << "Your password has been changed\n\n";
            break;
        }
        else{
            cout << "Incorrect password. Please try again.\n\n";
            //error message
        }
    }

    filePassword.clear();
    passwordFile.close();
}

class room { //Hotel rooms details class
    public:

    room() = default;
    room(int cust_roomnum, int cust_floor, string cust_roomtype, double cust_price, string cust_bedno, string cust_guestno)
    {
        roomnum = cust_roomnum;
        floor = cust_floor;
        roomtype = cust_roomtype;
        price = cust_price;
        bedno = cust_bedno;
        guestno = cust_guestno;
    }

    //Getters
    int get_roomnum()
    {return roomnum;}
    int get_floor()
    {return floor;}
    string get_roomtype()
    {return roomtype;}
    int get_price()
    {return price;}
    string get_bedno()
    {return bedno;}
    string get_guestno()
    {return guestno;}

    //Setters
    void set_roomnum(int new_roomnum)
    { roomnum = new_roomnum; }
    void set_floor(int new_floor)
    { floor = new_floor; }
    void set_roomtype(string new_roomtype)
    { roomtype = new_roomtype; }
    void set_price(int new_price)
    { price = new_price; }
    void set_bedno(string new_bedno)
    { bedno = new_bedno; }
    void set_guestno(string new_guestno)
    { guestno = new_guestno; }

    void roomfile(){        
        cout << roomnum << "\t" << floor << "\t" << roomtype << "\t" << price << "\t" << bedno << guestno << "\n" << endl;
    }

    private:
    int roomnum;
    int floor;
    string roomtype;
    double price;
    string bedno;
    string guestno;
};

void droomintro () { //Option 1. Display all rooms heading
    cout << "\t\t\tList of rooms" << endl;
    cout << "\t\t\t_____________\n" << endl;
    cout << "Room\t" << "Floor\t" << "Type\t" << "Price\t" << "Bed No." << "\t\t\t\tGuest No.\n" << endl; 
}

void displayroom(){ //Hotel rooms details function
    room single[4];
    room duo[4];
    room queen[4];
    room king[4];
    room studio[3];
    room family[3];
    room suite[2];

    single[0].set_roomnum(101);
    single[0].set_floor(1);
    single[0].set_roomtype("Single");
    single[0].set_price(150.00);
    single[0].set_bedno("1 single bed");
    single[0].set_guestno("\t\t\t1 person");

    single[1].set_roomnum(102);
    single[1].set_floor(1);
    single[1].set_roomtype("Single");
    single[1].set_price(150.00);
    single[1].set_bedno("1 single bed");
    single[1].set_guestno("\t\t\t1 person");

    single[2] = room(103, 1, "Single", 150.00, "1 single bed", "\t\t\t1 person");

    single[3] = room(104, 1, "Single", 150.00, "1 single bed", "\t\t\t1 person");

    duo[0] = room(105, 1, "Double", 200.00, "2 single beds", "\t\t\t2 persons");

    duo[1] = room(106, 1, "Double", 200.00, "2 single beds", "\t\t\t2 persons");

    duo[2] = room(201, 2, "Double", 200.00, "2 single beds", "\t\t\t2 persons");

    duo[3] = room(202, 2, "Double", 200.00, "2 single beds", "\t\t\t2 persons");

    queen[0] = room(203, 2, "Queen", 250.00, "1 queen-size beds", "\t\t2 persons");

    queen[1] = room(204, 2, "Queen", 250.00, "1 queen-size beds", "\t\t2 persons");

    queen[2] = room(301, 3, "Queen", 250.00, "1 queen-size beds", "\t\t2 persons");

    queen[3] = room(302, 3, "Queen", 250.00, "1 queen-size beds", "\t\t2 persons");

    king[0] = room(205, 2, "King", 300.00, "1 king-size beds", "\t\t2 persons");

    king[1] = room(206, 2, "King", 300.00, "1 king-size beds", "\t\t2 persons");

    king[2] = room(303, 3, "King", 300.00, "1 king-size beds", "\t\t2 persons");

    king[3] = room(304, 3, "King", 300.00, "1 king-size beds", "\t\t2 persons");

    studio[0] = room(305, 3, "Studio", 400.00, "1 queen-size beds", "\t\t2 persons");

    studio[1] = room(306, 3, "Studio", 400.00, "1 queen-size beds", "\t\t2 persons");

    studio[2] = room(401, 4, "Studio", 400.00, "1 queen-size beds", "\t\t2 persons");

    family[0] = room(402, 4, "Family", 400.00, "2 queen-size & 1 single bed", "\t5 persons");

    family[1] = room(403, 4, "Family", 400.00, "2 queen-size & 1 single bed", "\t5 persons");

    family[2] = room(404, 4, "Family", 400.00, "2 queen-size & 1 single bed", "\t5 persons");

    suite[0] = room(501, 5, "Suite", 600.00, "1 king-size bed", "\t\t\t2 persons");

    suite[1] = room(502, 5, "Suite", 600.00, "1 king-size bed", "\t\t\t2 persons");

    for (int i=0; i<4; i++)
    {
        single[i].roomfile();//calling roomfile function in class room
    }

    for (int i=0; i<4; i++)
    {
        duo[i].roomfile();
    }

    for (int i=0; i<4; i++)
    {
        queen[i].roomfile();
    }

    for (int i=0; i<4; i++)
    {
        king[i].roomfile();
    }

    for (int i=0; i<3; i++)
    {
        studio[i].roomfile();
    }

    for (int i=0; i<3; i++)
    {
        family[i].roomfile();
    }

    for (int i=0; i<2; i++)
    {
        suite[i].roomfile();
    }
}


string mainmenu(string &a){ // Getting answer from customerif they want to book or not function
    string b;
    cout << "_______________________________________________________" << endl;
    cout << "<<<<<<<<<<<<<Hotel G34 Reservation System>>>>>>>>>>>>>>" << endl;
    cout << "\tDo you want to book a room from our hotel?" << endl;
    cout << "\tYes or No?" << endl;

    cin >> b;

    return b;
}

string cn(string &a){ //Getting answer if customer wants to continue with reservation after option 1
    cout << "Do you want to continue with the reservation?" << endl;
    string c;
    cin >> c;

    return c;
}

int checkin(int *dd,  int *mm, int *yy, int *sub){ //Getting check-in date and subtracting the year to make it usable with ctime library
    cout << "\nEnter check-in date in DD MM YYYY (e.g 01 01 2001)" << endl;
    cin >> *dd >> *mm >> *yy;
    *sub = *yy - 1900;

    cout << *dd << "/" << *mm << "/" << *yy << endl;

    return *sub;
}

void info (string *n, string *i, string *p, string *s){ //Getting customer details on the booking
    cout << "\nEnter your name (Please enter your first name only): " << endl;
    cin >> *n;
    cout << "\nEnter your ic number: " << endl;
    cin >> *i;
    cout << "\nEnter your phone number: " << endl;
    cin >> *p;
    cout << "\nEnter your address: " << endl;
    char address [100];
    cin.ignore();
    cin.getline (address, 100);

    for(int j = 0; j < size(address); j++){
        if(address [j] != 0){        
            *s += address [j];
        }

        else{
            break;
        }
    }
}

int checkout (int *dd1, int *mm1, int *yy1, int *sub1){ //Getting check-out date and subtracting the year to make it usable with ctime library
    cout << "\nEnter check-out date in DD MM YYYY (e.g 02 02 2002)" << endl;
    cin >> *dd1 >> *mm1 >> *yy1;
    *sub1 = *yy1 - 1900;

    cout << *dd1 << "/" << *mm1 << "/" << *yy1 << endl;

    return *sub1;
}

double howlong (int day, int month, int years, int day1, int month1, int years1, bool *loginStatus){ //Getting the no of days customer staying and giving the details on check-in & check-out date
    double diff;
    double days;

    month -= 1;
    month1 -= 1;

    struct tm in = {0,0,12,day,month,years};
    struct tm out = {0,0,12,day1,month1,years1};

    time_t x = mktime(&in);
    time_t y = mktime(&out);

    if ( x != (time_t)(-1) && y != (time_t)(-1) )
    {
        diff = difftime(y,x) / (60*60*24);

        cout << "\nCheck-in details: " << ctime(&x);
        cout << "Check-out details: " << ctime(&y);
        cout << "No. of days : " << diff << " days" << endl;
        days = diff;
    }
    else 
    {
        cout << "\nThe date inserted is not in the format of dd mm yyyy (e.g: 03 03 2003)" << endl;
        *loginStatus = false;
    }

    return days;
}

int Wroom (int &room){ //Getting room number from customer
int room1[24] = {101, 102, 103, 104, 105, 106, 201, 202, 203, 204, 205, 206, 301, 302, 303, 304, 305, 306, 401, 402, 403, 404, 501, 502};
int y = 0;

    cout << "Which room do you want to book?" << endl;
    cout << "Please enter the room number : " << endl;

  while (y == 0) {
    cin >> room;

    if (room == room1[0] || room == room1[1] || room == room1[2] || room == room1[3]
    || room == room1[4] || room == room1[5] || room == room1[6] || room == room1[7]
    || room == room1[8] || room == room1[9] || room == room1[10] || room == room1[11]
    || room == room1[12] || room == room1[13] || room == room1[14] || room == room1[15]
    || room == room1[16] || room == room1[17] || room == room1[18] || room == room1[19]
    || room == room1[20] || room == room1[21] || room == room1[22] || room == room1[23] )
    {
      y++;
    }
    else { 
      cout <<  "Please enter the correct room number." << endl;
      y = 0;
    }

  }

    return room;
}

double sumprice (int &selection, double &stay){ //room price total after multiplying with days of staying
    double sum = 0;

    if (selection == 101 || selection == 102 || selection == 103 || selection == 104)
    {
        for (int i = 1; i <= stay; i++)
        {
            sum += 150;
        }
    }//single

    else if (selection == 105 || selection == 106 || selection == 201 || selection == 202)
    {
        for (int i = 1; i <= stay; i++)
        {
            sum += 200;
        }
    }//duo

    else if (selection == 203 || selection == 204 || selection == 301 || selection == 302)
    {
        for (int i = 1; i <= stay; i++)
        {
            sum += 250;
        }
    }//queen

    else if (selection == 205 || selection == 206 || selection == 303 || selection == 304)
    {
        for (int i = 1; i <= stay; i++)
        {
            sum += 300;
        }
    }//king

    else if (selection == 305 || selection == 306 || selection == 401)
    {
        for (int i = 1; i <= stay; i++)
        {
            sum += 400;
        }
    }//studio

    else if (selection == 402 || selection == 403 || selection == 404)
    {
        for (int i = 1; i <= stay; i++)
        {
            sum += 400;
        }
    }//family

    else if (selection == 501 || selection == 502)
    {
        for (int i = 1; i <= stay; i++)
        {
            sum += 600;
        }
    }//suite

    cout << "Current total: RM" << sum << endl;
    return sum;
}

double additional (double &stay){ //Optional additional services and the total fees of the services
    double bed, pillow, blanket, breakfast, paytotal=0;

    cout << "\nNo. of extra bed needed ( 1 bed/night = RM 40/night)" << endl;
    cin >> bed;
    cout << "No. of extra pillow needed ( 1 pillow/night = RM 10/night)" << endl;
    cin >> pillow;
    cout << "No. of extra blanket needed ( 1 blanket/night = RM 15/night)" << endl;
    cin >> blanket;
    cout << "No. of pax for buffet breakfast (RM 25/pax)" << endl;
    cin >> breakfast;

    bed = bed*40*stay;
    pillow = pillow*10*stay;
    blanket = blanket*15*stay;
    breakfast = breakfast*25*stay;

    paytotal = paytotal+bed+pillow+blanket+breakfast;

    return paytotal;
}

void dinmenu (){ //displaying optional in-room dining menu
    cout <<"\t\t\tIn-Room Dining Menu" << endl;
    cout <<"\t\t\t____________________" << endl;
    cout <<"\t\t\t    Main Course\n" << endl;
    cout <<"\t\t1. Smoked Beef Short Rib with BBQ Sauce and Steak Fries [RM 90]" << endl;
    cout <<"\t\t2. Pan Seared Salmon, Mango Salsa, Crispy Fish Skin & Garlic Beurre Bianc [RM 79]" << endl;
    cout <<"\t\t3. Mixed Grilled Seafood [RM 190]" << endl;
    cout <<"\t\t4. Grilled Grass-Fed Chilled Australian Rib Eye(250gm) [RM 120]" << endl;
    cout <<"\t\t5. Herb Roasted Rack of Lamb [RM 120]" << endl;
    cout <<"\t\t6. Sea Bass Al Cartoccio [RM 59]" << endl;
    cout <<"\t\t7. Cancel/exit" << endl;
}

double dinselection (){ //Getting in-room dining menu selection and total fees for the dining
    int dishes;
    double totaldin = 0;
    string yorn;
    int select;
    int y = 0;

    cout << "\nDo you wish to place an order (Yes/7. Exit)?" << endl;
    cin >> yorn;

    while (y == 0)
    {
    if (yorn == "Yes")
    {
       cout << "\nHow many dishes you want?" << endl;
       cin >> dishes;

       for (int i = 1; i<=dishes; i++)
       {
           cout << "\nPlease make selection from 1 to 6" << endl;
           cin >> select;

           switch (select)
           {
            case 1:
            {
                totaldin += 90;
                y++;
                break;
            }
            case 2:
            {
                totaldin += 79;
                y++;
                break;
            }
            case 3:
            {
                totaldin += 190;
                y++;
                break;
            }
            case 4:
            {
                totaldin += 120;
                y++;
                break;
            }
            case 5:
            {
                totaldin += 120;
                y++;
                break;
            }
            case 6:
            {
                totaldin += 59;
                y++;
                break;
            }
            default: 
            {
            cout << "Wrong selection" << endl;
            y = 0;
            }
           }
       }
    }
    else if (yorn == "7")
    {
        totaldin = 00;
        y++;
    }
    else { cout << "Wrong selection" << endl; y++;}
    }

    return totaldin;
}

double inctax(double *roomfee, double *diningfee, double *addfee, double *totalall){ //Calculating tax for rooms and etc.
    double tax;

    tax = (*roomfee+*diningfee+*addfee)*0.1;
    *totalall = *roomfee+*diningfee+*addfee+tax;

    return tax;
}

//Printing all reservation details on the terminal abd file
void payment (double total, string name, string icnum, string phonenum, string address, int room, int day, int month, int year, int day1, int month1, int year1, double stay, double din, double sumadd){
    double roomfee = total;
    double diningfee = din;
    double addfee = sumadd;
    double totalall;

    double tax = inctax(&roomfee, &diningfee, &addfee, &totalall);

    cout << "\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n" << endl;
    cout << "\t\t\t Hotel G34 Reservation Details" << endl;
    cout << "\n\t\t\t************************************\n" << endl;
    cout << "Name :" << name << endl;
    cout << "IC Number :" << icnum << endl;
    cout << "Phone Number :" << phonenum << endl;
    cout << "Your Address :" << address << endl;
    cout << "Room Number :" << room << endl;
    cout << "Check-in date :" << day << "/" << month << "/" << year << endl;
    cout << "Check-out date :" << day1 << "/" << month1 << "/" << year1 << endl;
    cout << "No. of days staying :" << stay << " days" << endl;
    cout << "Room price for " << stay << " days : RM" << total << endl;
    cout << "Additional fees(Optional) : RM" << sumadd << endl;
    cout << "In-room dining fees(Optional) : RM" << din << endl;
    cout << "Service tax (10%) : RM" << tax << endl;
    cout << "Final total : RM" << totalall << endl;
    cout << "\nThank you for choosing Hotel G34 as your place to stay and rest." << endl;
    cout << "Enjoy your stay with us!" << endl;
    cout << "If there is any problem with the reservation, you can directly call us at 07-5634722" << endl;
    cout << "\nPlease refer to receipt.txt for the official receipt." << endl;

    fstream custfile("receipt.txt");
    if (custfile.is_open()){
      custfile << "\t\t\tOFFICIAL RECEIPT" << endl;
      custfile << "\t\t\t   HOTEL G34" << endl;
      custfile << "\t\t\t________________\n" << endl;
      custfile << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n" << endl;
      custfile << "\t\t\t Hotel G34 Reservation Details" << endl;
      custfile << "\n\t\t\t************************************\n" << endl;
      custfile << "Name :" << name << endl;
      custfile << "IC Number :" << icnum << endl;
      custfile << "Phone Number :" << phonenum << endl;
      custfile << "Your Address :" << address << endl;
      custfile << "Room Number :" << room << endl;
      custfile << "Check-in date :" << day << "/" << month << "/" << year << endl;
      custfile << "Check-out date :" << day1 << "/" << month1 << "/" << year1 << endl;
      custfile << "No. of days staying :" << stay << " days" << endl;
      custfile << "Additional fees(Optional) : RM" << sumadd << endl;
      custfile << "In-room dining fees(Optional) : RM" << din << endl;
      custfile << "Service tax (10%) : RM" << tax << endl;
      custfile << "Final total : RM" << totalall << endl;
      custfile << "\nThank you for choosing Hotel G34 as your place to stay and rest." << endl;
      custfile << "Enjoy your stay with us!" << endl;
      custfile << "If there is any problem with the reservation, you can directly call us at 07-5634722" << endl;
    }

}

void logout(bool &loginStatus){
    loginStatus = false;
    cout << "\nYou have successfully logged out.\n";
    cout << "Thank you for choosing Hotel G34\n";
}

bool anotherRoom (bool &loginStatus){
    string newroom;

    cout << "\nDo you want to book another room (Yes/No) ?" << endl;
    cin >> newroom;
    if (newroom == "Yes")
    { loginStatus = true;}
    else if (newroom == "No")
    { logout(loginStatus);}
    else
    {
    cout << "\nYou've entered the answer other than suggested one, unfortunately you need to do the booking again with the right answer for each question, thank you for the understanding." << endl;
    logout(loginStatus);
    }

    return loginStatus;
}

int main(){                

    int choices;
    string answer;
    string con;
    string name;
    string icnum;
    string phonenum;
    string address;
    int day, month, year, minus, years;
    int day1, month1, year1, minus1, years1;
    double stay;
    int room;
    int selection;
    double total;
    string want;
    double sumadd;
    string dinner;
    double din;
    string newroom;
    bool loginStatus = false;
    int i = 0;

    answer = mainmenu(answer); //calling fuction and getting string answer

    if (answer == "Yes"){ //first condition from answer

    while(loginStatus == false){ //for the purpose of account login & account registration (first loop)
        cout << "\nPlese Login to your account first.\nIf you are a new user, you can register a new account.\n\n1.Login\n2.Register an account\n";
        cin >> selection;

        if(selection == 1){
            loginStatus = login(loginStatus, i);
        }

        else if (selection == 2){
            createNewUser();
        }

        else{
            cout << "\nError. Please enter either 1 or 2.\n";
        }
    } // when loginStatus == true the loop will end

    while (loginStatus == true) //All the choices for the reservation system (2nd loop)
    {
     cout << "_____________________________________________________" << endl;
     cout << "<<<<<<<<<<<<<Hotel G34 Room Reservation>>>>>>>>>>>>>>" << endl;
     cout << "\t1. Display all rooms" << endl;
     cout << "\t2. Book a room" << endl;
     cout << "\t3. Additional Services (after booking & if needed)" << endl;
     cout << "\t4. Change password" << endl;
     cout << "\t5. Logout" << endl;
     cout << "Choice: " << endl;
     cin >> choices;

     switch (choices) //switch cases depending on the choices customer made
     {
        case 1: 
        {
            droomintro();
            displayroom();
            con = cn(con);
            if (con == "Yes")
            {
              loginStatus = true;
            }
            else if (con == "No")
            {
               logout(loginStatus);
            }
            else
            {
                cout << "\nYou've entered the wrong answer. Please answer the question according to suggested answer.\n" << endl;
                loginStatus = true;
            }
            break;
        }

        case 2:
        {
            info(&name, &icnum, &phonenum, &address);

            years = checkin(&day, &month, &year, &minus);

            years1 = checkout(&day1, &month1, &year1, &minus1);

            stay = howlong (day, month, years, day1, month1, years1, &loginStatus);

            selection = Wroom(room);

            total = sumprice (selection, stay);

            cout << "\nDo you want extra services such as extra bed etc. (Yes / No) ?" << endl;
            cin >> want;
            if (want == "Yes")
            {loginStatus = true;}
            else if (want == "No")
            {
                din = 0;
                sumadd = 0;
                payment (total, name, icnum, phonenum, address, room, day, month, year, day1, month1, year1, stay, din, sumadd);
                loginStatus = anotherRoom(loginStatus);
            }
            else
            {
                cout << "\nYou've entered the wrong answer. Please answer the question according to suggested answer.\n" << endl;
                loginStatus = true;
            }

            break;
        }

        case 3:
        {
            sumadd = additional(stay);
            cout << "Addition total : RM" << sumadd << endl;

            cout << "\nDo you want In-Room Dining (Yes/No) ?" << endl;
            cin >> dinner;
            if (dinner == "Yes")
            {
                dinmenu();
                din = dinselection();
                payment (total, name, icnum, phonenum, address, room, day, month, year, day1, month1, year1, stay, din, sumadd);
                loginStatus = anotherRoom(loginStatus);
            }
            else if (dinner == "No")
            {
                din = 0;
                payment (total, name, icnum, phonenum, address, room, day, month, year, day1, month1, year1, stay, din, sumadd);
                loginStatus = anotherRoom(loginStatus);
            }
            else
            {
                cout << "\nYou've entered the wrong answer. Please answer the question according to suggested answer.\n" << endl;
                loginStatus = true;
            }

            break;
        }

        case 4:
        {
            changePassword(i);
            break;
        }

        case 5:
        {
            logout(loginStatus);
            break;
        }

        default:
        {
            cout << "\nYou've entered the wrong choices. Please make the choices again.\n" << endl;
            loginStatus = true;
        }
     }
    }
    }

    else if (answer == "No") // second condition from answer
    {cout << "\nThank you for visiting our Hotel website!" << endl;
     cout << "You have successfully logged out.\n" << endl;
    }
    
    else {
      cout << "\nYou've entered the answer other than suggested one, unfortunately you need to do the booking again with the right answer for each question, thank you for the understanding." << endl;
    }// final condition from answer
    
    return 0;
}
