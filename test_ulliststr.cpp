#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main()
{
    ULListStr list;
    list.push_back("a");
    std::cout << "Should be a: " << list.get(0) << std::endl;
	list.pop_front();
    std::cout << list.size() << std::endl;

}
