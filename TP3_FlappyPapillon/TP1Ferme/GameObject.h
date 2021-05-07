#pragma once

class GameObject
{
public:
	GameObject();
	~GameObject() = default;

	virtual void Update(long Millis);

	virtual double GetX() const;
	virtual double GetY() const;
	virtual void SetX(double X);
	virtual void SetY(double Y);

protected:
	double PositionX, PositionY;
	double Largeur, Hauteur;

};
