#pragma once
#include"Object.h"

class Node
{
public:

	Node *left;
	Node *right;
	Object m_data;
	int m_id ;
	int m_radius;

	void Init( Node *L = 0, Node *R = 0, int Radius = 0);
	void Update(float dt = 0);
	void Render(RenderWindow &wnd);

	Node();
	~Node();
};
