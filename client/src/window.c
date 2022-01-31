// window.c

#include "cheers.h"

void rooms_add_click(app_t *app, object_t *object, SDL_Event *event) {
    //add_room(object_search_byid("rooms_container", app->root), 3, "Name", "Last uername", "abracadara bla bla bla");
}


void lister(app_t *app, object_t *lister) {
    int pos = 0;

    if(vector_size(&lister->children) < 1) return;
 
    for (vector_t *node = lister->children; node != NULL; node = node->next) {
        object_t *child = (object_t *)node->data;
        
        child->style.position.y = pos;
        pos = pos + child->style.size.gheight;
    }

    lister->style.size.height = pos;
}

void scroller(app_t *app, object_t *scroller) {
    object_t *container = (object_t *) scroller->children->data;

    if(!scroller->is_hovered) return;

    int scroller_top_gy = scroller->style.position.gy;
    int scroller_bottom_gy = scroller->style.position.gy + scroller->style.size.gheight;
    int new_container_top_y = container->style.position.y + (app->wheel_y * SCROLL_MULTIPLIER);
    int new_container_top_gy = scroller->style.position.gy + container->style.position.y + (app->wheel_y * SCROLL_MULTIPLIER);
    int new_container_bottom_gy = scroller->style.position.gy + container->style.position.y + container->style.size.gheight + (app->wheel_y * SCROLL_MULTIPLIER);

    if(scroller->style.size.gheight >= container->style.size.gheight) {
        container->style.position.y = 0;
        return;
    }

    if(scroller_bottom_gy > new_container_bottom_gy) container->style.position.y = -(container->style.size.gheight - scroller->style.size.gheight);
    else if(scroller_top_gy < new_container_top_gy) container->style.position.y = 0;
    else container->style.position.y = new_container_top_y;
}

static void button_submit_on_click(app_t *app, struct object_s *object, SDL_Event *event) {
    set_active_main_window(app);
}

static void button_signup_on_click(app_t *app, struct object_s *object, SDL_Event *event) {
    set_active_signup_window(app);
}

static void input_on_focus_start(app_t *app, struct object_s *object) {
    if(object->style.text_content == NULL) {
        object->style.text_content = (char *) malloc(1024 * sizeof(char));
        memset(object->style.text_content, 0, 1024 * sizeof(char));
    }
    object->style.font.color = set_color(255, 255, 255, 255);
    app->text_input_ptr = object->style.text_content;
}
static void input_on_focus_end(app_t *app, struct object_s *object) {
    app->text_input_ptr = NULL;
    if(strlen(object->style.text_content) < 1) {
        free(object->style.text_content);
        object->style.text_content = NULL;
        object->style.font.color = set_color(255, 255, 255, 150);
    }
}


void set_active_login_window(app_t *app) {
    SDL_SetWindowTitle(app->window,  "Cheers! | Log in");
    object_search_byid("login_container", app->root)->is_active = true;
    object_search_byid("signup_container", app->root)->is_active = false;
    object_search_byid("main_container", app->root)->is_active = false;
}

void set_active_signup_window(app_t *app) {
    SDL_SetWindowTitle(app->window,  "Cheers! | Sign up");
    object_search_byid("signup_container", app->root)->is_active = true;
    object_search_byid("login_container", app->root)->is_active = false;
    object_search_byid("main_container", app->root)->is_active = false;
}

void set_active_main_window(app_t *app) {
    SDL_SetWindowTitle(app->window,  APP_TITLE);
    SDL_SetWindowMinimumSize(app->window, 1360, 768);
    object_search_byid("main_container", app->root)->is_active = true;
    object_search_byid("signup_container", app->root)->is_active = false;
    object_search_byid("login_container", app->root)->is_active = false;
}

void init_login_window(app_t *app) {
    style_t main_container = set_clear_style();
    main_container.position = set_pos(0, 0, false, false);
    main_container.size = set_size(100, 100, true, true);
    main_container.anchor = ANCHOR_TOP_LEFT;

    style_t style_background = set_clear_style();
    style_background.position = set_pos(0, 0, false, false);
    style_background.size = set_size(100, 100, true, true);
    style_background.anchor = ANCHOR_TOP_LEFT;
    style_background.background_color = set_color(31, 32, 44, 255);

    style_t style_container = set_clear_style();
    style_container.position = set_pos(50, 0, true, false);
    style_container.size = set_size(250, 100, false, true);
    style_container.anchor = ANCHOR_TOP_CENTER;

    style_t style_logo = set_clear_style();
    style_logo.position = set_pos(50, 65, true, false);
    style_logo.size = set_size(80, 80, false, false);
    style_logo.anchor = ANCHOR_TOP_CENTER;
    style_logo.texture = render_texture(app, "resource/img/logo.png");

    style_t style_title = set_clear_style();
    style_title.position = set_pos(50, 165, true, false);
    style_title.size = set_size(100, 42, true, false);
    style_title.anchor = ANCHOR_TOP_CENTER;
    style_title.text_content = APP_SCREEN_TITLE;
    style_title.text_anchor = ANCHOR_CENTER_CENTER;
    style_title.font = set_font(FONT_ROBOTO_REGULAR_36, set_color(255, 255, 255, 255));

    style_t style_subtitle = set_clear_style();
    style_subtitle.position = set_pos(50, 217, true, false);
    style_subtitle.size = set_size(100, 19, true, false);
    style_subtitle.anchor = ANCHOR_TOP_CENTER;
    style_subtitle.text_content = APP_SCREEN_SUBTITLE;
    style_subtitle.text_anchor = ANCHOR_CENTER_CENTER;
    style_subtitle.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    style_t style_input_name = set_clear_style();
    style_input_name.position = set_pos(50, 264, true, false);
    style_input_name.size = set_size(100, 48, true, false);
    style_input_name.padding.left = 15;
    style_input_name.anchor = ANCHOR_TOP_CENTER;
    style_input_name.background_color = set_color(62, 67, 101, 255);
    style_input_name.text_placeholder = USERNAME_INPUT_TEXT;
    // style_input_name.text_content = (char *) malloc(1024 * sizeof(char));
    // memset(style_input_name.text_content, 0, 1024 * sizeof(char));
    style_input_name.text_anchor = ANCHOR_CENTER_LEFT;
    style_input_name.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_input_pass= set_clear_style();
    style_input_pass.position = set_pos(50, 327, true, false);
    style_input_pass.size = set_size(100, 48, true, false);
    style_input_pass.padding.left = 15;
    style_input_pass.anchor = ANCHOR_TOP_CENTER;
    style_input_pass.background_color = set_color(62, 67, 101, 255);
    style_input_pass.text_placeholder = PASSWORD_INPUT_TEXT;
    style_input_pass.text_anchor = ANCHOR_CENTER_LEFT;
    style_input_pass.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_button_submit = set_clear_style();
    style_button_submit.position = set_pos(50, 432, true, false);
    style_button_submit.size = set_size(90, 48, true, false);
    style_button_submit.anchor = ANCHOR_TOP_CENTER;
    style_button_submit.background_color = set_color(62, 67, 101, 255);
    style_button_submit.text_content = LOGIN_BUTTON_TEXT;
    style_button_submit.text_anchor = ANCHOR_CENTER_CENTER;
    style_button_submit.font = set_font(FONT_ROBOTO_REGULAR_18, set_color(255, 255, 255, 255));

    style_t style_button_signup = set_clear_style();
    style_button_signup.position = set_pos(50, 494, true, false);
    style_button_signup.size = set_size(90, 14, true, false);
    style_button_signup.anchor = ANCHOR_TOP_CENTER;
    style_button_signup.text_content = "Haven't account?";
    style_button_signup.text_anchor = ANCHOR_CENTER_CENTER;
    style_button_signup.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 150));

    style_t style_copyright = set_clear_style();
    style_copyright.position = set_pos(50, 100, true, true);
    style_copyright.size = set_size(100, 14, true, false);
    style_copyright.anchor = ANCHOR_BOTTOM_CENTER;
    style_copyright.padding.bottom = 20;
    style_copyright.text_content = APP_COPYRIGHT;
    style_copyright.text_anchor = ANCHOR_CENTER_CENTER;
    style_copyright.font = set_font(FONT_ROBOTO_REGULAR_12, set_color(255, 255, 255, 255));


    object_add("login_container", app->root, &main_container);
    object_add("background", object_search_byid("login_container", app->root), &style_background);
    object_add("container", object_search_byid("login_container", app->root), &style_container);
    object_add("logo", object_search_byid("container", app->root), &style_logo);
    object_add("title", object_search_byid("container", app->root), &style_title);
    object_add("subtitle", object_search_byid("container", app->root), &style_subtitle);
    object_add("input_name", object_search_byid("container", app->root), &style_input_name);
    object_add("input_pass", object_search_byid("container", app->root), &style_input_pass);
    object_add("button_submit", object_search_byid("container", app->root), &style_button_submit);
    object_add("button_signup", object_search_byid("container", app->root), &style_button_signup);
    object_add("copyright", object_search_byid("container", app->root), &style_copyright);

    object_add("signup_container", app->root, &main_container);
    object_add("signup_title", object_search_byid("signup_container", app->root), &style_title);

    //SDL_StartTextInput();

    object_search_byid("button_submit", app->root)->is_hover_reacting = true;
    object_search_byid("button_submit", app->root)->is_click_reacting = true;
    object_search_byid("button_submit", app->root)->on_click = button_submit_on_click;

    object_search_byid("button_signup", app->root)->on_click = button_signup_on_click;

    object_search_byid("input_name", app->root)->is_hover_reacting = true;
    object_search_byid("input_name", app->root)->is_click_reacting = true;
    object_search_byid("input_name", app->root)->is_focus_reacting = true;
    object_search_byid("input_name", app->root)->on_focus_start = input_on_focus_start;
    object_search_byid("input_name", app->root)->on_focus_end = input_on_focus_end;

    object_search_byid("input_pass", app->root)->is_hover_reacting = true;
    object_search_byid("input_pass", app->root)->is_click_reacting = true;
    object_search_byid("input_pass", app->root)->is_focus_reacting = true;
    object_search_byid("input_pass", app->root)->on_focus_start = input_on_focus_start;
    object_search_byid("input_pass", app->root)->on_focus_end = input_on_focus_end;
}

void init_main_window(app_t *app) {
    style_t style_container = set_clear_style();
    style_container.size = set_size(100, 100, true, true);
    style_container.anchor = ANCHOR_TOP_LEFT;
    style_container.background_color = set_color(62, 67, 101, 255);
    style_container.z_index = 1;

    style_t style_container_1 = set_clear_style();
    style_container_1.position = set_pos(0, 0, true, false);
    style_container_1.size = set_size(20, 100, true, true);
    style_container_1.anchor = ANCHOR_TOP_LEFT;
    style_container_1.padding.top = 52;
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
    style_chats_1.size = set_size(100, 52, true, false);
    style_chats_1.anchor = ANCHOR_TOP_LEFT;
    style_chats_1.background_color = set_color(24, 26, 41, 255);
    style_chats_1.is_static = true;
    style_chats_1.z_index = 1;


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
    style_enter_message_text.text_placeholder = "Write a message...";
    style_enter_message_text.text_anchor = ANCHOR_CENTER_LEFT;
    style_enter_message_text.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    style_t style_send_message_logo = set_clear_style();
    style_send_message_logo.position = set_pos(100, 50, true, true);
    style_send_message_logo.size = set_size(24, 24, false, false);
    style_send_message_logo.anchor = ANCHOR_CENTER_RIGHT;
    style_send_message_logo.texture = render_texture(app, "resource/img/send.png");



    

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

    style_t style_server_online = set_clear_style();
    style_server_online.position = set_pos(0, 50, false, true);
    style_server_online.size = set_size(100, 100, true, true);
    style_server_online.anchor = ANCHOR_CENTER_LEFT;
    style_server_online.padding = set_pad(0, 14, 0, 0);
    style_server_online.text_content = "345 / 567 online";
    style_server_online.text_anchor = ANCHOR_CENTER_LEFT;
    style_server_online.font = set_font(FONT_ROBOTO_REGULAR_14, set_color(255, 255, 255, 150));


    ////User status/settings

    style_t style_container_user_inner = set_clear_style();
    style_container_user_inner.position = set_pos(0, 50, false, true);
    style_container_user_inner.size = set_size(100, 40, true, false);
    style_container_user_inner.anchor = ANCHOR_CENTER_LEFT;
    style_container_user_inner.padding = set_pad(68, 14, 0, 0);

    style_t style_user_icon = set_clear_style();
    style_user_icon.position = set_pos(14, 0, false, false);
    style_user_icon.size = set_size(40, 40, false, false);
    style_user_icon.anchor = ANCHOR_TOP_LEFT;
    style_user_icon.texture = render_texture(app, "resource/img/user_avatar.png");
    style_user_icon.is_static= true;

    style_t style_container_username_status = set_clear_style();
    style_container_username_status.position = set_pos(0, 50, false, true);
    style_container_username_status.size = set_size(100, 35, true, false);
    style_container_username_status.anchor = ANCHOR_CENTER_LEFT;

    style_t style_username = set_clear_style();
    style_username.position = set_pos(0, 0, false, false);
    style_username.size = set_size(100, 19, true, false);
    style_username.anchor = ANCHOR_TOP_LEFT;
    style_username.text_content = "foldybox";
    style_username.text_anchor = ANCHOR_CENTER_LEFT;
    style_username.font = set_font(FONT_ROBOTO_MEDIUM_16, set_color(255, 255, 255, 255));

    style_t style_user_status = set_clear_style();
    style_user_status.position = set_pos(0, 19, false, false);
    style_user_status.size = set_size(100, 16, true, false);
    style_user_status.anchor = ANCHOR_TOP_LEFT;
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

    style_t style_container_chat_name_online = set_clear_style();
    style_container_chat_name_online.position = set_pos(0, 50, false, true);
    style_container_chat_name_online.size = set_size(70, 39, true, false);
    style_container_chat_name_online.anchor = ANCHOR_CENTER_LEFT;
    style_container_chat_name_online.padding = set_pad(14, 0, 0, 0);
    //style_container_chat_name_online.background_color = set_color(255, 150, 255, 255);

    style_t style_chat_chat_name = set_clear_style();
    style_chat_chat_name.position = set_pos(0, 0, false, false);
    style_chat_chat_name.size = set_size(100, 19, true, false);
    style_chat_chat_name.anchor = ANCHOR_TOP_LEFT;
    style_chat_chat_name.text_content = "Greating room";
    style_chat_chat_name.text_anchor = ANCHOR_CENTER_LEFT;
    style_chat_chat_name.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 255));

    style_t style_chat_online = set_clear_style();
    style_chat_online.position = set_pos(0, 23, false, false);
    style_chat_online.size = set_size(100, 16, true, false);
    style_chat_online.anchor = ANCHOR_TOP_LEFT;
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

    style_t style_rooms_container = set_clear_style();
    style_rooms_container.position = set_pos(0, 0, false, false);
    style_rooms_container.size = set_size(100, 1000, true, false);
    style_rooms_container.anchor = ANCHOR_TOP_LEFT;

    style_t style_greating_container = set_clear_style();
    style_greating_container.position = set_pos(0, 0, false, false);
    style_greating_container.size = set_size(100, 92, true, false);
    style_greating_container.padding = set_pad(0, 0, 14, 14);
    style_greating_container.anchor = ANCHOR_TOP_LEFT;

    style_t style_messages_container = set_clear_style();
    style_messages_container.position = set_pos(0, 0, false, false);
    style_messages_container.size = set_size(100, 1000, true, false);
    style_messages_container.anchor = ANCHOR_TOP_LEFT;


    /////BASE CONTAINERS/////
    object_add("main_container", app->root, &style_container);
    object_add("container_1", object_search_byid("main_container", app->root), &style_container_1);
    object_add("container_2", object_search_byid("main_container", app->root), &style_container_2);
    object_add("container_3", object_search_byid("main_container", app->root), &style_container_3);

    object_add("chats_1", object_search_byid("container_1", app->root), &style_chats_1);
    object_add("chats_2", object_search_byid("container_1", app->root), &style_chats_2);
    object_search_byid("chats_2", app->root)->on_update = scroller;
    object_add("chats_3", object_search_byid("container_1", app->root), &style_chats_3);

    object_add("messages_1", object_search_byid("container_2", app->root), &style_messages_1);
    object_add("messages_2", object_search_byid("container_2", app->root), &style_messages_2);
    object_search_byid("messages_2", app->root)->on_update = scroller;
    object_add("messages_3", object_search_byid("container_2", app->root), &style_messages_3);

    object_add("games_1", object_search_byid("container_3", app->root), &style_games_1);
    object_add("games_2", object_search_byid("container_3", app->root), &style_games_2);

    object_add("container_user_inner", object_search_byid("chats_1", app->root), &style_container_user_inner);
    object_add("user_icon", object_search_byid("container_user_inner", app->root), &style_user_icon);
    object_add("container_username_status", object_search_byid("container_user_inner", app->root), &style_container_username_status);
    object_add("username", object_search_byid("container_username_status", app->root), &style_username);
    object_add("user_status", object_search_byid("container_username_status", app->root), &style_user_status);

    //Chat list
    object_add("rooms_container", object_search_byid("chats_2", app->root), &style_rooms_container);
    object_search_byid("rooms_container", app->root)->on_update = lister;


    object_add("greating_container", object_search_byid("rooms_container", app->root), &style_greating_container);
    add_chat(app, object_search_byid("greating_container", app->root), 0, "Greating room", "Welcome back stranger!", 0);

    add_chat(app, object_search_byid("rooms_container", app->root), 1, "Unicornland", "Room for real girls", 34);
    add_chat(app, object_search_byid("rooms_container", app->root), 2, "Witchers room", "Room for real boys", 1);


    object_add("messages_container", object_search_byid("messages_2", app->root), &style_messages_container);
    object_search_byid("messages_container", app->root)->on_update = lister;

    add_message(app, object_search_byid("messages_container", app->root), 0, "foldybox", "Bla blabla blal  dlfdlfldfl.", 0, false);
    add_message(app, object_search_byid("messages_container", app->root), 0, "foldybox", "Bla blabla blal  dlfdlfldfl.", 0, false);
    add_message(app, object_search_byid("messages_container", app->root), 0, "foldybox", "Bla blabla blal  dlfdlfldfl.", 0, false);
    add_message(app, object_search_byid("messages_container", app->root), 0, "foldybox", "Bla blabla blal  dlfdlfldfl.", 0, false);
    add_message(app, object_search_byid("messages_container", app->root), 0, "foldybox", "Bla blabla blal  dlfdlfldfl.", 0, false);
    add_message(app, object_search_byid("messages_container", app->root), 0, "foldybox", "Bla blabla blal  dlfdlfldfl.", 0, false);
    add_message(app, object_search_byid("messages_container", app->root), 0, "foldybox", "Bla blabla blal  dlfdlfldfl.", 0, false);


    ////Cop & Past Inc. Server
    //object_add("container_for_server", object_search_byid("container_1", app->root), &style_container_for_server);
    object_add("container_server_logo", object_search_byid("chats_3", app->root), &style_container_server_logo);
    object_add("container_server_online", object_search_byid("chats_3", app->root), &style_container_server_online);
    object_add("server_logo", object_search_byid("container_server_logo", app->root), &style_server_logo);
    object_add("server_online", object_search_byid("container_server_online", app->root), &style_server_online);



    ////Side bar for games, stickers, emojis
    // object_add("container_for_entertainments", object_search_byid("container_3", app->root), &style_container_for_entertainments);
    object_add("button_for_games", object_search_byid("games_1", app->root), &style_button_for_games);
    object_add("button_for_skickers", object_search_byid("games_1", app->root), &style_button_for_skickers);
    object_add("button_for_games_title", object_search_byid("button_for_games", app->root), &style_button_for_games_title);
    object_add("button_for_stickers_title", object_search_byid("button_for_skickers", app->root), &style_button_for_stickers_title);
    object_add("game_container", object_search_byid("games_2", app->root), &style_game_container);
    object_add("game_icon_container", object_search_byid("game_container", app->root), &style_game_icon_container);
    object_add("game_container_description", object_search_byid("game_container", app->root), &style_game_container_description);
    object_add("game_icon", object_search_byid("game_icon_container", app->root), &style_game_icon);
    object_add("game_container_gamename", object_search_byid("game_container_description", app->root), &style_game_container_gamename);
    object_add("game_container_gamedescription", object_search_byid("game_container_description", app->root), &style_game_container_gamedescription);
    object_add("game_container_gameplayers", object_search_byid("game_container_description", app->root), &style_game_container_gameplayers);
    object_add("game_gamename", object_search_byid("game_container_gamename", app->root), &style_game_gamename);
    object_add("game_gamedescription", object_search_byid("game_container_gamedescription", app->root), &style_game_gamedescription);
    object_add("game_gameplayers", object_search_byid("game_container_gameplayers", app->root), &style_game_gameplayers);


    object_add("container_chat_buttons", object_search_byid("messages_1", app->root), &style_container_chat_buttons);
    object_add("container_chat_name_online", object_search_byid("messages_1", app->root), &style_container_chat_name_online);
    object_add("container_leave_chat", object_search_byid("container_chat_buttons", app->root), &style_container_leave_chat);
    object_add("container_chat_menu", object_search_byid("container_chat_buttons", app->root), &style_container_chat_menu);
    object_add("container_sidebar", object_search_byid("container_chat_buttons", app->root), &style_container_sidebar);
    object_add("leave_chat_button", object_search_byid("container_leave_chat", app->root), &style_leave_chat_button);
    //object_add("leave_chat_button_text", object_search_byid("leave_chat_button", app->root), &style_leave_chat_button_text);
    object_add("chat_menu_logo", object_search_byid("container_chat_menu", app->root), &style_chat_menu_logo);
    object_add("sidebar_logo", object_search_byid("container_sidebar", app->root), &style_sidebar_logo);
    object_add("chat_chat_name", object_search_byid("container_chat_name_online", app->root), &style_chat_chat_name);
    object_add("chat_online", object_search_byid("container_chat_name_online", app->root), &style_chat_online);


    // ////Sending message
    // object_add("container_for_entering_messeges", object_search_byid("container_2", app->root), &style_container_for_entering_messeges);
    object_add("container_add_file", object_search_byid("messages_3", app->root), &style_container_add_file);
    object_add("container_enter_message", object_search_byid("messages_3", app->root), &style_container_enter_message);
    object_add("container_send_message", object_search_byid("messages_3", app->root), &style_container_send_message);
    object_add("add_file_logo", object_search_byid("container_add_file", app->root), &style_add_file_logo);
    object_add("enter_message_text", object_search_byid("container_enter_message", app->root), &style_enter_message_text);
    object_search_byid("enter_message_text", app->root)->on_focus_start = input_on_focus_start;
    object_search_byid("enter_message_text", app->root)->on_focus_end = input_on_focus_end;
    object_search_byid("enter_message_text", app->root)->is_hover_reacting = true;
    object_search_byid("enter_message_text", app->root)->is_click_reacting = true;
    object_search_byid("enter_message_text", app->root)->is_hover_reacting = true;
    object_add("send_message_logo", object_search_byid("container_send_message", app->root), &style_send_message_logo);

}

object_t *add_chat(app_t *app, object_t *container, int id, char *chat_name, char *chat_status, int chat_icon) {
    char *chat_id = NULL;
    char *icon_path = NULL;
    style_t style_room = set_clear_style();
    style_t style_room_icon = set_clear_style();
    style_t style_inner = set_clear_style();
    style_t style_room_username = set_clear_style();
    style_t style_room_message = set_clear_style();

    asprintf(&chat_id, "chat_%d", id);
    asprintf(&icon_path, "resource/img/chat_icons/chat_icon_%d.png", chat_icon);

    style_room.position = set_pos(0, 0, false, false);
    style_room.size = set_size(100, 64, true, false);
    style_room.anchor = ANCHOR_TOP_LEFT;
    style_room.padding=set_pad(76, 14, 0, 0);
    style_room.background_color = set_color(31, 32, 44, 255);

    style_room_icon.position = set_pos(14, 50, false, true);
    style_room_icon.size = set_size(48, 48, false, false);
    style_room_icon.anchor = ANCHOR_CENTER_LEFT;
    style_room_icon.texture = render_texture(app, icon_path);
    style_room_icon.background_color = set_color(0, 0, 0, 255);
    style_room_icon.is_static = true;
    
    style_inner.position = set_pos(0, 50, false, true);
    style_inner.size = set_size(100, 42, true, false);
    style_inner.anchor = ANCHOR_CENTER_LEFT;

    style_room_username.position = set_pos(0, 0, false, false);
    style_room_username.size = set_size(100, 19, true, false);
    style_room_username.anchor = ANCHOR_TOP_LEFT;
    style_room_username.text_content = chat_name;
    style_room_username.text_anchor = ANCHOR_CENTER_LEFT;
    style_room_username.font = set_font(FONT_ROBOTO_MEDIUM_16, set_color(255, 255, 255, 255));

    style_room_message.position = set_pos(0, 23, false, false);
    style_room_message.size = set_size(100, 19, true, false);
    style_room_message.anchor = ANCHOR_TOP_LEFT;
    style_room_message.text_content = chat_status;
    style_room_message.text_anchor = ANCHOR_CENTER_LEFT;
    style_room_message.font = set_font(FONT_ROBOTO_REGULAR_16, set_color(255, 255, 255, 150));

    object_t *chat = object_add(chat_id, container, &style_room);
    chat->is_hover_reacting = true;
    chat->is_click_reacting  = true;
    object_add("", chat, &style_room_icon);
    object_t *inner = object_add("", chat, &style_inner);
    object_add("", inner, &style_room_username);
    object_add("", inner, &style_room_message);

    return chat;
}

object_t *add_message(app_t *app, object_t *container, int id, char *message_username, char *message_text, int message_user_icon, bool is_mine) {
    char *message_id = NULL;
    char *icon_path = NULL;
    style_t style_message = set_clear_style();
    style_t style_message_icon = set_clear_style();
    style_t style_message_text = set_clear_style();

    asprintf(&message_id, "message_%d", id);
    asprintf(&icon_path, "resource/img/chat_icons/chat_icon_%d.png", message_user_icon);

    style_message.position = set_pos(0, 0, false, false);
    style_message.size = set_size(100, 150, true, false);
    style_message.anchor = ANCHOR_TOP_LEFT;
    style_message.padding=set_pad(76, 0, 14, 14);
    style_message.background_color = set_color(5, 133, 8, 10);
    style_message.is_auto_height = true;

    style_message_icon.position = set_pos(14, 14, false, false);
    style_message_icon.size = set_size(48, 48, false, false);
    style_message_icon.anchor = ANCHOR_TOP_LEFT;
    style_message_icon.texture = render_texture(app, icon_path);
    style_message_icon.background_color = set_color(0, 0, 0, 255);
    style_message_icon.is_static = true;

    style_message_text.position = set_pos(0, 0, false, false);
    style_message_text.size = set_size(60, 100, true, true);
    style_message_text.anchor = ANCHOR_TOP_LEFT;
    style_message_text.padding = set_pad(14, 14, 14, 14);
    style_message_text.background_color = set_color(0, 57, 7, 255);
    style_message_text.text_content = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce iaculis justo dui. Quisque nec efficitur dolor. In nec arcu tristique, dignissim ante sit amet, fringilla nibh. Mauris lacinia purus quis molestie blandit. Nulla ut congue libero. Nullam at nisi vitae ante euismod faucibus. Pellentesque suscipit varius egestas. Proin bibendum rhoncus odio, at lacinia arcu molestie nec. Nam gravida nisl non nunc fringilla dictum. Nunc mollis erat ut lacus ultrices, et tempus ligula dignissim. Fusce quis porttitor nulla, nec sodales justo. Cras sed ipsum quis augue pharetra condimentum. Sed dapibus eget velit id ultrices. Maecenas id justo elit. Fusce finibus sapien nec volutpat mollis. Donec eu purus volutpat, placerat tellus scelerisque, sollicitudin felis.";
    style_message_text.is_auto_height = true;

    object_t *message = object_add(message_id, container, &style_message);
    object_add("", message, &style_message_icon);
    object_add("", message, &style_message_text);

    return message;
}