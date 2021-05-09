#pragma once
#include "GameObject.h"
#include "Obstacle.h"

class Papillon : public GameObject
{
public:
	Papillon();
	~Papillon();

	virtual void Update(long Millis) override;

	double GetLargeur() const;
	double GetHauteur() const;

	void Sauter();
	void Rebondir();
	void PerdreUneVie();

	bool SortieHaut();
	bool SortieBas();
	bool DetectionCollision(Obstacle* obstacle);
	int GetVies() const;


protected:
	double Largeur, Hauteur;
	double AccelerationY;
	double VelocityY;
	int Vies;

};
