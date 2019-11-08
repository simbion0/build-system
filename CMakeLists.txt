cmake_minimum_required(VERSION 3.12)

project(simple_math VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(${PROJECT_SOURCE_DIR}/lib/version/version.h.in ${PROJECT_SOURCE_DIR}/lib/version/version.h)

add_executable(calculate_app ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_library(calculate_lib ${PROJECT_SOURCE_DIR}/lib/calculate/lib.cpp)
add_library(current_ver ${PROJECT_SOURCE_DIR}/lib/version/version.cpp)

add_executable(test_lib ${PROJECT_SOURCE_DIR}/test/test_lib.cpp)

set_target_properties(calculate_app calculate_lib current_ver test_lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_lib PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(calculate_app
    calculate_lib
    current_ver
)

target_link_libraries(test_lib
    ${Boost_LIBRARIES}
    calculate_lib
)

install(TARGETS calculate_app RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT simbion0@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(calculate_fun_test test_lib)
