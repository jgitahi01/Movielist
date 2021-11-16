#include "MovielistNode.h"

// function prototype
void PrintMenu(string title);

// start main function
int main()
{
    string plTitle;

    cout << "Enter movielist title:\n";
    getline(cin, plTitle);

    PrintMenu(plTitle);

    return 0;
}

// PrintMenu function implementation
// PrintMenu() takes the movie title as a parameter and outputs a menu
// of options to manipulate the movielist. Each option is represented by a
// single character. Build and output the menu within the function.
void PrintMenu(string title)
{
    Movielist list;
    string id;
    string sname;
    string aname;
    int length;
    int oldPos;
    int newPos;
    char choice;

    while (true)
    {
        cout << endl
             << title << " MOVIELIST MENU" << endl;
        cout << "a - Add movie" << endl;
        cout << "d - Remove movie" << endl;
        cout << "c - Change position of movie" << endl;
        cout << "s - Output movie by specific actor" << endl;
        cout << "t - Output total time of movie (in hours/min)" << endl;
        cout << "o - Output full movielist" << endl;
        cout << "q - Quit" << endl
             << endl;

        cout << "Choose an option:\n";
        cin >> choice;
        cin.ignore(); //flush newline

        if (choice == 'q' || choice == 'Q')
        {
            exit(1);
        }
        else if (choice == 'a' || choice == 'A')
        {
            cout << "\nADD MOVIE" << endl;
            cout << "Enter movie's unique ID: ";
            cin >> id;
            cin.ignore(); //ignore newline
            cout << "Enter movie's name: ";
            getline(cin, sname);
            cout << "Enter actor's name: ";
            getline(cin, aname);
            cout << "Enter movies's length (in hours/mins): ";
            cin >> length;
            list.AddMovie(id, sname, aname, length);
        }
        else if (choice == 'd' || choice == 'D')
        {
            cout << "\nREMOVE MOVIE" << endl;
            cout << "Enter movies's unique ID: ";
            cin >> id;
            list.RemoveMovie(id);
        }
        else if (choice == 'c' || choice == 'C')
        {
            cout << "\nCHANGE POSITION OF MOVIE" << endl;
            cout << "Enter movie's current position: ";
            cin >> oldPos;
            cout << "Enter new position for movie: ";
            cin >> newPos;
            list.ChangePosition(oldPos, newPos);
        }
        else if (choice == 's' || choice == 'S')
        {
            cout << "\nOUTPUT MOVIE BY SPECIFIC ACTOR" << endl;
            cout << "Enter actor's name: ";
            getline(cin, aname);
            list.MoviesByActor(aname);
        }
        else if (choice == 't' || choice == 'T')
        {
            cout << "\nOUTPUT TOTAL TIME OF MOVIES (IN HOURS/MINS)" << endl;
            cout << "Total time: " << list.TotalTime() << " hours/mins" << endl;
        }
        else if (choice == 'o' || choice == 'O')
        {
            cout << endl
                 << title << " - OUTPUT FULL MOVIELIST" << endl;
            list.PrintList();
        }
        else
        {
            cout << "Invalid menu choice! Please try again." << endl;
        }
    }
} // end of PrintMenu function
