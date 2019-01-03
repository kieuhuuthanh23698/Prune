#include "tree.h"



void tree::Init(RenderWindow &wnd, float time )
{
	Vector2i pos_mouse = Mouse::getPosition(wnd);
	//root = new Node();
	root->m_data.Init(pos_mouse.x,pos_mouse.y, time);

}

void Add_node(Node *root)
{
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL && root->m_data.Spri.getScale().x > 3)
	{
		int x = root->m_data.Spri.getPosition().x;
		int y = root->m_data.Spri.getPosition().y + root->m_data.Spri.getScale().y*15;
		cout << " Scale : " << root->m_data.Spri.getScale().x<< endl;
		if (root->m_id % 3 == 0)
		{
			srand(time(NULL));
			Node *temp = new Node();
			temp->m_data.Init(x,y);
			temp->m_id = root->m_id + 1;
			int r = (rand() % (30 - 20 + 1) + 20);
			temp->m_radius = root->m_radius + r;
			temp->m_data.Spri.setRotation(temp->m_radius);
			root->left=temp;
			cout << temp->m_id << endl;
			cout << "Radius1 : "      << temp->m_id <<" "<< temp->m_radius << endl;

			srand(time(NULL));
			Node *temp2 = new Node();
			temp2->m_data.Init(x, y);
			temp2->m_id = root->m_id + 1;
			r= (rand() % (-30 +20 + 1) - 20);
			temp2->m_radius = root->m_radius + r;
			temp2->m_data.Spri.setRotation(temp2->m_radius);
			cout << "Radius 2  : " << temp2->m_radius << endl;
			root->right = temp2;
			return;
		}
		else
		{
			Node *temp = new Node();
			temp->m_data.Init(x, y);
			temp->m_id = root->m_id + 1;
			temp->m_radius = root->m_radius;
			temp->m_data.Spri.setRotation(temp->m_radius);

			root->left = temp;
			cout << temp->m_id << endl;
			cout << " Y2 : " << y << endl;
			return;
		}
	}
	Add_node(root->left);
	Add_node(root->right);
}

void grown(Node *root,float dt)
{
	if (root == NULL) return;
	if (root->m_data.Spri.getScale().x < 5)
	{
		root->m_data.Update(dt);
	}
	grown(root->left,dt);
	grown(root->right, dt);
}

void tree::Update(float dt)
{
	if (root == NULL)return;
	else
	{
		grown(root, dt);
		Add_node(root);
	}

}
void render(Node *root, RenderWindow &wnd)
{
	if (root == NULL) return;
	wnd.draw(root->m_data.Spri);
	render(root->left,wnd);
	render(root->right,wnd);
}

void tree::Render(RenderWindow &wnd)
{
	render(root, wnd);
}

tree::tree()
{
	root = new Node();
}

tree::~tree()
{
}
