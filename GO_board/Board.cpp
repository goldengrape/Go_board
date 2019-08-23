//
//  Board.cpp
//  GO_board
//
//  Created by GoldenGrape on 2019/8/23.
//  Copyright © 2019 GoldenGrape. All rights reserved.
//

#include "Board.hpp"
#include <iostream>
#include <string>
using namespace std;

void Board::init_point(){
    point.reserve(max_row*max_col);
    int i=0;
    for (int row=0 ; row < max_row; row++){
        for(int col=0; col< max_col; col++){
            point.push_back(Point(row,col,0));
            i++;
        }
    }
    set_neighbour();
}

void Board::display(string t){
    int i=0;
    for (int row=0 ; row < max_row; row++){
        for(int col=0; col< max_col; col++){
            if (t=="icon") {
                cout<<point[i].get_icon()<<" ";
            }else if(t=="name"){
                cout<<point[i].get_name()<<" ";
            }else if(t=="self_qi"){
                cout<<point[i].get_qi().size()<<" ";
            }else if(t=="company"){
                cout<<point[i].get_company().size()<<" ";
            };
            i++;
        }
        cout << endl;
        }
    cout << endl;
    }

void Board::set(int row, int col, int color){
    int index=row * max_row+ col;
    point[index].set_color(color);
}

void Board::set_neighbour(){
    
    int i=0;
    for (i=0; i<point.size();i++){
        point[i].reset_neighbour();
        // add down neighbour
        if (i+max_col<point.size()){
            point[i].add_neighbour(point[i+max_col]);
        }
        // add up neighbour
        if (i>=max_col){
            point[i].add_neighbour(point[i-max_col]);
        }
        // add right neighbour
        if (point[i].get_col()+1<max_col){
            point[i].add_neighbour(point[i+1]);
        }
        // add left neighbour
        if (point[i].get_col()>0){
            point[i].add_neighbour(point[i-1]);
        }
    }
}


void Board::set_qi(){
    for (int i=0; i< point.size();i++){
        point[i].reset_qi();
        if (point[i].get_color() != 0){
            for (Point &p:point[i].get_neighbour()){
                if (p.get_color()==0){
                    point[i].add_qi(p);
                }
            }
        }
    }
}
void Board::set_company(){
    for (int i=0; i< point.size();i++){
        point[i].reset_company();
        if (point[i].get_color() != 0){
            for (auto p:point[i].get_neighbour()){
                if (p.get_color()==point[i].get_color()){
                    point[i].add_company(p);
                }
            }
        }
    }
}

void Board::set_all_point(){
    set_neighbour();
    set_qi();
    set_company();
}
