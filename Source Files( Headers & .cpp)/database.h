#ifndef DATABASE_H
#define DATABASE_H
#include "Base.h"

class Database{
private:
	Base *listADT;
	int size;
public:
	Database();
	~Database();

	int getsize();
	void add(Product*);
	void scrap(Product*);
	Product* retrieve(int);

	void to_file();
};

#endif	

