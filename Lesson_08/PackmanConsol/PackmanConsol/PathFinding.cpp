#include "stdafx.h"
#include "PathFinding.h"

CPathFinding::CPathFinding()
{

}
CPathFinding::~CPathFinding()
{

}
void CPathFinding::FindRoot(std::vector<CVector2>& root,  CVector2 startPos, CVector2 targetPos)
{
	root.clear();
	//コストを初期化
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			m_nodes[y][x].moveCost = -1;
			m_nodes[y][x].isDone = false;
			if (m_nodes[y][x].mapID == 1) {
				//壁は探索済みにする。
				m_nodes[y][x].isDone = true;
			}
			m_nodes[y][x].parentNode = NULL;
		}
	}
	//開始ノードを取得する。
	SNode* startNode = &m_nodes[startPos.GetY()][startPos.GetX()];
	startNode->moveCost = 0;
	while (true) {
		SNode* processNode = NULL;
		//全ノードに対して確認/アップデートを行う。
		for (int y = 0; y < MAP_HEIGHT; y++) {
			for (int x = 0; x < MAP_WIDTH; x++) {
				SNode* node = &m_nodes[y][x];
				if (node->isDone || node->moveCost < 0) {
					continue;
				}
				//処理中のノードがなければ現在のノード。
				if (!processNode) {
					processNode = node;
					continue;
				}
				//訪問済みでないノードのうち、一番小さいコストのノードを探す。
				if (node->moveCost < processNode->moveCost) {
					//さらに安い。
					processNode = node;
				}
			}
		}
		// 処理中のノードがなくなったら、つまりすべてチェックが終わったらループ終了
		if (!processNode) {
			break;
		}
		//調査済みにする。
		processNode->isDone = true;
		//隣接しているノードにコストを設定する。
		for (int i = 0; i < LINK_NODE_MAX; i++) {
			SNode* node = processNode->linkNode[i];
			if (node == NULL) {
				continue;
			}
			int cost = processNode->moveCost + 1;
			bool needsUpdate = (node->moveCost < 0) || (node->moveCost > cost);
			if (needsUpdate) {
				//更新の必要あり。
				node->moveCost = cost;
				node->parentNode = processNode;
			}
		}
	}
	//ルートを作る。
	SNode* node = &m_nodes[targetPos.GetY()][targetPos.GetX()];
	
	while (node != startNode) {
		root.push_back(node->position);
		node = node->parentNode;
	}
	std::reverse(root.begin(),root.end());	
}
void CPathFinding::BuildNodes()
{
	//ノードを構築する。
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			SNode* node = &m_nodes[y][x];
			//マップのＩＤを入れる
			node->mapID = g_map[y][x];
			//隣接マップをNULL初期化。
			node->linkNode[0] = NULL;
			node->linkNode[1] = NULL;
			node->linkNode[2] = NULL;
			node->linkNode[3] = NULL;
			node->moveCost = 0;
			//隣接マップのノードを入れる。
			//右のノード
			if (x + 1 < MAP_WIDTH) {
				node->linkNode[0] = &m_nodes[y][x+1];
			}
			//左のノード
			if (x - 1 >= 0) {
				node->linkNode[1] = &m_nodes[y][x-1];
			}
			//上のノード
			if (y + 1 < MAP_HEIGHT) {
				node->linkNode[2] = &m_nodes[y+1][x];
			}
			//下のノード
			if (y - 1 >= 0) {
				node->linkNode[3] = &m_nodes[y-1][x];
			}
			node->position.Set(x, y);
		}
	}
}