#include <iostream>
 using namespace std;
//class containing the functions
 class Shape{
    public:
    int squareArea(int side){
        return side*side;
    }

    int cubeArea(int side){
        return side*side*side;
    }

    int rectangleArea(int length, int breadth){
        return length*breadth;
    }

    int cuboidArea(int length, int breadth, int height){
        return 6*((length*breadth) + (breadth*height) + (length*height));
    }
 };
//menu-driven program to find areas
 int main(){
    Shape shapes;
    int choice;

    cout <<"1. Area of Square\n";
    cout <<"2. Area of Cube\n";
    cout <<"3. Area of Rectangle\n";
    cout <<"4. Area of Cuboid\n";
    cout <<"5. Exit\n";



    while(1){
        cout <<"\nEnter your choice: ";
        cin >>choice;
        switch(choice){
            case 1:
            int side;
            cout <<"Enter the side of the square: ";
            cin >>side;

            cout <<shapes.squareArea(side) <<endl;
            break;

            case 2:
            int sideCube;
            cout <<"Enter the side of the cube: ";
            cin >>sideCube;

            cout <<shapes.cubeArea(sideCube);
            break;

            case 3:
            int length, breadth;
            cout <<"Enter the length of the cube: ";
            cin >>length;
            cout <<"Enter the breadth of the cube: ";
            cin >>breadth;

            cout <<shapes.rectangleArea(length, breadth);
            break;

            case 4:
            int l, b, h;
            cout <<"Enter the length of the cuboid: ";
            cin >>l;
            cout <<"Enter the breadth of the cuboid: ";
            cin >>b;
            cout <<"Enter the height of the cuboid: ";
            cin >>h;

            cout <<shapes.cuboidArea(l, b, h);

            case 5:
            cout <<"Exiting program...\n";
            return -1;
        }
    }

 }