project(Qplay)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(include/ ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Qplay_H_QT
include/QPlayVentana.hpp
include/Player.hpp
)

set(QPlay_H

)

set(Qplay_SRCS 
src/main.cpp
src/ui/QPlayVentana.cpp
src/modelo/Player.cpp)

# qt4_automoc(${Qplay_SRCS} ${Qplay_H_QT})

QT4_WRAP_CPP(Qplay_HEADERS_MOC ${Qplay_H_QT}) 

add_executable(qplay ${Qplay_SRCS} ${Qplay_HEADERS_MOC})

target_link_libraries(qplay ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_PHONON_LIBRARY})

install(TARGETS qplay RUNTIME DESTINATION bin)