#include "coffset.h"
#include <iostream>

std::string get_filename(){
    return "/home/tempest/datasets/traj/pyiron-pos-1.xyz";
}

void test_natoms(){
    {
    std::fstream file = _get_file_stream(get_filename());
    int natoms = _get_file_natoms(file);
    std::cout << "natoms: " << natoms << std::endl;
    }

}

void test_offsets(){
    {
    std::fstream file = _get_file_stream(get_filename());
    auto offsets = _get_file_offsets(file);

    offsets = _get_offsets(get_filename());

    }
}


int main()
{
    std::cout << "Hello Test!" << std::endl;
    test_natoms();
    test_offsets();
    return 0;
}

