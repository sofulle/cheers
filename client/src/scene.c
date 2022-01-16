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
    // style_t style_background = set_clear_style();
    // style_background.position = set_pos(0, 0, false, false);
    // style_background.size = set_size(100, 100, true, true);
    // style_background.anchor = ANCHOR_TOP_LEFT;
    // style_background.background_color = set_color(62, 67, 101, 255);

    style_t style_container = set_clear_style();
    style_container.size = set_size(100, 100, true, true);
    style_container.anchor = ANCHOR_TOP_LEFT;
    style_container.background_color = set_color(62, 67, 101, 255);
    style_container.z_index = 1;

    style_t style_container_1 = set_clear_style();
    style_container_1.position = set_pos(0, 0, true, false);
    style_container_1.size = set_size(20, 100, true, true);
    style_container_1.anchor = ANCHOR_TOP_LEFT;
    style_container_1.background_color = set_color(31, 32, 44, 255); //white


    style_t style_container_2 = set_clear_style();
    style_container_2.position = set_pos(20, 0, true, false);
    style_container_2.size = set_size(60, 100, true, true);
    style_container_2.anchor = ANCHOR_TOP_LEFT;
    style_container_2.background_color = set_color(57, 61, 85, 255); //red

    style_t style_container_3 = set_clear_style();
    style_container_3.position = set_pos(80, 0, true, false);
    style_container_3.size = set_size(20, 100, true, true);
    style_container_3.anchor = ANCHOR_TOP_LEFT;
    style_container_3.background_color = set_color(31, 32, 44, 255);

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



    object_add("container", app->root, &style_container, NULL, NULL, NULL, NULL);
    object_add("container_1", object_search_byid("container", app->root), &style_container_1, NULL, NULL, NULL, NULL);
    object_add("container_2", object_search_byid("container", app->root), &style_container_2, NULL, NULL, NULL, NULL);
    object_add("container_3", object_search_byid("container", app->root), &style_container_3, NULL, NULL, NULL, NULL);
    object_add("chats_ls_bar", object_search_byid("container_1", app->root), &style_chats_ls_bar, NULL, NULL, NULL, NULL);
    object_add("container_for_rooms_ls", object_search_byid("chats_ls_bar", app->root), &style_container_for_rooms_ls, NULL, NULL, NULL, NULL);
    ////Rooms/Direct button
    object_add("button_for_rooms", object_search_byid("container_for_rooms_ls", app->root), &style_button_for_rooms, NULL, NULL, NULL, NULL);
    object_add("button_for_ls", object_search_byid("container_for_rooms_ls", app->root), &style_button_for_ls, NULL, NULL, NULL, NULL);
    object_add("button_for_rooms_logo", object_search_byid("button_for_rooms", app->root), &style_button_for_rooms_logo, NULL, NULL, NULL, NULL);
    object_add("button_for_rooms_title", object_search_byid("button_for_rooms", app->root), &style_button_for_rooms_title, NULL, NULL, NULL, NULL);
    object_add("button_for_ls_logo", object_search_byid("button_for_ls", app->root), &style_button_for_ls_logo, NULL, NULL, NULL, NULL);
    object_add("button_for_ls_title", object_search_byid("button_for_ls", app->root), &style_button_for_ls_title, NULL, NULL, NULL, NULL);
    ////Cop & Past Inc. Server
    object_add("container_for_server", object_search_byid("container_1", app->root), &style_container_for_server, NULL, NULL, NULL, NULL);


    ////Sending message
    object_add("container_for_entering_messeges", object_search_byid("container_2", app->root), &style_container_for_entering_messeges, NULL, NULL, NULL, NULL);
    object_add("container_add_file", object_search_byid("container_for_entering_messeges", app->root), &style_container_add_file, NULL, NULL, NULL, NULL);
    object_add("container_enter_message", object_search_byid("container_for_entering_messeges", app->root), &style_container_enter_message, NULL, NULL, NULL, NULL);
    object_add("container_send_message", object_search_byid("container_for_entering_messeges", app->root), &style_container_send_message, NULL, NULL, NULL, NULL);
    object_add("add_file_logo", object_search_byid("container_add_file", app->root), &style_add_file_logo, NULL, NULL, NULL, NULL);
    object_add("enter_message_text", object_search_byid("container_enter_message", app->root), &style_enter_message_text, NULL, NULL, NULL, NULL);
    object_add("send_message_logo", object_search_byid("container_send_message", app->root), &style_send_message_logo, NULL, NULL, NULL, NULL);



    ////Side bar for games, stickers, emojis
    object_add("container_for_entertainments", object_search_byid("container_3", app->root), &style_container_for_entertainments, NULL, NULL, NULL, NULL);

    object_add("button_for_games", object_search_byid("container_for_entertainments", app->root), &style_button_for_games, NULL, NULL, NULL, NULL);
    object_add("button_for_skickers", object_search_byid("container_for_entertainments", app->root), &style_button_for_skickers, NULL, NULL, NULL, NULL);
    //object_add("button_for_emojis", object_search_byid("container_for_entertainments", app->root), &style_button_for_emojis, NULL, NULL, NULL, NULL);

    object_add("button_for_games_title", object_search_byid("button_for_games", app->root), &style_button_for_games_title, NULL, NULL, NULL, NULL);
    object_add("button_for_stickers_title", object_search_byid("button_for_skickers", app->root), &style_button_for_stickers_title, NULL, NULL, NULL, NULL);
    //object_add("button_for_emojis_title", object_search_byid("button_for_emojis", app->root), &style_button_for_emojis_title, NULL, NULL, NULL, NULL);

    ////Bar for chat info
    object_add("chat_bar", object_search_byid("container_2", app->root), &style_chat_bar, NULL, NULL, NULL, NULL);
    object_add("container_chat_buttons", object_search_byid("chat_bar", app->root), &style_container_chat_buttons, NULL, NULL, NULL, NULL);
    object_add("container_leave_chat", object_search_byid("container_chat_buttons", app->root), &style_container_leave_chat, NULL, NULL, NULL, NULL);
    object_add("container_chat_menu", object_search_byid("container_chat_buttons", app->root), &style_container_chat_menu, NULL, NULL, NULL, NULL);
    object_add("container_sidebar", object_search_byid("container_chat_buttons", app->root), &style_container_sidebar, NULL, NULL, NULL, NULL);
    object_add("leave_chat_button", object_search_byid("container_leave_chat", app->root), &style_leave_chat_button, NULL, NULL, NULL, NULL);
    //object_add("leave_chat_button_text", object_search_byid("leave_chat_button", app->root), &style_leave_chat_button_text, NULL, NULL, NULL, NULL);
    object_add("chat_menu_logo", object_search_byid("container_chat_menu", app->root), &style_chat_menu_logo, NULL, NULL, NULL, NULL);
    object_add("sidebar_logo", object_search_byid("container_sidebar", app->root), &style_sidebar_logo, NULL, NULL, NULL, NULL);


    

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
