#include "spdlog_issue_1562/spdlog_issue_1562.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    auto logger = spdlog_issue_1562::setup_logger({}, "main");

    if (logger) {
        logger->info("Hello, World!");
    } else {
        std::cerr << "invalid logger\n";
    }

    if (spdlog_issue_1562::logger) {
        spdlog_issue_1562::logger->info("global: Hello, World!");
    } else {
        std::cerr << "invalid spdlog_issue_1562::logger\n";
    }

    return 0;
}
