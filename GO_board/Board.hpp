//
//  Board.hpp
//  GO_board
//
//  Created by GoldenGrape on 2019/8/23.
//  Copyright © 2019 GoldenGrape. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <vector>
#include "Point.hpp"

using namespace std;

class Board{
public:
    Board(int mrow, int mcol):max_row(mrow), max_col(mcol){init_point();};
    void init_point();
    void display(string type);
    void set(int row, int col, int color);
    void set_all_point();
private:
    int max_row, max_col;
    vector<Point> point;
    void set_neighbour();
    void set_qi();
    void set_company();
};
#endif /* Board_hpp */
