/*!
 * @brief	マップ構築処理。
 */

#ifndef _CMAPBUILDER_H_
#define _CMAPBUILDER_H_

#include "packman/game/Map/CGround.h"
class CMapBuilder{
public:
	CMapBuilder();
	~CMapBuilder();
	void Build();
private:
	CGround m_ground;

};

const float GRID_SIZE = 0.2f;
const int NUM_GRID = 15;

extern int sMap[NUM_GRID][NUM_GRID];

#endif 