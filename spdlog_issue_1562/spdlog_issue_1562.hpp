#ifndef SPDLOG_ISSUE_1562_HPP
#define SPDLOG_ISSUE_1562_HPP

#include "spdlog_issue_1562_export.hpp"

#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

#include <memory>
#include <vector>

namespace spdlog_issue_1562
{

    static std::shared_ptr<spdlog::logger> logger;

    std::shared_ptr<spdlog::logger> SPDLOG_ISSUE_1562_API setup_logger(
            std::vector<spdlog::sink_ptr> sinks,
            std::string logger_name
    );

} // namespace spdlog_issue_1562

#endif // SPDLOG_ISSUE_1562_HPP
