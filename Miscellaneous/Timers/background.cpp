// A timer that runs in the background, in a seperate thread than the main program

// To compile - run `g++ -pthread -o <executable name> <file path>`
// arg -pthread is imp, otherwise you'll get error - undefined reference to pthread_create

#include <iostream>
#include <chrono>
#include <future>

void timer1(){
    std::cout << "Timer1 starts [1s interval]\n";
    for(int i{}; i<10; i++){
        std::cout << (10-i) << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Done\n";
}

// Has better accuracy
void timer2(){
    std::cout << "Timer2 starts [2s interval]\n";
    auto start = std::chrono::high_resolution_clock::now();
    for(int i{}; i<10; i++){
        std::cout << (10-i) << '\n';
        std::this_thread::sleep_until(start + (i+1) * std::chrono::seconds(2));
    }
    std::cout << "Done\n";
}

int main(int argc, char **argv){
    void (*select_timer)();
    if(argc != 2){
        std::cout << "Usage: " << argv[0] << "timer1/timer2\n";
        return 1;
    }
    if(argv[1] == std::string{"timer1"}){
        select_timer = timer1;
    }
    else if(argv[1] == std::string{"timer2"}){
        select_timer = timer2;
    }
    else{
        std::cerr << "Invalid argument!\n";
        return 1;
    }
    auto future = std::async(select_timer);
    std::cout << "Doing something else...\n";
    return 0;
}
