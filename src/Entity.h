/*
 * Entity.h
 *
 *  Created on: Mar 1, 2018
 *      Author: Astrid
 */

#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
private:
	int x;
	int y;
public:
	Entity();
	Entity(int x, int y);
	virtual ~Entity();

	void setX(int x);
	void setY(int y);

	int getX();
	int getY();
};

#endif /* ENTITY_H_ */