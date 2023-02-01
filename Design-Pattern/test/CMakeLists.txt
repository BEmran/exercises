# ##############################################################################
# System Dependencies
# ##############################################################################
# find googletest library
find_package(GTest REQUIRED)
if (NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test library [gtest] not found")
endif ()

include(GoogleTest)
set(GOOGLE_LIBRARIES gtest gtest_main)

# ##############################################################################
include(${CMAKE_SOURCE_DIR}/../cmake/AddTestWithLibraries.cmake)

# ##############################################################################
set(UTEST_LOG ${CMAKE_CURRENT_SOURCE_DIR}/utest_log.cpp)
package_add_test_with_libraries(utest_logger "${UTEST_LOG}" "${SHARED_LIBS}" "")
