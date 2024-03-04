cmake_minimum_required(VERSION 3.16.0)

# Set the project name and language
project(oop
    VERSION 0.0.1
    DESCRIPTION ""
    HOMEPAGE_URL "%%myurl%%"
    LANGUAGES CXX C)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # generate compile_commands.json for clang

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)

# ##############################################################################
# Project Configuration
# ##############################################################################
# Only do these if this is the main project, and not if it is included through
# add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app Note this needs to be done
    # in the main CMakeLists since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest) # note: this adds a BUILD_TESTING which defaults to ON
endif()

# # ##############################################################################
# # Setup project directories
# # ##############################################################################
# # Introduce variables: CMAKE_INSTALL_LIBDIR, CMAKE_INSTALL_BINDIR,
# # CMAKE_INSTALL_INCLUDEDIR
# include(GNUInstallDirs)

# # adjust install prefix directory if not specified
# string(COMPARE EQUAL "${CMAKE_INSTALL_PREFIX}" "/usr/local" install_prefix_not_specified)

# if(install_prefix_not_specified)
# get_filename_component(BINARY_PARENT_DIR ${CMAKE_BINARY_DIR} PATH)
# set(CMAKE_INSTALL_PREFIX "${BINARY_PARENT_DIR}/install")
# endif()

# # Make relative paths absolute (needed later on)
# foreach(p LIB BIN INCLUDE)
# set(var CMAKE_INSTALL_${p}DIR)

# if(NOT IS_ABSOLUTE "${${var}}")
# set(ABSOLUTE_INSTALL_${p}DIR "${CMAKE_INSTALL_PREFIX}/${${var}}")
# endif()
# endforeach()

# ##############################################################################
# Library
# ##############################################################################
add_subdirectory(${CMAKE_SOURCE_DIR}/visitor)
add_subdirectory(${CMAKE_SOURCE_DIR}/observer)