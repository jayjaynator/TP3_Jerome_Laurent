#pragma once

class GameObject
{
public:
	GameObject(double X, double Y, double L, double H);
	~GameObject() = default;

	virtual void Update(long Millis);

	double GetX() const;
	double GetY() const;
	void SetX(double X);
	void SetY(double Y);
	double GetLargeur() const;
	double GetHauteur() const;

protected:
	double PositionX, PositionY;
	double Largeur, Hauteur;

};
