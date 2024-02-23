
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/propertyconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::helpers;

int main() {
    // Set up a simple configuration that logs on the console.
    BasicConfigurator::configure();

    LoggerPtr logger(Logger::getLogger("MyApp"));

    // Load configuration file
    PropertyConfigurator::configure("./log4cxx.properties");

    LOG4CXX_DEBUG(logger, "This is a debug message");
    LOG4CXX_INFO(logger, "This is an info message");
    LOG4CXX_WARN(logger, "This is a warning message");
    LOG4CXX_ERROR(logger, "This is an error message");

    return 0;
}