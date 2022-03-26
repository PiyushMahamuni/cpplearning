#include <iostream>
#include "Movies.h"

using namespace std;

int main(){
    Movies movies;
    char select;
    do{
        cout << "1: Add a new Movie or increment watched for a movie" << endl
             << "2: Display All Movies" << endl
             << "3: Display Movies Count" << endl
             << "Q: Quit" << endl;
        cin >> select;
        switch(select){
            case '1':
                movies.add_movie();
                break;
            case '2':
                movies.display_count();
                movies.display_movies();
                break;
            case '3':
                movies.display_count();
                break;
            case 'q':
            case 'Q':
                cout << "Okay, goodbye..." << endl;
                break;
            default:
                cout << "Invalid Entry, try again." << endl;
        }
    }while(select != 'q' && select != 'Q');
    return 0;
}