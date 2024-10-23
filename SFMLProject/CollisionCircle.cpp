#include "stdafx.h"
#include "CollisionCircle.h"


CollisionCircle::CollisionCircle(float radian)
	: radian(radian)
	, Collision(ColliderType::Circle)
	, collisionCircle(radian)
{
	Init();
}

CollisionCircle::~CollisionCircle()
{
}

void CollisionCircle::Init()
{
	collisionCircle.setFillColor(sf::Color::Transparent);
	collisionCircle.setOutlineColor(sf::Color::Green);
	collisionCircle.setOutlineThickness(1);
	collisionCircle.setRadius(radian);
	collisionCircle.setOrigin({ radian, radian });
}

void CollisionCircle::Update()
{
	Collision::Update();
}

void CollisionCircle::Render(sf::RenderWindow& renderWindow)
{
	if (collisionCount > 0)
		collisionCircle.setOutlineColor(sf::Color::Red);
	else
		collisionCircle.setOutlineColor(sf::Color::Green);

	renderWindow.draw(collisionCircle);
}

void CollisionCircle::SetPosition(const sf::Vector2f& pos)
{
	collisionCircle.setPosition(pos);
	Collision::SetPosition(pos);
}

void CollisionCircle::SetScale(sf::Vector2f size)
{
	collisionCircle.setRadius(size.x / 2.f);
}