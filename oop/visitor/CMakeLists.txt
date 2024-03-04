# # ##############################################################################
# # Create header file list
# # ##############################################################################
# set(LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/visitor/include)
# set(LIB_HEADER_LIST ${LIB_INCLUDE_DIR}/utils.hpp)

# # ##############################################################################
# # Create source file list
# # ##############################################################################
# set(LIB_SOURCE_DIR ${PROJECT_SOURCE_DIR}/visitor/src)
# set(LIB_SOURCE_LIST ${LIB_SOURCE_DIR}/utils.cpp)

# # ##############################################################################
# # Build library
# # ##############################################################################
# # Declare a C++ library Make an automatic library - will be static or dynamic
# # based on user setting
# set(VISITOR_LIB visitor_library)
# add_library(${VISITOR_LIB} ${LIB_SOURCE_LIST}) # ${LIB_HEADER_LIST}

# # Global includes
# target_include_directories(${VISITOR_LIB} PUBLIC
#     $<BUILD_INTERFACE:${LIB_INCLUDE_DIR}>
#     $<INSTALL_INTERFACE:${ABSOLUTE_INSTALL_INCLUDEDIR}>)

# # Link required library
# target_link_libraries(${VISITOR_LIB} PUBLIC)

# # All users of this library will need at least C++20
# target_compile_features(${VISITOR_LIB} PUBLIC cxx_std_20)

# # IDEs should put the headers in a nice place
# source_group(
#     TREE "${LIB_INCLUDE_DIR}"
#     PREFIX "Header Files"
#     FILES ${LIB_HEADER_LIST})

# # ##############################################################################
# # Executable
# # ##############################################################################
# add_executable(testo app/main.cpp)
# target_link_libraries(testo ${VISITOR_LIB})
# # target_link_directories(testo PUBLIC ${LIB_INCLUDE_DIR})

add_subdirectory(enum)
# add_subdirectory(oo)
add_subdirectory(variant)