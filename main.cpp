#include <iostream>
#include <cmath>
using namespace std;

struct polar {
    double distance;
    double angle;
};

struct rect {
    double x;
    double y;
};

polar rectangular_to_polar(rect xy);
void show_polar(polar ra);
rect polar_to_rectangular(polar ra);
void show_rect(rect xy);
void pol_shit(void);
void rect_shit(void);
void menu(void);

int main() {
    int choice = 0;
    struct rect rect2polconv ;
           polar pol2rectconv;
    struct polar p;
           rect r;
    cout << endl;

    while ( choice != 3) {
        menu();
        cin >> choice;
        if (choice == 1)
            rect_shit();
        else if (choice == 2)
            pol_shit();
    }
    cout << "Exiting program." << endl << endl;

    return 0;
}

polar rectangular_to_polar(rect xy) {
    polar result;
    result.distance = sqrt(pow(xy.x, 2) + pow(xy.y, 2));
    result.angle = atan2(xy.y, xy.x) * 180 / M_PI;
    return result;
}

rect polar_to_rectangular(polar ra) {
    rect result;
    result.x = ra.distance * cos(ra.angle * M_PI / 180);
    result.y = ra.distance * sin(ra.angle * M_PI / 180);
    return result;
}

void show_polar(polar ra) {
    cout << "Distance: " << ra.distance << endl;
    cout << "Angle: " << ra.angle << endl << endl;
}

void show_rect(rect xy) {
    cout << "X: " << xy.x << endl;
    cout << "Y: " << xy.y << endl << endl;
}

void menu(void) {
    cout << "1. Rectangular to Polar" << endl;
    cout << "2. Polar to Rectangular" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "[1/2/3] : ";
}

void rect_shit(void) {
    struct rect rect2polconv;
    struct polar p;
    cout << "Enter x and y coordinates: ";
    cin >> rect2polconv.x >> rect2polconv.y;
    p = rectangular_to_polar(rect2polconv);
    show_polar(p);
}
void pol_shit(void) {
    struct polar pol2rectconv;
    struct rect r;
    cout << "Enter Radius and angle: ";
    cin >> pol2rectconv.distance >> pol2rectconv.angle;
    r = polar_to_rectangular(pol2rectconv);
    show_rect(r);
}
