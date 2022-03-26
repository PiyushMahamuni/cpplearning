#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Test{
private:
    int data;
public:
    Test() : data{0} { cout << "\tTest constructor (" << data << ')' << endl; }
    Test(int data) : data { data } { cout << "\tTest constructor (" << data << ')' << endl; }
    int get_data() const { return data; }
    ~Test() { cout << "\tTest destructor (" << data << ')' << endl; }
};

//Function Prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<shared_ptr<Test>>& vec, int num);
void display(const vector<shared_ptr<Test>>& vec);

int main(){
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter? ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
    
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(){
    return make_unique<std::vector<std::shared_ptr<Test>>>();
    // do not forget the parathesis at the end -----------^^
    // those parathensis are supposed to carry arguments for , in this case the vector
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num){
    int temp;
    for(int i{}; i<num; i++){
        std::cout << "Enter datapoint [" << i << "]: ";
        std::cin >> temp;
        vec.push_back(std::make_shared<Test>(temp));
    }
}

void display(const std::vector<std::shared_ptr<Test>>& vec){
    std::cout << "displaying data in vector of shared ptr to Test======\n";
    for(const auto& item: vec){
        std::cout << item->get_data() << endl;
    }
}