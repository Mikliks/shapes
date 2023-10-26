#include "mainObj.h"

bool compareByRadius(shape* left, shape* right)
{
	return left->GetRadius() < right->GetRadius();
}

#pragma region first

mainObj::mainObj()
{
	quantity = 10;
	minRadius = 1;
	maxRadius = 100;
	direction = true;

	CreateArray1();
}
mainObj::~mainObj()
{
	for (shape* shape : arrShape_1)
	{
		delete shape;
	}

	for (shape* shape : arrShape_2)
	{
		delete shape;
	}

}

void mainObj::CreateArray1()
{
	ClearArr_1_2();

	srand((unsigned)time(0));

	int radiusX = 0;
	double step = 0;
	ShapeType type = ShapeType::NotDefine;
	shape* shape = nullptr;

	for (size_t i = 0; i < quantity; i++)
	{
		type = shape::GetType(rand() % countType);
		radiusX = rand() % (maxRadius - minRadius + 1) + minRadius;
		if (type == ShapeType::Ellipse)
		{			
			int param = radiusX / koeffForEllipse;
			shape = new ellipse((double)radiusX, (double)(param == 0 ? 1 : param));
		}
		else if (type == ShapeType::Circle)
		{
			radiusX = rand() % (maxRadius - minRadius + 1) + minRadius;
			shape = new circle((double)radiusX);
		}
		else if (type == ShapeType::Helix)
		{	
			int param = radiusX / koeffForHelixStep;
			step = rand() % (param == 0 ? 1 : param );
			shape = new helix((double)radiusX, step);
		}
		if (shape != nullptr) arrShape_1.push_back(shape);
		shape = nullptr;
	}

	std::cout << "\nCreated array_1 size: "<<quantity<<"   min radius : " << minRadius << "   max radus : " << maxRadius << "         press key \"1(print)\" or \"9(info)\" \n" << std::endl;

}
void mainObj::CreateArray2()
{
	std::vector<shape*> tmp;
	
	for (size_t i = 0; i < arrShape_1.size(); i++)
	{	
		if (arrShape_1[i]->GetName() == "circle")
		{				
			arrShape_2.push_back(arrShape_1[i]);
		}
		else
		{
			tmp.push_back(arrShape_1[i]);
		}
	}
	arrShape_1 = tmp;

	std::cout << "\nCreated array2 size: " << arrShape_2.size()<< "        press key \"4(print)\" or \"9(info)\" \n" << std::endl;
}



void mainObj::SortArray2()
{
	std::sort( arrShape_2.begin(), arrShape_2.end(), compareByRadius);

	std::cout << "\n Container 2 sorted by radius  press key \"4(print)\" or \"9(info)\" \n" << std::endl;
}

void mainObj::ClearArr_1_2()
{
	for (shape* shape : arrShape_1)
	{
		delete shape;
	}
	for (shape* shape : arrShape_2)
	{
		delete shape;
	}
	
	arrShape_1.clear();
	arrShape_2.clear();
}



#pragma endregion

#pragma region print

void mainObj::PrintInfoArr1()
{
	myVector vec, tang;

	std::cout << "\n\t\tFirst Container: size:" << arrShape_1.size() << "\n" << std::endl;

	for (shape* shape : arrShape_1)
	{		
		vec = shape->GetCoordinates(PI_2);
		tang = shape->GetTangent(PI_2,direction);
		std::cout << shape->GetName() << "\tcoord: (" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		if (shape->GetName() == "ellipse")
		{
			std::cout << "\ttang: (??????????, ?????????, ?????????)" << std::endl;
		}
		else
		std::cout << "\ttang: (" << tang.x << ", " << tang.y << ", " << tang.z << ")" << std::endl;
	}
}
void mainObj::PrintInfoArr2()
{
	myVector vec, tang;

	double radSum = 0;


	std::cout << "\n\t\tSecond Container: size:" << arrShape_2.size() << "\n" << std::endl;

	for (shape* shape : arrShape_2)
	{
		vec = shape->GetCoordinates(PI_2);
		tang = shape->GetTangent(PI_2, direction);
		std::cout << shape->GetName() << "\tcoord: (" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		if (shape->GetName() == "ellipse")
		{
			std::cout << "\ttang: (??????????, ?????????, ?????????)" << std::endl;
		}
		else
			std::cout << "\ttang: (" << tang.x << ", " << tang.y << ", " << tang.z << ")" ;
		std::cout << "\tr= " << shape->GetRadius() << std::endl;
		radSum += shape->GetRadius();
	}

	std::cout << "\n\t\tSecond Container: sum of radii of all curves:    " << radSum << "\n" << std::endl;
}


#pragma endregion

#pragma region get_set

int mainObj::GetMinRadius()
{
	return minRadius;
}
int mainObj::GetMaxRadius()
{
	return maxRadius;
}

void mainObj::SetQuantity(int size)
{
	quantity = size;
	CreateArray1();
}
void mainObj::SetMinRadius(int size)
{
	minRadius = size;
	CreateArray1();
}
void mainObj::SetMaxRadius(int size)
{
	maxRadius = size;
	CreateArray1();
}
void mainObj::SetTraversalDirection(int set)
{
	direction = set;	
}

#pragma endregion


