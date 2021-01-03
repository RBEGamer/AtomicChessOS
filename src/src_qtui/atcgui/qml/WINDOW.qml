import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
//IMPORT THE C++ BACKEND
import MenuManager 1.0



Rectangle {
    id: window
    objectName: "window"

    width: 800
    height: 480
    color: "#07a8a5"

    z: -1

    MenuManager{
        id:main_menu
        objectName: "mainmenu"
    }


    Rectangle {
        id: hb_container
        objectName: "hb_container"
        x: 0
        y: 0
        width: 800
        height: 69
        color: "#dbdbdb"
        visible: true

        Text {
            id: hb_headline_text
            objectName: "hb_headline_text"
            x: 318
            y: 18
            width: 164
            height: 34
            text: qsTr("MAIN MENU")
            visible: true
            lineHeightMode: Text.ProportionalHeight
            fontSizeMode: Text.FixedSize
            font.pixelSize: 30
        }

        Text {
            id: hb_atc_text
            x: 83
            y: 18
            width: 164
            height: 34
            text: qsTr("ATC")
            font.pixelSize: 30
            fontSizeMode: Text.FixedSize
            lineHeightMode: Text.ProportionalHeight
        }

        Button {
            id: hb_settings_button
            x: 731
            y: 4
            width: 61
            height: 61

            Image {
                id: hb_settings_icon
                x: 0
                y: 0
                width: 61
                height: 61
                fillMode: Image.PreserveAspectFit
                source: "noun_Settings_56313.png"
            }
            Connections {
                target: hb_settings_button
                function onClicked(_mouse){
                    //ss_container.visible = true
                    main_menu.lb_settings_btn()
                }
            }
        }

        Image {
            id: hb_connection_icon
            objectName: "hb_connection_icon"
            x: 671
            y: 4
            width: 61
            height: 61
            fillMode: Image.PreserveAspectFit
            source: "noun_Cloud_offline.png"


        }

        Button {
            id: hb_atc_button
            x: 8
            y: 4
            width: 61
            height: 61

            Image {
                id: hb_atc_icon
                x: 0
                y: 0
                width: 61
                height: 61
                fillMode: Image.PreserveAspectFit
                source: "noun_Chess_1376847.png"

            }

            Connections {
                target: hb_atc_button
                function onClicked(_mouse){
                    main_menu.is_open_is_screen_btn()
                }
            }

        }

    }

    Rectangle {
        id: mm_container
        objectName: "mm_container"
        x: 0
        y: 69
        width: 800
        height: 411
        color: "#07a8a5"
        visible: true
        Rectangle {
            id: mm_searching_for_players_box
            x: 47
            y: 31
            width: 691
            height: 343
            visible: true
            color: "#189694"


            BusyIndicator {
                id: sfp_indicator
                x: 253
                y: 132
                width: 171
                height: 171
                visible: false
                Connections {
                    target: sfp_indicator
                }
                wheelEnabled: true
            }

            Button {
                id: mm_en_sfg_btn
                x: 29
                y: 8
                width: 207
                height: 55
                text: qsTr("START SEARCH FOR GAME")
                Connections {
                    target: mm_en_sfg_btn
                    function onClicked(_mouse){
                        main_menu.mm_search_for_players_toggled(true);
                        sfp_indicator.visible = true;
                    }
                }
            }

            Button {
                id: mm_dis_sfg_btn
                x: 468
                y: 8
                width: 207
                height: 55
                text: qsTr("STOP SEARCH FOR GAME")
                Connections {
                    target: mm_dis_sfg_btn
                    function onClicked(_mouse){
                        main_menu.mm_search_for_players_toggled(false);
                        sfp_indicator.visible = false;
                    }
                }
            }


        }

        Rectangle {
            id: mm_sart_game_box
            x: 61
            y: 31
            width: 253
            height: 343
            visible: false
            color: "#1f8f8d"
            Button {
                id: mm_show_playerlist_btn
                x: 26
                y: 151
                width: 207
                height: 55
                visible: false
                text: qsTr("SHOW AVARIABLE PLAYERS")
                Connections {
                    target: mm_show_playerlist_btn
                    function onClicked(_mouse){
                        main_menu.mm_search_for_players_toggled(false) //DONT KNOW WHY ITS INVERTED...
                        sfp_indicator.visible = true;
                    }
                }
            }

            Button {
                id: mm_start_random_btn
                x: 26
                y: 183
                width: 207
                height: 55
                visible: false
                text: qsTr("START AI MATCH")
                Connections {
                    target: mm_start_random_btn
                    function onClicked(_mouse){
                        main_menu.mm_search_for_players_toggled(true) //DONT KNOW WHY ITS INVERTED...
                        sfp_indicator.visible = false;
                    }
                }
            }
        }
    }

    Rectangle {
        id: ls_container
        objectName: "ls_container"
        x: 0
        y: 69
        width: 800
        height: 411
        color: "#07a8a5"
        visible: false
        Button {
            id: ls_login_btn
            x: 272
            y: 147
            width: 257
            height: 118
            text: qsTr("BEGIN")
            font.pointSize: 20
            Connections {
                target: ls_login_btn
                function onClicked(_mouse){
                    main_menu.ls_login_btn()
                }
            }
        }
    }

    Rectangle {
        id: ss_container
        objectName: "ss_container"
        x: 0
        y: 68
        width: 800
        height: 411
        color: "#07a8a5"
        visible: false
        Grid {
            id: ss_manual_function_buttons_grid
            x: 0
            y: 0
            width: 230
            height: 411
            layoutDirection: Qt.LeftToRight
            verticalItemAlignment: Grid.AlignVCenter
            horizontalItemAlignment: Grid.AlignHCenter
            padding: 17
            spacing: 68
            rows: 5
            columns: 1

            Button {
                id: ss_scan_board_btn
                width: 200
                height: 80
                text: qsTr("CALIBRATION WIZARD")
                Connections {
                    target: ss_scan_board_btn
                    function onClicked(_mouse){
                        main_menu.sm_scan_board_btn()
                    }
                }
            }

            Button {
                id: ss_init_board_btn
                width: 200
                height: 80
                text: qsTr("INIT BOARD")
                Connections {
                    target: ss_init_board_btn
                    function onClicked(_mouse){
                        main_menu.sm_init_btn()
                    }
                }
            }

            Button {
                id: ss_log_out_btn
                width: 200
                height: 80
                text: qsTr("LOGOUT")
                Connections {
                    target: ss_log_out_btn
                    function onClicked(_mouse){
                        main_menu.sm_logout_btn()

                    }
                }
            }
        }

        Button {
            id: sm_back_btn
            x: 686
            y: 363
            text: qsTr("BACK")
            Connections {
                target: sm_back_btn
                function onClicked(_mouse){
                    main_menu.go_menu_back()
                }
            }
        }

        Button {
            id: sm_dbg_btn
            x: 686
            y: 8
            text: qsTr("DBG")
            Connections {
                target: sm_dbg_btn
                function onClicked(_mouse){
                    main_menu.open_debug_menu()
                }
            }
        }
    }

    Rectangle {
        id: is_container
        x: 0
        y: 68
        width: 800
        height: 411
        color: "#07a8a5"
        visible: false
        objectName: "is_container"

        Button {
            id: is_back_btn
            x: 686
            y: 363
            text: qsTr("BACK")
            Connections {
                target: is_back_btn
                function onClicked(_mouse){
                    main_menu.go_menu_back()
                }
            }
        }

        Text {
            id: is_hwid_label
            objectName: "is_hwid_label"
            x: 57
            y: 54
            width: 680
            height: 75
            color: "#ffffff"
            text: qsTr("HWID")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Text {
            id: is_sessionid_label
            objectName: "is_sessionid_label"
            x: 57
            y: 155
            width: 680
            height: 78
            color: "#ffffff"
            text: qsTr("SESSION_ID")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Text {
            id: is_version_label
            objectName: "is_version_label"
            x: 57
            y: 246
            width: 680
            height: 102
            color: "#ffffff"
            text: qsTr("ATCOS_VERSION")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }
    }

    Rectangle {
        id: es_container
        x: 0
        y: 69
        width: 800
        height: 411
        color: "#07a8a5"
        objectName: "es_container"
        Button {
            id: es_back_btn
            x: 686
            y: 363
            text: qsTr("BACK")
            Connections {
                target: es_back_btn
                function onClicked(_mouse){
                    main_menu.go_menu_back()
                }
            }
        }

        Text {
            id: es_lasterr_label
            x: 97
            y: 54
            width: 652
            height: 246
            color: "#ffffff"
            text: qsTr("ERROR")
            horizontalAlignment: Text.AlignHCenter
            objectName: "es_lasterr_label"
            font.pixelSize: 30
        }
        visible: false
    }

    Rectangle {
        id: msgta_container
        objectName: "msgta_container"
        x: 2
        y: 70
        width: 800
        height: 411
        color: "#07a8a5"

        Text {
            id: msgta_headline_label
            x: 358
            y: 54
            color: "#ffffff"
            text: qsTr("MESSAGE")
            horizontalAlignment: Text.AlignHCenter
            objectName: "es_lasterr_label"
            font.pixelSize: 30
        }

        Text {
            id: msgta_message_label
            objectName: "msgta_message_label"
            x: 56
            y: 102
            width: 695
            height: 142
            color: "#ffffff"
            text: qsTr("MESSAGE")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }

        Button {
            id: msgta_button_cancel
            x: 134
            y: 295
            width: 175
            height: 70
            text: qsTr("CANCEL")
            Connections {
                target: msgta_button_cancel
                function onClicked(_mouse){
                    main_menu.message_screen_cancel_btn()
                }
            }
        }

        Button {
            id: msgta_button_ok
            x: 487
            y: 295
            width: 175
            height: 70
            text: qsTr("OK")
            Connections {
                target: msgta_button_ok
                function onClicked(_mouse){
                    main_menu.message_screen_ok_btn()
                }
            }
        }
        visible: false
    }

    Rectangle {
        id: msgtb_container
        objectName: "msgtb_container"
        x: 2
        y: 70
        width: 800
        height: 411
        color: "#07a8a5"
        Text {
            id: msgtb_headline_label
            x: 358
            y: 54
            color: "#ffffff"
            text: qsTr("MESSAGE")
            horizontalAlignment: Text.AlignHCenter
            objectName: "msgtb_headline_label"
            font.pixelSize: 30
        }

        Text {
            id: msgtb_message_label
            x: 56
            y: 102
            width: 695
            height: 142
            color: "#ffffff"
            text: qsTr("MESSAGE")
            objectName: "msgtb_message_label"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            id: msgtb_button_ok
            x: 316
            y: 279
            width: 175
            height: 70
            text: qsTr("OK")
            Connections {
                target: msgtb_button_ok
                function onClicked(_mouse){
                    main_menu.message_screen_ok_btn()
                }
            }
        }
        visible: false
    }

    Rectangle {
        id: processing_container
        objectName: "processing_container"
        x: 0
        y: 70
        width: 800
        height: 411
        color: "#07a8a5"
        Text {
            id: processing_headline_label
            x: 308
            y: 34
            color: "#ffffff"
            text: qsTr("PLEASE WAIT")
            objectName: "processing_headline_label"
            font.pixelSize: 30
        }

        BusyIndicator {
            id: busyIndicator
            x: 223
            y: 85
            width: 355
            height: 293
            wheelEnabled: false
        }
        visible: false
    }

    Rectangle {
        id: debug_container
        x: -1
        y: 70
        width: 800
        height: 411
        color: "#07a8a5"
        visible: false
        objectName: "debug_container"
        Text {
            id: debug_headline_label
            x: 351
            y: 31
            color: "#ffffff"
            text: qsTr("DEBUG")
            objectName: "debug_headline_label"
            font.pixelSize: 30
        }

        Button {
            id: debug_back_btn
            x: 685
            y: 363
            text: qsTr("BACK")
            Connections {
                target: debug_back_btn
                function onClicked(_mouse){
                    main_menu.lb_settings_btn()
                }
            }
        }

        Rectangle {
            id: debug_bg_rect
            x: 46
            y: 31
            width: 727
            height: 315
            color: "#189694"

            Button {
                id: debug_fkt_a_btn
                x: 13
                y: 14
                width: 209
                height: 60
                text: qsTr("CALIBRATE_HOME_POS")
                Connections {
                    target: debug_fkt_a_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(0)
                    }
                }
            }

            Button {
                id: debug_fkt_b_btn
                x: 259
                y: 14
                width: 209
                height: 60
                text: qsTr("LOAD_DEFAULT_CONFIG")
                Connections {
                    target: debug_fkt_b_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(1)
                    }
                }
            }

            Button {
                id: debug_fkt_c_btn
                x: 510
                y: 14
                width: 209
                height: 60
                text: qsTr("MAKE_MOVE_TEST")
                Connections {
                    target: debug_fkt_c_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(2)
                    }
                }
            }

            Button {
                id: debug_fkt_d_btn
                x: 13
                y: 121
                width: 209
                height: 60
                text: qsTr("G5 -> A2")
                Connections {
                    target: debug_fkt_d_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(3)
                    }
                }
            }

            Button {
                id: debug_fkt_e_btn
                x: 259
                y: 121
                width: 209
                height: 60
                text: qsTr("UPLOAD CONFIG FILE")
                Connections {
                    target: debug_fkt_e_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(4)
                    }
                }
            }

            Button {
                id: debug_fkt_f_btn
                x: 510
                y: 121
                width: 209
                height: 60
                text: qsTr("UPLOAD LOGFILE")
                Connections {
                    target: debug_fkt_f_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(5)
                    }
                }
            }

            Button {
                id: debug_fkt_g_btn
                x: 13
                y: 218
                width: 209
                height: 60
                text: qsTr("DOWNLOAD CONFIG FILE")
                Connections {
                    target: debug_fkt_g_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(6)
                    }
                }
            }

            Button {
                id: debug_fkt_h_btn
                x: 259
                y: 218
                width: 209
                height: 60
                text: qsTr("FKT_H")
                Connections {
                    target: debug_fkt_h_btn
                    function onClicked(_mouse){
                        main_menu.debug_screen_fkt(7)
                    }
                }

            }
        }
    }

    Rectangle {
        id: game_container
        x: 1
        y: 69
        width: 800
        height: 411
        color: "#07a8a5"
        border.color: "#000100"
        visible: false
        objectName: "game_container"
        Text {
            id: game_headline_label
            x: 308
            y: 34
            color: "#ffffff"
            text: qsTr("GAME STATE")
            horizontalAlignment: Text.AlignHCenter
            objectName: "game_headline_label"
            font.pixelSize: 30
        }


        Text {
            id: game_possible_move_label
            x: 8
            y: 85
            color: "#ffffff"
            text: qsTr("POSSIBLE MOVES")
            horizontalAlignment: Text.AlignHCenter
            objectName: "game_possible_move_label"
            font.pixelSize: 24
        }


        Button {

            id: game_abortgame_btn
            objectName: "game_abortgame_btn"
            x: 286
            y: 305
            width: 266
            height: 89
            text: qsTr("ABORT GAME")
            focusPolicy: Qt.ClickFocus
            autoRepeat: false
            Connections {
                target: game_abortgame_btn
                function onClicked(_mouse){
                    main_menu.gs_abort_game()
                }
            }
        }

        ListView {
            id: game_possible_moves_list
            objectName: "game_possible_moves_list"
            x: 25
            y: 132
            width: 215
            height: 271
            model: ListModel {
                ListElement {
                    name: "E2 -> E4"

                }

                ListElement {
                    name: "G6 -> A4"

                }


            }
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1


                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    spacing: 10
                }
            }
        }

        Text {
            id: game_statistics_headline_label1
            x: 579
            y: 85
            color: "#ffffff"
            text: qsTr("GAME STATISTICS")
            visible: true
            horizontalAlignment: Text.AlignHCenter
            objectName: "game_possible_move_label"
            font.pixelSize: 24
        }

    }

    Rectangle {
        id: showavariableplayer_container
        objectName: "showavariableplayer_container"
        x: 0
        y: 70
        width: 800
        height: 411
        color: "#07a8a5"
        visible: false

        Button {
            id: showavariableplayer_back_btn
            x: 686
            y: 363
            text: qsTr("BACK")
            visible: true
            Connections {
                target: is_back_btn
                function onClicked(_mouse){
                    main_menu.go_menu_back()
                }
            }
        }
    }



}




/*##^##
Designer {
    D{i:0;active3dScene:"-1"}
}
##^##*/