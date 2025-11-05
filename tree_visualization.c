#include "tree_visualization.h"
#include <stdio.h>
#include <string.h>



/*---------------------------------------------------------
 * Prints a single node's core info
 *--------------------------------------------------------*/
void print_node_info(tnode* root) {
    printf("[%s] ", nodetype_to_string(root->nodetype));

    if (root->nodetype == DOTNODE)
        printf("operator:'.' ");
    else if (root->nodetype == ARROWNODE)
        printf("operator:'->' ");
    else if (root->varname)
        printf("var:%s ", root->varname);

    printf("type:%s ", type_to_string(root->type));

    if (root->type == TYPE_INT)
        printf("val:%d ", root->val);

    // if (root->dimlist)
    //     print_dimlist(root->dimlist);
    // if (root->plist)
    //     print_paramlist(root->plist);
    if (root->Gentry)
        print_gsymbol(root->Gentry);

    printf("\n");
}

/*---------------------------------------------------------
 * Prints DOTNODE or ARROWNODE neatly
 *--------------------------------------------------------*/
void print_field_access_node(tnode* root, char* new_prefix, const char* left_label, const char* right_label) {
    int child_count = 0;
    if (root->left) child_count++;
    if (root->right) child_count++;

    int printed_children = 0;

    if (root->left) {
        printed_children++;
        printf("%s%s", new_prefix, (printed_children == child_count) ? "└── " : "├── ");
        printf("[%s] var:%s type:%s\n",
               left_label,
               root->left->varname ? root->left->varname : "(unnamed)",
               root->left->typeEntry ? root->left->typeEntry->name : type_to_string(root->left->type));
    }

    if (root->right) {
        printed_children++;
        printf("%s%s", new_prefix, (printed_children == child_count) ? "└── " : "├── ");
        printf("[%s] var:%s type:%s\n",
               right_label,
               root->right->varname ? root->right->varname : "(unnamed)",
               root->right->typeEntry ? root->right->typeEntry->name : type_to_string(root->right->type));
    }
}

/*---------------------------------------------------------
 * Recursive helper to print a full chain of DOTNODEs like a.b.c.d
 *--------------------------------------------------------*/
void print_dotnode_chain(tnode* node) {
    if (!node) return;

    if (node->nodetype == DOTNODE) {
        print_dotnode_chain(node->left);
        if (node->right && node->right->varname)
            printf(".%s", node->right->varname);
        else
            printf(".(unknown)");
    } else if (node->varname) {
        printf("%s", node->varname);
    } else {
        printf("(unnamed)");
    }
}

/*---------------------------------------------------------
 * Main recursive tree printer
 *--------------------------------------------------------*/
void tree_visual_print_tree_structure(tnode *root, char *prefix, int is_last, int is_root, int skip_middle) {
    if (!root)
        return;

    // Print prefix and branch
    if (!is_root) {
        printf("%s", prefix);
        printf("%s", is_last ? "└── " : "├── ");
    }

    // Print node info
    print_node_info(root);

    // Build prefix for child nodes
    char new_prefix[256];
    if (is_root)
        strcpy(new_prefix, "");
    else {
        strcpy(new_prefix, prefix);
        strcat(new_prefix, is_last ? "    " : "│   ");
    }

    /*---------------------------------------------
     * Special handling: FUNCTIONNODE (with args via middle)
     *--------------------------------------------*/
    if (root->nodetype == FUNCTIONNODE) {
        int child_count = 0;
        if (root->left) child_count++; // function name

        // Count args linked via right->middle
        tnode *arg = root->right;
        while (arg) {
            child_count++;
            arg = arg->middle;
        }

        int printed_children = 0;

        // Function name first
        if (root->left) {
            printed_children++;
            tree_visual_print_tree_structure(root->left, new_prefix,
                                             printed_children == child_count, 0, 0);
        }

        // Then all arguments
        arg = root->right;
        while (arg) {
            printed_children++;
            tree_visual_print_tree_structure(arg, new_prefix,
                                             printed_children == child_count, 0, 1);
            arg = arg->middle;
        }
        return;
    }

    /*---------------------------------------------
     * Special handling: DOTNODE or ARROWNODE
     *--------------------------------------------*/
    if (root->nodetype == DOTNODE) {
        // First line: same structure as other nodes
        printf("%s%s", prefix, is_last ? "└── " : "├── ");
        printf("[DOT] operator:'.' type:%s val:%d\n",
            type_to_string(root->type), root->val);

        // Second line: indented continuation with the full chain
        printf("%s%sFull Access: ", prefix, is_last ? "    " : "│   ");
        print_dotnode_chain(root);
        printf("\n");
        return;
    }


    if (root->nodetype == ARROWNODE) {
        print_field_access_node(root, new_prefix, "PTR", "FIELD");
        return;
    }

    /*---------------------------------------------
     * Default: other nodes (left, middle, right)
     *--------------------------------------------*/
    int child_count = 0;
    if (root->left) child_count++;
    if (root->middle) child_count++;
    if (root->right) child_count++;

    int printed_children = 0;

    if (root->left) {
        printed_children++;
        tree_visual_print_tree_structure(root->left, new_prefix,
                                         printed_children == child_count, 0, skip_middle);
    }

    if (root->middle && !skip_middle) {
        printed_children++;
        tree_visual_print_tree_structure(root->middle, new_prefix,
                                         printed_children == child_count, 0, skip_middle);
    }

    if (root->right) {
        printed_children++;
        tree_visual_print_tree_structure(root->right, new_prefix,
                                         printed_children == child_count, 0, skip_middle);
    }
}

/*---------------------------------------------------------
 * Public interface: Full detailed print
 *--------------------------------------------------------*/
void tree_visual_printTree(tnode *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    printf("\nTree Structure:\n");
    printf("================\n");
    tree_visual_print_tree_structure(root, "", 1, 1, 0);
    printf("\n");
}

/*---------------------------------------------------------
 * Compact single-line view (for debugging)
 *--------------------------------------------------------*/
void tree_visual_print_tree_compact(tnode *root, int depth) {
    if (root == NULL)
        return;

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("|- [%s]", nodetype_to_string(root->nodetype));

    if (root->nodetype == DOTNODE) {
        printf(" (DOTNODE '.') ");
        printf("Access: ");
        print_dotnode_chain(root);
    } else if (root->nodetype == ARROWNODE) {
        printf(" (ARROWNODE '->')");
        if (root->left && root->right)
            printf(" [%s->%s]", root->left->varname, root->right->varname);
    }

    if (root->varname)
        printf(" %s", root->varname);
    if (root->val != 0)
        printf(" val=%d", root->val);

    if (root->dimlist)
        print_dimlist(root->dimlist);
    if (root->plist)
        print_paramlist(root->plist);
    if (root->Gentry)
        print_gsymbol(root->Gentry);

    printf("\n");

    if (root->left)
        tree_visual_print_tree_compact(root->left, depth + 1);
    if (root->middle)
        tree_visual_print_tree_compact(root->middle, depth + 1);
    if (root->right)
        tree_visual_print_tree_compact(root->right, depth + 1);
}

/*---------------------------------------------------------
 * Public interface: Compact print
 *--------------------------------------------------------*/
void tree_visual_printTreeCompact(tnode *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    printf("\nCompact Tree View:\n");
    printf("==================\n");
    tree_visual_print_tree_compact(root, 0);
    printf("\n");
}
