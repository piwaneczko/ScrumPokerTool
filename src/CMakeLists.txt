cmake_minimum_required(VERSION 3.10)

project(ScrumPoker)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)

option(BUILD_SHARED_LIBS   "Disable building shared libs"   OFF )
option(USE_BUNDLED_ZLIB   "Use static zlib"   ON )
option(BUILD_CLAR    "Don't build clar"   OFF )
add_subdirectory(zlibstatic)
add_subdirectory(libgit2)

################# QT5 #################

find_package(Qt5 COMPONENTS Core Quick Qml QuickWidgets Xml XmlPatterns QuickControls2)
# For the autogenerated files (moc) in the build dir
set(CMAKE_INCLUDE_CURRENT_DIR on)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_AUTORCC off)

#######################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_INSTALL_FULL_BINDIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_INSTALL_FULL_BINDIR}")
add_subdirectory(app)