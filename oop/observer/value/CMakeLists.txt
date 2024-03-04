set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/observer/value)
set(LIB_HEADER_LIST
    ${SOURCE_DIR}/observer.hpp
    ${SOURCE_DIR}/person.hpp
    )

set(LIB_SOURCE_LIST 
    ${SOURCE_DIR}/person.cpp
    )

set(OBSERVER_VALUE_LIB observer_value_library)
add_library(${OBSERVER_VALUE_LIB} ${LIB_SOURCE_LIST}) # ${LIB_HEADER_LIST}
target_compile_features(${OBSERVER_VALUE_LIB} PUBLIC cxx_std_20)

add_executable(observer_value main.cpp)
target_link_libraries(observer_value ${OBSERVER_VALUE_LIB})
