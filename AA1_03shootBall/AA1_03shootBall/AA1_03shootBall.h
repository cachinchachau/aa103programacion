#pragma once

enum class Ball
{

    VERDE,
    NARANJA,
    AMARILLO,
    AZUL,
    ROJO,
    NONE

};

struct Player
{

    std::string name;
    int score;
    int pos;
    int ballCounter = 0;

    Ball* gun = nullptr;

    void init(std::string newName, int position)
    {

        name = newName;
        pos = position;

        gun = new Ball[30];

        for (int i = 0; i < 30; i++)
        {

            int num = rand() % 4;

            switch (num)
            {
            case 0:
                gun[i] = Ball::NARANJA;
                break;
            case 1:
                gun[i] = Ball::VERDE;
                break;
            case 2:
                gun[i] = Ball::ROJO;
                break;
            case 3:
                gun[i] = Ball::AZUL;
                break;
            case 4:
                gun[i] = Ball::AMARILLO;
                break;
            default:
                break;
            }

        }

    }

    Ball shoot()
    {
        gun[ballCounter] = Ball::NONE;
        ballCounter++;
        return gun[ballCounter - 1];
    }
};

struct Panel
{

    Ball* panel = nullptr;
    int size;

    void init()
    {
        std::cout << "how many balls in the panel? ";
        std::cin >> size;

        panel = new Ball[size];

        for (int i = 0; i < size; i++)
        {

            int num = rand() % 4;

            switch (num)
            {
            case 0:
                panel[i] = Ball::NARANJA;
                break;
            case 1:
                panel[i] = Ball::VERDE;
                break;
            case 2:
                panel[i] = Ball::ROJO;
                break;
            case 3:
                panel[i] = Ball::AZUL;
                break;
            case 4:
                panel[i] = Ball::AMARILLO;
                break;
            default:
                break;
            }

        }

    }

    void insert(int position, Ball ball)
    {

        if (position < 0 || position > size)
        {
            std::cout << "invalid position" << std::endl;
            return;
        }

        size++;

        Ball* tempPanel = new Ball[size];

        for (int i = 0; i < position; i++)
        {
            tempPanel[i] = panel[i];
        }

        tempPanel[position] = ball;

        for (int i = position + 1; i < size; i++)
        {
            tempPanel[i] = panel[i - 1];
        }

        delete[] panel;

        panel = tempPanel;

    }

    int verifier(int position, Ball ball) const
    {
        if (position < 0 || position > size)
        {
            std::cout << "invalid position" << std::endl;
            return;
        }

        int count = 0;
        int offsetL = 2;
        int offsetR = 2;
        int firstBall;

        if (position == 0)
        {
            offsetL = 0;
        }
        else if (position == 1)
        {
            offsetL = 1;
        }
        else if (position == size)
        {
            offsetR = 0;
        }
        else if (position == size - 1)
        {
            offsetR = 1;
        }

        for (int i = position - offsetL; i <= (position + offsetR); i++)
        {
            if (panel[i] == panel[position])
            {
                if (count == 0)
                    firstBall = i;

                count++;

            }
            else
            {
                count = 0;
            }

            if (count == 3)
            {
                return firstBall;
            }

        }

        return -1;

    }

    void resizePanel(int newSize)
    {
        size = newSize;

        Ball* tempPanel = new Ball[newSize];

        for (int i = 0; i < newSize; i++)
        {
            tempPanel[i] = panel[i];
        }

        delete[] panel;

        panel = tempPanel;
    }

    void deleteThree(int position)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = position; j < size - 3; j++)
            {
                panel[j] = panel[j + 1];
            }
        }

        panel[size - 1] = Ball::NONE;
        panel[size - 2] = Ball::NONE;
        panel[size - 3] = Ball::NONE;

    }

    void insertThree()
    {
        for (int i = size - 3; i < size; i++)
        {

            int num = rand() % 4;

            switch (num)
            {
            case 0:
                panel[i] = Ball::NARANJA;
                break;
            case 1:
                panel[i] = Ball::VERDE;
                break;
            case 2:
                panel[i] = Ball::ROJO;
                break;
            case 3:
                panel[i] = Ball::AZUL;
                break;
            case 4:
                panel[i] = Ball::AMARILLO;
                break;
            default:
                break;
            }

        }
    }

    void printPanel()
    {
        for (int i = 0; i < size; i++)
        {

            switch (panel[i])
            {
            case Ball::NARANJA:
                std::cout << "O ";
                break;
            case Ball::AMARILLO:
                std::cout << "Y ";
                break;
            case Ball::AZUL:
                std::cout << "B ";
                break;
            case Ball::ROJO:
                std::cout << "R ";
                break;
            case Ball::VERDE:
                std::cout << "G ";
                break;
            default:
                break;
            }

        }
    }

};

char printFirstBall(Ball* gun, int pos)
{
    switch (gun[pos])
    {
    case Ball::NARANJA:
        return 'O';
        break;
    case Ball::AMARILLO:
        return 'Y';
        break;
    case Ball::AZUL:
        return 'B';
        break;
    case Ball::ROJO:
        return 'R';
        break;
    case Ball::VERDE:
        return 'G';
        break;
    default:
        break;
    }
}