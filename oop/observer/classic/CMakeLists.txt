set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/observer/classic)
set(LIB_HEADER_LIST
    ${SOURCE_DIR}/observer.hpp
    ${SOURCE_DIR}/person_subject.hpp
    ${SOURCE_DIR}/person_observer.hpp
    ${SOURCE_DIR}/subject.hpp
    )
set(LIB_SOURCE_LIST   
    ${SOURCE_DIR}/person_subject.cpp
    ${SOURCE_DIR}/person_observer.cpp
    ${SOURCE_DIR}/subject.cpp
    )

set(OBSERVER_CLASIC_LIB observer_clasic_library)
add_library(${OBSERVER_CLASIC_LIB} ${LIB_SOURCE_LIST}) # ${LIB_HEADER_LIST}
target_compile_features(${OBSERVER_CLASIC_LIB} PUBLIC cxx_std_20)

add_executable(observer_classic main.cpp)
target_link_libraries(observer_classic ${OBSERVER_CLASIC_LIB})
