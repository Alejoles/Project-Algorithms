#ifndef _Simpleg_hpp_
#define _Simpleg_hpp_

#include <string>
#include <map>
#include <set>

struct Node;
struct Edge;

struct SimpleGraph{
	set<Node* > nodes;
	set<Edge* > edges;
	map<std::string, Node*> nodeMap;
};

struct Node{
	std::string name;
	set<Edge* > edges;
};

struct Edge {
	Node *Tail;
	Node *Head;
	double cost;
};

#endif // _Simpleg_hpp_
