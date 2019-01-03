#include "Node.h"

void Node::Init( Node *L , Node *R , int Radius)
{
	left = L;
	right = R;
	m_data.Spri.setRotation(Radius);
	m_radius = Radius;
}
void Node::Update(float dt )
{
	m_data.Update(dt);
}
void Node::Render(RenderWindow &wnd)
{
	wnd.draw(m_data.Spri);
}

Node::Node()
{
	left = nullptr;
	right = nullptr;
	m_id = 1;
	m_radius = 0;
}
Node::~Node()
{

}