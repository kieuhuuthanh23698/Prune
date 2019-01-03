#pragma once
#include"Node.h"

class tree
{
public:
	Node *root;
	tree();
	void Init(RenderWindow &wnd, float time = 0) ;
	void Update(float dt);
	void Render(RenderWindow &wnd);
	~tree();
};

