#if 1
#include<ctime>
#include<vector>
#include"tree.h"



class GameManager
{
private:
	tree* root = new tree;
	float t=-1;
public:
	void Init(RenderWindow &window)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	//	temp.Init(TEXTURE_TREE, mousePos.x, mousePos.y);
		root->Init(window);
	}
	void Update(float dt)
	{	

		root->Update(dt);
	}

	void Render(RenderWindow &window)
	{
		root->Render(window);
	}

	static GameManager *getInstance()
	{
		if (s_Intance == nullptr)
		{
			s_Intance = new GameManager();
		}
		return s_Intance;
	}
private:
	static GameManager *s_Intance;

};

GameManager* GameManager::s_Intance = nullptr;

int main()
{
	RenderWindow App(VideoMode(WINDOWS_W, WINDOWS_H), "Game Prune", Style::Default);
	App.setFramerateLimit(3030);
	Clock clock;
	Time elapsed;
	Event evnt;

	Texture t1;
	Sprite s1;
	t1.loadFromFile(TEXTURE_TREE);
	s1.setTexture(t1);
	s1.setPosition(200, 300);
	s1.setOrigin(t1.getSize().x / 2, 0); 


	bool init = true;
	Color b(0,0,0);


	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed && init)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
				//	GameManager::getInstance()->Init(App);
					init = false;

				}
				break;
			}
			if (event.type == Event::Closed)
				App.close();
		}

		elapsed = clock.getElapsedTime();

		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;

		if (Keyboard::isKeyPressed(Keyboard::R))
		{

			s1.setRotation(s1.getRotation()+0.1);
		}
		clock.restart();

		float x =  s1.getScale().x + dt;
		float y = s1.getScale().y + dt;
		if (x < 5 && y > -5)
		{
			cout << "X : " << s1.getPosition().x << endl;
			cout << "Y : " << s1.getPosition().y << endl;

			cout << " RESULT X : " << s1.getPosition().x*s1.getScale().x << endl;
			cout << " RESULT Y : " << s1.getPosition().y*s1.getScale().y << endl;
			s1.setScale(x, -x);
		}

	//	GameManager::getInstance()->Update(dt);


		App.clear(b);

	//	GameManager::getInstance()->Render(App);

		App.draw(s1);

		App.display();

	}
	return EXIT_SUCCESS;
}
#endif