#include <iostream>

using namespace std;

/// 1 class declaration
class AREA_FINDER
{
public:
    float RECTANGLE(float width, float length);
private:
    float dm_width;
    float dm_length;
    float dm_area;
};

/// 2 method definitions
/// type class:method(type & name parameters)
float AREA_FINDER::RECTANGLE(float width, float length)
{
    dm_width = width;
    dm_length = length;
    dm_area = dm_width * dm_length;
    return dm_area;
}
float R_area;

int main()
{
    /// 3 create and object
    /// class class_name object_name or names;
    class AREA_FINDER rect1,rect2;
    cout << "Find area of AREA_FINDERs!" << endl;
    /// 4 result = object.method(values to be processed aka arguments)
    R_area = rect1.RECTANGLE(20.5, 30.5);
    cout << "Area of rectangle 1 is " << R_area << " Sq Meters" << endl;
    return 0;
}
