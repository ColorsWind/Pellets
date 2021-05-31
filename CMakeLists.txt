cmake_minimum_required(VERSION 3.17)
project(Pellets)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)
add_executable(${PROJECT_NAME} main.cpp Location.h Location.cpp Vector.h Vector.cpp Pellet/Pellet.h Board/Board.cpp Board/Board.h Grid/Grid.h
        Grid/AbstractGrid.cpp Grid/HPGrid.cpp
        Pellet/SolidPellet.cpp Grid/AirGrid.cpp Grid/GridItem.cpp Grid/GridItem.h Pellet/PelletItem.cpp Pellet/PelletItem.h
        Board/GameBoard.cpp Board/GameBoard.h
        Constants.h
        Pellet/AbstractPellet.cpp
        Pellet/ExplosivePellet.cpp
        Pellet/RandomPellet.cpp
        Grid/AbsorbGrid.cpp
        Grid/RewardGrid.cpp
        Grid/RewardGridItem.cpp Grid/RewardGridItem.h
        Backend/Collision.cpp Backend/Collision.h
        Widget/MainWindow.cpp Widget/MainWindow.h Widget/MainWindow.ui Widget/GameWindow.cpp Widget/GameWindow.h Widget/GameWindow.ui Widget/GameBoardView.cpp Widget/GameBoardView.h Grid/ExplosiveGrid.cpp Grid/RandomGrid.cpp)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
