#include <iostream>
#include "DoubleVector.h"

int main()
{
    // Construct a vector
    learncpp::DoubleVector dv{};
    // Reserve memory for it
    dv.reserve(3);
    // Add elements (within the already reserved memory)
    dv.push_back(1.1);
    dv.push_back(2.2);
    dv.push_back(3.3);

    std::cout << "DoubleVector content: " << dv;
    std::cout << "Size: " << dv.size() << " and capacity: " << dv.capacity();
    std::cout << std::endl;

    // Initializer list ctor
    learncpp::DoubleVector dv1{0.1, 0.2, 0.3, 0.4};
    std::cout << "Initializer list DoubleVector content: " << dv1;
    std::cout << "Size: " << dv1.size() << " and capacity: " << dv1.capacity();
    std::cout << std::endl;

    // Copy constructor
    learncpp::DoubleVector dv2{dv};
    // Change some stuff
    dv2[2] = 10.99;
    dv2[0] = 0.01;
    // Add another element
    dv2.push_back(12.34);
    std::cout << "Copy constructed DoubleVector content: " << dv2;
    std::cout << "Size: " << dv2.size() << " and capacity: " << dv2.capacity();
    std::cout << std::endl;
    
    // Copy assignment operator
    dv2 = dv;
    std::cout << "Copy assigned DoubleVector content: " << dv2;
    std::cout << "Size: " << dv2.size() << " and capacity: " << dv2.capacity();
    std::cout << std::endl;

    // Move ctor
    learncpp::DoubleVector dv3{std::move(dv2)};
    std::cout << "Move constructed DoubleVector content: " << dv3;
    std::cout << "Size: " << dv3.size() << " and capacity: " << dv3.capacity();
    std::cout << std::endl;

    learncpp::DoubleVector dv4{};
    // Move assignment operator
    dv4 = std::move(dv3);
    std::cout << "Move assigned DoubleVector content: " << dv4;
    std::cout << "Size: " << dv4.size() << " and capacity: " << dv4.capacity();
    std::cout << std::endl;

}