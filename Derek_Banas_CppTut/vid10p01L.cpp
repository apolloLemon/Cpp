#include <iostream>
#include <time>

class Warrior{
private:
	std::string name;
	int hp atk blk;
	
	static int numOfWarriors;

public:
	std::string GetName{return name;}
	void SetName(std::string name){this->name=name;}
	int GetHP{return hp;}
	void SetHP(int hp){this->hp=hp;}
	int GetATK{return atk;}
	void SetATK(int atk){this->atk=atk;}
	int GetBLK{return blk;}
	void SetBLK(int blk){this->blk=blk;}

	void SetAll(std::string, int, int, int);
	Warrior(std::string, int, int, int);
	Warrior();
	~Warrior();
	static int GetNumOfWarriors{return numOfWarriors;}
}

int main () {
	srand(time(NULL));
	Warrior thor("Thor",100,30,15);
	Warrior hulk("Thor",100,30,15);

	return 0;
}