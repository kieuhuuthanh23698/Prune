// Prune.cpp : Defines the entry point for the console application.
//
#include <cstdlib>
#include "stdafx.h"
#include <iostream>
#include "SFML\Graphics.hpp"

using namespace sf;
using namespace std;

#define WINDOWS_W	900
#define WINDOWS_H	600
#define FPS_LIMIT	60

struct CanhCay
{
	float x, y;
};

struct NodeTree
{
	CanhCay canhCay;
	NodeTree *nodeLeft = NULL, *nodeRight = NULL;
};

void render(NodeTree *root, sf::RenderWindow &window)
{
	if (root == NULL || root->nodeLeft == NULL)
		return;
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(root->canhCay.x, root->canhCay.y)),
		sf::Vertex(sf::Vector2f(root->nodeLeft->canhCay.x, root->nodeLeft->canhCay.y))
	};
	window.draw(line, 2, sf::Lines);
	if (root->nodeRight != NULL)
	{
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(root->canhCay.x, root->canhCay.y)),
			sf::Vertex(sf::Vector2f(root->nodeRight->canhCay.x, root->nodeRight->canhCay.y))
		};
		window.draw(line, 2, sf::Lines);
		render(root->nodeRight, window);
	}
	render(root->nodeLeft, window);
}


void ReNhanh(NodeTree *nhanh)
{
	if (nhanh == NULL)
		return;
	if (nhanh->nodeLeft == NULL && nhanh->nodeRight == NULL)
	{
		srand(time(NULL));
		int a = 10, b = 30;
		int r = (rand() % (b - a + 1) + a);
		float ran = r / 2.0; 
		std::cout << "ran: " << ran << std::endl;
		//thêm nhánh trái
		NodeTree *nhanhMoiTrai = new NodeTree();
		nhanhMoiTrai->canhCay.x = nhanh->canhCay.x - ran;
		nhanhMoiTrai->canhCay.y = nhanh->canhCay.y - 10;
		nhanh->nodeLeft = nhanhMoiTrai;
		//thêm nhánh phải
		srand(time(NULL));
		r = (rand() % (b - a + 1) + a);
		ran = r / 2.0;
		std::cout << "ran: " << ran << std::endl;
		NodeTree *nhanhMoiPhai = new NodeTree();
		nhanhMoiPhai->canhCay.x = nhanh->canhCay.x + ran;
		nhanhMoiPhai->canhCay.y = nhanh->canhCay.y - 10;
		nhanh->nodeRight = nhanhMoiPhai;
		return;
	}
	else
	{
		ReNhanh(nhanh->nodeLeft);
		ReNhanh(nhanh->nodeRight);
	}
}

void ThemNhanh(NodeTree *nhanh)
{
	if (nhanh == NULL)
		return;
	if (nhanh->nodeLeft == NULL && nhanh->nodeRight == NULL)
	{
		srand(time(NULL));
		int a = 0, b = 1;
		int ran = (rand() % (b - a + 1) + a);
		NodeTree *nhanhMoi = new NodeTree();
		if(ran == 0)
			nhanhMoi->canhCay.x = nhanh->canhCay.x + 3;
		else
			nhanhMoi->canhCay.x = nhanh->canhCay.x - 3;
		nhanhMoi->canhCay.y = nhanh->canhCay.y - 10;
		nhanh->nodeLeft = nhanhMoi;
	}
	else
	{
		ThemNhanh(nhanh->nodeLeft);
		ThemNhanh(nhanh->nodeRight);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "PRUNE!", Style::Default);
	window.setFramerateLimit(FPS_LIMIT);
	Clock clock;
	Time elapsed;
	//========================INIT
	NodeTree root;
	root.canhCay.x = 450; root.canhCay.y = 600;
	float dentaTime = 0;
	int soNhanh = 0;

	//========================LOOP
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		elapsed = clock.getElapsedTime();
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;
		std::cout << "dt: " << dt << std::endl; 
		std::cout << "denta time " << dentaTime << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();
		// ================================ Update ================================ 
		//sau một thời gian nhất định thì cây sẽ thêm 1 nhánh, cây khi thêm đủ 3 nhánh thì sẽ tách thành 2 nhánh
		dentaTime += dt + 0.05;
		if (dentaTime >= 2)
		{
			if (soNhanh == 3)
			{
				ReNhanh(&root);//them trai , phai
				soNhanh = 0;
			}
			else
			{
				ThemNhanh(&root);//chi them trai
				soNhanh++;
				dentaTime = 0;
			}
		}
		
		// ================================ Draw ================================ 
		window.clear();
		//render
		
		render(&root, window);
		/*sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(450,600)),
			sf::Vertex(sf::Vector2f(450,590))
		};
		window.draw(line, 2, sf::Lines);*/
		window.display();
	}
    return 0;
}

