#include <iostream>

class Car
{
public:
	Car(int x, int y);
	virtual int getPositionX();
	virtual int getPositionY();
	virtual std::string getOrientation();
	virtual bool move(int step);
	virtual bool setOrientation(std::string orientation);
	virtual bool setPosition(int x, int y);
	virtual void turnClockwise();

private:
	int currentX;
	int currentY;
	int boundaryX;
	int boundaryY;
	std::string currentOrientation;
	bool checkPosition(int x, int y);
	bool checkOrientation(std::string orientation);
};

//when create a instance,it need to input the car park size.
Car::Car(int x, int y) :
	currentX(0),currentY(0), boundaryX(0), boundaryY(0), currentOrientation("N")
{
	if (x <= 0 || y <= 0)
	{
		throw std::exception("X or Y setting value is not allowed");
	}
	boundaryX = x;
	boundaryY = y;
}

int Car::getPositionX()
{
	return currentX;
}

int Car::getPositionY()
{
	return currentY;
}

std::string Car::getOrientation()
{
	return currentOrientation;
}

//check current position in the car park zone.
bool Car::checkPosition(int x, int y)
{
	if (x > boundaryX || y > boundaryY || x<= 0 || y <= 0)
	{
		std::cout << "X or Y out of range.X:" << x << " Y:" << y << std::endl;
		//throw std::exception("X or Y out of range");
		return false;
	}
	return true;
}

//orientation only support E W N S
bool Car::checkOrientation(std::string orientation)
{
	if (orientation == "E" || orientation == "N" || orientation == "W" || orientation == "S")
	{
		return true;
	}
	
	std::cout << "Orientation is not right:" << orientation << std::endl;
	return false;
}

bool Car::setPosition(int x, int y)
{
	if (checkPosition(x, y) == false)
	{
		return false;
	}
	
	currentX = x;
	currentY = y;
	std::cout << "Current position set to X:" << x << " Y:" << y << std::endl;
	return true;
}

bool Car::setOrientation(std::string orientation)
{
	if (checkOrientation(orientation) == false)
	{
		return false;
	}
	currentOrientation = orientation;
	std::cout << "Current Orientation set to:" << currentOrientation << std::endl;
	return true;
}

void Car::turnClockwise()
{
	if (currentOrientation == "E")
	{
		currentOrientation = "S";
		std::cout << "Current Orientation:" << currentOrientation << std::endl;
	}
	else if (currentOrientation == "S")
	{
		currentOrientation = "W";
		std::cout << "Current Orientation:" << currentOrientation << std::endl;
	}
	else if (currentOrientation == "W")
	{
		currentOrientation = "N";
		std::cout << "Current Orientation:" << currentOrientation << std::endl;
	}
	else if (currentOrientation == "N")
	{
		currentOrientation = "E";
		std::cout << "Current Orientation:" << currentOrientation << std::endl;
	}
}

bool Car::move(int step)
{
	if (step < 0)
	{
		std::cout << "move step is not right:" << step << std::endl;
		return false;
	}
	int tempX = currentX;
	int tempY = currentY;
	if (currentOrientation == "E")
	{
		tempX += step;
	}
	else if (currentOrientation == "S")
	{
		tempY -= step;
	}
	else if (currentOrientation == "W")
	{
		tempX -= step;
	}
	else if (currentOrientation == "N")
	{
		tempY += step;
	}

	if (checkPosition(tempX, tempY) == false)
	{
		return false;
	}

	currentX = tempX;
	currentY = tempY;
	return true;
}

int main()
{
	std::cout << "Example1:" << std::endl;
	Car car1(4, 4);
	car1.setPosition(1, 1);
	car1.setOrientation("N");
	car1.turnClockwise();
	
	std::cout << "Example2:" << std::endl;
	Car car2(4, 4);
	car2.setPosition(1, 1);
	car2.setOrientation("N");
	car2.move(1);
	std::cout << "Current Position X:" << car2.getPositionX() << std::endl;
	std::cout << "Current Position Y:" << car2.getPositionY() << std::endl;

	std::cout << "Example3:" << std::endl;
	Car car3(4, 4);
	car3.setPosition(1, 1);
	car3.setOrientation("E");
	car3.move(1);
	std::cout << "Current Position X:" << car3.getPositionX() << std::endl;
	std::cout << "Current Position Y:" << car3.getPositionY() << std::endl;

	std::cout << "Example4:" << std::endl;
	Car car4(4, 4);
	car4.setPosition(1, 1);
	car4.setOrientation("W");
	car4.move(1);

	std::cout << "Example5:" << std::endl;
	Car car5(4, 4);
	car5.setPosition(1, 1);
	car5.setOrientation("E");
	car5.move(2);
	std::cout << "Current Position X:" << car5.getPositionX() << std::endl;
	std::cout << "Current Position Y:" << car5.getPositionY() << std::endl;

}
