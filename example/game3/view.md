graph TD
    A[main.cpp] --> B[QGuiApplication & QQmlApplicationEngine]
    B --> C{加载 QML}
    C --> D[samegame.qml]
    D --> E1[BoomBlock.qml]
    D --> E2[Button.qml]
    D --> E3[Dialog.qml]
    D --> F[samegame.js]
    D --> G[资源文件（pics, highscores）]