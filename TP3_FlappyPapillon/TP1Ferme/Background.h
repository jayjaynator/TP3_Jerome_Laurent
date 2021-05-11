#pragma once


class Background
{
public:
	Background();
	Background(double PositionDepartX);
	~Background();

	void Update(long Millis);
	double GetPositionX() const;

	

private:
	double PositionX;
	

};