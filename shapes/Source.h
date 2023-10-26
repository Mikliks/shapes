#pragma once


#include <conio.h>
#include <thread>

#include "mainObj.h"




#pragma region first


void WaitingInput();

#pragma endregion

#pragma region executed functions

void LoopStop();
void PrintContainer1(mainObj * obj);
void CreateContainer2(mainObj* obj);
void SortContainer2(mainObj* obj);
void PrintContainer2(mainObj* obj);
void SetQuantityLimit(mainObj* obj);
void SetMinRadius(mainObj* obj);
void SetMaxRadius(mainObj* obj);
void SetTraversalDirection(mainObj* obj);
void Info();

#pragma endregion
