#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

#include "lexer.hpp"

enum NodeType
{
	NODETYPENONE,
	ROOT,
	FUNCTION_DECL,
	VARIABLE_DECL,
	ARGUMENT
};

struct Node;

typedef std::vector<Node> Nodes;

struct Node
{
	NodeType type;
	CType cType;
	std::string spelling;
	Nodes children;
};

struct AST
{
public:
	Node root {NodeType::ROOT};
};

class Parser
{
public:
	bool Parse( Tokens tokens, AST & tree );
};

#endif //PARSER_HPP
