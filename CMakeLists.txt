project(Qplay)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(include/ ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Qplay_H include/Qplay.h)

set(Qplay_SRCS src/Qplay.cpp src/main.cpp)
# qt4_automoc(${Qplay_SRCS} ${Qplay_H})

QT4_WRAP_CPP(Qplay_HEADERS_MOC ${Qplay_H}) 

add_executable(Qplay ${Qplay_SRCS} ${Qplay_HEADERS_MOC})

target_link_libraries(Qplay ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_PHONON_LIBRARY})

install(TARGETS Qplay RUNTIME DESTINATION bin)