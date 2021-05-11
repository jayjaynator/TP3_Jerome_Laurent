#pragma once

class GameObject
{
public:
	GameObject(double X, double Y);
	~GameObject() = default;

	virtual void Update(long Millis);

	double GetX() const;
	double GetY() const;
	void SetX(double X);
	void SetY(double Y);

	

protected:
	double PositionX, PositionY;
	

};
