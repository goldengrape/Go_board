//
//  Point.cpp
//  GO_board
//
//  Created by GoldenGrape on 2019/8/23.
//  Copyright © 2019 GoldenGrape. All rights reserved.
//

#include "Point.hpp"
#include <string>
using namespace std;

Point::Point(int row,int col, int color){
    this->row=row;
    this->col=col;
    this->color=color;
    this->icon="+";
    set_name();
}
void Point::set_color(int c){
    color=c;
    switch (color) {
        case 1:
            icon="●";
            break;
        case -1:
            icon="○";
            break;
        default:
            icon="+";
            break;
    }
    set_name();
}
