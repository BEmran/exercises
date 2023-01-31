# ##############################################################################
# Create header file list
# ##############################################################################
set(LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/design_pattern)
set(LIB_HEADER_LIST
        ${LIB_INCLUDE_DIR}/log.hpp)

# ##############################################################################
# Create source file list
# ##############################################################################
set(LIB_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(LIB_SOURCE_LIST
        ${LIB_SOURCE_DIR}/log.cpp)

# ##############################################################################
# Build library
# ##############################################################################
# Declare a C++ library Make an automatic library - will be static or dynamic
# based on user setting
add_library(${SHARED_LIBS} ${LIB_SOURCE_LIST}) # ${LIB_HEADER_LIST}

# Global includes
target_include_directories(
        ${SHARED_LIBS} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${ABSOLUTE_INSTALL_INCLUDEDIR}>)

# Link required library
target_link_libraries(${SHARED_LIBS} PRIVATE)

# All users of this library will need at least C++17
target_compile_features(${SHARED_LIBS} PUBLIC cxx_std_17)

target_compile_options(${SHARED_LIBS} PRIVATE ${PROJECT_WARNINGS})

# IDEs should put the headers in a nice place
source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${LIB_HEADER_LIST})

# ##############################################################################
# Install
# ##############################################################################

install(
        TARGETS ${SHARED_LIBS}
        # IMPORTANT: Add the core_library to the "export-set"
        EXPORT ${TARGETS_EXPORT_NAME}
        LIBRARY DESTINATION ${ABSOLUTE_INSTALL_LIBDIR} COMPONENT shlib
        ARCHIVE DESTINATION ${ABSOLUTE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${ABSOLUTE_INSTALL_BINDIR} COMPONENT bin
        INCLUDES
        DESTINATION ${ABSOLUTE_INSTALL_INCLUDEDIR}
        # PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/core COMPONENT dev
)

install(
        DIRECTORY ${LIB_INCLUDE_DIR}/
        DESTINATION ${ABSOLUTE_INSTALL_INCLUDEDIR}
        COMPONENT PATTERN
        "${LIB_HEADER_LIST}")