cmake_minimum_required(VERSION 3.10)

project(ScrumPokerTool NONE)

set(SOURCES main.cpp)
set(HEADERS git2pp.h)
set(RESOURCES resources/app.rc resources/app.ico)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libgit2/include)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

target_link_libraries(${PROJECT_NAME} zlibstatic git2)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:git2> $<TARGET_FILE_DIR:${PROJECT_NAME}>)