#include "Poker.h"
#include "Player.h"
#include "GameScene.h"
Poker::Poker():m_isSelect(false),m_isDianJi(false){

}
Poker::~Poker(){

}
Poker* Poker::create(const char *pszFileName, const CCRect& rect){
	Poker* pk = new Poker();
	if (pk && pk->initWithFile(pszFileName,rect))
	{
		pk->autorelease();
		return pk;
	}
	CC_SAFE_DELETE(pk);
	return pk;
}
void Poker::onEnter(){
	CCSprite::onEnter();
	//������Ӧע��
	touchListener = EventListenerTouchOneByOne::create();//�������㴥���¼�������
	touchListener->onTouchBegan = CC_CALLBACK_2(Poker::onTouchBegan, this);//������ʼ
	touchListener->onTouchMoved = CC_CALLBACK_2(Poker::onTouchMoved, this);//�����ƶ�
	touchListener->onTouchEnded = CC_CALLBACK_2(Poker::onTouchEnded, this);//��������
	touchListener->setSwallowTouches(true);//�������̲�����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);//ע��ַ���
}
void Poker::onExit(){
	//�Ƴ�������Ӧ
	_eventDispatcher->removeEventListenersForTarget(this);
	CCSprite::onExit();
}
bool Poker::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
	CCSize size = getContentSize();
	CCRect rect(-size.width/2,-size.height/2,size.width,size.height);
	CCPoint ptouch = convertTouchToNodeSpaceAR(pTouch); //��Ӣ��֮��ת�� ���� �� �ڵ�ռ�
	if(rect.containsPoint(ptouch) && m_isDianJi)
	{
		if(!m_isSelect){
			SelectPkLuTou();
		}
		else{
			
			SelectPkSuoTou();
		}
		return true;
	}
	return false;
	//������ﷵ��false���������̵�
}
void Poker::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent){

}
void Poker::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent){

}
void Poker::onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){

}
void Poker::showFront(){
	if(m_huaSe != Gui)
		this->setTextureRect(CCRect(this->m_num*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
	else
		this->setTextureRect(CCRect((this->m_num-XiaoGui)*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
}
void Poker::showLast(){
	this->setTextureRect(CCRect(PaiHaoBM*pkWidth,HuaSeBM*pkHeight,pkWidth,pkHeight));
}
Poker* Poker::copy(){
	Poker* pk;
	if(m_huaSe != Gui)
		pk = Poker::create("poker.png",CCRect(this->m_num*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
	else
		pk = Poker::create("poker.png",CCRect((this->m_num-XiaoGui)*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
	pk->m_isDianJi = this->m_isDianJi;
	pk->m_isSelect = this->m_isSelect;
	pk->setHuaSe(this->getHuaSe());
	pk->setNum(this->getNum());
	pk->m_gameMain = this->m_gameMain;
	return pk;
}
void Poker::setTouchPriority(int num){
	_eventDispatcher->setPriority(touchListener, num);
}
void Poker::SelectPkLuTou(){
	//���Ҫ������
	this->m_isSelect = true;
	this->setPosition(ccp(getPositionX(),getPositionY()+10));
	m_gameMain->getArrPlayerOut()->addObject(this);
	m_gameMain->PlayerOutPaiXu(m_gameMain->getArrPlayerOut());
}
void Poker::SelectPkSuoTou(){
	//�ӳ������Ƴ�����
	m_isSelect = false;
	this->setPosition(ccp(getPositionX(),getPositionY()-10));
	m_gameMain->getArrPlayerOut()->removeObject(this);
}