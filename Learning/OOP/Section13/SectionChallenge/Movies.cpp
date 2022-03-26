#include "Movies.h"
#include <string>
#include <iostream>

int Movies::count = 0;

void Movies::add_movie(){
    try_again:
    std::cout << "Enter a new movie [n] or" << std::endl
         << "Increment watched of already watched movie [i]: "<< std::endl;
    char choice;
    std::cin >> choice;
    switch(choice){
        // Adding a new Movie
        case 'n':
        case 'N':
        {
            Movie temp;
            // Create a new Movie Object
            bool to_add {true};
            // See if the movie already exists in the collection
            for (auto &movie: collection){
                if(((movie.ptr)->name) == ((temp.ptr)->name)){ //if the movie exists, to_add = false
                    to_add = false;
                    try_again_1:
                    std::cout << "Movie already exists, we can increment the watched" << std::endl
                         << "instead, should we do that? (y/n): ";
                    std::cin >> choice;
                    switch(choice){
                        case 'y':
                        case 'Y':
                            movie.ptr->watched++;
                            break;
                        case 'n':
                        case 'N':
                            std::cout << "Aborted Increment." << std::endl;
                            break;
                        default:
                            std::cout << "Invalid Entry, try again.!" << std::endl;
                            goto try_again_1;
                    }
                    break;
                }
            }
            if(to_add){
                collection.push_back(std::move(temp)); // move the temp movie object into collection
                std::cout << "Movie added successfully!" << std::endl
                     << "-----------------------------------" << std::endl;
                count++;
            }
            break;
        }
        
        
        //increment the count of already existing movie
        case 'i':
        case 'I':
        {
            std::string _name;
            bool not_found {true};
            try_again_2:
            std::cout << "Enter Name of Movie: ";
            getchar();
            getline(std::cin, _name);
            for(auto &movie: collection){
                if (movie.ptr->name == _name){
                    not_found = false;
                    movie.ptr->watched++;
                    std::cout << "successfully incremented wathced for" << std::endl
                         << "Movie: " << _name << std::endl;
                    break;
                }
            }
            if(not_found){
                try_again_3:
                std::cout << "Error!!! Movie name not found in the collection!" << std::endl
                          << "Should I display all the movie names? (y/n/q-quit): ";
                std::cin >> choice;
                switch(choice){
                    case 'y':
                    case 'Y':
                        this->display_movies(); //fall through desired
                    case 'n':
                    case 'N':
                        goto try_again_2;
                        break;
                    case 'q':
                    case 'Q':
                        std::cout << "Operation Aborted: incrementing" << std::endl;
                        break;
                    default:
                        std::cout << "Invalid Entry! try again." << std::endl;
                        goto try_again_3;
                }
            }
            break;
            
        }
            
        default:
            std::cout << "Invalid Entry, please try again." << std::endl;
            goto try_again;
    }
}

void Movies::display_movies() const{
    for(auto &movie: collection){
        movie.display();
    }
}

void Movies::display_count(){
    std::cout << "-----------------------------------------------" << std::endl
         << "Movies in collection: " << count << std::endl
         << "-----------------------------------------------" << std::endl;
}