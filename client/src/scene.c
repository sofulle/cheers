// scene.c

#include "cheers.h"

void scene_init(app_t *app) {
    // style_t style_background = set_clear_style();
    // style_background.position = set_pos(0, 0, false, false);
    // style_background.size = set_size(100, 100, true, true);
    // style_background.anchor = ANCHOR_TOP_LEFT;
    // style_background.background_color = set_color(31, 32, 44, 255);

    // style_t style_container = set_clear_style();
    // style_container.position = set_pos(50, 0, true, false);
    // style_container.size = set_size(270, 100, false, true);
    // style_container.anchor = ANCHOR_TOP_CENTER;
    // style_container.z_index = 1;

    // style_t style_logo = set_clear_style();
    // style_logo.position = set_pos(50, 65, true, false);
    // style_logo.size = set_size(80, 80, false, false);
    // style_logo.anchor = ANCHOR_TOP_CENTER;
    // style_logo.texture = render_texture(app, "resource/img/logo.png");

    // style_t style_title = set_clear_style();
    // style_title.position = set_pos(50, 165, true, false);
    // style_title.size = set_size(100, 42, true, false);
    // style_title.anchor = ANCHOR_TOP_CENTER;
    // style_title.text_content = "Cheers!";
    // style_title.text_anchor = ANCHOR_CENTER_CENTER;
    // style_title.font = set_font(FONT_ROBOTO_REGULAR_36, set_color(255, 255, 255, 255));

    // style_t style_subtitle = set_clear_style();
    // style_subtitle.position = set_pos(50, 217, true, false);
    // style_subtitle.size = set_size(100, 19, true, false);
    // style_subtitle.anchor = ANCHOR_TOP_CENTER;
    // style_subtitle.text_content = "Lets start your own party!";
    // style_subtitle.text_anchor = ANCHOR_CENTER_CENTER;
    // style_subtitle.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    // style_t style_input_name = set_clear_style();
    // style_input_name.position = set_pos(50, 264, true, false);
    // style_input_name.size = set_size(100, 48, true, false);
    // style_input_name.padding.left = 15;
    // style_input_name.anchor = ANCHOR_TOP_CENTER;
    // style_input_name.background_color = set_color(62, 67, 101, 255);
    // style_input_name.text_content = "Name";
    // style_input_name.text_anchor = ANCHOR_CENTER_LEFT;
    // style_input_name.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    // style_t style_input_username = set_clear_style();
    // style_input_username.position = set_pos(50, 327, true, false);
    // style_input_username.size = set_size(100, 48, true, false);
    // style_input_username.padding.left = 15;
    // style_input_username.anchor = ANCHOR_TOP_CENTER;
    // style_input_username.background_color = set_color(62, 67, 101, 255);
    // style_input_username.text_content = "Username";
    // style_input_username.text_anchor = ANCHOR_CENTER_LEFT;
    // style_input_username.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    // style_t style_button_submit = set_clear_style();
    // style_button_submit.position = set_pos(50, 432, true, false);
    // style_button_submit.size = set_size(90, 48, true, false);
    // style_button_submit.padding.left = 15;
    // style_button_submit.anchor = ANCHOR_TOP_CENTER;
    // style_button_submit.background_color = set_color(62, 67, 101, 255);
    // style_button_submit.text_content = "Log in";
    // style_button_submit.text_anchor = ANCHOR_CENTER_CENTER;
    // style_button_submit.font = set_font(FONT_ROBOTO_REGULAR_18, set_color(255, 255, 255, 255));

    // style_t style_copyright = set_clear_style();
    // style_copyright.position = set_pos(50, 100, true, true);
    // style_copyright.size = set_size(100, 14, true, false);
    // style_copyright.anchor = ANCHOR_BOTTOM_CENTER;
    // style_copyright.padding.bottom = 20;
    // style_copyright.text_content = "Cop & Past Inc.";
    // style_copyright.text_anchor = ANCHOR_CENTER_CENTER;
    // style_copyright.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 255));

    // object_add("background", app->root, &style_background, NULL, NULL, NULL, NULL);
    // object_add("container", app->root, &style_container, NULL, NULL, NULL, NULL);
    // object_add("logo", object_search_byid("container", app->root), &style_logo, NULL, NULL, NULL, NULL);
    // object_add("title", object_search_byid("container", app->root), &style_title, NULL, NULL, NULL, NULL);
    // object_add("subtitle", object_search_byid("container", app->root), &style_subtitle, NULL, NULL, NULL, NULL);
    // object_add("input_name", object_search_byid("container", app->root), &style_input_name, NULL, NULL, NULL, NULL);
    // object_add("input_username", object_search_byid("container", app->root), &style_input_username, NULL, NULL, NULL, NULL);
    // object_add("button_submit", object_search_byid("container", app->root), &style_button_submit, NULL, NULL, NULL, NULL);
    // object_add("copyright", object_search_byid("container", app->root), &style_copyright, NULL, NULL, NULL, NULL);





    // your awesome code below <3
    

    style_t style_container = set_clear_style();
    style_container.size = set_size(100, 100, true, true);
    style_container.anchor = ANCHOR_TOP_LEFT;
    style_container.background_color = set_color(62, 67, 101, 255);
    style_container.z_index = 1;

    style_t style_container_1 = set_clear_style();
    style_container_1.position = set_pos(0, 0, true, false);
    style_container_1.size = set_size(20, 100, true, true);
    style_container_1.anchor = ANCHOR_TOP_LEFT;
    style_container_1.padding.top = 128;
    style_container_1.padding.bottom = 52;
    style_container_1.background_color = set_color(31, 32, 44, 255);


    style_t style_container_2 = set_clear_style();
    style_container_2.position = set_pos(20, 0, true, false);
    style_container_2.size = set_size(60, 100, true, true);
    style_container_2.anchor = ANCHOR_TOP_LEFT;
    style_container_2.padding.top = 52;
    style_container_2.padding.bottom = 52;
    style_container_2.background_color = set_color(57, 61, 85, 255);

    style_t style_container_3 = set_clear_style();
    style_container_3.position = set_pos(80, 0, true, false);
    style_container_3.size = set_size(20, 100, true, true);
    style_container_3.anchor = ANCHOR_TOP_LEFT;
    style_container_2.padding.top = 52;
    style_container_3.background_color = set_color(31, 32, 44, 255);

    style_t style_messages_1 = set_clear_style();
    style_messages_1.position = set_pos(0, 0, false, true);
    style_messages_1.size = set_size(100, 52, true, false);
    style_messages_1.anchor = ANCHOR_TOP_LEFT;
    style_messages_1.background_color = set_color(31, 32, 44, 255);
    style_messages_1.is_static = true;


    style_t style_messages_2 = set_clear_style();
    style_messages_2.position = set_pos(0, 0, false, false);
    style_messages_2.size = set_size(100, 100, true, true);
    style_messages_2.anchor = ANCHOR_TOP_LEFT;
    style_messages_2.background_color = set_color(57, 61, 85, 255);

    style_t style_messages_3 = set_clear_style();
    style_messages_3.position = set_pos(0, 100, false, true);
    style_messages_3.size = set_size(100, 52, true, false);
    style_messages_3.anchor = ANCHOR_BOTTOM_LEFT;
    style_messages_3.padding.left = 52;
    style_messages_3.padding.right = 52;
    style_messages_3.background_color = set_color(31, 32, 44, 255);
    style_messages_3.is_static = true;


    style_t style_chats_1 = set_clear_style();
    style_chats_1.position = set_pos(0, 0, false, true);
    style_chats_1.size = set_size(100, 128, true, false);
    style_chats_1.anchor = ANCHOR_TOP_LEFT;
    style_chats_1.background_color = set_color(24, 26, 41, 255);
    style_chats_1.is_static = true;


    style_t style_chats_2 = set_clear_style();
    style_chats_2.position = set_pos(0, 0, false, false);
    style_chats_2.size = set_size(100, 100, true, true);
    style_chats_2.anchor = ANCHOR_TOP_LEFT;
    style_chats_2.background_color = set_color(31, 32, 44, 255);

    style_t style_chats_3 = set_clear_style();
    style_chats_3.position = set_pos(0, 100, false, true);
    style_chats_3.size = set_size(100, 52, true, false);
    style_chats_3.anchor = ANCHOR_BOTTOM_LEFT;
    style_messages_3.padding.left = 52;
    style_messages_3.padding.right = 118;
    style_chats_3.background_color = set_color(24, 26, 35, 255);
    style_chats_3.is_static = true;

    style_t style_games_1 = set_clear_style();
    style_games_1.position = set_pos(0, 0, false, true);
    style_games_1.size = set_size(100, 52, true, false);
    style_games_1.anchor = ANCHOR_TOP_LEFT;
    style_games_1.background_color = set_color(31, 32, 44, 255);
    style_games_1.is_static = true;


    style_t style_games_2 = set_clear_style();
    style_games_2.position = set_pos(0, 52, false, false);
    style_games_2.size = set_size(100, 100, true, true);
    style_games_2.anchor = ANCHOR_TOP_LEFT;
    style_games_2.background_color = set_color(31, 32, 44, 255);


    style_t style_chats_ls_bar = set_clear_style();
    style_chats_ls_bar.position = set_pos(0, 0, true, false);
    style_chats_ls_bar.size = set_size(100, 128, true, false);
    style_chats_ls_bar.anchor = ANCHOR_TOP_LEFT;
    style_chats_ls_bar.background_color = set_color(24, 26, 41, 255);

    style_t style_container_for_rooms_ls = set_clear_style();
    style_container_for_rooms_ls.position = set_pos(0, 50, true, true);
    style_container_for_rooms_ls.size = set_size(100, 64, true, false);
    style_container_for_rooms_ls.anchor = ANCHOR_TOP_LEFT;
    style_container_for_rooms_ls.background_color = set_color(31, 32, 44, 255);

    style_t style_chat_bar = set_clear_style();
    style_chat_bar.position = set_pos(0, 0, true, false);
    style_chat_bar.size = set_size(100, 52, true, false);
    style_chat_bar.anchor = ANCHOR_TOP_LEFT;
    style_chat_bar.background_color = set_color(31, 32, 44, 255);

    style_t style_button_for_rooms = set_clear_style();
    style_button_for_rooms.position = set_pos(0, 0, true, false);
    style_button_for_rooms.size = set_size(50, 100, true, true);
    style_button_for_rooms.anchor = ANCHOR_TOP_LEFT;
    style_button_for_rooms.background_color = set_color(24, 26, 41, 255);

    style_t style_button_for_ls = set_clear_style();
    style_button_for_ls.position = set_pos(50, 0, true, false);
    style_button_for_ls.size = set_size(50, 100, true, true);
    style_button_for_ls.anchor = ANCHOR_TOP_LEFT;
    style_button_for_ls.background_color = set_color(24, 26, 41, 255);


    style_t style_button_for_rooms_logo = set_clear_style();
    style_button_for_rooms_logo.position = set_pos(50, 11, true, false);
    style_button_for_rooms_logo.size = set_size(24, 24, false, false);
    style_button_for_rooms_logo.anchor = ANCHOR_TOP_CENTER;
    style_button_for_rooms_logo.texture = render_texture(app, "resource/img/home.png");

    style_t style_button_for_ls_logo = set_clear_style();
    style_button_for_ls_logo.position = set_pos(50, 11, true, false);
    style_button_for_ls_logo.size = set_size(24, 24, false, false);
    style_button_for_ls_logo.anchor = ANCHOR_TOP_CENTER;
    style_button_for_ls_logo.texture = render_texture(app, "resource/img/direct.png");
    

    style_t style_button_for_rooms_title = set_clear_style();
    style_button_for_rooms_title.position = set_pos(50, 25, true, false);
    style_button_for_rooms_title.size = set_size(100, 42, true, false);
    style_button_for_rooms_title.anchor = ANCHOR_TOP_CENTER;
    style_button_for_rooms_title.text_content = "Rooms";
    style_button_for_rooms_title.text_anchor = ANCHOR_CENTER_CENTER;
    style_button_for_rooms_title.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 150));


    style_t style_button_for_ls_title = set_clear_style();
    style_button_for_ls_title.position = set_pos(50, 25, true, false);
    style_button_for_ls_title.size = set_size(100, 42, true, false);
    style_button_for_ls_title.anchor = ANCHOR_TOP_CENTER;
    style_button_for_ls_title.text_content = "Direct";
    style_button_for_ls_title.text_anchor = ANCHOR_CENTER_CENTER;
    style_button_for_ls_title.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 150));

    style_t style_container_for_server = set_clear_style();
    style_container_for_server.position = set_pos(0, 100, true, true);
    style_container_for_server.size = set_size(100, 52, true, false);
    style_container_for_server.anchor = ANCHOR_BOTTOM_LEFT;
    style_container_for_server.background_color = set_color(24, 26, 35, 255);


    style_t style_container_for_entering_messeges = set_clear_style();
    style_container_for_entering_messeges.position = set_pos(0, 100, false, true);
    style_container_for_entering_messeges.size = set_size(100, 52, true, false);
    style_container_for_entering_messeges.anchor = ANCHOR_BOTTOM_LEFT;
    style_container_for_entering_messeges.padding.left = 52;
    style_container_for_entering_messeges.padding.right = 52;
    style_container_for_entering_messeges.background_color = set_color(31, 32, 44, 255);


    style_t style_container_for_entertainments = set_clear_style();
    style_container_for_entertainments.position = set_pos(0, 0, true, false);
    style_container_for_entertainments.size = set_size(100, 52, true, false);
    style_container_for_entertainments.anchor = ANCHOR_TOP_LEFT;
    style_container_for_entertainments.background_color = set_color(255, 255, 255, 255);//(31, 32, 44, 255);


    style_t style_button_for_games = set_clear_style();
    style_button_for_games.position = set_pos(0, 0, true, false);
    style_button_for_games.size = set_size(50, 100, true, true);
    style_button_for_games.anchor = ANCHOR_TOP_LEFT;
    style_button_for_games.background_color = set_color(31, 32, 44, 255);

    style_t style_button_for_skickers = set_clear_style();
    style_button_for_skickers.position = set_pos(50, 0, true, false);
    style_button_for_skickers.size = set_size(50, 100, true, true);
    style_button_for_skickers.anchor = ANCHOR_TOP_LEFT;
    style_button_for_skickers.background_color = set_color(31, 32, 44, 255);

    // style_t style_button_for_emojis = set_clear_style();
    // style_button_for_emojis.position = set_pos(67, 0, true, false);
    // style_button_for_emojis.size = set_size(34, 100, true, true);
    // style_button_for_emojis.anchor = ANCHOR_TOP_LEFT;
    // style_button_for_emojis.background_color = set_color(31, 32, 44, 255);


    style_t style_button_for_games_title = set_clear_style();
    style_button_for_games_title.position = set_pos(50, 50, true, true);
    style_button_for_games_title.size = set_size(100, 14, true, false);
    style_button_for_games_title.anchor = ANCHOR_CENTER_CENTER;
    style_button_for_games_title.text_content = "GAMES";
    style_button_for_games_title.text_anchor = ANCHOR_CENTER_CENTER;
    style_button_for_games_title.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_button_for_stickers_title = set_clear_style();
    style_button_for_stickers_title.position = set_pos(50, 50, true, true);
    style_button_for_stickers_title.size = set_size(100, 14, true, false);
    style_button_for_stickers_title.anchor = ANCHOR_CENTER_CENTER;
    style_button_for_stickers_title.text_content = "STICKERS";
    style_button_for_stickers_title.text_anchor = ANCHOR_CENTER_CENTER;
    style_button_for_stickers_title.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    // style_t style_button_for_emojis_title = set_clear_style();
    // style_button_for_emojis_title.position = set_pos(50, 25, true, false);
    // style_button_for_emojis_title.size = set_size(100, 14, true, false);
    // style_button_for_emojis_title.anchor = ANCHOR_TOP_CENTER;
    // style_button_for_emojis_title.text_content = "EMOJIS";
    // style_button_for_emojis_title.text_anchor = ANCHOR_CENTER_CENTER;
    // style_button_for_emojis_title.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_container_add_file = set_clear_style();
    style_container_add_file.position = set_pos(0, 0, false, false);
    style_container_add_file.size = set_size(52, 52, false, false);
    style_container_add_file.anchor = ANCHOR_TOP_LEFT;
    style_container_add_file.padding = set_pad(14, 0, 0, 0);
    style_container_add_file.background_color = set_color(31, 32, 44, 255);
    //style_container_add_file.background_color = set_color(241, 232, 44, 255);
    style_container_add_file.is_static = true;

    style_t style_container_enter_message = set_clear_style();
    style_container_enter_message.position = set_pos(0, 0, false, false);
    style_container_enter_message.size = set_size(100, 100, true, true);
    style_container_enter_message.anchor = ANCHOR_TOP_LEFT;
    style_container_enter_message.background_color = set_color(31, 32, 44, 255);
    //style_container_enter_message.background_color = set_color(31, 22, 144, 255);

    style_t style_container_send_message = set_clear_style();
    style_container_send_message.position = set_pos(100, 0, true, false);
    style_container_send_message.size = set_size(52, 52, false, false);
    style_container_send_message.anchor = ANCHOR_TOP_RIGHT;
    style_container_send_message.padding = set_pad(0, 14, 0, 0);
    style_container_send_message.background_color = set_color(31, 32, 44, 255);
    //style_container_send_message.background_color = set_color(31, 232, 44, 255);
    style_container_send_message.is_static = true;

    ///Logos in sending
    style_t style_add_file_logo = set_clear_style();
    style_add_file_logo.position = set_pos(0, 50, true, true);
    style_add_file_logo.size = set_size(24, 24, false, false);
    style_add_file_logo.anchor = ANCHOR_CENTER_LEFT;
    style_add_file_logo.texture = render_texture(app, "resource/img/add_file.png");

    style_t style_enter_message_text = set_clear_style();
    style_enter_message_text.position = set_pos(0, 50, false, true);
    style_enter_message_text.size = set_size(100, 100, true, true);
    style_enter_message_text.anchor = ANCHOR_CENTER_LEFT;
    style_enter_message_text.padding = set_pad(14, 0, 0, 0);
    style_enter_message_text.text_content = "Write a message...";
    style_enter_message_text.text_anchor = ANCHOR_CENTER_LEFT;
    style_enter_message_text.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_send_message_logo = set_clear_style();
    style_send_message_logo.position = set_pos(100, 50, true, true);
    style_send_message_logo.size = set_size(24, 24, false, false);
    style_send_message_logo.anchor = ANCHOR_CENTER_RIGHT;
    style_send_message_logo.texture = render_texture(app, "resource/img/send.png");


    ////Chat bar  look

    // style_t style_enter_message_text = set_clear_style();
    // style_enter_message_text.position = set_pos(0, 50, false, true);
    // style_enter_message_text.size = set_size(100, 100, true, true);
    // style_enter_message_text.anchor = ANCHOR_CENTER_LEFT;
    // style_enter_message_text.padding = set_pad(14, 0, 0, 0);
    // style_enter_message_text.text_content = "Write a message...";
    // style_enter_message_text.text_anchor = ANCHOR_CENTER_LEFT;
    // style_enter_message_text.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    

    ////Chat info bar

    style_t style_container_chat_buttons = set_clear_style();
    style_container_chat_buttons.position = set_pos(100, 0, true, false);
    style_container_chat_buttons.size = set_size(190, 100, false, true);
    style_container_chat_buttons.anchor = ANCHOR_TOP_RIGHT;
    style_container_chat_buttons.padding = set_pad(0, 0, 0, 0);
    //style_container_chat_buttons.background_color = set_color(255, 255, 255, 255);

    style_t style_container_leave_chat = set_clear_style();
    style_container_leave_chat.position = set_pos(0, 0, false, false);
    style_container_leave_chat.size = set_size(72, 52, false, false);
    style_container_leave_chat.anchor = ANCHOR_TOP_LEFT;

    style_t style_container_chat_menu = set_clear_style();
    style_container_chat_menu.position = set_pos(86, 0, false, false);
    style_container_chat_menu.size = set_size(52, 52, false, false);
    style_container_chat_menu.anchor = ANCHOR_TOP_LEFT;

    style_t style_container_sidebar = set_clear_style();
    style_container_sidebar.position = set_pos(138, 0, false, false);
    style_container_sidebar.size = set_size(52, 52, false, false);
    style_container_sidebar.anchor = ANCHOR_TOP_LEFT;


    /////LEAVE BUTTON

    style_t style_leave_chat_button = set_clear_style();
    style_leave_chat_button.position = set_pos(50, 50, true, true);
    style_leave_chat_button.size = set_size(72, 25, false, false);
    style_leave_chat_button.anchor = ANCHOR_CENTER_CENTER;
    style_leave_chat_button.background_color = set_color(62, 67, 101, 255);
    style_leave_chat_button.text_content = "LEAVE";
    style_leave_chat_button.text_anchor = ANCHOR_CENTER_CENTER;
    style_leave_chat_button.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    style_t style_chat_menu_logo = set_clear_style();
    style_chat_menu_logo.position = set_pos(50, 50, true, true);
    style_chat_menu_logo.size = set_size(24, 24, false, false);
    style_chat_menu_logo.anchor = ANCHOR_CENTER_CENTER;
    style_chat_menu_logo.texture = render_texture(app, "resource/img/menu.png");

    style_t style_sidebar_logo = set_clear_style();
    style_sidebar_logo.position = set_pos(50, 50, true, true);
    style_sidebar_logo.size = set_size(24, 24, false, false);
    style_sidebar_logo.anchor = ANCHOR_CENTER_CENTER;
    style_sidebar_logo.texture = render_texture(app, "resource/img/sidebar.png");

    //Cop & Past Inc. Server

    style_t style_container_server_logo = set_clear_style();
    style_container_server_logo.position = set_pos(0, 0, false, false);
    style_container_server_logo.size = set_size(52, 100, false, true);
    style_container_server_logo.anchor = ANCHOR_TOP_LEFT;
    style_container_server_logo.is_static = true;


    style_t style_container_server_name = set_clear_style();
    style_container_server_name.position = set_pos(52, 0, false, false);
    style_container_server_name.size = set_size(50, 100, true, true);
    style_container_server_name.anchor = ANCHOR_TOP_LEFT;

    style_t style_container_server_online = set_clear_style();
    style_container_server_online.position = set_pos(100, 0, true, false);
    style_container_server_online.size = set_size(118, 100, false, true);
    style_container_server_online.anchor = ANCHOR_TOP_RIGHT;
    style_container_server_online.is_static = true;

    style_t style_server_logo = set_clear_style();
    style_server_logo.position = set_pos(50, 15, true, false);
    style_server_logo.size = set_size(24, 24, false, false);
    style_server_logo.anchor = ANCHOR_TOP_CENTER;
    style_server_logo.texture = render_texture(app, "resource/img/server.png");

    style_t style_server_name = set_clear_style();
    style_server_name.position = set_pos(0, 50, false, true);
    style_server_name.size = set_size(100, 100, true, true);
    style_server_name.anchor = ANCHOR_CENTER_LEFT;
    style_server_name.padding = set_pad(0, 0, 0, 0);
    style_server_name.text_content = "Cop & Past Inc. Server";
    style_server_name.text_anchor = ANCHOR_CENTER_LEFT;
    style_server_name.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_server_online = set_clear_style();
    style_server_online.position = set_pos(0, 50, false, true);
    style_server_online.size = set_size(100, 100, true, true);
    style_server_online.anchor = ANCHOR_CENTER_LEFT;
    style_server_online.padding = set_pad(0, 14, 0, 0);
    style_server_online.text_content = "345 / 567 online";
    style_server_online.text_anchor = ANCHOR_CENTER_LEFT;
    style_server_online.font = set_font(FONT_ROBOTO_REGULAR_14, set_color(255, 255, 255, 150));


    ////User status/settings

    style_t style_container_user = set_clear_style();
    style_container_user.position = set_pos(0, 0, true, true);
    style_container_user.size = set_size(100, 64, true, false);
    style_container_user.anchor = ANCHOR_TOP_LEFT;
    style_container_user.background_color = set_color(24, 26, 41, 255);


    style_t style_container_user_icon = set_clear_style();
    style_container_user_icon.position = set_pos(0, 0, true, false);
    style_container_user_icon.size = set_size(20, 100, true, true);
    style_container_user_icon.anchor = ANCHOR_TOP_LEFT;


    style_t style_container_username_status = set_clear_style();
    style_container_username_status.position = set_pos(20, 0, true, false);
    style_container_username_status.size = set_size(50, 100, true, true);
    style_container_username_status.anchor = ANCHOR_TOP_LEFT;
    //style_container_username_status.background_color = set_color(255, 0, 255, 255);

    style_t style_container_search = set_clear_style();
    style_container_search.position = set_pos(70, 0, true, false);
    style_container_search.size = set_size(15, 100, true, true);
    style_container_search.anchor = ANCHOR_TOP_LEFT;

    style_t style_container_settings = set_clear_style();
    style_container_settings.position = set_pos(85, 0, true, false);
    style_container_settings.size = set_size(15, 100, true, true);
    style_container_settings.anchor = ANCHOR_TOP_LEFT;

    style_t style_search_logo = set_clear_style();
    style_search_logo.position = set_pos(50, 15, true, false);
    style_search_logo.size = set_size(24, 24, false, false);
    style_search_logo.anchor = ANCHOR_TOP_CENTER;
    style_search_logo.texture = render_texture(app, "resource/img/search.png");

    style_t style_settings_logo = set_clear_style();
    style_settings_logo.position = set_pos(50, 15, true, false);
    style_settings_logo.size = set_size(24, 24, false, false);
    style_settings_logo.anchor = ANCHOR_TOP_CENTER;
    style_settings_logo.texture = render_texture(app, "resource/img/settings.png");
    
    //User icon
    style_t style_user_icon = set_clear_style();
    style_user_icon.position = set_pos(50, 15, true, false);
    style_user_icon.size = set_size(40, 40, false, false);
    style_user_icon.anchor = ANCHOR_TOP_CENTER;
    style_user_icon.texture = render_texture(app, "resource/img/user_avatar.png");

    //Username/status


    style_t style_container_username = set_clear_style();
    style_container_username.position = set_pos(0, 0, true, false);
    style_container_username.size = set_size(100, 50, true, true);
    style_container_username.anchor = ANCHOR_TOP_LEFT;
    //style_container_username.background_color = set_color(255, 0, 255, 255);

    style_t style_container_user_status = set_clear_style();
    style_container_user_status.position = set_pos(0, 50, false, true);
    style_container_user_status.size = set_size(100, 50, true, true);
    style_container_user_status.anchor = ANCHOR_TOP_LEFT;
    //style_container_user_status.background_color = set_color(255, 255, 255, 255);

    style_t style_username = set_clear_style();
    style_username.position = set_pos(0, 10, false, true);
    style_username.size = set_size(100, 100, true, true);
    style_username.anchor = ANCHOR_TOP_LEFT;
    style_username.padding = set_pad(0, 15, 0, 0);
    style_username.text_content = "foldybox";
    style_username.text_anchor = ANCHOR_CENTER_LEFT;
    style_username.font = set_font(FONT_ROBOTO_REGULAR_14, set_color(255, 255, 255, 255));

    style_t style_user_status = set_clear_style();
    style_user_status.position = set_pos(0, 50, false, true);
    style_user_status.size = set_size(100, 100, true, true);
    style_user_status.anchor = ANCHOR_CENTER_LEFT;
    style_user_status.padding = set_pad(0, 0, 10, 0);
    style_user_status.text_content = "Never gonna give you up";
    style_user_status.text_anchor = ANCHOR_CENTER_LEFT;
    style_user_status.font = set_font(FONT_ROBOTO_REGULAR_14, set_color(255, 255, 255, 150));



    /////PROTOTYPE OF DIRECT

    //main container
    style_t style_container_for_chats = set_clear_style();
    style_container_for_chats.position = set_pos(0, 130, true, false);
    style_container_for_chats.size = set_size(100, 100, true, true);
    style_container_for_chats.anchor = ANCHOR_TOP_LEFT;
    style_container_for_chats.background_color = set_color(255, 0, 255, 255);

    style_t style_container_for_messagebar = set_clear_style();
    style_container_for_messagebar.position = set_pos(0, 0, true, false);
    style_container_for_messagebar.size = set_size(100, 64, true, false);
    style_container_for_messagebar.anchor = ANCHOR_TOP_LEFT;
    // style_container_for_messagebar.background_color = set_color(255, 255, 255, 255);

    style_t style_container_username_message = set_clear_style();
    style_container_username_message.position = set_pos(0, 0, true, false);
    style_container_username_message.size = set_size(85, 100, true, true);
    style_container_username_message.anchor = ANCHOR_TOP_LEFT;
    style_container_username_message.background_color = set_color(31, 32, 44, 255);

    style_t style_container_time = set_clear_style();
    style_container_time.position = set_pos(85, 0, true, false);
    style_container_time.size = set_size(15, 100, true, true);
    style_container_time.anchor = ANCHOR_TOP_LEFT;
    //style_container_time.background_color = set_color(255, 255, 255, 255);

    style_t style_chat_username = set_clear_style();
    style_chat_username.position = set_pos(0, 50, false, true);
    style_chat_username.size = set_size(100, 100, true, true);
    style_chat_username.anchor = ANCHOR_CENTER_LEFT;
    style_chat_username.padding = set_pad(14, 0, 0, 0);
    style_chat_username.text_content = "Immanuel Kant";
    style_chat_username.text_anchor = ANCHOR_CENTER_LEFT;
    style_chat_username.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    style_t style_users_message = set_clear_style();
    style_users_message.position = set_pos(0, 50, false, true);
    style_users_message.size = set_size(100, 100, true, true);
    style_users_message.anchor = ANCHOR_CENTER_LEFT;
    style_users_message.padding = set_pad(14, 0, 10, 0);
    style_users_message.text_content = "foldybox: Welcome!";
    style_users_message.text_anchor = ANCHOR_CENTER_LEFT;
    style_users_message.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_container_chat_username = set_clear_style();
    style_container_chat_username.position = set_pos(0, 0, true, false);
    style_container_chat_username.size = set_size(100, 50, true, true);
    style_container_chat_username.anchor = ANCHOR_TOP_LEFT;
    //style_container_chat_username.background_color = set_color(255, 0, 255, 255);

    style_t style_container_users_message = set_clear_style();
    style_container_users_message.position = set_pos(0, 50, true, true);
    style_container_users_message.size = set_size(100, 50, true, true);
    style_container_users_message.anchor = ANCHOR_TOP_LEFT;
    //style_container_users_message.background_color = set_color(255, 255, 255, 255);

    style_t style_messaged_time = set_clear_style();
    style_messaged_time.position = set_pos(0, 50, false, true);
    style_messaged_time.size = set_size(100, 100, true, true);
    style_messaged_time.anchor = ANCHOR_CENTER_LEFT;
    style_messaged_time.padding = set_pad(0, 0, 0, 0);
    style_messaged_time.text_content = "17:34";
    style_messaged_time.text_anchor = ANCHOR_CENTER_CENTER;
    style_messaged_time.font = set_font(FONT_ROBOTO_REGULAR_14, set_color(255, 255, 255, 150));

    style_t style_container_chat_name_online = set_clear_style();
    style_container_chat_name_online.position = set_pos(0, 0, true, false);
    style_container_chat_name_online.size = set_size(70, 100, true, true);
    style_container_chat_name_online.anchor = ANCHOR_TOP_LEFT;
    style_container_chat_name_online.padding = set_pad(0, 0, 0, 0);
    //style_container_chat_name_online.background_color = set_color(255, 150, 255, 255);

    style_t style_container_chat_chat_name = set_clear_style();
    style_container_chat_chat_name.position = set_pos(0, 0, true, false);
    style_container_chat_chat_name.size = set_size(100, 50, true, true);
    style_container_chat_chat_name.anchor = ANCHOR_TOP_LEFT;
    //style_container_chat_chat_name.background_color = set_color(255, 0, 255, 255);

    style_t style_container_chat_online = set_clear_style();
    style_container_chat_online.position = set_pos(0, 50, true, true);
    style_container_chat_online.size = set_size(100, 50, true, true);
    style_container_chat_online.anchor = ANCHOR_TOP_LEFT;
    //style_container_chat_online.background_color = set_color(255, 255, 255, 255);

    style_t style_chat_chat_name = set_clear_style();
    style_chat_chat_name.position = set_pos(0, 50, false, true);
    style_chat_chat_name.size = set_size(100, 100, true, true);
    style_chat_chat_name.anchor = ANCHOR_CENTER_LEFT;
    style_chat_chat_name.padding = set_pad(14, 10, 0, 0);
    style_chat_chat_name.text_content = "Greating room";
    style_chat_chat_name.text_anchor = ANCHOR_CENTER_LEFT;
    style_chat_chat_name.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    style_t style_chat_online = set_clear_style();
    style_chat_online.position = set_pos(0, 50, false, true);
    style_chat_online.size = set_size(100, 100, true, true);
    style_chat_online.anchor = ANCHOR_CENTER_LEFT;
    style_chat_online.padding = set_pad(14, 0, 10, 0);
    style_chat_online.text_content = "34 / 99 online";
    style_chat_online.text_anchor = ANCHOR_CENTER_LEFT;
    style_chat_online.font = set_font(FONT_ROBOTO_REGULAR_14, set_color(255, 255, 255, 150));

    style_t style_game_container = set_clear_style();
    style_game_container.position = set_pos(0, 0, true, true);
    style_game_container.size = set_size(100, 128, true, false);
    style_game_container.padding.left = 128;
    style_game_container.anchor = ANCHOR_TOP_LEFT;
    // style_game_container.background_color = set_color(255, 255, 255, 255);

    style_t style_game_icon_container = set_clear_style();
    style_game_icon_container.position = set_pos(0, 0, true, false);
    style_game_icon_container.size = set_size(128, 100, false, true);
    style_game_icon_container.anchor = ANCHOR_TOP_LEFT;
    //style_game_icon_container.background_color = set_color(255, 255, 0, 255);
    style_game_icon_container.is_static = true;


    style_t style_game_container_description = set_clear_style();
    style_game_container_description.position = set_pos(0, 0, true, false);
    style_game_container_description.size = set_size(100, 100, true, true);
    style_game_container_description.anchor = ANCHOR_TOP_LEFT;
    //style_game_container_description.background_color = set_color(255, 255, 255, 255); style_game_icon

    style_t style_game_icon = set_clear_style();
    style_game_icon.position = set_pos(14, 14, true, false);
    style_game_icon.size = set_size(100, 100, false, false);
    style_game_icon.anchor = ANCHOR_TOP_LEFT;
    style_game_icon.texture = render_texture(app, "resource/img/game_icon.png");

    style_t style_game_container_gamename = set_clear_style();
    style_game_container_gamename.position = set_pos(0, 0, true, true);
    style_game_container_gamename.size = set_size(100, 25, true, true);
    style_game_container_gamename.anchor = ANCHOR_TOP_LEFT;
    //style_game_container_gamename.background_color = set_color(0, 255, 255, 255);

    style_t style_game_container_gamedescription = set_clear_style();
    style_game_container_gamedescription.position = set_pos(0, 25, true, true);
    style_game_container_gamedescription.size = set_size(100, 50, true, true);
    style_game_container_gamedescription.anchor = ANCHOR_TOP_LEFT;
    //style_game_container_gamedescription.background_color = set_color(255, 255, 255, 255);

    style_t style_game_container_gameplayers = set_clear_style();
    style_game_container_gameplayers.position = set_pos(0, 75, true, true);
    style_game_container_gameplayers.size = set_size(100, 25, true, true);
    style_game_container_gameplayers.anchor = ANCHOR_TOP_LEFT;
    //style_game_container_gameplayers.background_color = set_color(255, 255, 0, 255);

    style_t style_game_gamename = set_clear_style();
    style_game_gamename.position = set_pos(0, 50, false, true);
    style_game_gamename.size = set_size(100, 100, true, true);
    style_game_gamename.anchor = ANCHOR_CENTER_LEFT;
    style_game_gamename.text_content = "Super game for all";
    style_game_gamename.text_anchor = ANCHOR_BOTTOM_LEFT;
    style_game_gamename.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    style_t style_game_gamedescription = set_clear_style();
    style_game_gamedescription.position = set_pos(0, 50, false, true);
    style_game_gamedescription.size = set_size(100, 100, true, true);
    style_game_gamedescription.anchor = ANCHOR_CENTER_LEFT;
    style_game_gamedescription.text_content = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    style_game_gamedescription.text_anchor = ANCHOR_CENTER_LEFT;
    style_game_gamedescription.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 150));

    style_t style_game_gameplayers = set_clear_style();
    style_game_gameplayers.position = set_pos(0, 50, false, true);
    style_game_gameplayers.size = set_size(100, 100, true, true);
    style_game_gameplayers.anchor = ANCHOR_CENTER_LEFT;
    style_game_gameplayers.text_content = "4-5 players";
    style_game_gameplayers.text_anchor = ANCHOR_TOP_LEFT;
    style_game_gameplayers.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 75));




    /////BASE CONTAINERS/////
    object_add("container", app->root, &style_container, NULL, NULL, NULL, NULL);
    object_add("container_1", object_search_byid("container", app->root), &style_container_1, NULL, NULL, NULL, NULL);
    object_add("container_2", object_search_byid("container", app->root), &style_container_2, NULL, NULL, NULL, NULL);
    object_add("container_3", object_search_byid("container", app->root), &style_container_3, NULL, NULL, NULL, NULL);

    object_add("chats_1", object_search_byid("container_1", app->root), &style_chats_1, NULL, NULL, NULL, NULL);
    object_add("chats_2", object_search_byid("container_1", app->root), &style_chats_2, NULL, NULL, NULL, NULL);
    object_add("chats_3", object_search_byid("container_1", app->root), &style_chats_3, NULL, NULL, NULL, NULL);

    object_add("messages_1", object_search_byid("container_2", app->root), &style_messages_1, NULL, NULL, NULL, NULL);
    object_add("messages_2", object_search_byid("container_2", app->root), &style_messages_2, NULL, NULL, NULL, NULL);
    object_add("messages_3", object_search_byid("container_2", app->root), &style_messages_3, NULL, NULL, NULL, NULL);

    object_add("games_1", object_search_byid("container_3", app->root), &style_games_1, NULL, NULL, NULL, NULL);
    object_add("games_2", object_search_byid("container_3", app->root), &style_games_2, NULL, NULL, NULL, NULL);


    // ////Rooms/Direct button
    // object_add("chats_ls_bar", object_search_byid("container_1", app->root), &style_chats_ls_bar, NULL, NULL, NULL, NULL);


    // object_add("container_for_chats", object_search_byid("container_1", app->root), &style_container_for_chats, NULL, NULL, NULL, NULL);


    // ////***Container for user/status/search/settings***////
    object_add("container_user", object_search_byid("chats_1", app->root), &style_container_user, NULL, NULL, NULL, NULL);
    object_add("container_user_icon", object_search_byid("container_user", app->root), &style_container_user_icon, NULL, NULL, NULL, NULL);
    object_add("container_username_status", object_search_byid("container_user", app->root), &style_container_username_status, NULL, NULL, NULL, NULL);
    object_add("container_search", object_search_byid("container_user", app->root), &style_container_search, NULL, NULL, NULL, NULL);
    object_add("container_settings", object_search_byid("container_user", app->root), &style_container_settings, NULL, NULL, NULL, NULL);
    object_add("search_logo", object_search_byid("container_search", app->root), &style_search_logo, NULL, NULL, NULL, NULL);
    object_add("settings_logo", object_search_byid("container_settings", app->root), &style_settings_logo, NULL, NULL, NULL, NULL);
    object_add("user_icon", object_search_byid("container_user_icon", app->root), &style_user_icon, NULL, NULL, NULL, NULL);
    object_add("container_username", object_search_byid("container_username_status", app->root), &style_container_username, NULL, NULL, NULL, NULL);
    object_add("container_user_status", object_search_byid("container_username_status", app->root), &style_container_user_status, NULL, NULL, NULL, NULL);
    object_add("username", object_search_byid("container_username", app->root), &style_username, NULL, NULL, NULL, NULL);
    object_add("user_status", object_search_byid("container_user_status", app->root), &style_user_status, NULL, NULL, NULL, NULL);





    object_add("container_for_rooms_ls", object_search_byid("chats_1", app->root), &style_container_for_rooms_ls, NULL, NULL, NULL, NULL);

    object_add("button_for_rooms", object_search_byid("container_for_rooms_ls", app->root), &style_button_for_rooms, NULL, NULL, NULL, NULL);
    object_add("button_for_ls", object_search_byid("container_for_rooms_ls", app->root), &style_button_for_ls, NULL, NULL, NULL, NULL);
    object_add("button_for_rooms_logo", object_search_byid("button_for_rooms", app->root), &style_button_for_rooms_logo, NULL, NULL, NULL, NULL);
    object_add("button_for_rooms_title", object_search_byid("button_for_rooms", app->root), &style_button_for_rooms_title, NULL, NULL, NULL, NULL);
    object_add("button_for_ls_logo", object_search_byid("button_for_ls", app->root), &style_button_for_ls_logo, NULL, NULL, NULL, NULL);
    object_add("button_for_ls_title", object_search_byid("button_for_ls", app->root), &style_button_for_ls_title, NULL, NULL, NULL, NULL);

    //Chat list
    object_add("container_for_messagebar", object_search_byid("chats_2", app->root), &style_container_for_messagebar, NULL, NULL, NULL, NULL);
    object_add("container_username_message", object_search_byid("container_for_messagebar", app->root), &style_container_username_message, NULL, NULL, NULL, NULL);
    object_add("container_time", object_search_byid("container_for_messagebar", app->root), &style_container_time, NULL, NULL, NULL, NULL);
    object_add("container_chat_username", object_search_byid("container_username_message", app->root), &style_container_chat_username, NULL, NULL, NULL, NULL);
    object_add("container_users_message", object_search_byid("container_username_message", app->root), &style_container_users_message, NULL, NULL, NULL, NULL);
    object_add("chat_username", object_search_byid("container_chat_username", app->root), &style_chat_username, NULL, NULL, NULL, NULL);
    object_add("users_message", object_search_byid("container_users_message", app->root), &style_users_message, NULL, NULL, NULL, NULL);
    object_add("messaged_time", object_search_byid("container_time", app->root), &style_messaged_time, NULL, NULL, NULL, NULL);

    ////Cop & Past Inc. Server
    //object_add("container_for_server", object_search_byid("container_1", app->root), &style_container_for_server, NULL, NULL, NULL, NULL);
    object_add("container_server_logo", object_search_byid("chats_3", app->root), &style_container_server_logo, NULL, NULL, NULL, NULL);
    object_add("container_server_name", object_search_byid("chats_3", app->root), &style_container_server_name, NULL, NULL, NULL, NULL);
    object_add("container_server_online", object_search_byid("chats_3", app->root), &style_container_server_online, NULL, NULL, NULL, NULL);
    object_add("server_logo", object_search_byid("container_server_logo", app->root), &style_server_logo, NULL, NULL, NULL, NULL);
    object_add("server_name", object_search_byid("container_server_name", app->root), &style_server_name, NULL, NULL, NULL, NULL);
    object_add("server_online", object_search_byid("container_server_online", app->root), &style_server_online, NULL, NULL, NULL, NULL);



    ////Side bar for games, stickers, emojis
    // object_add("container_for_entertainments", object_search_byid("container_3", app->root), &style_container_for_entertainments, NULL, NULL, NULL, NULL);
    object_add("button_for_games", object_search_byid("games_1", app->root), &style_button_for_games, NULL, NULL, NULL, NULL);
    object_add("button_for_skickers", object_search_byid("games_1", app->root), &style_button_for_skickers, NULL, NULL, NULL, NULL);
    object_add("button_for_games_title", object_search_byid("button_for_games", app->root), &style_button_for_games_title, NULL, NULL, NULL, NULL);
    object_add("button_for_stickers_title", object_search_byid("button_for_skickers", app->root), &style_button_for_stickers_title, NULL, NULL, NULL, NULL);
    object_add("game_container", object_search_byid("games_2", app->root), &style_game_container, NULL, NULL, NULL, NULL);
    object_add("game_icon_container", object_search_byid("game_container", app->root), &style_game_icon_container, NULL, NULL, NULL, NULL);
    object_add("game_container_description", object_search_byid("game_container", app->root), &style_game_container_description, NULL, NULL, NULL, NULL);
    object_add("game_icon", object_search_byid("game_icon_container", app->root), &style_game_icon, NULL, NULL, NULL, NULL);
    object_add("game_container_gamename", object_search_byid("game_container_description", app->root), &style_game_container_gamename, NULL, NULL, NULL, NULL);
    object_add("game_container_gamedescription", object_search_byid("game_container_description", app->root), &style_game_container_gamedescription, NULL, NULL, NULL, NULL);
    object_add("game_container_gameplayers", object_search_byid("game_container_description", app->root), &style_game_container_gameplayers, NULL, NULL, NULL, NULL);
    object_add("game_gamename", object_search_byid("game_container_gamename", app->root), &style_game_gamename, NULL, NULL, NULL, NULL);
    object_add("game_gamedescription", object_search_byid("game_container_gamedescription", app->root), &style_game_gamedescription, NULL, NULL, NULL, NULL);
    object_add("game_gameplayers", object_search_byid("game_container_gameplayers", app->root), &style_game_gameplayers, NULL, NULL, NULL, NULL);



    ////Bar for chat info
    // object_add("chat_bar", object_search_byid("container_2", app->root), &style_chat_bar, NULL, NULL, NULL, NULL);

    object_add("container_chat_buttons", object_search_byid("messages_1", app->root), &style_container_chat_buttons, NULL, NULL, NULL, NULL);
    object_add("container_chat_name_online", object_search_byid("messages_1", app->root), &style_container_chat_name_online, NULL, NULL, NULL, NULL);
    object_add("container_chat_chat_name", object_search_byid("container_chat_name_online", app->root), &style_container_chat_chat_name, NULL, NULL, NULL, NULL);
    object_add("container_chat_online", object_search_byid("container_chat_name_online", app->root), &style_container_chat_online, NULL, NULL, NULL, NULL);
    object_add("container_leave_chat", object_search_byid("container_chat_buttons", app->root), &style_container_leave_chat, NULL, NULL, NULL, NULL);
    object_add("container_chat_menu", object_search_byid("container_chat_buttons", app->root), &style_container_chat_menu, NULL, NULL, NULL, NULL);
    object_add("container_sidebar", object_search_byid("container_chat_buttons", app->root), &style_container_sidebar, NULL, NULL, NULL, NULL);
    object_add("leave_chat_button", object_search_byid("container_leave_chat", app->root), &style_leave_chat_button, NULL, NULL, NULL, NULL);
    //object_add("leave_chat_button_text", object_search_byid("leave_chat_button", app->root), &style_leave_chat_button_text, NULL, NULL, NULL, NULL);
    object_add("chat_menu_logo", object_search_byid("container_chat_menu", app->root), &style_chat_menu_logo, NULL, NULL, NULL, NULL);
    object_add("sidebar_logo", object_search_byid("container_sidebar", app->root), &style_sidebar_logo, NULL, NULL, NULL, NULL);
    object_add("chat_chat_name", object_search_byid("container_chat_chat_name", app->root), &style_chat_chat_name, NULL, NULL, NULL, NULL);
    object_add("chat_online", object_search_byid("container_chat_online", app->root), &style_chat_online, NULL, NULL, NULL, NULL);


    // ////Sending message
    // object_add("container_for_entering_messeges", object_search_byid("container_2", app->root), &style_container_for_entering_messeges, NULL, NULL, NULL, NULL);
    object_add("container_add_file", object_search_byid("messages_3", app->root), &style_container_add_file, NULL, NULL, NULL, NULL);
    object_add("container_enter_message", object_search_byid("messages_3", app->root), &style_container_enter_message, NULL, NULL, NULL, NULL);
    object_add("container_send_message", object_search_byid("messages_3", app->root), &style_container_send_message, NULL, NULL, NULL, NULL);
    object_add("add_file_logo", object_search_byid("container_add_file", app->root), &style_add_file_logo, NULL, NULL, NULL, NULL);
    object_add("enter_message_text", object_search_byid("container_enter_message", app->root), &style_enter_message_text, NULL, NULL, NULL, NULL);
    object_add("send_message_logo", object_search_byid("container_send_message", app->root), &style_send_message_logo, NULL, NULL, NULL, NULL);


    

}

void scene_prepare(app_t* app) {
	SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);
	SDL_RenderClear(app->renderer);
}

void scene_update(app_t* app) {
    object_hierarchy_exec(app, app->root, object_update);
}

void scene_draw(app_t* app) {
    for (int i = 0; i < 16; i++) {
        object_hierarchy_search_n_exec_byzindex(app, app->root, object_draw, i);
    }
}

void scene_present(app_t* app) {
	SDL_RenderPresent(app->renderer);
}

void scene_free(app_t* app) {

}
