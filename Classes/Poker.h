#pragma once
#include "cocos2d.h"
#include "Global.h"
class GameScene;
USING_NS_CC;
class Poker : public Sprite
{
public:
	Poker();
	~Poker();
	static Poker* create(const char *pszFileName, const CCRect& rect);
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
	void showFront();//��ʾ����
	void showLast();//��ʾ����
	Poker* copy();//����
	void setTouchPriority(int num);
	void SelectPkLuTou();//���ѡ�����ƾ�¶��ͷ
	void SelectPkSuoTou();//���ѡ�����ƾ���ͷ
private:
	CC_SYNTHESIZE(bool,m_isSelect,Select);//�Ƿ���ѡ
	CC_SYNTHESIZE(GameScene*,m_gameMain,GameMain);
	CC_SYNTHESIZE(bool,m_isDianJi,DianJi);//�Ƿ��ܱ����
	CC_SYNTHESIZE(int,m_huaSe,HuaSe);//��ɫ
	CC_SYNTHESIZE(int,m_num,Num);//��ֵ
	EventListenerTouchOneByOne* touchListener;
};
