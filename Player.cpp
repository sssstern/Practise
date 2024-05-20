//#include "Player.h"
//
//void update(float time)
//{
//	switch (Player::dir)
//	{
//	case 0: dx = speed; dy = 0; break;
//	case 1: dx = -speed; dy = 0; break;
//	case 2: dx = 0; dy = speed; break;
//	case 3: dx = 0; dy = -speed; break;
//	}
//	x += dx * time;
//	y += dy * time;
//	speed = 0;
//	sprite.setPosition(x, y);
//	interactionWithMap();
//}
//float getplayercoordinateX() {
//	return x;
//}
//float getplayercoordinateY() {
//	return y;
//}
//void interactionWithMap()
//{
//	for (int i = y / 32; i < (y + h) / 32; i++)
//		for (int j = x / 32; j < (x + w) / 32; j++)
//		{
//			if (TileMap[i][j] == '0')
//			{
//				if (dy > 0)
//				{
//					y = i * 32 - h;
//				}
//				if (dy < 0)
//				{
//					y = i * 32 + 32;
//				}
//				if (dx > 0)
//				{
//					x = j * 32 - w;
//				}
//				if (dx < 0)
//				{
//					x = j * 32 + 32;
//				}
//			}
//			if (TileMap[i][j] == 's') {
//				playerScore++;
//				TileMap[i][j] = ' ';
//			}
//		}
//}