#ifndef PHP_MEMINFO_H
#define PHP_MEMINFO_H 1

#define phpext_meminfo_ptr &meminfo_module_entry

#define MEMINFO_NAME "PHP Meminfo"
#define MEMINFO_VERSION "1.0"
#define MEMINFO_AUTHOR "Benoit Jacquemont"
#define MEMINFO_COPYRIGHT  "Copyright (c) 2010-2017 by Benoit Jacquemont"
#define MEMINFO_COPYRIGHT_SHORT "Copyright (c) 2011-2017"

PHP_FUNCTION(meminfo_dump);
PHP_FUNCTION(meminfo_dump2);

zend_ulong   meminfo_get_element_size(zval* z);

// Functions to browse memory parts to record item
void meminfo_browse_exec_frames(smart_str *stream,  HashTable *visited_items, int *first_element);
void meminfo_browse_class_static_members(smart_str *stream,  HashTable *visited_items, int *first_element);

void meminfo_zval_dump(smart_str * stream, char * frame_label, zend_string * symbol_name, zval * zv, HashTable *visited_items, int *first_element);
void meminfo_hash_dump(smart_str *stream, HashTable *ht, zend_bool is_object, HashTable *visited_items, int *first_element);
void meminfo_browse_zvals_from_symbol_table(smart_str *stream, char * frame_label, HashTable *symbol_table, HashTable * visited_items, int *first_element);
void meminfo_browse_zvals_from_op_array(smart_str *stream, char * frame_label, zend_op_array *op_array, zend_execute_data *exec_frame, HashTable * visited_items, int *first_element);
int meminfo_visit_item(char *item_identifier, HashTable *visited_items);

void meminfo_build_frame_label(char * frame_label, int frame_label_len, zend_execute_data* frame);

zend_string * meminfo_escape_for_json(const char *s);

extern zend_module_entry meminfo_entry;

#endif
