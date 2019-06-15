cmake_minimum_required(VERSION 3.10)

project(ScrumPokerTool)

set(SOURCES 
    src/main.cpp)
set(HEADERS 
    include/git2pp.h)
set(RESOURCES 
    resources/app.rc 
    resources/app.ico)
    
add_executable(${PROJECT_NAME} 
               ${SOURCES} 
               ${HEADERS} 
               ${RESOURCES})

target_link_libraries(${PROJECT_NAME} 
                      zlibstatic 
                      git2
                      Qt5::QuickControls2
                      Qt5::Core
                      Qt5::Quick
                      Qt5::Qml
                      Qt5::XmlPatterns
                      Qt5::Xml)

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                ${CMAKE_CURRENT_SOURCE_DIR}/src
                           PRIVATE 
                                ${CMAKE_CURRENT_SOURCE_DIR}/../libgit2/include
)
                      
qt5_use_modules(${PROJECT_NAME} Quick Core Qml QuickControls2)
                    
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_FULL_BINDIR}")

############ Installation #############

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY resources/qml DESTINATION ${CMAKE_INSTALL_BINDIR})

########### Qt Deployment #############

get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

install(CODE "execute_process(COMMAND ${WINDEPLOYQT_EXECUTABLE} --verbose 0 -qml --qmldir \"${CMAKE_INSTALL_FULL_BINDIR}/qml\" --no-compiler-runtime --dir \"${CMAKE_INSTALL_FULL_BINDIR}\" \"${CMAKE_INSTALL_FULL_BINDIR}/${PROJECT_NAME}.exe\")")

#######################################