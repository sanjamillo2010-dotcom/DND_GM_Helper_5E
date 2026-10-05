cmake_minimum_required(VERSION 3.5)

project(DND_GM_Helper_5E VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Tell Qt/CMake where the .ui files are located
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES
    DND_GM_Helper_5E_fr_FR.ts
)

set(PROJECT_SOURCES
    main.cpp

    src/campaign.cpp
    include/campaign.h

    src/missions.cpp
    include/missions.h

    include/npccreatordialog.h
    src/npccreatordialog.cpp

    src/campaigndashbord.cpp
    include/campaigndashbord.h
    ui/campaigndashbord.ui

    src/dashbord.cpp
    include/dashbord.h
    ui/dashbord.ui

    src/missiondashbord.cpp
    include/missiondashbord.h
    ui/missiondashbord.ui

    src/npc.cpp
    include/npc.h

    src/utils.cpp
    include/utils.h

    src/npcwindow.cpp
    include/npcwindow.h

    include/missionworkspaceview.h
    src/missionworkspaceview.cpp

    ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)

    qt_add_executable(DND_GM_Helper_5E
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

    qt_create_translation(
        QM_FILES
        ${CMAKE_SOURCE_DIR}
        ${TS_FILES}
    )

else()

    if(ANDROID)

        add_library(DND_GM_Helper_5E SHARED
            ${PROJECT_SOURCES}
        )

    else()

        add_executable(DND_GM_Helper_5E
            ${PROJECT_SOURCES}
        )

    endif()

    qt5_create_translation(
        QM_FILES
        ${CMAKE_SOURCE_DIR}
        ${TS_FILES}
    )

endif()

target_link_libraries(DND_GM_Helper_5E
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(DND_GM_Helper_5E
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(${QT_VERSION} VERSION_LESS 6.1.0)

    set(BUNDLE_ID_OPTION
        MACOSX_BUNDLE_GUI_IDENTIFIER
        com.example.DND_GM_Helper_5E
    )

endif()

set_target_properties(DND_GM_Helper_5E PROPERTIES

    ${BUNDLE_ID_OPTION}

    MACOSX_BUNDLE_BUNDLE_VERSION
        ${PROJECT_VERSION}

    MACOSX_BUNDLE_SHORT_VERSION_STRING
        ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}

    MACOSX_BUNDLE
        TRUE

    WIN32_EXECUTABLE
        TRUE

)

include(GNUInstallDirs)

install(
    TARGETS DND_GM_Helper_5E

    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)

    qt_finalize_executable(DND_GM_Helper_5E)

endif()
