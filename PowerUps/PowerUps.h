#ifndef POWERUPS_H
#define POWERUPS_H

class PowerUps {
    private:
        float X;
        float Y;
        bool isActive;

    public:
        PowerUps();
        virtual void applyEffect();
        void render();
        void deactivate();
        void randomizePowerUp();
        virtual ~PowerUps();
};

#endif