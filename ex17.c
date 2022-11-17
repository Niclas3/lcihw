#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    int max_data;
    int max_rows;
    struct Address rows[MAX_ROWS]; 
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

void die_and_clean(const char *message, struct Connection *conn)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    if (conn->db) 
        free(conn->db);
    if(conn->file)
        fclose(conn->file);
    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) {
        /* die("Failed to load database."); */
        die_and_clean("Failed to load database.", conn);
    }
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn) {
        /* die("Memory error"); */
        die_and_clean("Memory error", conn);
    }
    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) {
        /* die("Memory error"); */
        die_and_clean("Memory error", conn);
    }

    if (mode == 'c' || mode == 'x') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }
    if (!conn->file) {
        /* die("Failed to open the file"); */
        die_and_clean("Failed to open the file", conn);
    }
    return conn;
}

void Database_close(struct Connection *conn)
{
    if (conn) {
        if (conn->file) {
            fclose(conn->file);
        }
        if (conn->db) {
            free(conn->db);
        }
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1){
        /* die("Failed to write database."); */
        die_and_clean("Failed to write database.", conn);
    }
    rc = fflush(conn->file);
    if (rc == -1) {
        /* die("Cannot flush database."); */
        die_and_clean("Cannot flush database.", conn);
    }
}

void Database_create(struct Connection *conn)
{
    int i = 0;
    for (i = 0; i < MAX_ROWS; i++) {
        //make a prototype to initialize it
        struct Address addr = { .id = i, .set = 0 };
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_create_as_abitrarily_size(struct Connection *conn,
        int max_data, int max_rows )
{
    conn->db->max_rows = max_rows; 
    conn->db->max_data = max_data;
    int i = 0;
    for (i = 0; i < max_rows; i++) {
        //make a prototype to initialize it
        struct Address addr = { .id = i, .set = 0 };
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id,
        const char* name, const char* email)
{
    struct Address *addr = &conn->db->rows[id];
    int max_d = conn->db->max_data;
    if (addr->set) {
        /* die("Already set, delete it first"); */
        die_and_clean("Already set, delete it first",conn);
    }

    addr->set = 1 ;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, max_d);
    // demonstrate the strncpy bug
    if (!res)
        /* die("Name copy failed"); */
        die_and_clean("Name copy failed", conn);
    res = strncpy(addr->email, email, max_d);

    if (!res)
        /* die("Email copy failed"); */
        die_and_clean("Name copy failed", conn);
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } else {
        /* die("ID is not set"); */
        die_and_clean("ID is not set", conn);
    }
}
void Database_find(struct Connection *conn, char* name)
{
    int found = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        struct Address *addr = &conn->db->rows[i];
        if (!strncmp(name , addr->name, strlen(name)) ){
            found= 1;
            Address_print(addr);
        }
    }
    if(!found)
        die_and_clean("Name not find.", conn);
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_delete_zm_version(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];
    free(addr->name);
    free(addr->email);
    addr->set = 0;
}

void Database_list(struct Connection *conn){
    for(int i = 0; i < MAX_ROWS; i++){
        struct Address *addr = &conn->db->rows[i];

        if (addr->set) {
            Address_print(addr);
        } 
    }
}

int* test(int a) 
{
    int b = 100;
    int array[1000000];
    printf("param a %d %p\n", a, &a);
    int *p_b = &b;
    return p_b;
}
void _(){
    _();
}

struct Large {
    long id;
    long count;
    long nothing;
};

void test1(struct Large large, int a[]) {
    int b = 1000;
    char *m = "abc";
}

int main(int argc, char* argv[])
{
    /* int tmp = 10; */
    /* int *p_tmp; */
    /* p_tmp = test(tmp); */
    /* printf("p_tmp: %p, %d\n", p_tmp, *p_tmp); */
    /* struct Large L = { */
    /*     .id=0xffffffff, */
    /*     .count=0xfffffff, */
    /*     .nothing=0xffffffff */
    /* }; */
    /* _(); */
    /* int a[0xffffffff]; */
    /* for (int i = 0; i < 0xffffffff; i++) { */
    /*     a[i] = 0xffffffff; */
    /* } */

    /* test1(L,a); */

    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    
    int id = 0;
    if (!(action == 'c' || action == 'x')) {
        if (argc > 3) id = atoi(argv[3]);
        if (id >= conn->db->max_rows) 
            /* die("There's not that many records."); */
            die_and_clean("There's not that many records.", conn);
    }

    switch (action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;
            
        case 'x':
            if (argc != 5)
                /* die("Need id, name, email to set"); */
                die_and_clean("Need max_data max_rows", conn);
            Database_create_as_abitrarily_size(conn, atoi(argv[2]),atoi(argv[3]));
            Database_write(conn);
            break;

        case 'g':
            if (argc != 4)
                /* die("Need an id to get"); */
                die_and_clean("Need an id to get", conn);
            Database_get(conn, id);
            break;

        case 's':
            if (argc != 6)
                /* die("Need id, name, email to set"); */
                die_and_clean("Need id, name, email to set", conn);
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if (argc != 4) 
                /* die("Need an id to delete"); */
                die_and_clean("Need an id to delete", conn);
            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'f':
            if (argc != 4) 
                /* die("Need an id to delete"); */
                die_and_clean("Need an id to delete", conn);
            Database_find(conn, argv[3]);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            /* die("Invalid action: c=create, g=get, s=set, d=delete, l=list"); */
            die_and_clean("Invalid action: c=create, g=get, s=set, d=delete, l=list", conn);
    }

    Database_close(conn);

    return 0;
}
