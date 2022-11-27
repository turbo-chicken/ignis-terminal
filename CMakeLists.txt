cmake_minimum_required(VERSION 3.23)
project(ignis_terminal)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

#add_subdirectory(external/wxWidgets/3.2.1)
add_subdirectory(external/putty/0.78)


#find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
#include(${wxWidgets_USE_FILE})

#find_package(wxWidgets REQUIRED)
#target_include_directories(ignis_terminal PUBLIC ${wxWidgets_INCLUDE_DIRS})
#target_compile_definitions(ignis_terminal PUBLIC ${wxWidgets_DEFINITIONS})
#target_compile_options(ignis_terminal PRIVATE ${wxWidgets_CXX_FLAGS})
#target_link_libraries(ignis_terminal ${wxWidgets_LIBRARIES})

add_executable(ignis_terminal WIN32
        src/main.cpp)

#target_link_libraries(ignis_terminal ${wxWidgets_LIBRARIES})
#target_link_libraries(ignis_terminal wx::net wx::core wx::base)