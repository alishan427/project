#include <iostream>
#include <windows.h>
using namespace std;
const int userArrSize = 10;
string usernames[userArrSize];
string passwords[userArrSize];
string roles[userArrSize];
int userCount = 0;

void header();
string signin(string name, string password);
bool signUp(string name, string password, string role);
int loginMenue();
int AdminOptions();
void new_entries_of_students();
void add_new_books();
void Delete_Entries();
void Check_About_Students();
void StudentOptions();

main()
{
    system("Color F0");

    string login;
    int option;
    header();
    while (option != 3)
    {
        option = loginMenue();
        if (option == 1)
        {
            string username;
            string password;
            cin >> username;
            cin >> password;
            string role = signin(username, password);

            if (role == "admin")
            {
               int option =  AdminOptions();
               if (option == 1)
               {
                  new_entries_of_students();
               }
               if (option == 2)
               {
                add_new_books();
               }
               if (option == 3)
               {
                 Delete_Entries();
               }
               if (option == 4)
               {
                 Check_About_Students();
               }
               if (option == 5)
               {
                break;
               }

            }
            if (role == "student")
            {
                StudentOptions();
            }
            if (role == "undefined")
            {
                loginMenue();
            }
        }

        if (option == 2)
        {
            string username;
            string password;
            string role;
            cin >> username;
            cin >> password;
            cin >> role;
            bool check = signUp(username, password, role);
            if (check == true)
            {
                cout << "Sign Up Successfully" << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
}
void header()
{
    cout << "         *********************************************************************************       " << endl;
    cout << "         **************************Library Management System******************************       " << endl;
    cout << "         *********************************************************************************                                                ";
    cout << "                                                         " << endl;
    cout << "                                                         " << endl;
}
int loginMenue()
{
    int option;
    cout << "1. Sign In " << endl;
    cout << "2. Sign Up " << endl;
    cout << "3. Exit " << endl;
    cout << endl;
    cout << "Enter Option: ";
    cin >> option;
    return option;
}

int AdminOptions()
{
    {   int option;
        cout << endl;
        cout << "  1. Add new entries of students:  " << endl;
        cout << "  2. Add new books:     " << endl;
        cout << "  3. Delete Entries:     " << endl;
        cout << "  4. Check data about students:  " << endl;
        cout << "  5. Exit                     " << endl;
        cout << "Option: ";
        cin >> option;
    }
}

bool signUp(string username, string password, string role)
{
    usernames[userCount] = username;
    passwords[userCount] = password;
    roles[userCount] = role;
    userCount = userCount + 1;
    return true;
}
string signin(string username, string password)
{
    for (int x = 0; x < userCount; x++)
    {
        string role1 = "admin";
        if (username == usernames[x] && password == passwords[x])
        {
            return role1;
        }
        string role = "student";
        if (username == usernames[x] && password == passwords[x])
        {
            return role;
        }
    }
    return "undefined";
}
void StudentOptions()
{
    cout << endl;
    cout << "1. Search New Arrivals: " << endl;
    cout << "2. Check Status:   " << endl;
    cout << "3. Search Book By Authors name: " << endl;
    cout << "4. Most Searched Books: " << endl;
    cout << "5. Exit " << endl;
}
void new_entries_of_students()
{   string name;
    string book_name;
    int Roll_No;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Roll_No: ";
    cin >> Roll_No;
    cout << "Enter Name of Book to Borrow: ";
    cin >> book_name;
}
void add_new_books()
{
    string book_name;
    string author_name;

    cout << "Enter Book Name: ";
    cin >> book_name;
    cout << "Enter author_name: ";
    cin >> author_name;
}
void Delete_Entries()
{

}

void Check_About_Students()
{
    
}