#pragma once


class Background
{
public:
	Background();
	Background(double PositionDepartX);
	~Background();

	void Update(long Millis);
	double GetPositionX() const;

	void ActiverAcceleration();
	void DesactiverAcceleration();

private:
	double PositionX;
	bool AccelerationActive;

};