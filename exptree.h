#ifndef EXPTREE_H
#define EXPTREE_H

typedef enum NodeType {
    READNODE,           // 0
    WRITENODE,          // 1
    CONNECTOR,          // 2
    OPERATOR,           // 3
    ASSIGNMENT,         // 4
    IFNODE,             // 5
    EXPRESSION,         // 6
    WHILENODE,          // 7
    DOWHILENODE,        // 8
    BREAKNODE,          // 9
    CONTINUENODE,       // 10
    VARNODE,            // 11
    LEAFNODE,           // 12
    ADDRNODE,           // 13
    PTRNODE,            // 14
    FUNCTIONNODE,       // 15
    RETURNNODE,         // 16
    BREAKPOINTNODE,     // 17
    DOTNODE,            // 18
    ARROWNODE,          // 19
    ALLOCNODE,          // 20
    FREENODE,           // 21
    INITIALIZENODE,     // 22
    NULLNODE,           // 23
} NodeType;

typedef enum DataType {
    TYPE_NULL,      // 0
    TYPE_INT,       // 1
    TYPE_STRING,    // 2
    TYPE_BOOL,      // 3
    TYPE_VAR,       // 4 
    TYPE_ARR,       // 5
    TYPE_PTR,       // 6
    TYPE_ADDR,      // 7
    TYPE_FUNCT,     // 8
    TYPE_FUNCT_PTR, // 9
    TYPE_TUPLE,     // 10
    TYPE_VOID,      // 11
} DataType;



#endif