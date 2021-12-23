#ifndef GENERATEMAZE_H
#define GENERATEMAZE_H

#include <vector>
using namespace std;

#define DOWN 1
#define RIGHT 2
#define LEFT 4
#define UP 8
#define WALL -1    //墙
#define NOTHING 2  //道路
#define END 3




//定义墙的结构体
struct block
{
    int row, column, direction;//行，列，该墙对应于路的方位
    //创建墙的函数
    block(int _row, int _column, int _direction)
    {
        row = _row;
        column = _column;
        direction = _direction;
    }
};

//起点和终点
struct point
{
    int x;
    int y;
};

void init(char G[100][100] , point *start);
void FindBlock(int x_num , int y_num , int m , int n , vector<block> *myblock , char G[100][100]);
bool GenerateMap(char G[100][100] , point *start , int x_num , int y_num , int m , int n , vector<block> &myblock );

//int m  = 33, n = 33;//墙的边界
//int x , y;//墙的界限
//vector<block> myblock;//存储待处理的墙
//int x_num = 1, y_num = 1;//玩家起始位置
//char G[100][100];//理想最大地图的最大边界（并非生成的地图的最大边界）
//point start , end;

#endif // GENERATEMAZE_H
