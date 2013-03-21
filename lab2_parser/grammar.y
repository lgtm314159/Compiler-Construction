%{
#include <iostream>
%}

%%

%token DIGIT

%%
program: TOKEN_PROGRAM TOKEN_ID TOKEN_SEMICLON (typeDefinitions |)
    (variableDeclarations |) (subprogramDeclarations |)
    compoundStatement TOKEN_DOT
    { cout << "program" << endl; };

typeDefinitions: TOKEN_TYPE typeDefinitionList;

typeDefinitionList: typeDefinitionList typeDefinition | typeDefinition;

variableDeclarations: TOKEN_VAR variableDeclarationList;

variableDeclarationList: variableDeclarationList variableDeclaration
    | variableDeclaration;

variableDeclaration: identifierList TYOKEN_COLON type TOKEN_SEMICOLON;

subprogramDeclarations: subpprogramDeclarationList;

subprogramDeclarationList: subprogramDeclarationList
    (procedureDeclaration | functionDeclaration)
    |;

typDefinition: TOKEN_ID TOKEN_EQ type TOKEN_SEMICOLON;

procedureDeclaration: TOKEN_PROCEDURE TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_SEMICOLON (block | TOKEN_FORWARD) TOKEN_SEMICOLON;

functionDeclaration: TOKEN_FUNCTION TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_COLON resultType TOKEN_SEMICOLON (block | TOKEN_FORWARD)
    TOKEN_SEMICOLON;

formalParameterList: formalParamSeq |;

formalParamSeq: formalParamSeq identifierList TOKEN_COLON type TOKEN_SEMICOLON
    | identifierList TOKEN_COLON type TOKEN_SEMICOLON;

block: (variableDeclarations |) compoundStatement;

compoundStatement: TOKEN_BEGIN statementSequence TOKEN_END;

statementSequence: statementSequence statement | statement;

statement: (simpleStatement | structuredStatement) TOKEN_SEMICOLON;

simpleStatement: assignmentStatement | procedureStatement |;

assignmentStatement: variable TOKEN_ASSIGN expression;

procedureStatement: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR

structuredStatement: compoundStatement
    | TOKEN_IF expression TOKEN_THEN statement ((TOKEN_ELSE statement) |)
    | TOKEN_WHILE expression TOKEN_DO statement
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO statement;

type: TOKEN_ID | TOKEN_ARRAY TOKEN_LBRACKET constant TOKEN_RANGE constant TOKEN_RBRACKET TOKEN_OF type
    | TOKEN_RECORD fieldList TOKEN_END;

resultType: TOKEN_ID;

fieldList: fieldListSeq |;

fieldListSeq: fieldListSeq identifierList TOKEN_COLON type TOKEN_SEMICOLON
    | identifierList TOKEN_COLON type TOKEN_SEMICOLON;

constant: (sign |) TOKEN_KW_INT;

expression: simpleExpression ((relationalOp simpleExpression) |);

relationalOp: TOKEN_LT | TOKEN_LE | TOKEN_GT | TOKEN_GE | TOKEN_NE | TOKEN_EQ;

simpleExpression: (sign |) term addOpTermList;

addOpTermList: addOpTermList addOp term|;

addOp: TOKEN_PLUS | TOKEN_MINUS | TOKEN_OR;

term: factor mulOpFactorList;

mulOpFactorList: mulOpFactorList mulOp Factor |;

mulOp: TOKEN_MULTIPLY | TOKEN_DIV | TOKEn_MOD | TOKEN_AND;

factor: TOKEN_KW_INT | TOKEN_KW_STR | variable | functionReference
    | TOKEN_NOT factor | TOKEN_LPAR expression TOKEN_RPAR;

functionReference: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR;

variable: TOKEN_ID componentSelection;

componentSelection: ((TOKEN_DOT TOKEN_ID componentSelection) | (TOKEN_LBRACKET expression TOKEN_RBRACKET componentSelection))
    |;

actualParameterList: expressionList |;

expressionList: expressionList expression | expression;

identifierList: identifierList TOKEN_COMMAS TOKEN_ID | TOKEN_ID;

sign: TOKEN_PLUS | TOKEN_MINUS %prec UMINUS







compoundStatement: TOKEN_BEGIN statementSequence TOKEN_END;

statementSequence: statementSequence TOKEN_SEMICOLON statement | statement;

statement: groupSimStruStatement;

groupSimStruStatement: simpleStatement | structuredStatement;

simpleStatement: assignmentStatement | procedureStatement |;

assignmentStatement: variable TOKEN_ASSIGN expression;

procedureStatement: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR

structuredStatement: compoundStatement
    | conditionalStatement
    | TOKEN_WHILE expression TOKEN_DO statement
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO statement;

conditionalStatement: matchedStatement | openStatement;

matchedStatement: TOKEN_IF expression TOKEN_THEN matchedStatement TOKEN_ELSE matchedStatement
    | simpleStatement | compoundStatement | TOKEN_WHILE expression TOKEN_DO matchedStatement | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO matchedStatement;

openStatement: TOKEN_IF expression TOKEN_THEN statement
    | TOKEN_IF expression TOKEN_THEN matchedStatement TOKEN_ELSE openStatement;




 

conditionalStatement: TOKEN_IF expression TOKEN_THEN statement
    | TOKEN_IF expressoin TOKEN_THEN closedStatement TOKEN_ELSE openStatement
    | TOKEN_IF expressoin TOKEN_THEN closedStatement TOKEN_ELSE closedStatement;

whileStatement: TOKEN_WHILE expression TOKEN_DO openStatement
    | TOKEN_WHILE expression TOKEN_DO closedStatement;

forStatement: TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO openStatement
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO closedStatement




closedCompoundStatement: TOKEN_BEGIN closedStatementSequence TOKEN_END;

closedStatementSequence: closedStatementSequence TOKEN_SEMICOLON closedStatement | closedStatement;

statement: openStatement | closedStatement;

openStatement: compoundStatement
    | TOKEN_IF expression TOKEN_THEN statement
    | TOKEN_IF expressoin TOKEN_THEN closedStatement TOKEN_ELSE openStatement
    | TOKEN_WHILE expression TOKEN_DO openStatement
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO openStatement;

closedStatement: simpleStatment
    | closedCompoundStatement
    | TOKEN_IF expressoin TOKEN_THEN closedStatement TOKEN_ELSE closedStatement 
    | TOKEN_WHILE expression TOKEN_DO closedStatement
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO closedStatement;

