#pragma once

class CVector2 {
private:
	int	x;
	int	y;
public:
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	void Add(const CVector2& v)
	{
		x += v.x;
		y += v.y;
	}
	void Set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};