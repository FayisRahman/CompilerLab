#include "tree_visualization.h"


void print_dimlist(DimNode* dimlist) {
    printf("Dims:[");
    while (dimlist) {
        printf("%d ", dimlist->size);
        dimlist = dimlist->next;
    }
    printf("] ");
}

void print_paramlist(ParamList* plist) {
    printf("Params:[");
    while (plist) {
        printf("%s:%s ", plist->name, type_to_string(plist->type));
        plist = plist->next;
    }
    printf("] ");
}

void print_gsymbol(Gsymbol* g) {
    if (!g) return;
    printf("Gentry:{name:%s type:%s varType:%d size:%d bind:%d flabel:%d} ",
           g->name,
           type_to_string(g->type),
           g->varType,
           g->size,
           g->binding,
           g->flabel);
}


void tree_visual_print_tree_structure(tnode *root, char *prefix, int is_last, int is_root,int skip_middle){
    if (!root)
        return;

    // Print current node with branch lines
    if (!is_root) {
        printf("%s", prefix);
        printf("%s", is_last ? "└── " : "├── ");
    }

    // Print node info
    printf("[%s] ", nodetype_to_string(root->nodetype));
    if (root->varname)
        printf("var:%s ", root->varname);

    printf("type:%s ", type_to_string(root->type));
    if (root->type == TYPE_INT)
        printf("val:%d ", root->val);

    if (root->dimlist)
        print_dimlist(root->dimlist);
    if (root->plist)
        print_paramlist(root->plist);
    if (root->Gentry)
        print_gsymbol(root->Gentry);

    printf("\n");

    // Prepare new prefix for children
    char new_prefix[256];
    if (is_root)
        strcpy(new_prefix, "");
    else {
        strcpy(new_prefix, prefix);
        strcat(new_prefix, is_last ? "    " : "│   ");
    }

    int child_count = 0;
    int printed_children = 0;

    // FUNCTIONNODE special handling
    if (root->nodetype == FUNCTIONNODE) {
        // Count children: left (function name) + number of args in right->middle chain
        int child_count = 0;
        if (root->left) child_count++; // function name
    
        tnode *arg = root->right;
        while (arg) { child_count++; arg = arg->middle; }
    
        int printed_children = 0;
    
        // Print function name
        if (root->left) {
            printed_children++;
            tree_visual_print_tree_structure(root->left, new_prefix,
                                     printed_children == child_count, 0,0);
        }
    
        // Print all arguments (start from right, follow middle)
        arg = root->right;
        while (arg) {
            printed_children++;
            tree_visual_print_tree_structure(arg, new_prefix,
                                     printed_children == child_count, 0,1);
            arg = arg->middle;
        }
    
        return;
    }
    // Normal nodes: left, middle, right
    if (root->left) child_count++;
    if (root->middle) child_count++;
    if (root->right) child_count++;

    if (root->left) {
        printed_children++;
        tree_visual_print_tree_structure(root->left, new_prefix,
                                 printed_children == child_count, 0,skip_middle);
    }
    if (root->middle && !skip_middle) {
        printed_children++;
        tree_visual_print_tree_structure(root->middle, new_prefix,
                                 printed_children == child_count, 0,skip_middle);
    }
    if (root->right) {
        printed_children++;
        tree_visual_print_tree_structure(root->right, new_prefix,
                                 printed_children == child_count, 0,skip_middle);
    }
}

void tree_visual_printTree(tnode *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    printf("\nTree Structure:\n");
    printf("================\n");
    tree_visual_print_tree_structure(root, "", 1, 1,0);
    printf("\n");
}

void tree_visual_print_tree_compact(tnode *root, int depth) {
    if (root == NULL)
        return;

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("|- [%s]", nodetype_to_string(root->nodetype));
    if (root->varname)
        printf(" %s", root->varname);
    if (root->val != 0)
        printf(" val=%d", root->val);

    // Extra info
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

