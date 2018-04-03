/** @file main.cpp
 *
 * This example shows how to use external Eigen library
 *
 * @author Dominik Belter
 */

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    try {
        Matrix2d A;
        A << 1, 2,
             3, 4;
        MatrixXd B(2,2);
        B << 2, 3,
             1, 4;
        std::cout << "a + b =\n" << A + B << std::endl;
        std::cout << "a - b =\n" << A - B << std::endl;
        std::cout << "Doing a += b;" << std::endl;
        A += B;
        std::cout << "Now a =\n" << A << std::endl;
        // access a single element
        std::cout << "A(0,0)=\n" << A(0,0) << "\n\n";
        // access a block
        std::cout << "A(0,:)=\n" << A.block<2,1>(0,0) << "\n\n";

        Vector3d v(1,2,3);
        Vector3d w(1,0,0);
        std::cout << "-v + w - v =\n" << -v + w - v << std::endl;


        getchar();
    }
	catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}
