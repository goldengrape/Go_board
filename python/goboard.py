#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np


# In[2]:


N=4
show_char={1:'●', -1:'○', 0:"+" }


# In[3]:


class Point():
    def __init__(self,row, col, color):
        self.row=row
        self.col=col
        self.color=color

        self.neighbour_pos ={"up": (self.row-1, self.col),
                        "down":(self.row+1, self.col),
                        "left":(self.row, self.col-1),
                        "right":(self.row,self.col+1)}
        self.belong_group=None
        self.company=set()
        self.neighbour=set()
        self.self_qi=set()
        self.group_qi=set()
    def join_group(self, group):
        if self.color==0:
            return False
        if group is None:
            return False
        elif self.belong_group is None:
            self.belong_group = group
            self.group_qi=self.belong_group.group_qi
            group.add_piece(self)
            return True
        elif self.belong_group==group:
            return True
        return False

    def set_by_board(self,board):
        if self.color==0:
            return 
        neighbour_list=list(self.neighbour_pos.values())
        if self.row ==0:
            neighbour_list.remove(self.neighbour_pos["up"])
        if self.row == board.row_max-1:
            neighbour_list.remove(self.neighbour_pos["down"])
        if self.col ==0:
            neighbour_list.remove(self.neighbour_pos["left"])
        if self.col == board.col_max-1:
            neighbour_list.remove(self.neighbour_pos["right"])
        self.neighbour=set([board.get_point(row, col) for (row, col) in neighbour_list])
        
        
        for p in self.neighbour:
            if p.color == self.color:
                self.company.add(p)
            elif p.color ==0:
                self.self_qi.add(p)
        if self.belong_group is not None:
            self.group_qi=self.belong_group.group_qi
                
    def get_qi(self):   
        return len(self.self_qi)
    def get_group_qi(self):
        return len(self.group_qi)
    def __str__(self):
        return "({},{},{})".format(self.row,self.col, show_char[self.color])
    __repr__ = __str__


# In[7]:


class Board():
    def __init__(self, row_max, col_max):
        
        self.point_list=[Point(row,col,0) for row in range(row_max) for col in range(col_max)]
        self.row_max=row_max
        self.col_max=col_max
        self.set_all_point()
        
    def get_point(self,row,col):
        index = row* self.row_max+col
        return self.point_list[index]
    
    def set_point(self, row, col, color):
        index = row* self.row_max+col
        self.point_list[index].color=color

    def set_all_point(self):
        for i in range(2): # somthing magic, I don't know why twice
            for p in self.point_list:
                p.set_by_board(self)
            for p in self.point_list:
                if not any([p.join_group(px.belong_group) for px in p.company]):
                    p.join_group(Piece_group())
        for p in self.point_list:
            if p.get_group_qi()==0:
                p.color=0
        
           
    def display(self, type="color"):
        for row in range(self.row_max):
            for col in range(self.col_max):
                p=self.get_point(row,col)
                if type=="color":
                    print(show_char[p.color], end=" ")
                elif type=="self_qi":
                    print(p.get_qi(), end=" ")
                elif type=="group_qi":
                    print(p.get_group_qi(), end=" ")
                else:
                    pass
            print()


# In[8]:


class Piece_group():
    def __init__(self):
        self.group_qi=set()
        self.piece_set=set()
        self.group_color=0
    def add_piece(self, point):
        self.piece_set.add(point)
        self.group_qi=self.group_qi.union(point.self_qi)
        point.belong_group=self
    def __str__(self):
        str_list=[p.__str__() for p in self.piece_set]
        return "group "+",".join(str_list)
    __repr__ = __str__


# In[13]:


board=Board(N,N)
board.set_point(0,0,-1)
board.set_point(0,1,1)
board.set_point(1,0,1)
board.set_point(1,1,-1)

board.display(type="color")
print("------")
board.display(type="self_qi")
print("------")
board.display(type="group_qi")

board.set_all_point()

board.display(type="color")
print("------")
board.display(type="self_qi")
print("------")
board.display(type="group_qi")


# In[ ]:





# In[ ]:




