#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<stdio.h>
using namespace std;
string acc_num;
string acc_trans;
int admin_account();
int client_account();
int login();
int add_account();
int read();
int modify_account();
int close_account();
int list_account();
int balance();
int withdraw();
int deposit();
void transfer();
struct account
{
    char account_num[10];
    char f_name[10];
    char last_name[10];
    long long balance;
    char type; //admin & client
    char username[15];
    char password[10];
};
int intro()
{
    int option;
    do
    {
        system("cls");
        cout << "\n\n\n\tBANKING RECORD SYSTEM";
        cout << "\n\n\n\t1. LOGIN";
        cout << "\n\n\t2. REGISTER";
        cout << "\n\n\t3. EXIT";
        cout << "\n\n\tSelect Your Option (1-3) ";
        cin >> option;
        system("cls");
        switch (option)
        {
        case 1:
            login();
            break;
        case 2:
            add_account();
            break;
        case 3:
            return 0;
            break;
        }
    } while (option != 3);
    return 0;
}
int login()
{
    account data;
    string user;
    string pass;
    cout << "\n\tEnter username : ";
    cin >> user;
    cout << "\n\tEnter Password : ";
    cin >> pass;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.username == user && data.password == pass)
        {
            if (data.type == 'A')
            {
                infile.close();
                admin_account();
            }
            else if (data.type == 'C')
            {
                infile.close();
                acc_num = data.account_num;
                client_account();
            }
        }

    }
    infile.close();
    return 0;
}
int admin_account()
{
    int option;
    int num;
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\tADMIN ACCOUNT";
        cout << "\n\n\n\t1. Add a New Account";
        cout << "\n\n\t2. Modify An Account";
        cout << "\n\n\t3. Close An Account";
        cout << "\n\n\t4. List All Accounts";
        cout << "\n\n\t5. Log Out";
        cout << "\n\n\tSelect Your Option (1-5) ";
        cin >> option;
        system("cls");
        switch (option)
        {
        case 1:
            add_account();
            break;
        case 2:
            modify_account();
            break;
        case 3:
            close_account();
            break;
        case 4:
            list_account();
            break;
        case 5:
            break;
        }
    } while (option != 5);
    return 0;
}
int add_account()
{
    account data;
    cout << "\n\n\n\tADD A NEW ACCOUNT";
    cout << "\n\n\n\tEnter The account No. : ";
    cin >> data.account_num;
    cout << "\n\tEnter Type of The account (A/C) : ";
    cin >> data.type;
    data.type = toupper(data.type);
    cout << "\n\tEnter the first name : ";
    cin >> data.f_name;
    cout << "\n\tEnter the last name : ";
    cin >> data.last_name;
    cout << "\n\tEnter opening balance : ";
    cin >> data.balance;
    cout << "\n\tEnter username : ";
    cin >> data.username;
    cout << "\n\tEnter Password : ";
    cin >> data.password;
    fstream outfile;
    outfile.open("DATA.txt", ios::in | ios::out | ios::app);
    outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
    outfile.close();
    return 0;
}
int list_account()
{
    account data;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    cout << "\n\tALL ACCOUNTS\n\n";
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        cout << "\n\tBALANCE DETAILS\n";
        cout << "================================";
        cout << "\n\tAccount No. : " << data.account_num;
        cout << "\n\tName : " << data.f_name << " " << data.last_name;
        cout << "\n\tType of Account : " << data.type;
        cout << "\n\tBalance : " << data.balance;
        cout << "\n\tUsername : " << data.username;
        cout << "\n\tPassword : " << data.password;
        cout << "\n================================\n\n";

    }
    infile.close();
    system("pause");
    return 0;
}
int close_account()
{
    account data;
    string acc_num;
    cout << "\n\n\n\tEnter The account No. : ";
    cin >> acc_num;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    ofstream outfile;
    outfile.open("new.txt", ios::in | ios::out | ios::app);

    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num != acc_num)
        {
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
        else
            cout << "\n\n\tRecord Deleted Successfully\n";
    }
    infile.close();
    outfile.close();
    remove("DATA.txt");
    rename("new.txt", "DATA.txt");
    return 0;
}
int modify_account()
{
    account data;
    read();
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    ofstream outfile;
    outfile.open("new.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num != acc_num)
        {
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
        else
        {
            cout << "\n\n\tMODIFY ACCOUNT";
            cout << "\n\n\tEnter The new account No. : ";
            cin >> data.account_num;
            cout << "\n\tEnter Type of The account (A/C) : ";
            cin >> data.type;
            cout << "\n\tEnter the first name : ";
            cin >> data.f_name;
            cout << "\n\tEnter the last name : ";
            cin >> data.last_name;
            cout << "\n\tEnter opening balance : ";
            cin >> data.balance;
            cout << "\n\tEnter username : ";
            cin >> data.username;
            cout << "\n\tEnter Password : ";
            cin >> data.password;
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
    }
    infile.close();
    outfile.close();
    remove("DATA.txt");
    rename("new.txt", "DATA.txt");
    system("pause");
    return 0;


}
//**
int read()
{
    cout << "\n\n\n\tEnter The account No. : ";
    cin >> acc_num;
    account data;
    int flag = 0;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num == acc_num)
        {
            flag = 1;
            cout << "\n\tBALANCE DETAILS\n";
            cout << "---------------------------------";
            cout << "\n\tAccount No. : " << data.account_num;
            cout << "\n\tName : " << data.f_name << " " << data.last_name;
            cout << "\n\tType of Account : " << data.type;
            cout << "\n\tBalance : " << data.balance << "\n";
            cout << "\n\tUsername : " << data.username << "\n";
            cout << "\n\tPassword : " << data.password << "\n";
            cout << "---------------------------------";
        }
    }
    if (flag == 0)
        cout << "\n\n\tAccount number does not exist";
    infile.close();
    return 0;
}
//**
int balance()
{
    account data;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num == acc_num)
        {
            cout << "\n\tBALANCE DETAILS\n";
            cout << "---------------------------------";
            cout << "\n\tBalance : " << data.balance << "\n";
            cout << "---------------------------------" << "\n";
        }
    }
    infile.close();
    system("pause");
    return 0;
}
int client_account()
{
    int option;
    int num;
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\tCLIENT ACCOUNT";
        cout << "\n\n\n\t1. Balance Enquiry";
        cout << "\n\n\t2. Withdraw";
        cout << "\n\n\t3. Deposit";
        cout << "\n\n\t4. Transfer";
        cout << "\n\n\t5. Log Out";
        cout << "\n\n\tSelect Your Option (1-5) ";
        cin >> option;
        system("cls");
        switch (option)
        {
        case 1:
            balance();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            deposit();
            break;
        case 4:
            transfer();
            break;
        case 5:
            break;
        }
    } while (option != 5);
    return 0;
}
int deposit()
{
    long long  Mdeposit;
    account data;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    ofstream outfile;
    outfile.open("new.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num != acc_num)
        {
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
        else
        {
            cout << "\n\tYour Balance is" << data.balance << endl;
            cout << "\n\tEnter The Amount That You Want to Deposit" << " : ";
            cin >> Mdeposit;
            data.balance += Mdeposit;

            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
    }
    infile.close();
    outfile.close();
    remove("DATA.txt");
    rename("new.txt", "DATA.txt");
    system("pause");
    return 0;

}
int withdraw()
{
    long long  Mwithdraw;
    account data;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    ofstream outfile;
    outfile.open("new.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num != acc_num)
        {
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
        else
        {
            cout << "\n\tYour Balance is" << data.balance << endl;
            cout << "\n\tEnter The Amount That You Want to Withdraw" << " : ";
            cin >> Mwithdraw;
            data.balance -= Mwithdraw;

            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
    }
    infile.close();
    outfile.close();
    remove("DATA.txt");
    rename("new.txt", "DATA.txt");
    system("pause");
    return 0;

}
void transfer()
{
    long long  Mwithdraw;
    account data;
    ifstream infile;
    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    ofstream outfile;
    outfile.open("new.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num != acc_num)
        {
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
        else
        {
            cout << "\n\tYour Balance is" << data.balance << endl;
            cout << "\n\tEnter The Amount That You Want to Transfer" << " : ";
            cin >> Mwithdraw;
            data.balance -= Mwithdraw;

            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
    }
    infile.close();
    outfile.close();
    remove("DATA.txt");
    rename("new.txt", "DATA.txt");

    cout << "\n\tTransfer to" << " : ";
    cin >> acc_trans;

    infile.open("DATA.txt", ios::in | ios::out | ios::app);
    outfile.open("new.txt", ios::in | ios::out | ios::app);
    while (infile >> data.account_num >> data.type >> data.f_name >> data.last_name >> data.balance >> data.username >> data.password)
    {
        if (data.account_num != acc_trans)
        {
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
        }
        else
        {
            data.balance += Mwithdraw;
            outfile << data.account_num << " " << data.type << " " << data.f_name << " " << data.last_name << " " << data.balance << " " << data.username << " " << data.password << " \n";
            cout << "\n\ntransfer completed";
        }
    }
    infile.close();
    outfile.close();
    remove("DATA.txt");
    rename("new.txt", "DATA.txt");
    system("pause");

}
int main()
{
    intro();
    return 0;
}