cmake_minimum_required(VERSION 3.6)
project(core)

include(ui/CMakeLists.txt)

include(package/CMakeLists.txt)

set(SOURCE_FILES
        Project.cpp
        ${SOURCE_FILES_PACKAGE}
        Map.cpp
        ${SOURCE_FILES_BASE}
        Exception.cpp
        FileInput.cpp
        core.cpp
        )

add_library(core ${SOURCE_FILES})

target_link_libraries(core Qt5::Widgets)
