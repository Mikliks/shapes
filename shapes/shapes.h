#pragma once

#include <iostream>

#include <cmath>
#include <string>

// количество типов создаваемых кривых
#define countType 2
// условный коеффициет для генерации случайного шага винтовой линии
#define koeffForHelixStep  10
// условный коеффицеент для задания соотношения большой и малой полуосей эллипса
#define koeffForEllipse 2

#define PI  3.141592653589793
#define PI_2 1.57079632679489661923

struct myVector
{
	double x;
	double y;
	double z;
	myVector(double x = 0, double y = 0, double z = 0) : x{ x }, y{ y }, z{ z }
	{}

};

enum class ShapeType
{
	Circle = 0,
	Ellipse,
	Helix,
	NotDefine
};

class shape
{	
protected:

public:

	static ShapeType GetType(int ntype);
	virtual void PrintInfo() = 0;

	virtual std::string GetName() = 0;
	virtual myVector GetCoordinates(double rad) = 0;
	virtual myVector GetTangent(double rad, int direction) = 0;

	virtual double GetRadius() = 0;
};

class ellipse : public shape
{

protected:
	double radiusX;
	double radiusY;
public:
	ellipse(double radiusX, double radiusY) : radiusX{radiusX}, radiusY{radiusY}
	{}
	
	virtual void PrintInfo() override;
	virtual std::string GetName() override;

	virtual myVector GetCoordinates(double rad) override;
	virtual myVector GetTangent(double rad, int direction) override;

	double GetRadius() override { return radiusX; }
};

class circle : public ellipse
{

public:
	circle(double radiusX) : ellipse(radiusX, radiusX)
	{}

	virtual void PrintInfo() override;
	virtual std::string GetName() override;

	virtual myVector GetCoordinates(double rad) override;
	virtual myVector GetTangent(double rad, int direction) override;

	//double GetRadius() override { return radiusX; }
};
class helix : public circle
{
	double step;
public:
	helix(double radiusX, double step) : circle(radiusX), step{step}
	{}

	virtual void PrintInfo() override final;
	virtual std::string GetName() override final;

	myVector GetCoordinates(double rad) override final;
	myVector GetTangent(double rad, int direction) override final;

	double GetRadius() override final{ return radiusX; }

};