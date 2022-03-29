//俄罗斯方块
#include<stdio.h>
#include<stdlib.h>//rand()srand()calloc()sleep()system()
#include <unistd.h>//usleep(ms)
//#include<conio.h>//getch()kbhit()cputs()
//#include<windows.h>

int Width = 10,Height = 25,Daily = 9,X = 0,Y = 0,Type = 0;
unsigned *Map;//store number(1or0) of every block
int Size,x,y,i,operation,step,fixation;//step步进fixation固定信号operation对方块的操作
int Node[]={51264, 12816, 21520, 21520, 25872, 34113, 21537, 38208, 25921, 38481,
38484, 38209, 25922, 43345, 34388, 38160, 25920, 38177, 42580, 38993};
//4 squares,4 directions,7 combinations,and there are 19 different shapes in all
//单个坐标占四位(高两位y低两位x)一个图形有四个坐标刚好为16位二进制数，只需遍历4次

int Get(fixation)
{//获取四个方块坐标
    for(i = Node[Type];i;i >>= 4){
        x = X + i%4,y = Y + i/4%4;
        return 0;
    }
}

int move(int *operation,int step)//判断位置是否合理，合理则移动
{//*operation指向方块的一种属性，也可以理解为对方块的操作(X,Y,Type)对应水平移动、竖直移动;step为步进
    Get(*operation += 1);
    if(x < 0||x >= Width||y >= Height||Map[y*Width+x]){
        fixation = 0;
    }
    //Get(*operation += 1)(x < 0||x >= Width||y >= Height||Map[y*Width+x]) && (fixation = 0);
    //判断每个方块是否越界，有无阻挡，如果有冲突，将fixation设为0，作为一个固定信号
    if(fixation) return 1;
    else if(*operation -= 1,operation == &Y) return -1;
    //return fixation ? 1 :(*operation -= 1,operation == &Y && (fixation = -1));
    //通过判断fixation是否=0来判断是否冲突，如果出现冲突执行后语句还原，将-1作为固定信号fixation值
    return 0;
}

int main()
{
    //SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO){1});
    for(srand(*Map = calloc(Size = Height*Width,4));fixation == 27;usleep(50))
    {
        Get(fixation = getchar());
            Map[y*Width+x] = 0;
        //Get(fixation = _kbhit() ? _getch() & 95 : 1)Map[y*Width+x] = 0;
        //_kbhit()功能及返回值： 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
        //getch()功能及返回值: 从键盘上读取到的字符
        if(fixation == 75)
        {
            move(&X,-1);
            break;
        }
        else if(fixation == 77)
        {
            move(&X,1);
            break;
        }
        else if(fixation == 80)
        {
            move(&Y,1);
            break;
        }
        else if(fixation == 72)
        {
            i = Type;
            if(i < 8)
                i=1;
                i=3;
            move(&Type, Type & i ^ i ? 1 : -i);
            break;
        }
        
        /*
        switch(fixation)
        {
            case 75 : move(&X,-1); break;//left
            case 77 : move(&X,1); break;//right
            case 80 : move(&Y,1); break;//concelerate
            case 72 : 
        }
        fixation ^ 75 || move(&X,-1);
        fixation ^ 77 || move(&X,1);
        fixation ^ 80 || move(&Y,1);
        fixation ^ 72 || (i = Type < 8 ? 1 : 3, move(&Type, Type & i ^ i ? 1 : -i));
        //有的形状旋转2次还原，有的4次，还有每次旋转都一样的特殊情况
        */
        Get(--Daily || (Daily = 9,move(&Y,fixation = 1)));
            Map[y*Width+x] = Type/4 * 16 + 154;//?
        //Get(--Daily || (Daily = 9,move(&Y,fixation = 1)))Map[y*Width+x] = 1;//Type/4*16+154;
        if(fixation == -1)
        {
            if(Y == 0)
            {//判断Y坐标是否移动
                fixation = 27;//Esc=27
                Type = rand()%20;//方块坐标和形状重新赋值(新方块)0-19
                X = 0;
                for(x = Width,i = Size-1;x -= Map[i],i;i-- % Width || (x = Width))
                {//i traverses in Size-1 to 0;x counts in 0 to Width;y covers in i to Width;
                 //每遍历完一行,i-- % Width =0,x归位最大值Width
                 if(x == 0)
                 {//如果x=0,说明此行为满行(填满方块),i+Width回到上一行,y从i的位置开始向上遍历,覆盖数据到顶结束
                     for(y = i += Width;!x && (--y >= Width);Map[y] = Map[y-Width]);
                 }
                }
            }
        }
        while(i < Size)
        {
            ++i % Width || printf("|\n");
            printf(Map[i] ? "[]" : " ");
            //打印地图
        }
        //for(;i < Size;++i % Width || printf("|\n"))printf(Map[i] ? "[]" : " ");//打印地图
    }
    return 0;
}