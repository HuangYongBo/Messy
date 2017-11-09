


/*
	井字棋

伪代码：
	游戏规则说明
	玩家选择先后手
	循环：	
		玩家/电脑落子
		落子合法性判断
		输赢判断

	是否结束游戏

*/


#include"PlayerClass.h"
using namespace std;

int main(int argc,char *argv[])
{
//	Player *computer = new Player('x');
	Player computer('x');
	cout << computer.IsLegal()<<endl;


	return 0;
}
