# set to 3.20 for replit compatibility
cmake_minimum_required(VERSION 3.20)
project(lyonesse)

set(CMAKE_CXX_STANDARD 23)

link_libraries(GL)
link_libraries(glfw)

set(LIB_PATH ${CMAKE_CURRENT_LIST_DIR}/lib)
set(IMGUI_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/imgui)

set(SOURCES
        main.cpp
        ${LIB_PATH}/glad.c
        window.cpp
        input.cpp
)

set(IMGUI_SOURCES
        ${IMGUI_PATH}/imgui_demo.cpp
        ${IMGUI_PATH}/imgui.cpp
        ${IMGUI_PATH}/imgui_draw.cpp
        ${IMGUI_PATH}/imgui_impl_glfw.cpp
        ${IMGUI_PATH}/imgui_impl_opengl3.cpp
        ${IMGUI_PATH}/imgui_tables.cpp
        ${IMGUI_PATH}/imgui_widgets.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${IMGUI_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${LIB_PATH})
target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_PATH})
