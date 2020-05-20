#include "spdlog_issue_1562.hpp"

#include "spdlog/async.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <iterator>
#include <string>

namespace spdlog_issue_1562
{

std::shared_ptr<spdlog::logger> setup_logger(
        std::vector<spdlog::sink_ptr> sinks,
        std::string logger_name)
{
    std::shared_ptr<spdlog::logger> logger = spdlog::get(logger_name);

    if (!logger) {
        if (sinks.size() > 0){
            logger = std::make_shared<spdlog::logger>(
                    logger_name,
                    std::begin(sinks),
                    std::end(sinks));
            spdlog::register_logger(logger);
        } else {
            logger = spdlog::stdout_color_mt(logger_name);
        }
    }

    spdlog_issue_1562::logger = logger;
    return logger;
}

} // namespace spdlog_issue_1562
