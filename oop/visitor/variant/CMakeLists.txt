set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/visitor/variant)
set(LIB_HEADER_LIST
    ${SOURCE_DIR}/circle.hpp
    ${SOURCE_DIR}/draw.hpp
    ${SOURCE_DIR}/shape.hpp
    ${SOURCE_DIR}/square.hpp
    ${SOURCE_DIR}/translate.hpp
    )
set(LIB_SOURCE_LIST
    ${SOURCE_DIR}/circle.cpp
    ${SOURCE_DIR}/square.cpp
    )

set(VISITOR_VARIANT_LIB visitor_variantenum_library)
add_library(${VISITOR_VARIANT_LIB} ${LIB_SOURCE_LIST}) # ${LIB_HEADER_LIST}
target_compile_features(${VISITOR_VARIANT_LIB} PUBLIC cxx_std_20)

add_executable(variant main.cpp)
target_link_libraries(variant ${VISITOR_VARIANT_LIB})
