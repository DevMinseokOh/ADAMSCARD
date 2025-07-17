cmake_minimum_required(VERSION 3.16)

project(MyDashboard VERSION 0.1 LANGUAGES CXX)

# ===================================================================
# 프로젝트 옵션 및 표준 설정
# ===================================================================
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # 현재 디렉토리를 include 경로에 추가

# ===================================================================
# 의존성 패키지 찾기
# ===================================================================
# --- Qt ---
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Quick QuickWidgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Quick QuickWidgets LinguistTools)

# --- 외부 라이브러리 (yaml-cpp) ---
# CMake가 패키지를 검색할 경로 목록에 yaml-cpp 설치 경로를 추가합니다.
list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/YAML_CPP")
find_package(yaml-cpp REQUIRED)

# ===================================================================
# 소스 파일 그룹화
# ===================================================================
# --- 기본 소스 파일 ---
set(PROJECT_MAIN_SOURCES
    main.cpp
    MainWindow.cpp
)

# --- UI 및 리소스 파일 ---
set(PROJECT_UI_FILES
    MainWindow.ui
)
qt_add_resources(PROJECT_RESOURCE_FILES Resources/resources.qrc)

# --- 번역 파일 ---
set(PROJECT_TRANSLATION_FILES
    MyDashboard_ko_KR.ts
)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_create_translation(PROJECT_QM_FILES ${CMAKE_SOURCE_DIR} ${PROJECT_TRANSLATION_FILES})
else()
    qt5_create_translation(PROJECT_QM_FILES ${CMAKE_SOURCE_DIR} ${PROJECT_TRANSLATION_FILES})
endif()


# --- MockDB 소스 파일 (GLOB_RECURSE 사용) ---
# MockDB 폴더 및 하위 폴더의 모든 .cpp 파일을 자동으로 찾습니다.
file(GLOB_RECURSE PROJECT_MOCKDB_SOURCES "MockDB/*.cpp")

# ===================================================================
# 타겟 정의 및 링크
# ===================================================================
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyDashboard
        MANUAL_FINALIZATION
        ${PROJECT_MAIN_SOURCES}
        ${PROJECT_UI_FILES}
        ${PROJECT_RESOURCE_FILES}
        ${PROJECT_TRANSLATION_FILES}
        ${PROJECT_QM_FILES}
        ${PROJECT_MOCKDB_SOURCES}
    )
    qt_finalize_executable(MyDashboard)
else() # Qt 5
    # Qt 5는 로직이 다를 수 있으므로 유지
    if(ANDROID)
        add_library(MyDashboard SHARED ${PROJECT_MAIN_SOURCES} ${PROJECT_UI_FILES} ${PROJECT_RESOURCE_FILES} ${PROJECT_TRANSLATION_FILES} ${PROJECT_QM_FILES} ${PROJECT_MOCKDB_SOURCES})
    else()
        add_executable(MyDashboard ${PROJECT_MAIN_SOURCES} ${PROJECT_UI_FILES} ${PROJECT_RESOURCE_FILES} ${PROJECT_TRANSLATION_FILES} ${PROJECT_QM_FILES} ${PROJECT_MOCKDB_SOURCES})
    endif()
endif()

# --- 라이브러리 링크 (공통) ---
target_link_libraries(MyDashboard PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickWidgets
    yaml-cpp::yaml-cpp
)

# ===================================================================
# 플랫폼별 속성 및 설치 규칙
# ===================================================================
# macOS / iOS 번들 설정
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MyDashboard)
endif()

set_target_properties(MyDashboard PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 설치 규칙
include(GNUInstallDirs)
install(TARGETS MyDashboard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
