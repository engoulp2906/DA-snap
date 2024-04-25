#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <regex>
#include <cmath>
using namespace std;
class login_system
{

protected:
    void waiting()
    {
        for (int i = 0; i < 10; i++)
        {
            Sleep(200);
            cout << "..";
        }
    }
    string fname, password, name, pass, date, month, year, email, number;

public:
    void homepage();
    void menu();
    void details();
    void modify();
    void change_password();
    void delete_account();
    void exit();
};

class CreateAcc : public login_system
{
public:
    void create();
};
class LoginPage : public login_system
{
public:
    void login();
};

class ListAccount : public login_system
{
public:
    void listacc();
};

class SearchAccount : public login_system
{
public:
    void searchacc();
};

void login_system::homepage()
{
    system("cls");
    cout << "\n\t    _____________________________________________________________________________________________" << endl;
    cout << "\t    |                                                  \t\t\t\t\t        |";
    cout << "\n\t    |\t\t             Welcome To My App: CREATE, LOGIN & AUTHENTICATION                  |" << endl;
    cout << "\t    |                                                  \t\t\t\t\t        |";
    cout << "\n\t    |___________________________________________________________________________________________|" << endl
         << endl
         << endl;
    cout << "\n\t\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|                HOMEPAGE              |";
    cout << "\n\t\t\t\t\t|______________________________________|";
    cout << "\n\t\t\t\t\t|                                      |";
    cout << "\n\t\t\t\t\t|Kindly select an option below:        |";
    cout << "\n\t\t\t\t\t|1. Create Account                     |";
    cout << "\n\t\t\t\t\t|2. Login                              |";
    cout << "\n\t\t\t\t\t|3. List of All Accounts               |";
    cout << "\n\t\t\t\t\t|4. Search Account By Name             |";
    cout << "\n\t\t\t\t\t|5. Exit                               |" << endl;
    cout << "\t\t\t\t\t|______________________________________|" << endl
         << endl;
    char x;
    cout << "\t\t\t\t\t-> ";
    cin >> x;
    if (x == '1')
    {
        CreateAcc acc;
        acc.create();
    }

    else if (x == '2')
    {
        LoginPage log;
        log.login();
    }
    else if (x == '3')
    {
        ListAccount l1;
        l1.listacc();
    }
    else if (x == '4')
    {
        SearchAccount s1;
        s1.searchacc();
    }
    else if (x == '5')
    {
        _exit(0);
    }
    else
    {
        cout << "\t\t\t\t\tInvalid Parameter, Try Again.";
        Sleep(636);
        homepage();
    }
}

void CreateAcc::create()
{
    system("cls");
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|               Create Account           |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl
         << endl;

    regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    regex phone_pattern(R"([0-9]{10})");

    string tempName, tempPhone, tempEmail;
    while (true)
    {
        cout << "\t\t\t\t\tEnter User_Name: " << endl
             << "\t\t\t\t\t";
        cin >> fname;

        fstream checkFile;
        checkFile.open("files", ios::in);
        bool usernameExists = false;
        while (checkFile >> tempName)
        {
            if (tempName == fname)
            {
                usernameExists = true;
                break;
            }

            checkFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        checkFile.close();

        if (usernameExists)
        {
            cout << "\n\t\t\t\t\tUsername already exists! Please choose a different username." << endl;
            continue;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << endl
             << "\t\t\t\t\tEnter your Contact Details: " << endl
             << "\t\t\t\t\tPhone Number : ";
        cin >> number;

        fstream checkFile;
        checkFile.open("files", ios::in);
        bool phoneExists = false;
        while (checkFile >> tempName >> tempPhone)
        {
            if (tempPhone == number)
            {
                phoneExists = true;
                break;
            }

            checkFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        checkFile.close();

        if (phoneExists)
        {
            cout << "\n\t\t\t\t\tPhone number already exists! Please enter a different phone number." << endl;
            continue;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << endl
             << "\t\t\t\t\tEnter Email Address: " << endl
             << "\t\t\t\t\t";
        cin >> email;

        fstream checkFile;
        checkFile.open("files", ios::in);
        bool emailExists = false;
        while (checkFile >> tempName >> tempPhone >> tempEmail)
        {
            if (tempEmail == email)
            {
                emailExists = true;
                break;
            }

            checkFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        checkFile.close();

        if (emailExists)
        {
            cout << "\n\t\t\t\t\tEmail address already exists! Please enter a different email address." << endl;
            continue;
        }
        else
        {
            break;
        }
    }

    cout << endl
         << "\t\t\t\t\tEnter your Date of Birth-" << endl
         << "\t\t\t\t\tDay :  ";
    cin >> date;
    cout << "\t\t\t\t\tMonth : ";
    cin >> month;
    cout << "\t\t\t\t\tYear :  ";
    cin >> year;

    while (true)
    {
        cout << endl
             << "\t\t\t\t\tEnter password: " << endl
             << "\t\t\t\t\t";
        char ch;
        password = "";
        ch = _getch();
        while (ch != 13)
        {
            if (ch == '\b')
            {
                if (!password.empty())
                {
                    cout << "\b \b";
                    password.pop_back();
                }
            }
            else
            {
                if (password.length() < 18)
                {
                    password.push_back(ch);
                    cout << '*';
                }
            }
            ch = _getch();
        }
        if (password.length() >= 8)
        {
            break;
        }
        cout << endl
             << "\t\t\t\tPlease enter the password greater than 8 characters!!!" << endl;
    }

    fstream file;
    file.open("files", ios::app | ios::out);
    if (!file)
    {
        cout << "\t\t\t\t\tRegistration failed" << endl
             << "Try again later" << endl;
    }
    else
    {
        file << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
        cout << "\n\n\t\t\t\t\tAccount Created Successfully." << endl
             << "\n\t\t\t\t\t";
        file.close();
    }
    system("pause");
    login_system::homepage();
}
void LoginPage::login()
{
    system("cls");
    cout << "\n\t\t\t\t\t _______________________________________" << endl;
    cout << "\t\t\t\t\t*                                      *" << endl;
    cout << "\t\t\t\t\t*            Welcome to MyApp          *" << endl;
    cout << "\t\t\t\t\t*                                      *" << endl;
    cout << "\t\t\t\t\t*              LOGIN PAGE              *" << endl;
    cout << "\t\t\t\t\t*______________________________________*" << endl
         << endl;
    fstream file;
    file.open("files", ios::in);
    if (!file)
    {
        cout << "\t\t\t\t\t\tError! File not found" << endl;
        file.close();
        cout << "\n\t\t\t\t\t\t";
        system("pause");
        file.close();
        homepage();
    }
    else
    {
        char ch;
        name = "";
        pass = "";
        int flag = 0;
        cout << "\t\t\t\t\tEnter User_Name : ";
        cin >> name;
        cout << "\t\t\t\t\tEnter Password : ";
        ch = _getch();
        while (ch != 13)
        {
            if (ch == '\b')
            {
                if (!pass.empty())
                {
                    cout << "\b \b";
                    pass.pop_back();
                }
            }
            else
            {
                pass.push_back(ch);
                cout << '*';
            }
            ch = _getch();
        }
        file >> fname >> password >> number >> email >> date >> month >> year;
        while (!file.eof())
        {
            if (name == fname && pass == password)
            {
                flag = 1;
                break;
            }
            file >> fname >> password >> number >> email >> date >> month >> year;
        }
        cout << "\n\t\t\t\t\tVerifying User Data" << endl
             << "\t\t\t\t\t";
        waiting();
        if (flag == 1)
        {
            cout << endl
                 << endl
                 << "\t\t\t\t\tLogin Successful";
            file.close();
            Sleep(789);
            menu();
        }
        else if (flag == 0)
        {
            cout << endl
                 << endl
                 << "\t\t\t\t\tNo account exists with given credentials." << endl;
            cout << "\n\t\t\t\t\t";
            system("pause");
            file.close();
            homepage();
        }
    }
}

void ListAccount::listacc()
{
    int x = 1;
    system("cls");
    cout << "\n\t\t\t\t\t _______________________________________" << endl;
    cout << "\t\t\t\t\t*                                      *" << endl;
    cout << "\t\t\t\t\t*            Welcome to MyApp          *" << endl;
    cout << "\t\t\t\t\t*                                      *" << endl;
    cout << "\t\t\t\t\t*              LOGIN PAGE              *" << endl;
    cout << "\t\t\t\t\t*______________________________________*" << endl
         << endl;

    fstream file;
    file.open("files", ios::in);
    if (!file)
    {
        cout << "\t\t\t\t\t Error! File not found" << endl;
    }
    else
    {
        file >> fname >> password >> number >> email >> date >> month >> year;
        while (!file.eof())
        {
            Sleep(66);
            cout << "\t\t\t\t\t\t ______________" << endl;
            cout << "\t\t\t\t\t\t|              |" << endl;
            cout << "\t\t\t\t\t\t|   ACCOUNT " << x++ << "  |" << endl;
            cout << "\t\t\t\t\t\t|______________|" << endl;
            cout << endl
                 << "\t\t\t\t\t 1. User_name = " << fname << endl;
            cout << "\t\t\t\t\t 2. Contact = " << number << endl;
            cout << "\t\t\t\t\t 3. Email = " << email << endl;
            cout << "\t\t\t\t\t 4. Date of Birth = " << date << "/" << month << "/" << year << endl;
            cout << "\t\t\t\t\t ------------------------------------" << endl
                 << endl;
            file >> fname >> password >> number >> email >> date >> month >> year;
        }
        cout << "\t\t\t\t\t Reached at end of the File" << endl;
    }
    file.close();
    cout << "\t\t\t\t\t ";
    system("pause");
    homepage();
}

void SearchAccount::searchacc()
{
    system("cls");
    cout << "\n\t\t\t\t ___________________________________________\n";
    cout << "\t\t\t\t|                                           |";
    cout << "\n\t\t\t\t|                SEARCH ACCOUNT             |" << endl;
    cout << "\t\t\t\t|___________________________________________|" << endl
         << endl;
    cout << "\t\t\t\t\tEnter User_Name: ";
    cin >> name;
    int found = 0;
    fstream file;
    file.open("files", ios::in);
    file >> fname >> password >> number >> email >> date >> month >> year;
    while (!file.eof())
    {
        if (name == fname)
        {
            Sleep(66);
            cout << endl
                 << "\t\t\t\t\t1. User_Name = " << fname << endl;
            cout << "\t\t\t\t\t2. Email = " << email << endl;
            cout << "\t\t\t\t\t3. Contact = " << number << endl;
            cout << "\t\t\t\t\t4. Date of Birth = " << date << "/" << month << "/" << year << endl
                 << endl;
            cout << "\t\t\t\t\t------------------------------------" << endl
                 << endl;
            found++;
        }
        file >> fname >> password >> number >> email >> date >> month >> year;
    }
    if (found == 0)
    {
        cout << endl
             << "\t\t\t\t\tNo account exist with [" << name << "] username ." << endl
             << endl;
    }
    file.close();
    cout << "\t\t\t\t\t";
    system("pause");
    homepage();
}
const int MAX_ACCOUNTS = 100;
struct BankAccount
{
    string accountNumber;
    string accountHolderName;
    double balance;
    double creditScore;
    double accountHistory;    // Years
    double paymentHistory;    // Percentage
    double debtToIncomeRatio; // Percentage
    double otherFactors;      // Arbitrary score (0-100)
    bool hasInsurance;
    string policyNumber;
    double coverageAmount;
    double premium;
    bool hasClaimedInsurance;
};
BankAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;
void initializeAccounts()
{
    // Database of 10 pre-defined accounts
    string accountNumbers[10] = {"1001", "1002", "1003", "1004", "1005", "1006", "1007", "1008", "1009", "1010"};
    string accountHolders[10] = {"Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Henry", "Ivy", "Jack"};
    double balances[10] = {5000.0, 3000.0, 7000.0, 4000.0, 6000.0, 2000.0, 8000.0, 4500.0, 5500.0, 3500.0};
    double creditScores[10] = {750.0, 700.0, 800.0, 720.0, 780.0, 680.0, 820.0, 730.0, 760.0, 710.0};

    for (int i = 0; i < 10; ++i)
    {
        accounts[numAccounts].accountNumber = accountNumbers[i];
        accounts[numAccounts].accountHolderName = accountHolders[i];
        accounts[numAccounts].balance = balances[i];
        accounts[numAccounts].creditScore = creditScores[i];
        accounts[numAccounts].accountHistory = 5.0;     // Default account history
        accounts[numAccounts].paymentHistory = 95.0;    // Default payment history
        accounts[numAccounts].debtToIncomeRatio = 20.0; // Default debt-to-income ratio
        accounts[numAccounts].hasInsurance = false;
        accounts[numAccounts].hasClaimedInsurance = false;
        numAccounts++;
    }
}
void createBankAccount()
{
    if (numAccounts < MAX_ACCOUNTS)
    {
        BankAccount newAccount;
        cout << "Enter Account Number: ";
        cin >> newAccount.accountNumber;
        cout << "Enter Account Holder Name: ";
        cin >> newAccount.accountHolderName;
        newAccount.balance = 0.0;
        newAccount.creditScore = 0.0; // Default credit score
        cout << "Enter Account History (years): ";
        cin >> newAccount.accountHistory;
        cout << "Enter Payment History (% of on-time payments): ";
        cin >> newAccount.paymentHistory;
        cout << "Enter Debt-to-Income Ratio (%): ";
        cin >> newAccount.debtToIncomeRatio;
        accounts[numAccounts++] = newAccount;
        cout << "Account created successfully." << endl;
    }
    else
    {
        cout << "Maximum number of accounts reached." << endl;
    }
}
void checkBalance() {
    string accNum;
    cout << "Enter Account Number: ";
    cin >> accNum;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accNum) {
            cout << "Current Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}
void depositMoney() {
    string accNum;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNum;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accNum) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            accounts[i].balance += amount;
            cout << "Deposit successful. Updated balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to transfer money between accounts
void transferMoney() {
    string senderAccNum, receiverAccNum;
    double amount;
    cout << "Enter Sender's Account Number: ";
    cin >> senderAccNum;
    cout << "Enter Receiver's Account Number: ";
    cin >> receiverAccNum;
    cout << "Enter Amount to Transfer: ";
    cin >> amount;
    // Find sender and receiver accounts
    int senderIndex = -1, receiverIndex = -1;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == senderAccNum) {
            senderIndex = i;
        }
        if (accounts[i].accountNumber == receiverAccNum) {
            receiverIndex = i;
        }
    }
    if (senderIndex != -1 && receiverIndex != -1) {
        if (accounts[senderIndex].balance >= amount) {
            accounts[senderIndex].balance -= amount;
            accounts[receiverIndex].balance += amount;
            cout << "Transfer successful." << endl;
            cout << "Sender's Updated Balance: " << accounts[senderIndex].balance << endl;
            cout << "Receiver's Updated Balance: " << accounts[receiverIndex].balance << endl;
        } else {
            cout << "Insufficient balance in the sender's account." << endl;
        }
    } else {
        cout << "One or both accounts not found." << endl;
    }
}

// Function to apply for a loan
void applyForLoan() {
    string accNum;
    double loanAmount;
    cout << "Enter Account Number: ";
    cin >> accNum;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accNum) {
            cout << "Enter Loan Amount: ";
            cin >> loanAmount;
            // Simple credit score-based approval
            if (accounts[i].creditScore >= 650) {
                accounts[i].balance += loanAmount;
                cout << "Loan approved. Updated balance: " << accounts[i].balance << endl;
            } else {
                cout << "Loan application rejected due to low credit score." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}
// Function to check credit score of an account
void checkCreditScore() {
    string accNum;
    cout << "Enter Account Number: ";
    cin >> accNum;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accNum) {
            cout << "Credit Score: " << accounts[i].creditScore << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to purchase insurance
void purchaseInsurance() {
    string accNum;
    double coverage, premium;
    cout << "Enter Account Number: ";
    cin >> accNum;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accNum) {
            if (accounts[i].hasInsurance) {
                cout << "Insurance policy already purchased for this account." << endl;
            } else {
                cout << "Enter Policy Number: ";
                cin >> accounts[i].policyNumber;
                cout << "Enter Coverage Amount: ";
                cin >> coverage;
                cout << "Enter Premium: ";
                cin >> premium;
                accounts[i].hasInsurance = true;
                accounts[i].coverageAmount = coverage;
                accounts[i].premium = premium;
                cout << "Insurance policy purchased successfully." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to check insurance policy details
void checkInsurancePolicy() {
    string accNum;
    cout << "Enter Account Number: ";
    cin >> accNum;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accNum) {
            if (accounts[i].hasInsurance) {
                cout << "Policy Number: " << accounts[i].policyNumber << endl;
                cout << "Coverage Amount: " << accounts[i].coverageAmount << endl;
                cout << "Premium: " << accounts[i].premium << endl;
            } else {
                cout << "No insurance policy purchased for this account." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to make insurance claim
void makeInsuranceClaim() {
    string accNum;
    cout << "Enter Account Number: ";
    cin >> accNum;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accNum) {
            if (accounts[i].hasInsurance) {
                if (!accounts[i].hasClaimedInsurance) {
                    // Process claim (For demonstration, just setting a flag)
                    accounts[i].hasClaimedInsurance = true;
                    cout << "Insurance claim processed successfully." << endl;
                } else {
                    cout << "Insurance claim already processed for this account." << endl;
                }
            } else {
                cout << "No insurance policy purchased for this account." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}
void displayBankingMenu()
{
    login_system ls;
    system("cls");
    cout << "\n\t\t\t\t __________________________________________________\n";
    cout << "\t\t\t\t|                                                  |";
    cout << "\n\t\t\t\t|                 Banking Portal                   |" << endl;
    cout << "\t\t\t\t|__________________________________________________|" << endl
         << endl
         << endl;
    cout << "\t\t\t\t\tKindly select an option below:" << endl
         << endl;
    cout << "\t\t\t\t\t1. Create Account" << endl
         << endl;
    cout << "\t\t\t\t\t2. Check Balance" << endl
         << endl;
    cout << "\t\t\t\t\t3. Deposit Money " << endl
         << endl;
    cout << "\t\t\t\t\t4. Transfer Money" << endl
         << endl;
    cout << "\t\t\t\t\t5. Apply for Loan" << endl
         << endl;
    cout << "\t\t\t\t\t6. Check Credit Score" << endl
         << endl;
    cout << "\t\t\t\t\t7. Purchase Insurance" << endl
         << endl;
    cout << "\t\t\t\t\t8. Check Insurance Policy" << endl
         << endl;
    cout << "\t\t\t\t\t9. Make Insurance Claim" << endl
         << endl;
    cout << "\t\t\t\t\t10. Exit" << endl;
    cout << endl;
    int choice;
    do {
        cout<<"\n\n";
        cout << "\t\t\t\t\tKindly select an option below: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createBankAccount();
                break;
            case 2:
                checkBalance();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                transferMoney();
                break;
            case 5:
                applyForLoan();
                break;
            case 6:
                checkCreditScore();
                break;
            case 7:
                purchaseInsurance();
                break;
            case 8:
                checkInsurancePolicy();
                break;
            case 9:
                makeInsuranceClaim();
                break;
            case 10:
                cout << "\n\t\t\t\t\tLogging Out Of Banking Portal . . ." << endl<< "\t\t\t\t\t";
                ls.menu();
            default:
                cout << "\t\t\t\t\tInvalid Option\n\t\t\t\t\tTry Again." << endl;
        }
    } while (choice != 10); 
}
void login_system::menu()
{
    system("cls");
    cout << "\n\t\t\t\t __________________________________________________\n";
    cout << "\t\t\t\t|                                                  |";
    cout << "\n\t\t\t\t|                 ACCOUNT MANAGMENT                |" << endl;
    cout << "\t\t\t\t|__________________________________________________|" << endl
         << endl
         << endl;
    cout << "\t\t\t\t\tKindly select an option below:" << endl
         << endl;
    cout << "\t\t\t\t\t1. Account Details" << endl
         << endl;
    cout << "\t\t\t\t\t2. Modify Account" << endl
         << endl;
    cout << "\t\t\t\t\t3. Open Banking Portal " << endl
         << endl;
    cout << "\t\t\t\t\t4. Change Password" << endl
         << endl;
    cout << "\t\t\t\t\t5. Delete Account" << endl
         << endl;
    cout << "\t\t\t\t\t6. Logout" << endl;
    char option;
    cout << endl
         << "\t\t\t\t\t-> ";
    cin >> option;
    switch (option)
    {
    case '1':
        details();
        break;
    case '2':
        modify();
        break;
    case '3':
        displayBankingMenu();
        break;
    case '4':
        change_password();
    case '5':
        delete_account();
    case '6':
    {
        cout << "\n\t\t\t\t\tLogging Out . . ." << endl
             << "\t\t\t\t\t";
        waiting();
        homepage();
    }
    default:
        cout << "\t\t\t\t\tInvalid Option\n\t\t\t\t\tTry Again." << endl;
        Sleep(636);
        menu();
    }
}
void login_system::details()
{
    system("cls");
    cout << "\n\t\t\t\t ___________________________________________\n";
    cout << "\t\t\t\t|                                           |";
    cout << "\n\t\t\t\t|              ACCOUNT DETAILS              |" << endl;
    cout << "\t\t\t\t|___________________________________________|" << endl
         << endl;
    fstream file;
    file.open("files", ios::in);
    file >> fname >> password >> number >> email >> date >> month >> year;
    while (!file.eof())
    {
        if (name == fname && password == pass)
        {
            Sleep(66);
            cout << endl
                 << "\t\t\t\t\t1. User_Name = " << fname << endl
                 << endl;
            Sleep(66);
            cout << "\t\t\t\t\t2. Email = " << email << endl
                 << endl;
            Sleep(66);
            cout << "\t\t\t\t\t3. Contact = " << number << endl
                 << endl;
            Sleep(66);
            cout << "\t\t\t\t\t4. Date of Birth = " << date << "/" << month << "/" << year << endl
                 << endl;
            Sleep(66);
            cout << "\t\t\t\t\t5. Account Password = " << password << endl
                 << endl;
            break;
        }
        file >> fname >> password >> number >> email >> date >> month >> year;
    }
    file.close();
    cout << "\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::modify()
{
    system("cls");
    cout << "\n\t\t\t\t ___________________________________________\n";
    cout << "\t\t\t\t|                                           |";
    cout << "\n\t\t\t\t|              MODIFY ACCOUNT               |" << endl;
    cout << "\t\t\t\t|___________________________________________|" << endl
         << endl;
    fstream file, file1;
    file.open("files", ios::in);
    file1.open("modify", ios::app | ios::out);
    file >> fname >> password >> number >> email >> date >> month >> year;
    while (!file.eof())
    {
        if (name == fname && pass == password)
        {
            cout << "\t\t\t\t\tEnter User_Name: " << endl
                 << "\t\t\t\t\t";
            cin >> fname;
            cout << endl
                 << "\t\t\t\t\tEnter your Date of Birth- " << endl
                 << "\t\t\t\t\tDay :  ";
            cin >> date;
            cout << "\t\t\t\t\tMonth : ";
            cin >> month;
            cout << "\t\t\t\t\tYear :  ";
            cin >> year;
            cout << endl
                 << "\t\t\t\t\tEnter your Contact Details: " << endl
                 << "\t\t\t\t\tPhone Number : ";
            cin >> number;
            cout << endl
                 << "\t\t\t\t\tEnter Email Address: " << endl
                 << "\t\t\t\t\t";
            cin >> email;
            file1 << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
        }
        else
        {
            file1 << fname << " " << password << " " << number << " " << email << " " << date << " " << month << " " << year << "\n";
        }
        file >> fname >> password >> number >> email >> date >> month >> year;
    }
    cout << endl
         << "\t\t\t\t\tSaving new details, Please wait . . ." << endl
         << "\t\t\t\t\t";
    waiting();
    file.close();
    file1.close();
    remove("files");
    rename("modify", "files");
    cout << endl
         << "\n\t\t\t\t\tAccount Details Saved Successfully." << endl;
    cout << "\t\t\t\t\tChanges will be shown after Re-login." << endl
         << "\n\t\t\t\t\t";
    system("pause");
    menu();
}
