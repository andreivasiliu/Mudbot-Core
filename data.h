#define STRING_SIZE 100

typedef struct _record_node {
	char *szKey;
	char *szVal;
	struct _record_node *pNext;
} record_node;

typedef struct _string_node {
	char *szItem;
	struct _string_node *pNext;
} string_node;

typedef struct _lookup_table_node {
	char *szName;
	void **ppData;
	struct _lookup_table_node *pNext;
} lookup_table_node;

typedef void(*cbVoidFunc)();

typedef struct _function_data {
	char *szName;
	cbVoidFunc pFunction;
	int data0;
	int data1;
	int data2;
} function_data;

void** new_record_list(void); // useful for tolua++
void destroy_record_list(record_node**);
void del_key(record_node**, const char *);
void del_keys_by_val(record_node**, const char *);
void add_key(record_node**, const char *, const char *);
int is_val(const record_node *, const char *);
int is_key(const record_node *, const char *);
record_node *pop_key(record_node**);
const char *get_val(const record_node *, const char *);
void print_record_list(const record_node *, const char *);
void print_record_list_to_buf(const record_node *, const char *, char *);
int num_keys(const record_node *);

void** new_string_list(void); // useful for tolua++
void destroy_string_list(string_node**);
void del_item(string_node**, const char*);
void add_item(string_node**, const char*);
void add_item_dup(string_node**, const char*);
int is_member(const char *, const string_node *);
const char *get_item(const string_node *, int);
void push_item(string_node**, const char *);
void push_item_dup(string_node**, const char *);
string_node *pop_item(string_node**);
string_node *duplicate_string_list(const string_node *);
int num_items(const string_node *);
void del_nitem(string_node**, int);
void print_string_list(const string_node *, const char *);

void** new_lookup_table(void); //useful for tolua++
void destroy_lookup_table(lookup_table_node **);
void add_data(lookup_table_node **, const char *, void **);
void *get_data(const lookup_table_node *, const char *);
void **get_pdata(const lookup_table_node *, const char *);
void remove_data(lookup_table_node **, const char *);
int does_data_exist(const lookup_table_node *, const char *);

void replace_char(char *, char, char);
void words(const char *, int, const char *, char *);
void word(const char *, int, const char *, char *);
