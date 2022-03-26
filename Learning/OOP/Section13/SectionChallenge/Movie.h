#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

struct Details{
public:
    std::string name;
    std::string rating;
    int watched;
};

class Movie{
private:
    Details *ptr;
    
public:
    //no args constructor
    Movie();
    
    //Move Constructor
    Movie(Movie &&source);
    
    //Destructor
    ~Movie();
    
    //display Movie Info
    void display() const;
    
    //increment watched
    void increment();
    
    friend class Movies;
};

#endif