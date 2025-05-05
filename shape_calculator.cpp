#include <iostream>
#include <vector>
#include <map>
#include <cmath> 

#define M_PI   3.14159265358979323846264338327950288

enum ShapeType {
    CIRCLE = 1,
    SQUARE,
    TRIANGLE,
    RECTANGLE,
    PENTAGON,
    HEXAGON,
    HEPTAGON,
    OCTAGON,
    NONAGON,
    DECAGON,
    POLYGON
};

std::map<ShapeType, std::string> shapeNames = {
    {CIRCLE, "Circle"},
    {SQUARE, "Square"},
    {TRIANGLE, "Triangle"},
    {RECTANGLE, "Rectangle"},
    {PENTAGON, "Pentagon"},
    {HEXAGON, "Hexagon"},
    {HEPTAGON, "Heptagon"},
    {OCTAGON, "Octagon"},
    {NONAGON, "Nonagon"},
    {DECAGON, "Decagon"},
    {POLYGON, "Polygon"},
};

void print_menu() {
    for (const auto& pair : shapeNames) {
        std::cout << static_cast<int>(pair.first) << ". " << pair.second << std::endl;
    }
    std::cout << "0. Exit\n\n" << std::endl;
};

void getInput(const std::string &prompt, double &value) {
    std::cout << prompt;
    std::cin >> value;
}

void getInput(const std::string &prompt, int &value) {
    std::cout << prompt;
    std::cin >> value;
}

void calculateCircle(double r, double &area, double &circumference) {
    area = M_PI * r * r;
    circumference = 2 * M_PI * r;
};

void calculateRectangle(double &l, double &w, double &area, double &perimeter) {
    area = l * w;
    perimeter = 2 * (l + w);
};

void calculateTriangle(double &b, double &h, double &area, double &perimeter) {
    area = 0.5 * b * h;
    perimeter = b + 2 * sqrt(pow((b/2), 2) + pow(h, 2));
};

void handleCircle() {
    double radius;
    getInput("Enter radius: ", radius);

    double area, circumference;
    calculateCircle(radius, area, circumference);

    std::cout<<"\n"<<std::endl;
    std::cout<<"Area: "<<area<<std::endl;
    std::cout<<"Circumference: "<<circumference<<std::endl;
};

void calculateRegularPolygon(int &sides, double &length, double &apothem, double &area, double &perimeter) {
    double angle_in_radians = (180.0 / sides) * (M_PI / 180.0);
    apothem = length / (2 * std::tan(angle_in_radians));
    area = (sides * length * apothem)/2;
    perimeter = length * sides;
};

void handleRegularPolygon(int sides) { 
    double length;
    getInput("Enter length: ", length);

    double apothem, area,perimeter;
    calculateRegularPolygon(sides, length, apothem, area, perimeter);

    std::cout<<"\n"<<std::endl;
    std::cout<<"Area: "<<area<<std::endl;
    std::cout<<"Perimeter: "<<perimeter<<std::endl;
};

void handleRectangle() { 
    double length, width;
    getInput("Enter length: ", length);
    getInput("Enter width: ", width);
    
    double area, perimeter;
    calculateRectangle(length, width, area, perimeter);

    std::cout<<"\n"<<std::endl;
    std::cout<<"Area: "<<area<<std::endl;
    std::cout<<"Perimeter: "<<perimeter<<std::endl;
};

void handleTriangle() { 
    double base, height;
    getInput("Enter base: ", base);
    getInput("Enter height: ", height);
    
    double area, perimeter;
    calculateTriangle(base, height, area, perimeter);

    std::cout<<"\n"<<std::endl;
    std::cout<<"Area: "<<area<<std::endl;
    std::cout<<"Perimeter: "<<perimeter<<std::endl;
};


void dispatch_shape(ShapeType shape) {
    if (shape < CIRCLE || shape > POLYGON) {
        std::cout << "Invalid shape selected.\n";
        return;
    }

    switch(shape) {
        case CIRCLE: handleCircle(); break;
        case SQUARE: handleRegularPolygon(4);  break;
        case TRIANGLE: handleTriangle(); break;
        case RECTANGLE: handleRectangle(); break;
        case PENTAGON: handleRegularPolygon(5); break;
        case HEXAGON: handleRegularPolygon(6); break;
        case HEPTAGON: handleRegularPolygon(7); break;
        case OCTAGON: handleRegularPolygon(8); break;
        case NONAGON: handleRegularPolygon(9); break;
        case DECAGON: handleRegularPolygon(10); break;
        case POLYGON: {
            int sides;
            getInput("Enter the number of sides: ", sides);
            handleRegularPolygon(sides); 
            break;
        }

    }
};

int main() {
    std::cout<<"Welcome to the Geometry Calculator!\n"<<std::endl;

     while (true) {
        std::cout<<"\n"<<std::endl;
        std::cout << "Choose a shape:\n";
        print_menu();

        int selection;
        std::cout << "Enter Choice: ";
        std::cin >> selection;

        if (selection == 0) {
            std::cout << "Shutting down...\n";
            break;  // Exits the loop and ends the program
        }

        ShapeType choice = static_cast<ShapeType>(selection);

        std::cout << "Your Choice: " << shapeNames[choice] << "\n\n";

        dispatch_shape(choice);  // Process the selected shape
    }

    return 0;
};

