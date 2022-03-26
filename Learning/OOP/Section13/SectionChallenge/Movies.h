#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <vector>
#include "Movie.h"

class Movies{
private:
    std::vector <Movie> collection;
    static int count;
public:
    // I don't need a user defined constructor here.
    
    // add movie to collection or increment the watched of already watched movie
    void add_movie();
    
    // display all movies
    void display_movies()const;
    
    // display movies count
    void static display_count();
};

#endif