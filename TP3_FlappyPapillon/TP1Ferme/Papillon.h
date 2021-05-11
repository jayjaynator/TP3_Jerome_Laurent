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

	void GraviteAffecteVelocite();
	void Sauter();
	void Rebondir();

	int GetVies() const;
	void GagnerUneVie();
	void PerdreUneVie();

	bool GetInvulnerable() const;
	void DevientInvulnerable2Sec();

	bool VelocityPlusGrandA299();
	bool SortieHaut();
	bool SortieBas();
	bool DetectionCollision(Obstacle* obstacle);

	void Acceleration();
	void ResetAcceleration();


protected:
	double Largeur, Hauteur;
	double AccelerationY;
	double VelocityY;
	int Vies;
	bool Invulnerable;

private:
	double NbSecondes=0;
	double NbSecInv = 2;

};
