#include "../inc/server.h"

// Проверяем действительно ли юзер, запрашивающий данные, является участником чата
bool check_user(int user_id, int chat_id) {
    char *sql_query = NULL;
    char *sql_pattern = "SELECT EXISTS (SELECT id FROM chat_relation WHERE user_id=(%d) chat_id=(%d));";
    asprintf(&sql_query, sql_pattern, user_id, chat_id);
    vector_t *exit = query_db(sql_query, 1);
    int result = atoi(exit->data);
    mx_strdel(&sql_query);
    vector_free(&exit);
    return result == 0 ? false : true;
}

bool is_user(char *username) { // work
    char *sql_query = NULL;
    char *sql_pattern = "SELECT EXISTS (SELECT id FROM user WHERE username=('%s'));";
    asprintf(&sql_query, sql_pattern, username);
    vector_t *exit = query_db(sql_query, 1);
    int result = atoi(exit->data);
    vector_free(&exit);
    mx_strdel(&sql_query);
    return result == 0 ? false : true;
}

void insert_user(char *username, char *name, char *password) { // work
    char *sql_query;
    char *sql_pattern = "INSERT INTO user (username, name, password) VALUES ('%s', '%s', '%s');";
    asprintf(&sql_query, sql_pattern, username, name, password);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void insert_chat(char *title, char *subscribe, int active_game, int type) { //work
    char *sql_query;
    char *sql_pattern = "INSERT INTO chat (title, subscribe, active_game, type) VALUES ('%s', '%s', %d, %d);";
    asprintf(&sql_query, sql_pattern, title, subscribe, active_game, type);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void insert_message(long int datetime, char *text, int chat_id, int user_id) { //work
    char *sql_query;
    char *sql_pattern = "INSERT INTO message (chat_id, user_id, datetime, text) VALUES (%d, %d, %ld, '%s');";
    asprintf(&sql_query, sql_pattern, chat_id, user_id, datetime, text);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void insert_chat_reletion(int user_id, int chat_id) { //work
    char *sql_query;
    char *sql_pattern = "INSERT INTO chat_relation (user_id, chat_id) VALUES (%d, %d);";
    asprintf(&sql_query, sql_pattern, user_id, chat_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

message_t *get_message(int chat_id, int message_id) { //work
    char *sql_query;
    char *sql_pattern = "SELECT user_id, datetime, text, is_deleted FROM message WHERE chat_id=(%d) AND id=(%d);";
    asprintf(&sql_query, sql_pattern, chat_id, message_id);
    vector_t *list = query_db(sql_query, 1);
    mx_strdel(&sql_query);
    message_t *message = (message_t *)malloc(sizeof(message_t));
    message->id = message_id;
    message->chat_id = chat_id;
    message->user_id = (int)list->data;
    message->datetime = (long)vector_get(&list, 1);
    message->text = (char *)vector_get(&list, 2);
    message->is_deleted = (bool)vector_get(&list, 3);
    return message;
}

user_t *get_user_by_id(int user_id) { // work
    char *sql_query = NULL;
    char *sql_pattern = "SELECT username, name, password, online FROM user WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, user_id);
    vector_t *list = query_db(sql_query, 1);
    mx_strdel(&sql_query);
    user_t *user = (user_t *)malloc(sizeof(user_t));
    user->id = user_id;
    user->username = (char *)list->data;
    user->name = (char *)vector_get(&list, 1)->data;
    user->password = (char *)vector_get(&list, 2)->data;
    user->online = (bool)vector_get(&list, 3)->data;
    return user;
}

user_t *get_user_by_username_and_password(char *username, char *password) { // work
    char *sql_query = NULL;
    char *sql_pattern = "SELECT id, name, online FROM user WHERE username=('%s') AND password=('%s');";
    asprintf(&sql_query, sql_pattern, username, password);
    vector_t *list = query_db(sql_query, 1);
    mx_strdel(&sql_query);
    user_t *user = (user_t *)malloc(sizeof(user_t));
    user->id = (int)list->data;
    user->username = username;
    user->name = vector_get(&list, 1)->data;
    user->password = password;
    user->online = (bool)vector_get(&list, 2)->data;
    return user;
}

int get_last_message_id(int chat_id) {
    char *sql_query = NULL;
    char *sql_pattern = "SELECT id FROM message WHERE chat_id=(%d) ORDER BY id DESC;";
    asprintf(&sql_query, sql_pattern, chat_id);
    vector_t *list = query_db(sql_query, 1);
    mx_strdel(&sql_query);
    int i = atoi(list->data);
    vector_free(&list);
    return i;
}

int get_last_user_id(int user_id) {
    char *sql_query = NULL;
    char *sql_pattern = "SELECT id FROM user ORDER BY id DESC;";
    asprintf(&sql_query, sql_pattern, user_id);
    vector_t *list = query_db(sql_query, 1);
    mx_strdel(&sql_query);
    int i = atoi(list->data);
    vector_free(&list);
    return i;
}

chat_t *get_chat(int chat_id) { //work
    char *sql_query = NULL;
    char *sql_pattern = "SELECT title, subscribe, active_game, type FROM chat WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, chat_id);
    vector_t *list = query_db(sql_query, 1);
    char *sql_query2 = NULL;
    char *sql_pattern2 = "SELECT user_id FROM chat_relation WHERE chat_id=(%d);";
    asprintf(&sql_query2, sql_pattern2, chat_id);
    chat_t *chat = (chat_t *)malloc(sizeof(chat_t));
    chat->id = chat_id;
    chat->name = (char *)list->data;
    chat->subscribe = (char *)vector_get(&list, 1)->data;
    chat->active_game = (int)vector_get(&list, 2)->data;
    chat->type = (int)vector_get(&list, 3)->data;
    chat->users_id = query_db(sql_query2, 1);
    mx_strdel(&sql_query);
    mx_strdel(&sql_query2);
    return chat;
}

int get_user_id(char *username) { // work
    char *sql_query = NULL;
    char *sql_pattern = "SELECT id FROM user WHERE username=('%s');";
    asprintf(&sql_query, sql_pattern, username);
    vector_t *list = query_db(sql_query, 1);
    int i = atoi(list->data);
    vector_free(&list);
    return i;
}

void remove_chat(int chat_id) {
    char *sql_query = NULL;
    char *sql_pattern = "DELETE FROM chat WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, chat_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void remove_chat_reletion(int user_id, int chat_id) {
    char *sql_query;
    char *sql_pattern = "DELETE FROM chat_relation WHERE user_id=(%d) AND chat_id=(%d);";;
    asprintf(&sql_query, sql_pattern, user_id, chat_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void update_user_username(char *username, int user_id) { // work
    char *sql_query = NULL;
    char *sql_pattern = "UPDATE user SET username=('%s'), WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, username, user_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void update_user_name(char *name, int user_id) { // work
    char *sql_query = NULL;
    char *sql_pattern = "UPDATE user SET name=('%s'), WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, name, user_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void update_user_password(char *password, int user_id) { // work
    char *sql_query = NULL;
    char *sql_pattern = "UPDATE user SET password=('%s'), WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, password, user_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void update_user_online(bool is_online, int user_id) {
    char *sql_query = NULL;
    char *sql_pattern = is_online ? "UPDATE user SET online=(1) WHERE id=(%d);" : "UPDATE users SET online=(0) WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, user_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

void rename_chat(char *title, int chat_id) {
    char *sql_query = NULL;
    char *sql_pattern = "UPDATE chat SET title=('%s'), WHERE id=(%d);";
    asprintf(&sql_query, sql_pattern, title, chat_id);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}

/*void drop_database(void) {
    char *sql_query = NULL;
    char *sql_pattern = "DROP DATABASE test;";
    asprintf(&sql_query, sql_pattern);
    query_db(sql_query, 2);
    mx_strdel(&sql_query);
}*/

/*int main() {
    char *name = "newuser";
    char *username = "newuser";
    char *password = "newpassword";
    //int id = get_user_id("user");
    insert_message("12.05.2021", "12:45", "hello", 1, 1);
    update_user("ip", name, password, 1);
    update_user_online(false, 1);
    ///char *title = "chat";
    //insert_chat(title, 0, 1);
    t_list *list = get_message(1, 2);
    if (list == NULL) {
        printf("NULL\n");
    }
    for ( ;list != NULL; list = list->next) {
        printf("%s\n", (char *)list->data);
        //printf("%i", id);
    }
}*/
