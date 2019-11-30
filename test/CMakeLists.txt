find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test_lib ${PROJECT_SOURCE_DIR}/test/test_lib.cpp)

set_target_properties(test_lib PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(test_lib
        ${Boost_LIBRARIES}
        calculate_lib
        )

enable_testing()

add_test(calculate_fun_test test_lib)