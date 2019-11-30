add_library(current_ver ${PROJECT_SOURCE_DIR}/lib/version/version.cpp)

configure_file(${PROJECT_SOURCE_DIR}/lib/version/version.h.in ${PROJECT_SOURCE_DIR}/lib/version/version.h)