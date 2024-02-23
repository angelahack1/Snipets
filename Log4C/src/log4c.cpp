#include <log4c.h>
#include <iostream>


int main() {
    // Initialize log4c
    if (log4c_init()) {
        std::cerr << "log4c_init() failed" << std::endl;
        return 1;
    }
 
    if (log4c_load("log4c.xml") == -1) {
       std::cerr << "log4c_load() failed" << std::endl;
        return 1;
    }

    // Get a pointer to a category
    log4c_category_t* mycat = log4c_category_get("mycat");

    // Log some messages
    log4c_category_log(mycat, LOG4C_PRIORITY_ERROR, "This is an error message");
    log4c_category_log(mycat, LOG4C_PRIORITY_WARN, "This is a warning message");
    log4c_category_log(mycat, LOG4C_PRIORITY_INFO, "This is an info message");

    // Cleanup log4c
    log4c_fini();

    return 0;
}
