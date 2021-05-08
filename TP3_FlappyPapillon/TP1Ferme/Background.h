#pragma once


class Background
{
public:
	Background();
	Background(double PositionDepartX);
	~Background();

	void Update();
	double GetPositionX() const;


private:
	double PositionX;
	double BGSpeed = 1;
};