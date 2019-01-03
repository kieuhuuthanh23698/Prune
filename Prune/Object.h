#pragma once
#include"resource.h";

class Object
{
public:

	Texture tex;
	Sprite  Spri;
	float m_time;

	void Update(float dt);
	void Init( int x, int y, float time = 0);
	Object();
	~Object();
};

