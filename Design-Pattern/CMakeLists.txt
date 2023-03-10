# Set minimum version of CMake.
cmake_minimum_required(VERSION 3.24)

# Set Project name, variable and settings
project(Design-Pattern)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # generate compile_commands.json for clang

# Prevent building in the source directory
include(${CMAKE_SOURCE_DIR}/../cmake/MacroOutOfSourceBuild.cmake)

# ##############################################################################
# System Dependencies
# ##############################################################################

# ##############################################################################
# Project Options
# ##############################################################################
option(WARNINGS_AS_ERRORS "Set warning as errors" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_EXECTUABLES "Build executables and examples" ON)
option(BUILD_TESTING "Build tests" OFF)
option(ENABLE_CPPCHECK "Enable static analysis with Cppcheck." OFF)
option(ENABLE_CLANG_TIDY "Enable static analysis with Clang-Tidy." OFF)

# ##############################################################################
# Build Type
# ##############################################################################
# set default configuration
set(DEFAULT_BUILD_TYPE "Debug")

# if no build type is choosed set to default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ${DEFAULT_BUILD_TYPE})
    message(
            STATUS
            "CMAKE_BUILD_TYPE is not set, configured to the default value ${DEFAULT_BUILD_TYPE}"
    )
else ()
    message(STATUS "Detect CMAKE_BUILD_TYPE of ${CMAKE_BUILD_TYPE}")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL Release)
    message(STATUS "Configure option for CMAKE_BUILD_TYPE of type Release")
    set(ENABLE_DOXYGEN OFF)

elseif (CMAKE_BUILD_TYPE STREQUAL Debug)
    message(STATUS "Configure option for CMAKE_BUILD_TYPE of type Debug")
    set(WARNINGS_AS_ERRORS ON)
    set(BUILD_TESTING ON)
    set(ENABLE_DOXYGEN OFF)
    set(ENABLE_CPPCHECK ON)
    set(ENABLE_CLANG_TIDY ON)
else ()
    message(
            FATAL_ERROR "Unrecognized CMAKE_BUILD_TYPE of type ${CMAKE_BUILD_TYPE}")
endif ()

# ##############################################################################
# Project Configuration
# ##############################################################################
# Only do these if this is the main project, and not if it is included through
# add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app Note this needs to be done
    # in the main CMakeLists since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest) # note: this adds a BUILD_TESTING which defaults to ON
endif ()

include(${CMAKE_SOURCE_DIR}/../cmake/StaticAnalyzers.cmake)

if (CMAKE_BUILD_TYPE STREQUAL Release)
    set(PROJECT_WARNINGS "")
else ()
    include(${CMAKE_SOURCE_DIR}/../cmake/CompilerWarnings.cmake)
endif ()

add_compile_options(${PROJECT_WARNINGS})

# ##############################################################################
# Setup project directories
# ##############################################################################
# Introduce variables: CMAKE_INSTALL_LIBDIR, CMAKE_INSTALL_BINDIR,
# CMAKE_INSTALL_INCLUDEDIR
include(GNUInstallDirs)

# adjust install prefix directory if not specified
string(COMPARE EQUAL "${CMAKE_INSTALL_PREFIX}" "/usr/local" install_prefix_not_specified)
if (install_prefix_not_specified)
    get_filename_component(BINARY_PARENT_DIR ${CMAKE_BINARY_DIR} PATH)
    set(CMAKE_INSTALL_PREFIX "${BINARY_PARENT_DIR}/install")
endif ()

# Make relative paths absolute (needed later on)
foreach (p LIB BIN INCLUDE)
    set(var CMAKE_INSTALL_${p}DIR)
    if (NOT IS_ABSOLUTE "${${var}}")
        set(ABSOLUTE_INSTALL_${p}DIR "${CMAKE_INSTALL_PREFIX}/${${var}}")
    endif ()
endforeach ()

# ##############################################################################
# Library
# ##############################################################################
set(SHARED_LIBS library)
if (BUILD_SHARED_LIBS)
    add_subdirectory(${CMAKE_SOURCE_DIR}/src)
endif ()
message(STATUS "${SHARED_LIBS} is set ${BUILD_SHARED_LIBS}")

# ##############################################################################
# testing setup
# ##############################################################################
if (BUILD_TESTING)
    message(
            STATUS
            "Build unit tests for the project. Tests should always be found in the test folder\n"
    )
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif ()

# ##############################################################################
# Executables
# ##############################################################################
if (BUILD_EXECTUABLES)
    add_subdirectory(${CMAKE_SOURCE_DIR}/app)
endif ()
message(STATUS "Building executables")
