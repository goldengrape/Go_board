//
//  main.cpp
//  GO_board
//
//  Created by GoldenGrape on 2019/8/14.
//  Copyright © 2019 GoldenGrape. All rights reserved.
//
// 测试写一个围棋显示程序
// 显示每一个子的气

#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Board.hpp"
#include "Piece_group.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
    const int black=1, white=-1, empty=0;
    int row_max=4, col_max=4;
    
    Board my_board=Board(row_max,col_max);
    my_board.set(0,0,black);
    my_board.set(1,0,black);
    my_board.set(0,1,white);
    my_board.set(1,1,white);
    my_board.set_all_point();
    my_board.display("icon");
    my_board.display("self_qi");
    my_board.display("company");
    return 0;
}
