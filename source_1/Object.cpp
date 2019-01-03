#include "Object.h"

void Object::Init(int x , int y , float time )
{
	tex.loadFromFile(TEXTURE_TREE);
	Spri.setTexture(tex);
	Spri.setPosition(x, y);
	Spri.setOrigin(tex.getSize().x / 2, 0);
	m_time = time;
}

void Object::Update(float dt) 
{
	float x = Spri.getScale().x + dt ;
	if (x < 5 )
	{
		Spri.setScale(x, -x);
	}
}

Object::Object()
{
	m_time = NULL;
}
Object::~Object()
{}