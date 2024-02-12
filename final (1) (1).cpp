#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <fstream>

void cyan()
{
    printf("\033[1;36m");
}
void red()
{
    printf("\033[1;31m");
}
using namespace std;
#define int long long

class Stock {
private:
    long long childCloths, maleCloths, femaleCloths;
    long long firstAidBox, regularMedicine, specialMedicine;
    long long pen, pencil, sharpener, notebooks, books;

public:
    Stock() = default; // Use default constructor if no initialization needed
};

class FoodStock : public Stock {
protected:
    int dryFoodStock, riceStock, meatStock, childFoodStock, fishStock, potatoStock, spiceryStock, othersStock;

public:
    FoodStock() = default;
    FoodStock(int dryFood, int rice, int meat, int childFood, int fish, int potato, int spicery, int others)
        : dryFoodStock(dryFood), riceStock(rice), meatStock(meat), childFoodStock(childFood), fishStock(fish), potatoStock(potato), spiceryStock(spicery), othersStock(others) {}
    void operator+=(FoodStock);
};

void FoodStock::operator+=(FoodStock fd2) {
    dryFoodStock += fd2.dryFoodStock;
}

class DDonation{
protected:
    string orgName_perName, donationDate;
public:
    virtual void takeDonation(){};
    virtual ~DDonation() = default; // Virtual destructor for proper cleanup
};


class Food: public DDonation{ // public FoodStock
protected:
    int dryFood, rice, meat, childFood, fish, potato, spicery, others;
public:
    Food(int dry = 0, int ri = 0, int me = 0, int chi = 0, int fi = 0, int po = 0, int spi = 0, int oth = 0)
        :dryFood(dry), rice(ri), meat(me), childFood(chi), fish(fi), potato(po), spicery(spi), others(oth){};
    void getFoodDonation(){
        cout<<"Enter Organization Name: "; cin>>orgName_perName;
        cout<<"Enter Date (MM/DD/YYYY): "; cin>>donationDate;
        cout<<"Enter Donation Quantity Of Each Item(in KG): "<<endl;
        cout<<"1. Dry Food: "; cin>>dryFood;
        cout<<"2. Child Food: "; cin>>childFood;
        cout<<"3. Rice: "; cin>>rice;
        cout<<"4. Potato: "; cin>>potato;
        cout<<"5. Meat: "; cin>>meat;
        cout<<"6. Fish: "; cin>>fish;
        cout<<"7. Spicery: "; cin>>spicery;
        cout<<"8. Others: "; cin>>others;
    }
};

class Campaign {
protected:
    string campaignName, duration, type;
    long double campaignStatus;

public:
    Campaign(string nam, string dura, string typ) : campaignName(nam), duration(dura), type(typ){};
    virtual void showAsk(){};
    virtual void getDonation(){};
    void showCampaign() {
        cout << "Campaign Completed: " << campaignStatus << "%" << endl;
    }
};

class FoodCampaign : public Campaign {
private:
    int dryFoodTarget, riceTarget, meatTarget, childFoodTarget, fishTarget, potatoTarget, spiceryTarget, othersTarget;
    int currdryFood=0, currrice=0, currmeat=0, currchildFood=0, currfish=0, currpotato=0, currspicery=0, currothers=0;

public:
    FoodCampaign(string nam, string dura, string typ, int dry = 0, int ri = 0, int me = 0, int chi = 0, int fi = 0, int po = 0, int spi = 0, int oth = 0)
        : Campaign(nam, dura, typ), dryFoodTarget(dry), riceTarget(ri), meatTarget(me), childFoodTarget(chi), fishTarget(fi), potatoTarget(po), spiceryTarget(spi), othersTarget(oth){};

    void showAsk() override{
        cout << "About: " << endl;
        cout << "Name: " << campaignName << " || Duration: " << duration << " || Campaign Completed: " << campaignStatus << "%" << endl;
        cout << "Asked Quantity (In KG): " << endl;
        cout << "Dry Food: " << dryFoodTarget << " || Rice: " << riceTarget << " || Child Food: " << childFoodTarget << " || Fish: " << fishTarget << " || Meat: " << meatTarget << " || Potato: " << potatoTarget << " || Spicery: " << spiceryTarget << " || Others: " << othersTarget << endl;
    }

    void getDonation() override{
        int dryFood, rice, meat, childFood, fish, potato, spicery, others;
        cout<<"                                           Enter Donation Quantity Of Each Item(in KG): "<<endl;
        cout<<"                                           1. Dry Food: "; cin>>dryFood;
        cout<<"                                           2. Child Food: "; cin>>childFood;
        cout<<"                                           3. Rice: "; cin>>rice;
        cout<<"                                           4. Potato: "; cin>>potato;
        cout<<"                                           5. Meat: "; cin>>meat;
        cout<<"                                           6. Fish: "; cin>>fish;
        cout<<"                                           7. Spicery: "; cin>>spicery;
        cout<<"                                           8. Others: "; cin>>others;
        currdryFood+=dryFood;
        currrice+=rice;
        currmeat+=meat;
        currchildFood+=childFood;
        currfish+=fish;
        currpotato+=potato;
        currspicery+=spicery;
        currothers+=others;
        int totalTarget = dryFoodTarget+riceTarget+meatTarget+childFoodTarget+fishTarget+potatoTarget+spiceryTarget+othersTarget;
        long double totalCurr = (long double)(currdryFood+currrice+currmeat+currchildFood+currfish+currpotato+currspicery+currothers);
        totalCurr = totalCurr/(long double)(totalTarget);
        campaignStatus = totalCurr*100;
    }
};

///Clothing Campaign Code
class ClothingCampaign : public Campaign{
private:
    int summerChildClothtarget, summerMaleClothTarget, summerFemaleClothTarget, winterChildClothTarget, winterFemaleClothTarget, winterMaleClothTarget;
    int currsummerChildCloth, currsummerMaleCloth, currsummerFemaleCloth, currwinterChildCloth, currwinterFemaleCloth, currwinterMaleCloth;

public:
    ClothingCampaign():currsummerChildCloth(0), Campaign("", "", ""), currsummerMaleCloth(0), currsummerFemaleCloth(0), currwinterChildCloth(0), currwinterFemaleCloth(0), currwinterMaleCloth(0){};
    ClothingCampaign(string nam, string dura, string typ, int sumChild, int sumMale, int sumFemale, int wintChild, int wintMale, int wintFemale)
        : Campaign(nam, dura, typ), summerChildClothtarget(sumChild), summerMaleClothTarget(sumMale), summerFemaleClothTarget(sumFemale), winterChildClothTarget(wintChild), winterFemaleClothTarget(wintFemale), winterMaleClothTarget(wintMale){};

    void showAsk() override{
        cout << "About: " << endl;
        cout << "Name: " << campaignName << " | Duration: " << duration << " | Status: " << campaignStatus << endl;
        cout << "Asked Quantity (In Pieces): " << endl;
        cout << "Summer Child Cloth: " << summerChildClothtarget << " | Summer Male Cloth: " << summerMaleClothTarget << " | Summer Female Cloth: " << summerFemaleClothTarget << " | Winter Child Cloth: " << winterChildClothTarget << " | Winter Male Cloth: " << winterMaleClothTarget << " | Winter Female Cloth: "<<winterFemaleClothTarget<<endl;
    }

    void getDonation() override{
        int sumChild, sumMale, sumFemale, wintChild, wintMale, wintFemale;
        cout<<"                                           Enter Donation Quantity Of Each Item(in KG): "<<endl;
        cout<<"                                           1. Summer Child Cloth: "; cin>>sumChild;
        cout<<"                                           2. Summer Male Cloth: "; cin>>sumMale;
        cout<<"                                           3. Summer Female Cloth: "; cin>>sumFemale;
        cout<<"                                           4. Winter Child Cloth: "; cin>>wintChild;
        cout<<"                                           5. Winter Male Cloth: "; cin>>wintMale;
        cout<<"                                           6. Winter Female Cloth: "; cin>>wintFemale;
        currsummerChildCloth+=sumChild;
        currsummerMaleCloth+=sumMale;
        currsummerFemaleCloth+=sumFemale;
        currwinterChildCloth+=wintChild;
        currwinterFemaleCloth+=wintFemale;
        currwinterMaleCloth+=wintMale;
        int totalClothTarget = summerChildClothtarget+ summerMaleClothTarget+summerFemaleClothTarget+winterChildClothTarget+winterFemaleClothTarget+ winterMaleClothTarget;
        long double totalClothCurr = (long double)(currsummerChildCloth+currsummerMaleCloth+currsummerFemaleCloth+currwinterChildCloth+currwinterFemaleCloth+currwinterMaleCloth);
        totalClothCurr = totalClothCurr/(long double)(totalClothTarget);
        campaignStatus = totalClothCurr*100;
    }
};


class StockManager{
protected:
    vector<Campaign*>campaigns;

public:
    void runNewClothingCampaign();
    void runNewFoodCampaign();
    void donateOngoingCampaign();
    void showCampaigns();

};

void StockManager::runNewClothingCampaign(){
    string campaignName, duration, camptype;
    int sumChild, sumMale, sumFemale, wintChild, wintMale, wintFemale;
    cout<<"                                           Campaign Type: "; cin.ignore(); getline(cin, camptype);
    cout<<"                                           Campaign Name: "; cin.ignore(); getline(cin, campaignName);
    cout<<"                                           Enter Donation Quantity Of Each Item(in KG): "<<endl;
    cout<<"                                           1. Summer Child Cloth: "; cin>>sumChild;
    cout<<"                                           2. Summer Male Cloth: "; cin>>sumMale;
    cout<<"                                           3. Summer Female Cloth: "; cin>>sumFemale;
    cout<<"                                           4. Winter Child Cloth: "; cin>>wintChild;
    cout<<"                                           5. Winter Male Cloth: "; cin>>wintMale;
    cout<<"                                           6. Winter Female Cloth: "; cin>>wintFemale;
    campaigns.push_back(new ClothingCampaign(campaignName, duration, camptype, sumChild, sumMale, sumFemale, wintChild, wintMale, wintFemale));
}

void StockManager::runNewFoodCampaign(){
    string campaignName, duration, camptype;
    int dryFoodTarget, riceTarget, meatTarget, childFoodTarget, fishTarget, potatoTarget, spiceryTarget, othersTarget;
    cin.ignore();
    cout<<"                                           Campaign Type: "; cin.ignore(); getline(cin, camptype);
    cout<<"                                           Campaign Name: "; cin.ignore(); getline(cin, campaignName);
    cout<<"                                           Campaign Duration: "; cin.ignore(); getline(cin, duration);
    cout<<"                                           Ask For Each Item(in KG):"<<endl;
    cout<<"                                           1. Dry Food: ";cin>>dryFoodTarget;
    cout<<"                                           2. Child Food: "; cin>>childFoodTarget;
    cout<<"                                           3. Rice: "; cin>>riceTarget;
    cout<<"                                           4. Potato: "; cin>>potatoTarget;
    cout<<"                                           5. Meat: "; cin>>meatTarget;
    cout<<"                                           6. Fish: "; cin>>fishTarget;
    cout<<"                                           7. Spicery: "; cin>>spiceryTarget;
    cout<<"                                           8. Others: "; cin>>othersTarget;
    FoodCampaign* newFood = new FoodCampaign(campaignName, duration, camptype, dryFoodTarget, riceTarget, meatTarget, childFoodTarget, fishTarget,potatoTarget, spiceryTarget, othersTarget);
    campaigns.push_back(newFood);
}

void StockManager::donateOngoingCampaign(){
    for(Campaign* campPtr: campaigns){
        campPtr->showAsk();
        campPtr->getDonation();
    }
}

void StockManager::showCampaigns(){
    for(Campaign* cmpt: campaigns){
        cmpt->showAsk();
        cout<<endl;
    }
}


void reset()
{
    printf("\033[0m");
}
void main_menu();
void admin_panel();
void registration();
void cool(StockManager* manager);
void donationDonate();

signed main() {
            cyan();
        printf("\n");
        printf("                                            ++===============================================================++\n");
        printf("                                            ||                                                               ||\n");
        printf("                                            ||                        MANAGE REFUGE                          ||\n");
        printf("                                            ||                                                               ||\n");
        printf("                                            ++===============================================================++\n\n");

        main_menu();
    return 0;
}



///Registrationn Menu

class User {
public:
    int userID;
    string username;
    string password;
    string email;
    virtual ~User() = default;
};

class Refugee : public User {
public:
    string registrationDate;
    string status;
};

class Sponsor : public User {
public:
    string organization;
    string sponsorshipType;
};

class Volunteer : public User {
public:
    int volunteerID;
    string availability;
};

class Admin : public User {
public:
    int adminID;
    string role;
};

void registerUser(vector<User*>& users) {
    int choice;
    printf("\n\n\n\n\n\n");
    cyan();
    printf("                                            ++===============================================================++\n");
    printf("                                            ||                           ");
    printf("Registration                        ");
   // reset();
    printf("||\n");
    printf("                                            ++===============================================================++\n");
    printf("                                            ||                                                               ||\n");
    printf("                                            ||       1. New Refugee Registration                             ||\n");
    printf("                                            ||       2. Sponsor Registration                                 ||\n");
    printf("                                            ||       3. Volunteer Registration                               ||\n");
    printf("                                            ||       4. Admin Registration                                   ||\n");
    printf("                                            ||                                                               ||\n");
    printf("                                            ++===============================================================++\n\n");
    int x;
    printf("                                                      Enter your Task number: ");
    cin >> choice;

    User* newUser;

    switch (choice) {
    case 1:
        newUser = new Refugee;
        break;
    case 2:
        newUser = new Sponsor;
        break;
    case 3:
        newUser = new Volunteer;
        break;
    case 4:
        newUser = new Admin;
        break;
    default:
        cout << "                                        Invalid choice. Exiting registration.\n";
        return;
    }

    cout << "                                        Registration for " << newUser->username << ":\n";
    cout << "                                        Username: ";
    cin >> newUser->username;
    cout << "                                        Password: ";
    cin >> newUser->password;
    cout << "                                        Email: ";
    cin >> newUser->email;

    if (choice == 1) {
        Refugee* refugee = dynamic_cast<Refugee*>(newUser);
        cout << "                                        Registration Date: ";
        cin >> refugee->registrationDate;
        cout << "                                        Status: ";
        cin >> refugee->status;
    }
    else if (choice == 2) {
        Sponsor* sponsor = dynamic_cast<Sponsor*>(newUser);
        cout << "                                        Organization: ";
        cin >> sponsor->organization;
        cout << "                                        Sponsorship Type: ";
        cin >> sponsor->sponsorshipType;
    }
    else if (choice == 3) {
        Volunteer* volunteer = dynamic_cast<Volunteer*>(newUser);
        cout << "                                        Availability: ";
        cin >> volunteer->availability;
    }
    else if (choice == 4) {
        Admin* admin = dynamic_cast<Admin*>(newUser);
        cout << "                                        Role: ";
        cin >> admin->role;
    }

    newUser->userID = users.size() + 1;
    users.push_back(newUser);

    cout << "                                        Registration Successful!\n";


    string filename;
    cout << "                                        Enter filename to save user data: ";
    cin >> filename;
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << newUser->userID << " " << newUser->username << " " << newUser->password << " " << newUser->email << endl;
        outFile.close();
        cout << "                                        User data saved to file: " << filename << endl;
    }
    else {
        cout << "                                        Error: Unable to open file for writing.\n";
    }
}

void cleanupUsers(vector<User*>& users) {
    for (auto& user : users) {
        delete user;
    }
}


void main_menu()
{
    vector<User*> users;
    while (1)
    {
        int choice;
        cyan();
        printf("\n\n");
        printf("                                            ++===============================================================++\n");
        printf("                                            ||                           Main Menu                           ||\n");
        printf("                                            ++===============================================================++\n");
        printf("                                            ||                                                               ||\n");        printf("                                            ||                                                               ||\n");
        printf("                                            ||          1. Registration                                      ||\n");
        printf("                                            ||          2. Admin Panel                                       ||\n");
        printf("                                            ||          3. Donation                                          ||\n");
        printf("                                            ||          4. Emergency Desk                                    ||\n");
        printf("                                            ||          5. Exit                                              ||\n");
        printf("                                            ||                                                               ||\n");
        printf("                                            ++===============================================================++\n\n");
        reset();
        printf("                                                        Enter your Task number: ");
        cin>>choice;

        switch (choice)
        {
        case 1:
            system("cls");
            registerUser(users);
            main_menu();
            break;
        case 2:
            system("cls");
            admin_panel();
            main_menu();
            break;
        case 3:
           // system("cls");
           donationDonate();
           main_menu();
            break;
        case 4:
            cout<<"                                 Md Jakir Hossain: 017107133333"<<endl;
            cout<<"                                 Most. Sadia Akhter: 01818383838"<<endl;
            cout<<"                                 Most. Dina Akhter: 018838383838"<<endl;
            main_menu();
            break;
        case 5:
           // system("cls");
           // equation_solve();
            break;
        case 6:
           // system("cls");
            cyan();
            printf("\n\n\n\n\n\n");
            printf("                                            ++===============================================================++\n");
            printf("                                            ||                                                               ||\n");
            printf("                                            ||              Thank you for using our application!             ||\n");
            printf("                                            ||                                                               ||\n");
            printf("                                            ++===============================================================++\n\n");
            reset();
            exit(0);
        default:
            system("cls");
            printf("\n\n\n\n\n\n");
            printf("                                            ++===============================================================++\n");
            printf("                                            ||                                                               ||\n");
            printf("                                            ||                ");
            red();
            printf("Invalid operation encountered !!");
            reset();
            printf("               ||\n");
            printf("                                            ||                                                               ||\n");
            printf("                                            ||               Please enter a valid Task number.               ||\n");
            printf("                                            ||                                                               ||\n");
            printf("                                            ++===============================================================++\n");
            printf("\n");
            break;
        }
    }
}

void admin_panel()
{
    printf("\n\n\n\n\n\n");
    printf("                                            ++===============================================================++\n");
    printf("                                            ||                           ");
    cyan();
    printf("Admin Panel                         ");
    reset();
    printf("||\n");
    printf("                                            ++===============================================================++\n");
    printf("                                            ||                                                               ||\n");
    printf("                                            ||       1. Campaign                                             ||\n");
    printf("                                            ||       2. Camp Overview                                        ||\n");
    printf("                                            ||       3. Current Statistics                                   ||\n");
    printf("                                            ||       4. Volunteer Management                                 ||\n");
    printf("                                            ||       5. Distribute Donations                                 ||\n");
    printf("                                            ||       6. Complain Box                                         ||\n");
    printf("                                            ||       7. Return Main Menu                                     ||\n");
    printf("                                            ||                                                               ||\n");
    printf("                                            ++===============================================================++\n\n");
    int p;
    printf("                                                      Enter your Task number: ");
    cin>>p;
    switch (p)
    {
    case 1:
        StockManager* manager;
        cout<<"                                           1. Ongoing Campaigns"<<endl;
        cout<<"                                           2. Current Stocks"<<endl;
        cout<<"                                           3. Run New Campaign"<<endl;
        cout<<"                                           4. Show Campaigns"<<endl;
        int campOpt;
        cin>>campOpt;
        switch(campOpt){
        case 1:
           manager->donateOngoingCampaign();
           break;
        case 4:
            manager->showCampaigns();
            admin_panel();
            break;
        case 3:
                cout<<"                                           1. Food Campaign"<<endl;
                cout<<"                                           2. Clothing Campaign"<<endl;
                cout<<"                                           3. Health Campaign"<<endl;
                cout<<"                                           4. Education Campaign"<<endl;
                cout<<"                                           5. Miscellaneous"<<endl;
                int campaignType;
                cin>>campaignType;
                switch(campaignType){
                    case 1:
                        manager->runNewFoodCampaign();
                        admin_panel();
                        break;
                    case 2:
                        manager->runNewClothingCampaign();
                        break;
                }
        break;
        }
        }}

        void donationDonate(){
class Donation {
public:
    Donation(string donorName, string other_donation, double amount, bool recurring)
        : donorName(donorName), other_donation(other_donation), amount(amount), recurring(recurring) {}

    void display(ostream& out) const {
        out << "                                        Donor: " << donorName << endl;
        out << "                                        Donations:" << endl;
        if (other_donation == "0")
            out << "                                        No things." << endl;
        else
            out <<"                                        "<<other_donation << endl;
        if (amount == 0)
            out << "                                        No cash.." << endl;
        else
            out <<"                                        "<< amount;
        if (recurring) {
            out << "(Recurring)";
        }
        out << "\n\n";
    }

private:
    string donorName;
    string other_donation;
    double amount;
    bool recurring;
};

class DonationManager {
public:
    void makeDonation() {
        string donorName;
        string other_donation;
        double amount;
        bool recurring;
        int type;

        cout << "                                        Enter donor name: ";
        cin >> donorName;

        cout << "                                        Enter donation amount: $(If you don't want ,type 0)";
        cin >> amount;

        if (amount != 0) {
            cout << "                                        Is it a recurring donation? (1 for yes, 0 for no): ";
            cin >> recurring;
        }

        cout << "                                        Enter other thing :(If you don't want ,type 0)";
        cin.ignore();
        getline(cin, other_donation);

        donations.push_back(Donation(donorName, other_donation, amount, recurring));
        cout << "\n                                        Thank you for your donation!\n\n";
    }

    void displayDonations(ostream& out) const {
        if (donations.empty()) {
            out<<"                                        No donations yet.\n\n";
        } else {
            out << "                                        All Donations:\n";
            for (const auto& donation : donations) {
                donation.display(out);
            }
        }
    }

    void saveDonationsToFile(const string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& donation : donations) {
                donation.display(outFile);
            }
            outFile.close();
            cout << "                                        Donations saved to file: " << filename << endl;
        } else {
            cout << "                                        Unable to open file: " << filename << endl;
        }
    }

private:
    vector<Donation> donations;
};
    DonationManager donationManager;
    int choice;

    do {
        printf("\n\n\n\n\n\n");
    printf("                                            ++===============================================================++\n");
    printf("                                            ||                           ");
  //  cyan();
    printf("   Donation                         ");
  //  reset();
    printf("||\n");
    printf("                                            ++===============================================================++\n");
    printf("                                            ||                                                               ||\n");
    printf("                                            ||       1. Make a Donation                                      ||\n");
    printf("                                            ||       2. Display Donations                                    ||\n");
    printf("                                            ||       3. Save Donations                                       ||\n");
    printf("                                            ||       0. Exit                                                 ||\n");
    printf("                                            ||                                                               ||\n");
    printf("                                            ++===============================================================++\n\n");
    int x;
    printf("                                                      Enter your Task number: ");
        cin >> choice;

        switch (choice) {
        case 1:
            donationManager.makeDonation();
            break;
        case 2:
            donationManager.displayDonations(cout);
            break;
        case 3:
            {
                string filename;
                cout <<setw(44) << "Enter filename to save donations: ";
                cin >> filename;
                donationManager.saveDonationsToFile(filename);
            }
            break;

        case 0:
            cout<<setw(44) << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout <<setw(44)<< "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}
