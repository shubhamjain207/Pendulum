#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    
    sf::Vertex line[6][2];
    sf::CircleShape shape[6];
    

    sf::Vector2i mousePos;
   
    bool flag1 = true;

    float posX=500, posY=250;

    float val=0.1f;

    int points[100][2];

    line[0][0].position = sf::Vector2f(posX-100, posY);
    line[0][0].color = sf::Color::Red;
    line[0][1].position = sf::Vector2f(posX-100-200, posY);
    line[0][1].color = sf::Color::Red;

    float wall = 5.f;

    shape[0].setOutlineColor(sf::Color::Red);
    shape[0].setOutlineThickness(4);
    shape[0].setFillColor(sf::Color::Black);
    shape[0].setRadius(50.f);
    shape[0].setPosition(line[0][1].position.x - 50, line[0][1].position.y - 50);


    for (int i = 1; i < 6; i++) {
        line[i][0].position = sf::Vector2f(posX, posY);
        line[i][0].color = sf::Color::Red;
        line[i][1].position = sf::Vector2f(posX, posY + 200);
        line[i][1].color = sf::Color::Red;
        

        shape[i].setOutlineColor(sf::Color::Red);
        shape[i].setOutlineThickness(4);
        shape[i].setFillColor(sf::Color::Black);
        shape[i].setRadius(50.f);
        shape[i].setPosition(posX - 50,posY + 200);
        posX += 100;

    }
    
    float endPoint = 180;

    sf::Mouse::setPosition(sf::Vector2i(shape[0].getPosition().x,shape[0].getPosition().y), window);
    
    for (int i = 0; i < 100; i++) {
        points[i][0] = sin(30);
        points[i][1] = cos(30);
       // endPoint += 1.0f;
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

      
        window.clear();

       
       
        if (endPoint < 182.3) {
        
            line[0][1].position = sf::Vector2f(400 + sin(endPoint) * 200, 300 + cos(endPoint) * 200);
            
            endPoint += val;
           
            
            if (endPoint <= 181) {
                val = 0.1f;
                
            }
           
            std::cout << "left- " << endPoint << std::endl;
            

            shape[0].setPosition(line[0][1].position.x - 50, line[0][1].position.y - 50);
        
        }

       

        else{

            

            line[5][1].position = sf::Vector2f(900 + sin(endPoint) * 200, 300 + cos(endPoint) * 200);
            endPoint += val;
            shape[5].setPosition(line[5][1].position.x - 50, line[5][1].position.y - 50);

            if (shape[5].getPosition().y <= 230) {
                val = -.1;

            }

            std::cout << "left- " << endPoint << std::endl;
            

        }

       

      /* 
       if (shape[5].getPosition().x - 160  <= shape[4].getPosition().x) {
            std::cout << "24" << std::endl;
            flag1 = true;
            

        }

        if (shape[0].getPosition().x + 120 >= shape[1].getPosition().x) {
                
                line[0][1].position = sf::Vector2f(line[0][1].position.x - 1.f, line[0][1].position.y);
                flag1 = false;
                

        }*/

        for (int i = 0; i < 6; i ++) {
            

            window.draw(shape[i]);

            

            window.draw(line[i], 2, sf::Lines);
        }
       
        window.display();

        window.setFramerateLimit(40);
    }

    return 0;
}