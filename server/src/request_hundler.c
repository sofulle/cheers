#include "../inc/server.h"

char *request_hundler(/*char *type, */char *buff) {
    insert_chat(buff, "aaa", 0, 1);
    insert_chat_reletion(1, 1);
    insert_chat_reletion(2, 1);
    insert_chat_reletion(3, 1);
    insert_chat_reletion(2, 2);
    chat_t *chat = get_chat(1);
    char *s = chat->name;
    return s;
    /*if (strcmp(type, "login_user") == 0) {
        if (get_user_by_username_and_password(username, password) == NULL) {
            printf("Ok, come through\n");
        }
        else {
            printf("Go on dick\n");
        }
    }
    else if (strcmp(type, "register_user") == 0) {
        if (!is_user(username)) {
            insert_user(username, name, password);
        }
        else {
            printf("This name is already exist\n");
        }
    }
    else if (strcmp(type, "update_user_username") == 0) {
        update_user_username(username, user_id);
    }
    else if (strcmp(type, "update_user_name") == 0) {
        update_user_username(name, user_id);
    }
    else if (strcmp(type, "update_user_password") == 0) {
        update_user_username(password, user_id);
    }
    else if (strcmp(type, "get_user") == 0) {
        get_user_by_id(user_id);
    }
    else if (strcmp(type, "get_user_id") == 0) {
        get_user_id(username);
    }
    else if (strcmp(type, "get_chat") == 0) {
        if (check_user(user_id, chat_id)) {
            chat_t *chat = get_chat(chat_id);
        }
        else {
            printf("Go on dick\n");
        }
    }*/

}
