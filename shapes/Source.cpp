#include "Source.h"


//флаг для бесконечного ожидания ввода от пользователя
bool flag = true;

#pragma region first


void WaitingInput()
{
	mainObj myObj;

	mainObj* obj = &myObj;

	while (flag)
	{
		switch (_getch())
		{
		case '0':
			LoopStop();
			break;
		case '1':
			PrintContainer1(obj);
			break;
		case '2':
			CreateContainer2(obj);
			break;
		case '3':
			SortContainer2(obj);
			break;
		case '4':
			PrintContainer2(obj);
			break;
		case '5':
			SetQuantityLimit(obj);
			break;
		case '6':
			SetMinRadius(obj);
			break;
		case '7':
			SetMaxRadius(obj);
			break;
		case '8':
			SetTraversalDirection(obj);
			break;
		case '9':
			Info();
			break;

		default:
			break;
		}
	}
}

#pragma endregion

#pragma region executed functions

void LoopStop()
{
	std::cout<<"Exit................."<<std::endl;
	flag = false;
}

void PrintContainer1(mainObj* obj)
{
	obj->PrintInfoArr1();
}

void CreateContainer2(mainObj* obj)
{
	obj->CreateArray2();
}

void SortContainer2(mainObj* obj)
{
	obj->SortArray2();
}

void PrintContainer2(mainObj* obj)
{
	obj->PrintInfoArr2();
}

void SetQuantityLimit(mainObj* obj)
{
	int size = 0;

	//ввод с защитой
	do
	{
		std::cout << "\nEnter number > 0 " << " :  ";
		std::cin >> size;

	} while (size <= 0 );

	obj->SetQuantity(size);
}

void SetMinRadius(mainObj* obj)
{
	int minRad = 0;

	//ввод с защитой
	do 
	{
		std::cout << "\nEnter min radius > 0 and < " << obj->GetMaxRadius() <<" :  ";
		std::cin >> minRad;

	} while (minRad < 0 || minRad > obj->GetMaxRadius());

	obj->SetMinRadius(minRad);
}

void SetMaxRadius(mainObj* obj)
{
	int maxRad = 0;
	//ввод с защитой
	do
	{
		std::cout << "\nEnter max > " << obj->GetMinRadius() <<" :  ";
		std::cin >> maxRad;

	} while (maxRad < 0 || maxRad < obj->GetMinRadius());

	obj->SetMaxRadius(maxRad);
}

void SetTraversalDirection(mainObj* obj)
{
	int inp;
	std::cout << "\nDirection: enter \"0\" for negative or \"1\" for positive:     ";
	std::cin >> inp;
	if (inp != 0)
	{
		std::cout << "the direction is set to positive\n" << std::endl;
		obj->SetTraversalDirection(1);
	}
	else
	{
		std::cout << "the direction is set to negative\n" << std::endl;
		obj->SetTraversalDirection(-1);
	}
}

void Info()
{
	std::cout<<""<<std::endl;
	std::cout<<"\tkey 0: ......................exit"<<std::endl;
	std::cout<<"\tkey 1: print  container_1"<<std::endl;
	std::cout<<"\tkey 2: create  container_2"<<std::endl;
	std::cout<<"\tkey 3: sort container_2"<<std::endl;
	std::cout<<"\tkey 4: print container_2"<<std::endl;
	std::cout<<"\tkey 5: ...........................set quantity limit (10 by default)"<<std::endl;
	std::cout<<"\tkey 6: ...........................set  min radius  (1 by default)"<<std::endl;
	std::cout<<"\tkey 7: ...........................set  max radius  ( 100 by default)"<<std::endl;
	std::cout<<"\tkey 8: ...........................set traversal direction (default is positive)"<<std::endl;
	std::cout<<"\tkey 9: ......................info"<<std::endl;;
	std::cout<<""<<std::endl;


}

#pragma endregion