#include "generatemaze.h"
#include "time.h"
#include "stdio.h"

void init(char G[100][100] , point *start)
{
    //将地图全部置为墙
    for (int i = 0 ; i < 100 ; ++i)
    {
        for (int j = 0 ; j < 100 ; ++j)
        {
            G[i][j] = WALL;
        }
    }
    //定义起始点
    G[1][1] = NOTHING;
    start->x = start->y = 1;
}

void FindBlock(int x_num , int y_num , int m , int n , vector<block> *myblock , char G[100][100])
{
    //找出与当前位置相邻的墙
    if (x_num + 1 <= m && G[x_num + 1][y_num] == WALL)
    {//down
        myblock->push_back(block(x_num + 1, y_num, DOWN));
    }
    if (y_num + 1 <= n && G[x_num][y_num + 1] == WALL)
    {//right
        myblock->push_back(block(x_num, y_num + 1, RIGHT));
    }
    if (x_num - 1 >= 1 && G[x_num - 1][y_num] == WALL)
    {//up
        myblock->push_back(block(x_num - 1, y_num, UP));
    }
    if (y_num - 1 >= 1 && G[x_num][y_num - 1] == WALL)
    {//left
        myblock->push_back(block(x_num, y_num - 1, LEFT));
    }
}

//更新地图数组中的数据
bool GenerateMap(char G[100][100] , point *start , int x_num , int y_num , int m , int n , vector<block> &myblock )
{
    init(G , start);
    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    srand((unsigned)time(NULL));//随机数种子
    FindBlock(x_num ,y_num ,  m , n , &myblock , G);
    //第一步压入两堵墙（起点右边和起点下面）进入循环
    while (myblock.size())
    {
        int BlockSize = myblock.size();
        //随机选择一堵墙（生成0 ~ BlockSize-1之间的随机数，同时也是vector里墙的下标）
        int randnum = rand() % BlockSize;
        block SelectBlock = myblock[randnum];
        x_num = SelectBlock.row;//矿工来到我们“选择的墙”这里
        y_num = SelectBlock.column;
        //根据当前选择的墙的方向进行后续操作
        //此时，起始点 选择的墙 目标块 三块区域在同一直线上
        //我们让矿工从“选择的墙”继续前进到“目标块”
        //矿工有穿墙能力 ：)
        switch (SelectBlock.direction)
        {
        case DOWN:
        {
            x_num++;
            break;
        }
        case RIGHT:
        {
            y_num++;
            break;
        }
        case LEFT:
        {
            y_num--;
            break;
        }
        case UP:
        {
            x_num--;
            break;
        }
        }

        //目标块如果是墙
        if (G[x_num][y_num] == WALL)
        {
            //打通墙和目标块
            G[SelectBlock.row][SelectBlock.column] = G[x_num][y_num] = NOTHING;
            //再次找出与矿工当前位置相邻的墙
            FindBlock(x_num ,y_num ,  m , n , &myblock , G);
        }
        else
        {
            //relax
        }

        myblock.erase(myblock.begin() + randnum);
    }


    G[m][n] = END;

//    for (int i = 0; i <= m + 1; i++)
//    {
//        for (int j = 0; j <= n + 1; j++)
//        {
//            if (i == start->x && j == start->y)
//            {
//                printf("ME");
//            }
//            else if (G[i][j] == END)
//            {
//                printf("EE");
//            }
//            else if (G[i][j] == NOTHING)
//            {
//                printf("  ");
//            }
//            else
//            {
//                printf("??");
//            }
//        }
//        printf("\n");
//    }
    return 1;
}

