#include <iostream>
#include <ctime>

class Warrior{
private:
	std::string name;
	int hp, atk, blk;

public:
	std::string GetName(){return name;}
	int GetHP(){return hp;}
	void SetHP(int hp){this->hp=hp;}
	int GetATK(){return atk;}
	void SetATK(int atk){this->atk=atk;}
	int GetBLK(){return blk;}
	void SetBLK(int blk){this->blk=blk;}
	

	bool IsAlive(){return(hp>0);}

	Warrior(std::string, int, int, int);

};

Warrior::Warrior(std::string name, int hp, int atk, int blk){
	this->name = name;
	this->hp = hp;
	this->atk = atk;
	this->blk = blk;
}

class Battle{
public: 
	static void StartFight(Warrior a, Warrior b);
};

void Battle::StartFight(Warrior a, Warrior b){
	int turn = 0;
	int dmg;
	while(a.IsAlive() and b.IsAlive()){
		if (turn%2==0) {
			std::cout << a.GetName() << " attacks " << b.GetName();
			dmg = (std::rand()%a.GetATK())-(std::rand()%b.GetBLK());
			if (dmg<0) dmg=0;
			std::cout << " and deals "<<dmg<<" damage\n";
			b.SetHP(b.GetHP()-dmg);
			std::cout << b.GetName() << " is down to "<<b.GetHP()<<" health\n";
		} else{
			std::cout << b.GetName() << " attacks " << a.GetName();
			dmg = (std::rand()%b.GetATK())-(std::rand()%a.GetBLK());
			if (dmg<0) dmg=0;
			std::cout << " and deals "<<dmg<<" damage\n";
			a.SetHP(a.GetHP()-dmg);
			std::cout << a.GetName() << " is down to "<<a.GetHP()<<" health\n";
		}

		turn ++;
	}
}

int main () {
	srand(time(NULL));
	Warrior thor("Thor",100,30,15);
	Warrior hulk("Hulk",135,25,10);

	Battle::StartFight(thor,hulk);

	return 0;
}