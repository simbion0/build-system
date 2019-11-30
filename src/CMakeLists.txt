add_executable(calculate_app ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(calculate_app
        calculate_lib
        current_ver
        )