#pragma once



#include <vector>
#include <algorithm>
#include <ctime>
#include "shapes.h"

bool compareByRadius(shape* left, shape* right);


class mainObj
{
	std::vector<shape*> arrShape_1;
	std::vector<shape*> arrShape_2;
	unsigned int quantity;
	int minRadius;
	int maxRadius;
	int direction;	
	void ClearArr_1_2();

	
	

public:

	mainObj();
	~mainObj();
	void CreateArray1();
	void CreateArray2();
	void SortArray2();
	
#pragma region print

	void PrintInfoArr1();
	void PrintInfoArr2();



#pragma endregion

#pragma region get_set

	int GetMinRadius();
	int GetMaxRadius();
	void SetQuantity(int size);
	void SetMinRadius(int size);
	void SetMaxRadius(int size);
	void SetTraversalDirection(int set);

#pragma endregion
	
};

