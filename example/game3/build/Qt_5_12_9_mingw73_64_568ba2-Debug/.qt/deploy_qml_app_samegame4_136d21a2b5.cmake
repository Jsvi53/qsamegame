include(C:/Users/28581/Desktop/qttest/game3/build/Qt_5_12_9_mingw73_64_568ba2-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/samegame4-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative")

qt6_deploy_qml_imports(TARGET samegame4 PLUGINS_FOUND plugins_found)
qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/28581/Desktop/qttest/game3/build/Qt_5_12_9_mingw73_64_568ba2-Debug/samegame4.exe
    ADDITIONAL_MODULES ${plugins_found}
    GENERATE_QT_CONF
)