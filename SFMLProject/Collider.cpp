#include "stdafx.h"
#include "Collider.h"
#include "CollisionRectangle.h"
#include "CollisionPoint.h"
#include "CollisionCircle.h"

int Collider::globalCount = 0;

Collider::Collider(ColliderType colliderType, ColliderLayer layer, sf::Vector2f offset, sf::Vector2f size)
	: active(true)
	, collision(nullptr)
	, collisionCount(0)
	, iD(globalCount++)
	, colliderLayer(layer)
	, isDestory(false)
{
	CreateCollision(colliderType, layer, offset, size);
}

Collider::~Collider()
{
	if (collision != nullptr)
		delete collision;
}

void Collider::SetOrigin(sf::Vector2f origin)
{
	collision->SetOrigin(origin);
}

void Collider::SetPosition(sf::Vector2f pos)
{
	position = pos + offsetPosition;
	collision->SetPosition(position);
}

sf::Vector2f Collider::GetPosition()
{
	return collision->GetPosition();
}

sf::Vector2f Collider::GetScale()
{
	return collision->GetScale();
}

void Collider::SetScale(sf::Vector2f size)
{
	collision->SetScale(size);
}

void Collider::CreateCollision(ColliderType colliderType, ColliderLayer layer, sf::Vector2f offset, sf::Vector2f size)
{
	if (ColliderType::Rectangle == colliderType)
		collision = new CollisionRectangle(size);
	else if (ColliderType::Circle == colliderType)
		collision = new CollisionCircle(size.x);
	else
		collision = new CollisionPoint();

	offsetPosition = offset;
	collision->SetOwner(this);
	ColliderManager::GetInstance().AddCollider(this, layer);
}

void Collider::Render(sf::RenderWindow& renderWindow)
{
	collision->Render(renderWindow);
}

void Collider::OnCollisionEnter(Collider* target)
{
	collision->IsCollision();
	owner->OnCollisionEnter(target);
}

void Collider::OnCollisionStay(Collider* target)
{
	owner->OnCollisionStay(target);
}

void Collider::OnCollisionEnd(Collider* target)
{
	collision->EndCollision();
	owner->OnCollisionEnd(target);
}

ColliderType Collider::GetColliderType()
{
	return collision->GetColliderType();
}
