#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>   // for mkdir()
#include <sys/types.h>
#include "../AST.h"       // Include your tnode definition and NodeType enum

FILE *stream;
int node_counter = 0;

// Forward declaration
void graphviz_traverse(struct tnode *node);

/*
 * Generate a descriptive key (label) for each node
 */
char* node_label(struct tnode *node) {
    char *label = malloc(128);
    if (!label) exit(1);

    sprintf(label, "%s", nodetype_to_string(node->nodetype));

    if (node->varname)
        sprintf(label + strlen(label), "\\nvar: %s", node->varname);
    if (node->type)
        sprintf(label + strlen(label), "\\ntype: %d", node->type);
    if (node->val)
        sprintf(label + strlen(label), "\\nval: %d", node->val);

    return label;
}

/*
 * Recursive traversal that emits Graphviz edges
 */
void graphviz_traverse(struct tnode *node) {
    if (!node) return;

    int this_id = ++node_counter;
    char *label = node_label(node);
    fprintf(stream, "  n%d [label=\"%s\", shape=box, style=rounded, color=blue];\n", this_id, label);
    free(label);

    // For each child, connect and recurse
    struct {
        struct tnode *child;
        const char *edge_name;
    } children[] = {
        { node->left,   "left" },
        { node->middle, "middle" },
        { node->right,  "right" }
    };

    for (int i = 0; i < 3; i++) {
        if (!children[i].child) continue;

        int child_id = node_counter + 1;
        fprintf(stream, "  n%d -> n%d [label=\"%s\"];\n", this_id, child_id, children[i].edge_name);

        // Avoid infinite recursion on middle args in FUNCTIONNODE
        if (node->nodetype == FUNCTIONNODE && strcmp(children[i].edge_name, "middle") == 0)
            continue;

        graphviz_traverse(children[i].child);
    }

    // Special handling for function argument lists
    if (node->nodetype == FUNCTIONNODE && node->right) {
        struct tnode *arg = node->right;
        while (arg) {
            int child_id = node_counter + 1;
            fprintf(stream, "  n%d -> n%d [label=\"arg\"];\n", this_id, child_id);
            graphviz_traverse(arg);
            arg = arg->middle;
        }
    }
}

/*
 * Main function to generate the .gv file inside ./TreeViz/
 */
void export_ast_to_graphviz(struct tnode *root, const char *filename) {
    // Ensure output directory exists
    const char *dir = "./TreeViz";
    struct stat st = {0};
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0755);
    }

    // Construct full file path
    char path[256];
    snprintf(path, sizeof(path), "%s/%s.gv", dir, filename);

    stream = fopen(path, "w");
    if (!stream) {
        perror("Failed to open output file");
        return;
    }

    fprintf(stream, "digraph AST {\n");
    fprintf(stream, "  node [fontname=\"Arial\"];\n");

    node_counter = 0;
    graphviz_traverse(root);

    fprintf(stream, "}\n");
    fclose(stream);

    printf("✅ Graphviz file generated: %s\n", path);
}

