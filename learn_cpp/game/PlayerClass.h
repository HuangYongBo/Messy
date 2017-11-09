



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

#include <iostream>
#include <stdbool.h>

using namespace std;
class Player
{

public:
	Player(char chess);
	~Player(){}
	bool IsLegal();	

private:
	char m_cChess;



};


Player::Player(char chess = 'x'):m_cChess(chess)
{
}

bool Player::IsLegal()
{
	std::cout << m_cChess <<endl;
	return true;	

}
