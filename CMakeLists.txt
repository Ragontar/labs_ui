cmake_minimum_required(VERSION 3.5)

project(labs_ui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(ROOT REQUIRED)
#include(${ROOT_USE_FILE})
#nclude_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

file(GLOB SRC
    "*.h"
    "*.cpp"
)

file(GLOB LAB1
    "lab1_src/*.h"
    "lab1_src/*.cpp"
    "lab2_src/*.h"
    "lab2_src/*.cpp"
)

if(ANDROID)
  add_library(labs_ui SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${SRC}
    ${LAB1}
  )
else()
  add_executable(labs_ui
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${SRC}
    ${LAB1}
  )
endif()



target_link_libraries(labs_ui PUBLIC ROOT::Physics ROOT::Core ROOT::Hist ROOT::MathCore ROOT::Matrix ROOT::TreePlayer ROOT::Tree ROOT::Graf PRIVATE Qt5::Widgets)
#${ROOT_LIBRARIES}
#target_link_libraries(labs_ui PRIVATE Qt5::Widgets ${ROOT_LIBRARIES})
