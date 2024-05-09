#include "PaddleCPU.h"

PaddleCPU::PaddleCPU(){
    width = 25;
    height = 120;
    x = 10;
    y = s.getScreenHeight()/2 - 60; 
    speed = 6;
}

void PaddleCPU::Update(){
    std::cout << "in progress..." << std::endl;
}
