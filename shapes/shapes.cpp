#include "shapes.h"

ShapeType shape::GetType(int ntype)
{
    if (ntype == 0) return ShapeType::Ellipse;
    if (ntype == 1) return ShapeType::Circle;
    if (ntype == 2) return ShapeType::Helix;

    return ShapeType::NotDefine;
}



#pragma region ellipse

void ellipse::PrintInfo()
{
    std::cout << "ellpse" << "\trX = " << radiusX << "\trY = " << radiusY << std::endl;
}
std::string ellipse::GetName()
{
    return "ellipse";
}

myVector ellipse::GetCoordinates(double rad)
{  
    double x, y,  z;
    if (rad == PI_2 || rad == -PI_2) x = 0;
    else x = radiusX * cos(rad);
    if (rad == 0 || rad == PI) y = 0;
    else y = radiusY * sin(rad);
    z = 0;
    return myVector(x, y, z);
}
myVector ellipse::GetTangent(double rad, int direction)
{
    return myVector(0,0,0);
}

#pragma endregion

#pragma region circle

void circle::PrintInfo()
{
    std::cout << "circle" << "\tr = " << radiusX << std::endl;
}
std::string circle::GetName()
{
    return "circle";
}

myVector circle::GetCoordinates(double rad)
{
    double x, y, z;
    if (rad == PI_2 || rad == -PI_2) x = 0;
    else x = radiusX * cos(rad);
    if (rad == 0 || rad == PI) y = 0;
    else y = radiusY * sin(rad);
    z = 0;
    return myVector(x, y, z);
}

myVector circle::GetTangent(double rad, int direction)
{
    double x, y, z;
    if (rad == PI_2 || rad == -PI_2) y = 0;
    else y = cos(rad) * direction;
    if (rad == 0 || rad == PI) x = 0;
    else x = sin(rad) * direction;
    z = 0;
    return myVector(x,y,z);
}

#pragma endregion

#pragma region helix

void helix::PrintInfo()
{
    std::cout << "helix" << "\tr = " << radiusX << "\tstep = " << step << std::endl;
}
std::string helix::GetName()
{
    return "helix";
}

myVector helix::GetCoordinates(double rad)
{
    double x, y, z;

    if (rad == PI_2 || rad == -PI_2) x = 0;
    else x = radiusX * cos(rad);

    if (rad == 0 || rad == PI) y = 0;
    else y = radiusY * sin(rad);
    
    if (rad == 0) z = 0;
    else z =  rad / 2 * PI * step;

    return myVector(x, y, z);
}

myVector helix::GetTangent(double rad, int direction)
{
    double x, y, z;
    if (rad == PI_2 || rad == -PI_2) y = 0;
    else y = cos(rad) * direction;
    if (rad == 0 || rad == PI) x = 0;
    else x = sin(rad) * direction;
    z = step / ((double)2 * radiusX) * (double)direction;
    return myVector(x, y, z);
}

#pragma endregion