#include <iostream>
#include <iomanip>

void displayVersion(float version);

void displayVersion(float version){
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Current version is " << version << std::endl;
}
