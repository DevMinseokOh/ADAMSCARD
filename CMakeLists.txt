cmake_minimum_required(VERSION 3.16)

project(ADAMSCARD VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 찾기 (공통)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Quick QuickWidgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Quick QuickWidgets LinguistTools)

# 번역 파일
set(TS_FILES ADAMSCARD_ko_KR.ts)

# Qt 리소스
qt_add_resources(RESOURCE_FILES Resources/resources.qrc)

# 프로젝트 소스
set(PROJECT_SOURCES
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui

    UserControls/TitleBar.h
    UserControls/TitleBar.cpp


    ${TS_FILES}
    ${RESOURCE_FILES}
)

# Qt 6 이상
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ADAMSCARD
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

    )

    target_link_libraries(ADAMSCARD PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::QuickWidgets
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

    qt_finalize_executable(ADAMSCARD)

else() # Qt 5

    if(ANDROID)
        add_library(ADAMSCARD SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ADAMSCARD
            ${PROJECT_SOURCES}
        )
    endif()

    target_link_libraries(ADAMSCARD PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::QuickWidgets
    )

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

endif()

# macOS / iOS 번들 설정
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ADAMSCARD)
endif()

set_target_properties(ADAMSCARD PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 설치 규칙
include(GNUInstallDirs)
install(TARGETS ADAMSCARD
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
