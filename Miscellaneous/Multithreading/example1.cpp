
// To compile - run `g++ -pthread -o <executable name> <file path>`
// arg -pthread is imp, otherwise you'll get error - undefined reference to pthread_create

#include <thread>
#include <iostream>
#include <chrono>

// Globals
std::chrono::_V2::system_clock::time_point endwait1, endwait2, endwait3;

void greet(){
    u_int32_t count{};
    while(std::chrono::high_resolution_clock::now() < endwait1){
        std::cout << '[' << count << "] Hello, nice to meet you!" << std::endl;
        count++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return;
}

void count(){
    u_int32_t count{};
    while(std::chrono::high_resolution_clock::now() < endwait2){
        std::cout << '[' << (count * 1.5) << "] Count: " << count << std::endl;
        count++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
    return;
}

void count_back(){
    int32_t count{};
    while(std::chrono::high_resolution_clock::now() < endwait3){
        std::cout << '[' << (-count * 2) << "] Count Back: " << count << std::endl;
        count--;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main(int argc, char **argv){
    if(argc != 4){
        std::cout << "Usage: " << argv[0] << " time1 time2 time3" << '\n';
        return 1;
    }
    std::cout << "Thread th1, th2, th3 now run independetly!\n";
    endwait1 = std::chrono::high_resolution_clock::now() + std::chrono::seconds(atoll(argv[1]));
    std::thread th1(greet);
    endwait2 = std::chrono::high_resolution_clock::now() + std::chrono::seconds(atoll(argv[1]));
    std::thread th2(count);
    endwait3 = std::chrono::high_resolution_clock::now() + std::chrono::seconds(atoll(argv[1]));
    std::thread th3(count_back);
    
    // wait for th1 thread to finish
    th1.join();
    std::cout << "Thread th1 just joined!\n";
    
    // wait for th2 thread to finish
    th2.join();
    std::cout << "Thread th2 just joined!\n";

    // wait for th3 thread to finish
    th3.join();
    std::cout << "Thread th3 just joined!\n";
    return 0;
}