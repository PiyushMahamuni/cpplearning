#include "Movie.h"
#include <iostream>

//no args constructor
Movie::Movie() : ptr{new Details}
{
    std::cout << "----------------------------------" << std:: endl
              << "Creating new Movie Object" << std::endl
              << "Enter Movie Name: ";
    getchar();
    getline(std::cin, (ptr->name));
    std::cout << "Enter Movie Rating: ";
    std::cin >> (ptr->rating);
    std::cout << "Enter watched: ";
    std::cin >> (ptr->watched);
    std::cout << "Object created successfully!" << std::endl
              <<"-----------------------------------" << std::endl;
}

//Move Constructor
Movie::Movie(Movie &&source) : ptr{source.ptr}
{
    std::cout << "Moving Movie: " << (ptr->name) << std::endl;
    source.ptr = nullptr;
}

//Display Movie Info
void Movie::display() const {
    std::cout << "--------------------------------------" << std::endl
              << "Movie Name: " << (ptr->name) << std::endl
              << "Movie Rating: " << (ptr->rating) << std::endl
              << "watched: " << (ptr->watched) << std::endl
              << "--------------------------------------" << std::endl;
}

void Movie::increment(){
    (ptr->watched)++;
}

Movie::~Movie(){
    delete ptr;
}