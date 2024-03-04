set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/visitor/enum)
set(LIB_HEADER_LIST
    ${SOURCE_DIR}/circle.hpp
    ${SOURCE_DIR}/shape.hpp
    ${SOURCE_DIR}/square.hpp
    )
set(LIB_SOURCE_LIST
    ${SOURCE_DIR}/circle.cpp
    ${SOURCE_DIR}/shape.cpp
    ${SOURCE_DIR}/square.cpp
    )

set(VISITOR_ENUM_LIB visitor_enum_library)
add_library(${VISITOR_ENUM_LIB} ${LIB_SOURCE_LIST}) # ${LIB_HEADER_LIST}
target_compile_features(${VISITOR_ENUM_LIB} PUBLIC cxx_std_20)

add_executable(enum main.cpp)
target_link_libraries(enum ${VISITOR_ENUM_LIB})
