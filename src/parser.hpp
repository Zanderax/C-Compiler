#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

#include "lexer.hpp"

typedef size_t index_t;

struct Node
{
};
typedef std::vector<Node> Nodes;

struct Argument : public Node
{
	std::string spelling;
	CType cType;
};
typedef std::vector<Argument> Arguments;

struct Statement : public Node
{
};
typedef std::vector<Statement> Statements;

struct Block : public Node
{
	Statements statements;
};

struct Function : public Node
{
	std::string spelling;
	CType cType;
	Arguments arguments;
	Block block;
};
typedef std::vector<Function> Functions;

struct AST
{
public:
	Functions functions;
};

class Parser
{
public:
	bool Parse( Tokens tokens, AST & tree );
};

#endif //PARSER_HPP
