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

	void ActiverAcceleration();
	void DesactiverAcceleration();

protected:
	double PositionX, PositionY;
	bool AccelerationActive;

};
