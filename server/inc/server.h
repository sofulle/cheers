#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <time.h>
#include <sys/signal.h>
#include <strings.h>
#include "../../frameworks/vector/inc/vector.h"
#include "libmx.h"

typedef struct message_s {
    int         id;
    int         chat_id;
    int         user_id;
    long        datetime;
    char        *text;
    bool        is_deleted;
} message_t;

typedef struct user_s {
    int         id;
    char        *username;
    char        *name;
    char        *password;
    bool        online;
} user_t;

typedef struct chat_s {
    int         id;
    char        *name;
    char        *subscribe;
    int         active_game;
    int         type;
    vector_t    *users_id;
} chat_t;

typedef struct game_s {
    int         id;
    char        *name;
} game_t;

void *query_db(char *query, int type);
bool check_user(int user_id, int chat_id);
bool is_user(char *username);
void insert_user(char *username, char *name, char *password);
void insert_chat(char *title, char *subscribe, int active_game, int type);
void insert_message(long datetime, char *text, int chat_id, int user_id);
void insert_chat_reletion(int user_id, int chat_id);
message_t *get_message(int chat_id, int message_id);
user_t *get_user_by_id(int user_id);
user_t *get_user_by_username_and_password(char *username, char *password);
chat_t *get_chat(int chat_id);
int get_last_message_id(int chat_id);
int get_last_user_id(int user_id);
int get_user_id(char *username);
void remove_chat(int chat_id);
void remove_chat_reletion(int user_id, int chat_id) ;
//void update_user(char *username, char *name, char *password, int user_id);
void update_user_username(char *username, int user_id);
void update_user_name(char *name, int user_id);
void update_user_password(char *password, int user_id);
void update_user_online(bool is_online, int user_id);
void rename_group(char *title, int chat_id);
char *request_hundler(/*char *type, */char *buff);
