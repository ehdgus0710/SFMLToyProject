#pragma once

class Collision
{
protected:
	ColliderType colliderType;
	sf::Vector2f position;

	int collisionCount;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(sf::RenderWindow& renderWindow);

	void IsCollision() { ++collisionCount; }
	void EndCollision() { --collisionCount; }

	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }
	sf::Vector2f GetPosition() { return position; }

	virtual void SetOrigin(const sf::Vector2f& origin) = 0;

	virtual sf::Vector2f GetScale() const = 0;
	virtual void SetScale(sf::Vector2f size);

	const ColliderType GetColliderType() { return colliderType; }
public:
	Collision(ColliderType colliderType);
	~Collision() {}

};

