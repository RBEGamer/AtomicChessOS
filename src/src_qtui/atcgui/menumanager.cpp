#include "menumanager.h"


MenuManager::MenuManager(QObject* _parent){
    qInfo() <<_parent->objectName();
}

MenuManager::MenuManager()
{
qInfo() <<"MenuManager constructor called";


QTimer *timer = new QTimer(this);
 connect(timer, &QTimer::timeout, this, &MenuManager::updateProgress);
 timer->start(500);


//CREATE THE MENU LEVEL TREE HERE
 //ITS NEEDED TO MAKER SHURE THAT THE USER ALWAYS ABLE TO OPEN MENUS
menu_levels["mm_container"] = 0;
menu_levels["ls_container"] = 0;
menu_levels["game_container"] = 0;
menu_levels["es_container"] = 0;
menu_levels["msgta_container"] = 0;
menu_levels["msgtb_container"] = 0;
menu_levels["processing_container"] = 0;


menu_levels["showavariableplayer_container"] = 1;
menu_levels["ss_container"] = 2;
menu_levels["debug_container"] = 3;
menu_levels["is_container"] = 4;



//switch_menu(guicommunicator::GUI_VALUE_TYPE::MAIN_MENU_SCREEN);
guiconnection.start_recieve_thread();
//guiconnection.check_guicommunicator_version();
guiconnection.createEvent(guicommunicator::GUI_ELEMENT::QI_START_EVENT,guicommunicator::GUI_VALUE_TYPE::ENABLED);
}


void MenuManager::set_headline_text(QString _name){
set_label_text("hb_container","hb_headline_text",_name);
}

void MenuManager::set_icon_image(QString _container_name, QString _image_name, QString _path){
    QObject* recht1 = this->parent()->findChild<QObject*>(_container_name);
    if(recht1){
        QObject* recht2 = recht1->findChild<QObject*>(_image_name);
        if(recht2){
            recht2->setProperty("source",_path);
        }else{
            qInfo()<< "cant get element" << _image_name;
        }
    }else{
        qInfo()<< "cant get element" << _container_name;
    }
}

void MenuManager::set_label_text(QString _container_name, QString _labelname,QString _text){
    QObject* recht1 = this->parent()->findChild<QObject*>(_container_name);
    if(recht1){
        QObject* recht2 = recht1->findChild<QObject*>(_labelname);
        if(recht2){
            recht2->setProperty("text",_text);
        }else{
            qInfo()<< "cant get element" << _labelname;
        }
    }else{
        qInfo()<< "cant get element" << _container_name;
    }
}

void MenuManager::set_visible_element(QString _name, bool _state){

    QObject* recht1 = this->parent()->findChild<QObject*>(_name);
    if(recht1){
        recht1->setProperty("visible",_state);
    }else{
        qInfo()<< "cant get element" << _name;
    }

}


void MenuManager::go_menu_back(){
    qInfo() << "DETRUCTOR CALLED";
    if(menu_visist_history.isEmpty()){
        return;
    }
    QString tmp = menu_visist_history.pop();
    qInfo() << tmp << " ---------------------";
    switch_menu(tmp);
}

void MenuManager::lb_info_btn(){
    MenuManager::switch_menu(guicommunicator::GUI_VALUE_TYPE::INFO_SCREEN);
}

//ENABLES A SPECIFIC MENU AND HIDES ALL OTHER
void MenuManager::switch_menu(QString _screen){
    //SAVE ONLY THE CURRENT SCREEN TO THE QUEUE IF WE MOVE A LEVEL UP IN SCREEN TREE
    if(menu_levels.contains(_screen) && menu_levels.contains(current_menu_opened) && menu_levels[_screen] > menu_levels[current_menu_opened]){
    menu_visist_history.push(current_menu_opened);
    qInfo()<< "added to history" << current_menu_opened << "-------------------------";
    }
    current_menu_opened = _screen;
    //HIDE ALL MENU
    set_visible_element("mm_container",false);
    set_visible_element("ls_container",false);
    set_visible_element("ss_container",false);
    set_visible_element("is_container",false);
    set_visible_element("es_container",false);
    set_visible_element("msgta_container",false);
    set_visible_element("msgtb_container",false);
    set_visible_element("processing_container",false);
    set_visible_element("debug_container",false);
    set_visible_element("game_container",false);
    set_visible_element("showavariableplayer_container",false);
    //ENABLE THE SELECTED MENU
    set_visible_element(_screen,true);

    //SET HEADLINE TEXT => READ PROPERTY FROM RECT ELEMENT
    QObject* recht1 = this->parent()->findChild<QObject*>(_screen);
    if(recht1){
         QString name = (QString)recht1->property("headline_bar_name").toString();
         if(!name.isEmpty()){
            set_headline_text(name);
         }

    }else{
        qInfo()<< "cant get element" << _screen;
    }

}
//ENABLES A SPECIFIC MENU 
void MenuManager::switch_menu(guicommunicator::GUI_VALUE_TYPE _screen){
    switch (_screen) {
        case guicommunicator::GUI_VALUE_TYPE::MAIN_MENU_SCREEN:{switch_menu("mm_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::LOGIN_SCREEN:{switch_menu("ls_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::SETTINGS_SCREEN:{switch_menu("ss_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::INFO_SCREEN:{switch_menu("is_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::ERROR_MESSAGE:{switch_menu("es_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::MESSAGEBOX_TYPE_A:{switch_menu("msgta_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::MESSAGEBOX_TYPE_B:{switch_menu("msgtb_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::PROCESSING_SCREEN:{switch_menu("processing_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::DEBUG_SCREEN:{switch_menu("debug_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::GAME_SCREEN:{switch_menu("game_container");break;}
        case guicommunicator::GUI_VALUE_TYPE::PLAYER_SEARCH_SCREEN:{switch_menu("showavariableplayer_container");break;}
        

        default:break;
    }
}

//PROCESSES EVENTS COMMING FROM THE INTER PROCESS COMMUNICATION AND SHOWS MENUS OR SET IMAGES/LABES
void MenuManager::updateProgress()
{
    guicommunicator::GUI_EVENT ev=  guiconnection.get_gui_update_event();

    if(!ev.is_event_valid){return;}

    //SWITCH MAIN MENU REQUEST
    if(ev.event == guicommunicator::GUI_ELEMENT::SWITCH_MENU){
        switch_menu(ev.type);
    }else if(ev.event == guicommunicator::GUI_ELEMENT::INFOSCREEN_HWID_LABEL){
        set_label_text("is_container","is_hwid_label",QString::fromStdString(ev.value));
    }else if(ev.event == guicommunicator::GUI_ELEMENT::INFOSCREEN_SESSIONID_LABEL){
        set_label_text("is_container","is_sessionid_label",QString::fromStdString(ev.value));
    }else if(ev.event == guicommunicator::GUI_ELEMENT::INFOSCREEN_VERSION){
        set_label_text("is_container","is_version_label",QString::fromStdString(ev.value));
    }else if(ev.event == guicommunicator::GUI_ELEMENT::INFOSCREEN_PLAYERINFO_LABEL){
        set_label_text("is_container","is_playerinfo_label",QString::fromStdString(ev.value));
    }else if(ev.event == guicommunicator::GUI_ELEMENT::ERROR){
        switch_menu(ev.type);
        set_label_text("es_container","es_lasterr_label",QString::fromStdString(ev.value));
    }else if(ev.event == guicommunicator::GUI_ELEMENT::NETWORK_STATUS){
        if(ev.type == guicommunicator::GUI_VALUE_TYPE::ONLINE){
            set_icon_image("hb_container","hb_connection_icon","qrc:/qml/noun_Cloud_online.png");
        }else if(ev.type == guicommunicator::GUI_VALUE_TYPE::OFFLINE){
            set_icon_image("hb_container","hb_connection_icon","qrc:/qml/noun_Cloud_offline.png");
        }
        set_label_text("es_container","es_lasterr_label",QString::fromStdString(ev.value));
    }else if(ev.event == guicommunicator::GUI_ELEMENT::MESSAGEBOX_MESSAGE_TEXT){
        set_label_text("msgta_container","msgta_message_label",QString::fromStdString(ev.value));
        set_label_text("msgtb_container","msgtb_message_label",QString::fromStdString(ev.value));

    }else if(ev.event == guicommunicator::GUI_ELEMENT::GAMESCREEN_PLAYER_COLOR){
        if(ev.type == guicommunicator::GUI_VALUE_TYPE::CHESS_COLOR_WHITE){
            set_icon_image("game_container","gs_my_turn_color_image","qrc:/qml/noun_Chess_3493083(1).png");
        }else if(ev.type == guicommunicator::GUI_VALUE_TYPE::CHESS_COLOR_BLACK){
            set_icon_image("game_container","gs_my_turn_color_image","qrc:/qml/noun_Chess_3493083.png");
        }
    }else if(ev.event == guicommunicator::GUI_ELEMENT::GAMESCREEN_PLAYER_TURN_COLOR){
        if(ev.type == guicommunicator::GUI_VALUE_TYPE::CHESS_COLOR_WHITE){
            set_icon_image("game_container","gs_current_turn_color_image","qrc:/qml/noun_Chess_3493083(1).png");
        }else if(ev.type == guicommunicator::GUI_VALUE_TYPE::CHESS_COLOR_BLACK){
            set_icon_image("game_container","gs_current_turn_color_image","qrc:/qml/noun_Chess_3493083.png");
        }
    }else if(ev.event == guicommunicator::GUI_ELEMENT::GAMESCREEN_POSSIBLE_MOVES){
        set_label_text("game_container","game_possible_move_text",QString::fromStdString(ev.value));
    }

}


MenuManager::~MenuManager(){
    qInfo() << "DETRUCTOR CALLED";
    //update_thread->terminate();
    guiconnection.stop_recieve_thread();
}


void MenuManager::show_error(QString _err){
    qInfo() << _err;
    //TODO SHWITCH TO ERR VIEW
}


void MenuManager::lb_settings_btn(){
    qInfo() <<"lb_settings_btn";
   MenuManager::switch_menu(guicommunicator::GUI_VALUE_TYPE::SETTINGS_SCREEN);
    // MenuManager::switch_menu(guicommunicator::GUI_VALUE_TYPE::SETTINGS_SCREEN);
};

void MenuManager::ls_login_btn(){
    qInfo() <<"ls_login_btn";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::BEGIN_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);

}

void MenuManager::is_open_is_screen_btn(){
    MenuManager::switch_menu(guicommunicator::GUI_VALUE_TYPE::INFO_SCREEN);
}


void MenuManager::open_debug_menu(){
     MenuManager::switch_menu(guicommunicator::GUI_VALUE_TYPE::DEBUG_SCREEN);
}

void MenuManager::sm_open_settings_btn(){
    qInfo() <<"sm_open_settings_btn";
}



void MenuManager::sm_logout_btn(){
    qInfo() << "sm_logout_btn";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::LOGOUT_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);
}

void MenuManager::sm_init_btn(){
    qInfo() << "sm_init_btn";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::INIT_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);
    
}
void MenuManager::sm_scan_board_btn(){
    qInfo() << "sm_scan_board_btn";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::SCAN_BOARD_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);
    
}
void MenuManager::mm_start_ai_btn(){
    qInfo() <<"start_ai";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::MAINMENU_START_AI_MATCH_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);
}

void MenuManager::mm_player_list_btn(){
    qInfo() << "goto_search_player_view";
    MenuManager::switch_menu(guicommunicator::GUI_VALUE_TYPE::PLAYER_SEARCH_SCREEN);
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::MAINMENU_PLAYER_LIST_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);
}


void MenuManager::mm_search_for_players_toggled(bool _state){
    qInfo() << "search_for_players_toggled";
    if(_state){
        qInfo() <<"1";
        guiconnection.createEvent(guicommunicator::GUI_ELEMENT::MAINMENU_START_AI_MATCH_BTN, guicommunicator::GUI_VALUE_TYPE::ENABLED);
    }else{
        qInfo() << "0";
        guiconnection.createEvent(guicommunicator::GUI_ELEMENT::MAINMENU_START_AI_MATCH_BTN, guicommunicator::GUI_VALUE_TYPE::DISBALED);
    }
}

void MenuManager::message_screen_ok_btn(){
    qInfo() <<"message_screen_ok_btn";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::MESSAGEBOX_OK_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);
}

void MenuManager::message_screen_cancel_btn(){
    qInfo() <<"message_screen_cancel_btn";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::MESSAGEBOX_CANCEL_BTN, guicommunicator::GUI_VALUE_TYPE::CLICKED);
}


void MenuManager::debug_screen_fkt(int _id){
    switch (_id)
    {
    case 0: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_A, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    case 1: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_B, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    case 2: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_C, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    case 3: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_D, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    case 4: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_E, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    case 5: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_F, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    case 6: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_G, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    case 7: guiconnection.createEvent(guicommunicator::GUI_ELEMENT::DEBUG_FUNCTION_H, guicommunicator::GUI_VALUE_TYPE::CLICKED);break;
    default:
        break;
    }
}


void MenuManager::gs_abort_game(){
    qInfo() <<"gs_abort_game";
    guiconnection.createEvent(guicommunicator::GUI_ELEMENT::GAMESCREEN_ABORT_GAME, guicommunicator::GUI_VALUE_TYPE::CLICKED);
}