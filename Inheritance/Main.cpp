#include "Point2D.h"
#include "Point3D.h"

int main() {
    int dimension{};
    std::cout << "Select the dot size (2 or 3): ";
    std::cin >> dimension;

    if (dimension == 2) {
        Point2D p1, p2;
        std::cout << "Enter the coordinates of the first point (x y): ";
        std::cin >> p1;
        std::cout << "Enter the coordinates of the second point (x y): ";
        std::cin >> p2;

        std::cout << "p1: " << p1 << "\n";
        std::cout << "p2: " << p2 << "\n";

        Point2D sum = p1 + p2;
        std::cout << "Sum p1 + p2: " << sum << "\n";

        double dx, dy;
        std::cout << "Enter the shift along Ox: ";
        std::cin >> dx;
        std::cout << "Enter the shift along Oy: ";
        std::cin >> dy;

        sum.MoveOx(dx);
        sum.MoveOy(dy);
        std::cout << "После сдвига: " << sum << "\n";
    }
    else if (dimension == 3) {
        Point3D q1, q2;
        std::cout << "Enter the coordinates of the first point (x y z): ";
        std::cin >> q1;
        std::cout << "Enter the coordinates of the second point (x y z): ";
        std::cin >> q2;

        std::cout << "q1: " << q1 << "\n";
        std::cout << "q2: " << q2 << "\n";

        Point3D sum = q1 + q2;
        std::cout << "Sum q1 + q2: " << sum << "\n";

        double dx, dy, dz;
        std::cout << "Enter the shift along Ox: ";
        std::cin >> dx;
        std::cout << "Enter the shift along Oy: ";
        std::cin >> dy;
        std::cout << "Enter the Oz shift: ";
        std::cin >> dz;

        sum.MoveOx(dx);
        sum.MoveOy(dy);
        sum.MoveOz(dz);
        std::cout << "After the shift: " << sum << "\n";
    }
    else {
        std::cerr << "Only dimensions 2 or 3 are allowed\n";
    }

    return 0;
}