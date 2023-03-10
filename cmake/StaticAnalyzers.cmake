# Currently supporting: Clang-Tidy, Cppcheck.

# ##############################################################################
# CLANG-TIDY
# ##############################################################################

if (ENABLE_CLANG_TIDY)
    find_program(
            CLANG_TIDY_EXE
            NAMES "clang-tidy"
            DOC "Path to clang-tidy executable")

    if (NOT CLANG_TIDY_EXE)
        message(FATAL_ERROR "clang-tidy requested but executable not found.")
    else ()
        message(
                STATUS
                "clang-tidy found: ${CLANG_TIDY_EXE} ${PROJECT_SOURCE_DIR}/.clang-tidy"
        )
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
        set(CMAKE_CXX_CLANG_TIDY
                ${CLANG_TIDY_EXE} --extra-arg=-Wno-unknown-warning-option
                -p=${CMAKE_BINARY_DIR} --format-style=file --config=
                --header-filter=.*)
    endif ()
endif ()

# ##############################################################################
# CPPCHECK
# ##############################################################################

if (ENABLE_CPPCHECK)
    find_program(
            CPPCHECK_EXE
            NAMES "cppcheck"
            DOC "Path to cppcheck executable")

    if (NOT CPPCHECK_EXE)
        message(FATAL_ERROR "Cppcheck requested but executable not found.")
    else ()
        message(STATUS "Cppcheck found: ${CPPCHECK_EXE}")
        set(CMAKE_CXX_CPPCHECK
                ${CPPCHECK_EXE}
                --std=c++17
                --quiet
                --suppressions-list=${CMAKE_CURRENT_SOURCE_DIR}/cppcheck-suppress.txt
                --enable=all
                --inline-suppr
                --inconclusive
                --output-file=${CMAKE_BINARY_DIR}/cppcheck-report.txt
                --template='{file}:{line},{severity},{id}:{message}'
                -I
                ${CMAKE_SOURCE_DIR}/include
                ${CMAKE_SOURCE_DIR}/src
                ${CMAKE_SOURCE_DIR}/app)
    endif ()
endif ()