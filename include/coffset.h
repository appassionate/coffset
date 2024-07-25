// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <float.h>
#include <math.h>

#define _FILE_OFFSET_BITS 64
#define _FILE_MAX_NFRAMES 100000000 // 100 million frames

typedef float coordinate[3];
typedef char element[2];

static std::fstream _get_file_stream(std::string filename){
    // Open file
    std::fstream file;
    file.open(filename.c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open()){
        std::cout << "Error opening file " << filename << std::endl;
        exit(1);
    }
    return file;
}

static int _get_file_natoms(std::fstream &file){

    // Get number of atoms
    int natoms;
    //读取文件的第一行
    std::string line;
    if (std::getline(file, line)){
        // line will be a string type number transformed to int
        std::stringstream ss(line); // Insert the string into a stream
        ss >> natoms;               // Extract the number from the stream
        }
    else{
        std::cout << "Error reading file" << std::endl;
        exit(1);
    }

    return natoms;
}


//todo: get xyz elements
static std::vector<long long> _get_file_offsets(std::fstream &file){

    // get offsets
    // 读取文件的第二行
    int natoms = _get_file_natoms(file);
    std::string line;
    int _rnums = natoms+2;
    // std::vector<std::streampos> offsets;
    std::vector<long long> offsets;

    //such a implementation will not check the FILE FORMAT is correct or not
    for (int w=0;w<_FILE_MAX_NFRAMES;w++){
        for (int i=0; i<_rnums; i++){
            if (std::getline(file, line)){
            }
            else{
                return offsets;
            }
        }
        offsets.push_back(file.tellg());
        // int _value = offsets[w];
        // printf("offset: %d\n", _value);

    }
    std::cout << "out of nframes max limit!" << std::endl;
    exit(1);

}


static std::vector<long long> _get_offsets(std::string filename){
    std::fstream file = _get_file_stream(filename);
    return _get_file_offsets(file);
}