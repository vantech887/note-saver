#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void createNote();
void readNote();
void deleteNote();

int main()
{
    while(true)
    {

        string option;
        cout << "welcome to note saver, I can save notes and stuff" << endl;
        while(option != "w" && option != "r" && option != "d")
        {
            cout << "Choose an option: write (w), read (r), delete (d), quit (q): ";
            cin >> option;
            option = tolower(option[0]);
        }
        if(option == "w")
        {
            createNote();
        }else if(option == "r")
        {
            readNote();
        } else if(option[0] == 'q')
        {
            break;
        } else
        {
            deleteNote();
        }
        cout << "thank you for using note saver" << endl;
    }
    
    return 0;
}

void createNote()
{
    string note;
    ofstream userNote("note.txt", ios::app);
    if (userNote.is_open())
    {
        cout << "file open succesfully..." << '\n' << "Enter note: ";
        cin.ignore();
        getline(cin, note);
        userNote << note << endl;
        userNote.close();
    } else cout << "unable to open file...";
    
}

void readNote()
{
    ifstream readNote("note.txt");
    if(readNote.is_open())
    {
        string line;
        while(getline(readNote, line))
        {
            cout << line << endl;;
        }
        readNote.close();
    }else cout << "unabale to  open file";
    
}

void deleteNote()
{
    remove("note.txt");
}