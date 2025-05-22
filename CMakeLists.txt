cmake_minimum_required(VERSION 3.16)
project(qsamegame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Qml Quick)

# 删除qt_standard_project_setup() - 这是Qt6特有的

# QML文件已在qrc资源文件中定义，不需要在此列出
# 直接添加可执行文件
add_executable(qsamegame main.cpp)
set_target_properties(qsamegame PROPERTIES WIN32_EXECUTABLE TRUE)

# 添加Qt5资源文件
qt5_add_resources(RESOURCES
    qsamegamercc.qrc
)

# 添加资源到可执行文件
target_sources(qsamegame PRIVATE ${RESOURCES})

target_link_libraries(qsamegame PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
)

# 移除Qt6特有的部署脚本生成命令
# 您可以使用windeployqt (Windows)或macdeployqt (Mac)来部署应用程序