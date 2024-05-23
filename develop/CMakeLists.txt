cmake_minimum_required(VERSION 3.5)

project(remoteControl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# Выбор компилятора
#set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_COMPILER "clang++")

# опции компиляции и линковка для Clang / LLVM
# -std=c++11 Стандарт ЯП С++
# -stdlib=libstdc++ Стандартная библиотека GNU. Для macOS libc++
# -Wall Базовый набор предупреждений компилятора
# -Wextra Расширенный набор предупреждений компилятора
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libstdc++ -Wall -Wextra -Wno-unused-value") #clang
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra") #g++
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libstdc++ -Wno-unused-value") #clang

# Подключение библиотек
#find_package(Qt6 REQUIRED COMPONENTS Core)
#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS Widgets Core REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core REQUIRED)

# LLVM
#enable_language(C)
#find_package(LLVM REQUIRED CONFIG)
#include_directories(${LLVM_INCLUDE_DIRS})
#add_definitions(${LLVM_DEFINITIONS})
# ~LLVM

# images
qt5_add_resources(IMAGE_FILES images/gui_imag.qrc)
#set(IMAGE_FILES images/gui_imag.qrc)
# ~images

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_SOURCES main.cpp)

set(FRONTEND_DIR ${PROJECT_ROOT}/frontend)
set(BACKEND_DIR ${PROJECT_ROOT}/backend)
set(DB ${PROJECT_ROOT}/DB)

set(BACKEND_SOURCE ${BACKEND_DIR}/source)
set(BACKEND_INCLUDE ${BACKEND_DIR}/include)

set (REMOTE_CONTROL_SRC
    ${FRONTEND_DIR}/dialog.cpp
    #${FRONTEND_DIR}/menuManager.cpp
    ${BACKEND_SOURCE}/mainBack.cpp
    #${FRONTEND_DIR}/additionParameters.cpp
    ${FRONTEND_DIR}/newdevise.cpp
    ${FRONTEND_DIR}/delete_dev.cpp
)
set (REMOTE_CONTROL_HDR
    ${FRONTEND_DIR}/dialog.h
    #${FRONTEND_DIR}/menuManager.h
    ${BACKEND_INCLUDE}/mainBack.h
    ${FRONTEND_DIR}/newdevise.h
    ${FRONTEND_DIR}/delete_dev.h
)
set (REMOTE_CONTROL_UI
    ${FRONTEND_DIR}/dialog.ui
    ${FRONTEND_DIR}/addNewDev.ui
    ${FRONTEND_DIR}/delete_dev.ui
    ${DB}/devices.txt
    devices.json
)

source_group(TREE ${PROJECT_ROOT} FILES
                                ${REMOTE_CONTROL_UI}
                                ${REMOTE_CONTROL_SRC}
                                ${REMOTE_CONTROL_HDR}
                                #${IMAGE_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(remoteControl
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${REMOTE_CONTROL_UI}
        ${REMOTE_CONTROL_SRC}
        ${REMOTE_CONTROL_HDR}
        ${IMAGE_FILES}
    )
# Define target properties for Android with Qt 6 as:
    set_property(TARGET remoteControl APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(remoteControl SHARED
            ${PROJECT_SOURCES}
            ${REMOTE_CONTROL_UI}
            ${REMOTE_CONTROL_SRC}
            ${REMOTE_CONTROL_HDR}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(remoteControl
            ${PROJECT_SOURCES}
            ${REMOTE_CONTROL_UI}
            ${REMOTE_CONTROL_SRC}
            ${REMOTE_CONTROL_HDR}
            ${IMAGE_FILES}
        )
    endif()
endif()

target_link_libraries(remoteControl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#target_link_libraries(remoteControl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${LLVM_LIBRARIES})
#target_link_libraries(remoteControl PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${LLVM_LIBRARIES} Core)

set_target_properties(remoteControl PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(remoteControl)
endif()
