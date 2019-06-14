cmake_minimum_required(VERSION 3.10)
project(ScrumPokerTool)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}) 


option(BUILD_SHARED_LIBS   "Disable building shared libs"   OFF )
option(USE_BUNDLED_ZLIB   "Use static zlib"   ON )
option(BUILD_CLAR    "Don't build clar"   OFF )
add_subdirectory(src)