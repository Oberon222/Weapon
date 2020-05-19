#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Weapon
{
private:
	string name;
	int range;
	float caliber;
	int Àmmunition_count;
	int maxSize;

public:
	void Initialize (string _name, int _ramge,  float _caliber, int _maxSize) 
	{
		name = _name;
		range = _ramge;
		caliber = _caliber;
		maxSize = _maxSize;
		Àmmunition_count = maxSize;
	}

	bool Shot()
	{
		while (Àmmunition_count > 0)
		{
			Àmmunition_count--;
			cout << "The shot was fired!" << endl;
			return 1;
		}
			cout<<"Reload the weapon" << endl;
			return 0;
	}

	void Recharge()
	{
		if (Àmmunition_count == 0) {
			Àmmunition_count = maxSize;
		}
	}

	
	void Save(Weapon a)
	{
		ofstream fout;
		fout.open("Weapon.txt");
		bool isOpen = fout.is_open();
		if (!isOpen) {
			cout << "Error" << endl;
		}

		fout.write((char*)&a, sizeof(Weapon));
		fout.close();

	}

	void Load()
	{
		ifstream fin;
		fin.open("Weapon.txt");
		if (!fin.is_open()) {
			cout << "Error" << endl;
		}

		Weapon tmp;
		while (fin.read((char*)&tmp, sizeof(Weapon)))
		{

		}
		fin.close();

	}

};

int main()
{
	Weapon pistol_1;
	pistol_1.Initialize("Makarov",50, 9, 8);
	pistol_1.Shot();
	pistol_1.Recharge();
	pistol_1.Save(pistol_1);
	pistol_1.Load();


	Weapon pistol_2;
	pistol_2.Initialize("Fort14",50,9,14);
	pistol_2.Shot();
	pistol_2.Recharge();
	pistol_2.Save(pistol_2);
	pistol_2.Load();

	Weapon pistol_3;
	pistol_3.Initialize("Beretta92",50,9,15);
	pistol_3.Shot();
	pistol_3.Recharge();
	pistol_3.Save(pistol_3);
	pistol_3.Load();

	

	system("pause");
	return 0;

}