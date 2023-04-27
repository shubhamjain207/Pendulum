#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    
    sf::Vertex line[6][2];
    sf::CircleShape shape[6];
    

    sf::Vector2i mousePos;
    bool flag = true;


    float posX=400, posY=250;


    for (int i = 0; i < 6; i++) {
        line[i][0].position = sf::Vector2f(posX, posY);
        line[i][0].color = sf::Color::Red;
        line[i][1].position = sf::Vector2f(posX, posY + 200);
        line[i][1].color = sf::Color::Red;
        

        shape[i].setOutlineColor(sf::Color::Red);
        shape[i].setOutlineThickness(2);
        shape[i].setFillColor(sf::Color::Black);
        shape[i].setRadius(50.f);
        shape[i].setPosition(posX - 50,posY + 200);
        posX += 100;

    }
    
   
    sf::Mouse::setPosition(sf::Vector2i(shape[0].getPosition().x,shape[0].getPosition().y), window);
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        mousePos = sf::Mouse::getPosition(window);

        if (flag) {
           

            line[0][1].position = sf::Vector2f(mousePos);
            shape[0].setPosition(mousePos.x - 50.f, mousePos.y - 50.f);
        
        }

  
        

        if (sqrt(pow((line[0][1].position.x - line[0][0].position.x),2) + pow((line[0][1].position.y - line[0][0].position.y), 2)) > 400.f) {
           
            line[0][1].position.x -= 1.f;
            line[0][1].position.y -= 1.f;
            
            std::cout << line[0][1].position.x << std::endl;
            std::cout << line[0][1].position.y << std::endl;

            flag = false;
        }
        else {
            flag = true;
        }

        window.clear();
        for (int i = 0; i < 6; i ++) {
            

            window.draw(shape[i]);
            window.draw(line[i], 2, sf::Lines);
        }
       
        window.display();
    }

    return 0;
}