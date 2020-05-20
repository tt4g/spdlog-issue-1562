#ifndef SPDLOG_ISSUE_1562_EXPORT_HPP
#define SPDLOG_ISSUE_1562_EXPORT_HPP

#ifdef _WIN32
#ifdef SPDLOG_ISSUE_1562_EXPORT
#define SPDLOG_ISSUE_1562_API __declspec(dllexport)
#else
#define SPDLOG_ISSUE_1562_API __declspec(dllimport)
#endif // SPDLOG_ISSUE_1562_EXPORT
#else // _WIN32
#define SPDLOG_ISSUE_1562_API
#endif // _WIN32

#endif // SPDLOG_ISSUE_1562_EXPORT_HPP
