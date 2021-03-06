cmake_minimum_required(VERSION 3.0.0)
project(spdlog_issue_1562 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Avoid MSVC warning from spdlog/fmt/bundled/core.h(327): warning C4566:
add_compile_options(
  $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>)

set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "")
set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "")
set(SPDLOG_BUILD_EXAMPLE_HO OFF CACHE BOOL "")
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "")
set(SPDLOG_BUILD_TESTS_HO OFF CACHE BOOL "")
set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "")
set(SPDLOG_SANITIZE_ADDRESS OFF CACHE BOOL "")
set(SPDLOG_INSTALL OFF CACHE BOOL "")
set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "")
set(SPDLOG_FMT_EXTERNAL_HO OFF CACHE BOOL "")
set(SPDLOG_NO_EXCEPTIONS OFF CACHE BOOL "")
add_subdirectory(thirdparty/spdlog)

add_library(spdlog_issue_1562_shared SHARED
  spdlog_issue_1562/spdlog_issue_1562.cpp)
target_compile_definitions(spdlog_issue_1562_shared
  PRIVATE
    SPDLOG_ISSUE_1562_EXPORT)
# Link static spdlog.
target_link_libraries(spdlog_issue_1562_shared
  PUBLIC
    spdlog::spdlog)

add_executable(spdlog_issue_1562 main.cpp)
target_compile_definitions(
  spdlog_issue_1562
    PRIVATE
      NOMINMAX)
target_link_libraries(spdlog_issue_1562
  PRIVATE
    spdlog_issue_1562_shared)
