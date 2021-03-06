#ifndef AST_H
#define AST_H

typedef enum {
    IF_NODE,
    INPUT_NODE,
    OUTPUT_NODE,
    RETURN_NODE,
    WHILE_NODE,
    WRITE_NODE,

    PLUS_NODE,
    MINUS_NODE,
    TIMES_NODE,
    OVER_NODE,
    LT_NODE,
    LE_NODE,
    GT_NODE,
    GE_NODE,
    EQ_NODE,
    NEQ_NODE,
    ASSIGN_NODE,
    
    BLOCK_NODE,
    VDECL_LIST_NODE,
    VDECL_NODE,
    VUSE_NODE,
    FLIST_NODE,
    FDECL_NODE,
    FHEADER_NODE,
    FBODY_NODE,
    FNAME_NODE,
    PLIST_NODE,
    FCALL_NODE,
    ALIST_NODE,
    
    NUM_NODE,
    STRING_NODE
} NodeKind;

struct node;
typedef struct node AST;

struct node_list;
typedef struct node_list Children;

int get_data(AST *node);
int get_child_count(AST *node);

char* kind2str(NodeKind kind);

void add_child(AST *parent, AST *child);
void print_tree(AST *ast);
void free_tree(AST *ast);

AST* new_node(NodeKind kind, int data);
AST* get_child(AST *parent, int idx);
AST* new_subtree(NodeKind kind, int child_count, ...);

NodeKind get_kind(AST *node);

#endif
