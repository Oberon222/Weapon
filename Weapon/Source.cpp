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

	void Load(Weapon a)
	{
		ifstream fin;
		fin.open("Weapon.txt");
		fin.read((char*)&a, sizeof(Weapon));
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
	pistol_1.Load(pistol_1);


	Weapon pistol_2;
	pistol_2.Initialize("Fort14",50,9,14);
	pistol_2.Shot();
	pistol_2.Recharge();
	pistol_2.Save(pistol_2);
	pistol_2.Load(pistol_2);

	Weapon pistol_3;
	pistol_3.Initialize("Beretta92",50,9,15);
	pistol_3.Shot();
	pistol_3.Recharge();
	pistol_3.Save(pistol_3);
	pistol_3.Load(pistol_3);

	

	system("pause");
	return 0;

}