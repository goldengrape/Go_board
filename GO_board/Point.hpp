//
//  Point.hpp
//  GO_board
//
//  Created by GoldenGrape on 2019/8/23.
//  Copyright © 2019 GoldenGrape. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Point {
public:
//    Point();
    Point(int row,int col, int color);
    
    int get_row(){return row;};
    int get_col(){return col;};
    int get_color(){return color;};
    string get_icon(){return icon;};
    string get_name(){return name;};
    void set_color(int c);
    
    void reset_neighbour(){neighbour.clear();};
    void reset_qi(){qi.clear();};
    void reset_company(){company.clear();};
    
    void add_neighbour(Point p){neighbour.push_back(p);};
    void add_qi(Point p){qi.push_back(p);};
    void add_company(Point p){company.push_back(p);};
    


    vector<Point> get_neighbour(){return neighbour;};
    vector<Point> get_qi(){return qi;};
    vector<Point> get_company(){return company;};
private:
    int row, col;
    int color;
    string icon;
    string name;
    void set_name(){name="("+to_string(row)+icon+to_string(col)+")";};
    vector<Point> neighbour;
    vector<Point> qi;
    vector<Point> company;

};

#endif /* Point_hpp */
