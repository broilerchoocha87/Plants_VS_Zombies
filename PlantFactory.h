#include <SFML/Graphics.hpp>
#include "Plants.cpp"
class PlantFactory
{
    protected:
        Plants **myActivePlants;
        int myNumPlants;// stores number of plants and next free location in myActivePlants
        sf::Texture texturePeashooter;
        sf:: Sprite sprite;
    public:
        PlantFactory();
        

        // Upon selection of user and condtions being met, a new plant is created and added to the array
        bool createPlant(int thisplantCode, int x, int y);
        
        // Either when plant dies or is forcefully removed
        void destroyPlant();

        void drawPlants(sf::RenderWindow &window);
        
        ~PlantFactory();
        

};