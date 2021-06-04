#include <iostream>
#include "OpenGL_API.hh"


using drawNS::APIopenGL3D;
using drawNS::Point3D;
using std::vector;
using std::cout;
using std::endl;

void wait4key() {
    do {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while(std::cin.get() != '\n');
}

int main(int argc, char **argv) {
    drawNS::Draw3DAPI * api = new APIopenGL3D(-5,5,-5,5,-5,5,1000,&argc,argv);
    api->change_ref_time_ms(0);
    vector<double> shape_id;
    const std::string color = "purple";
    const std::string color1 = "blue";
    const std::string color2 = "red";
    const int delay_in_milliseconds = 16;
    for (int i=0; i<101; i++){
        double factor1 = double(i)*(5.0/100.0);
        double factor2 = double(i)*(2/100.0);
        double factor3 = double(i)*(2.75/100.0);
        shape_id.push_back(api->draw_polyhedron({{
            Point3D(-factor1,-factor1,-factor1),Point3D(factor1,-factor1,-factor1),Point3D(factor1,factor1,-factor1),Point3D(-factor1,factor1,-factor1)},{
            Point3D(-factor1,-factor1,factor1),Point3D(factor1,-factor1,factor1),Point3D(factor1,factor1,factor1),Point3D(-factor1,factor1,factor1)
        }},color));
        shape_id.push_back(api->draw_polyhedron({{
            Point3D(-factor2,-factor2,-factor2),Point3D(factor2,-factor2,-factor2),Point3D(factor2,factor2,-factor2),Point3D(-factor2,factor2,-factor2)},{
            Point3D(-factor2,-factor2,factor2),Point3D(factor2,-factor2,factor2),Point3D(factor2,factor2,factor2),Point3D(-factor2,factor2,factor2)
        }},color1));
        shape_id.push_back(api->draw_polyhedron({{
            Point3D(-factor3,-factor3,-factor3),Point3D(factor3,-factor3,-factor3),Point3D(factor3,factor3,-factor3),Point3D(-factor3,factor3,-factor3)},{
            Point3D(-factor3,-factor3,factor3),Point3D(factor3,-factor3,factor3),Point3D(factor3,factor3,factor3),Point3D(-factor3,factor3,factor3)
        }},color2));
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_in_milliseconds));
        api->erase_shape(shape_id[0]);
        api->erase_shape(shape_id[1]);
        api->erase_shape(shape_id[2]);
        shape_id.erase(shape_id.begin(),shape_id.begin()+2);
        if (i == 100) {
            for (; i >=0;--i) {
                factor1 = double(i) * (5.0 / 100.0);
                factor2 = double(i)*(2/100.0);
                factor3 = double(i)*(2.75/100.0);
                shape_id.push_back(api->draw_polyhedron({{
                     Point3D(-factor1,-factor1,-factor1),Point3D(factor1,-factor1,-factor1),Point3D(factor1,factor1,-factor1),Point3D(-factor1,factor1,-factor1)},{
                     Point3D(-factor1,-factor1,factor1),Point3D(factor1,-factor1,factor1),Point3D(factor1,factor1,factor1),Point3D(-factor1,factor1,factor1)}},color));
                shape_id.push_back(api->draw_polyhedron({{
                     Point3D(-factor2,-factor2,-factor2),Point3D(factor2,-factor2,-factor2),Point3D(factor2,factor2,-factor2),Point3D(-factor2,factor2,-factor2)},{
                     Point3D(-factor2,-factor2,factor2),Point3D(factor2,-factor2,factor2),Point3D(factor2,factor2,factor2),Point3D(-factor2,factor2,factor2)
                }},color1));
                shape_id.push_back(api->draw_polyhedron({{
                    Point3D(-factor3,-factor3,-factor3),Point3D(factor3,-factor3,-factor3),Point3D(factor3,factor3,-factor3),Point3D(-factor3,factor3,-factor3)},{
                    Point3D(-factor3,-factor3,factor3),Point3D(factor3,-factor3,factor3),Point3D(factor3,factor3,factor3),Point3D(-factor3,factor3,factor3)
                }},color2));
                std::this_thread::sleep_for(std::chrono::milliseconds(delay_in_milliseconds));
                api->erase_shape(shape_id[0]);
                api->erase_shape(shape_id[1]);
                api->erase_shape(shape_id[2]);
                shape_id.erase(shape_id.begin(),shape_id.begin()+2);
            }
        }
    }

    std::cin.get();


    delete api; //mandatory, because class destructor contains kill command for drawing process, use it to avoid
                //seg faults when closing program

    return 0;
}
