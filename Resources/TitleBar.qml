import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: titleBar
    height: 50
    width: parent.width
    color: "#6B66FF"

    RowLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.margins: 10 // 모든 방향으로 10px의 여백을 줍니다.
        spacing: 10

        Text {
            text: "ADAMSCARD"
            color: "white"
            font.bold: true
        }

        Item { Layout.fillWidth: true }

        ToolButton {
            icon.source: "qrc:/Resources/Minimize.png"
            onClicked: mainWindow.minimizeWindow()
        }

        ToolButton {
            icon.source: mainWindow.maximized
                          ? "qrc:/Resources/Restore.png"
                          : "qrc:/Resources/Maximize.png"
            onClicked: mainWindow.toggleMaximize()
        }

        ToolButton {
            icon.source: "qrc:/Resources/Close.png"
            onClicked: mainWindow.quitApp()
        }
    }
}
