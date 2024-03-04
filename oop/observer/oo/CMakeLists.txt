set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/observer/oo)
set(LIB_HEADER_LIST
    ${SOURCE_DIR}/address_observer.hpp
    ${SOURCE_DIR}/name_observer.hpp
    ${SOURCE_DIR}/observer.hpp
    ${SOURCE_DIR}/person.hpp
    )

set(LIB_SOURCE_LIST 
    ${SOURCE_DIR}/address_observer.cpp
    ${SOURCE_DIR}/name_observer.cpp
    ${SOURCE_DIR}/person.cpp
    )

set(OBSERVER_OO_LIB observer_oo_library)
add_library(${OBSERVER_OO_LIB} ${LIB_SOURCE_LIST}) # ${LIB_HEADER_LIST}
target_compile_features(${OBSERVER_OO_LIB} PUBLIC cxx_std_20)

add_executable(observer_oo main.cpp)
target_link_libraries(observer_oo ${OBSERVER_OO_LIB})
