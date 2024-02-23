#include <log4c.h>
#include <iostream>


int main() {
 
    if (log4c_load("./log4c.xml") == -1) {
       std::cerr << "log4c_load() failed" << std::endl;
        return 1;
    } else {
        std::cout<<"log4c_load() ...Done."<<std::endl;
    }

        // Initialize log4c
    if (log4c_init()) {
        std::cerr << "log4c_init() failed" << std::endl;
        return 1;
    } else {
        std::cout<<"log4c_init() ...Done."<<std::endl;
    }

    std::cout<<"Initialization has been done!"<<std::endl;
    // Get a pointer to a category
    log4c_category_t* mycat = log4c_category_get("mycat");

    std::cout<<"About to log some messages..."<<std::endl;
    // Log some messages
    log4c_category_log(mycat, LOG4C_PRIORITY_ERROR, "This is an error message");
    log4c_category_log(mycat, LOG4C_PRIORITY_WARN, "This is a warning message");
    log4c_category_log(mycat, LOG4C_PRIORITY_INFO, "This is an info message");

    std::cout<<"About to clean resources..."<<std::endl;
    // Cleanup log4c
    log4c_fini();

    std::cout<<"About to get out..."<<std::endl;
    return 0;
}
