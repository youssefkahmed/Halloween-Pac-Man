#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\window.hpp>
#include <sstream>
#include "Hearts.h"
#include "MapUpDown.h"
#include "MapLeftRight.h"
#include "MapInner.h"
#include "Coin.h"
#include "Menu.h"

using  namespace sf;
 
int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "Pac-Man");
	
	int Draw = 0;

	int ClearMenu = 0;
	float playerspeed = 0.35, enemyspeed = 0.3;
	int counter = 0;
	int movement1 = 0, movement2 = 0, movement3 = 0;


	//MUSIC
	Music music ;
	music.openFromFile("DamagedCoda.wav");
	music.play();



	//SoundEffects
	sf::SoundBuffer sound0;
	sf::Sound sound1;
	if (!sound0.loadFromFile("killed.wav"))
	{
		
	}
	sound1.setBuffer(sound0);
	





	SoundBuffer sound2;
	Sound sound3;
	if (!sound2.loadFromFile("hearteat.wav"))
	{
		
	}
	sound3.setBuffer(sound2);


	SoundBuffer sound4;
	Sound sound5;
	if (!sound4.loadFromFile("coineat.wav"))
	{
		
	}
	sound5.setBuffer(sound4);


	



	//MapDrawing

	Map map1(Vector2f(800, 30));
	map1.position(Vector2f(0, 0));

	Map map2(Vector2f(800, 30));
	map2.position(Vector2f(0, 520));


	Map1 map3(Vector2f(20, 520));
	map3.position(Vector2f(0, 0));

	Map1 map4(Vector2f(20, 520));
	map4.position(Vector2f(780, 0));

	Map map_Line(Vector2f(20, 80));
	map_Line.position(Vector2f(240, 30));

	Map map_Line2(Vector2f(20, 80));
	map_Line2.position(Vector2f(240.f, 440.f));


	Map map_Line3(Vector2f(20, 80));
	map_Line3.position(Vector2f(540.f, 440.f));

	Map map_Line4(Vector2f(20, 80));
	map_Line4.position(Vector2f(540.f, 30.f));


	Map map_Line5(Vector2f(70, 20));
	map_Line5.position(Vector2f(510.f, 250.f));


	Map map_Line6(Vector2f(70, 20));
	map_Line6.position(Vector2f(510.f, 345.f));


	Map map_Line7(Vector2f(70, 20));
	map_Line7.position(Vector2f(240.f, 250.f));


	Map map_Line8(Vector2f(70, 20));
	map_Line8.position(Vector2f(240.f, 350.f));


	Map1 map_Line9(Vector2f(220, 20));
	map_Line9.position(Vector2f(300.f, 170.f));


	Map2 map_Line10(Vector2f(20, 270));
	map_Line10.position(Vector2f(400.f, 170.f));


	Map2 shapeL_U(Vector2f(20, 100));
	shapeL_U.position(Vector2f(80.f, 320.f));
	
	Map2 shapeL_D(Vector2f(100, 20));
	shapeL_D.position(Vector2f(80.f, 420.f));

	Map2 shapeL_U2(Vector2f(20, 100));
	shapeL_U2.position(Vector2f(705.f, 320.f));

	Map2 shapeL_D2(Vector2f(100, 20));
	shapeL_D2.position(Vector2f(625.f, 420.f));

	Map2 shapeT_U(Vector2f(20, 100));
	shapeT_U.position(Vector2f(80.f, 90.f));


	Map2 shapeT_D(Vector2f(100, 20));
	shapeT_D.position(Vector2f(80.f, 90.f));


	Map2 shapeT_U2(Vector2f(100, 20));
	shapeT_U2.position(Vector2f(620.f, 90.f));


	Map2 shapeT_D2(Vector2f(20, 100));
	shapeT_D2.position(Vector2f(705.f, 90.f));

	Map map_TransLine5(sf::Vector2f(20.f, 80.f));
	map_TransLine5.position(Vector2f(475.f, 380.f));

	Map map_TransLine2(sf::Vector2f(20.f, 70.f));
	map_TransLine2.position(Vector2f(600.f, 180.f));

	Map map_TransLine3(sf::Vector2f(70.f, 20.f));
	map_TransLine3.position(Vector2f(630.f, 250.f));

	Map map_TransLine4(sf::Vector2f(70.f, 20.f));
	map_TransLine4.position(Vector2f(430.f, 345.f));

	Map map_TransLine(sf::Vector2f(70.f, 20.f));
	map_TransLine.position(Vector2f(220.f, 330.f));

	Map map_TransLine7(sf::Vector2f(220.f, 20.f));
	map_TransLine7.position(Vector2f(230.f, 90.f));

	Map map_TransLine8(sf::Vector2f(20.f, 80.f));
	map_TransLine8.position(Vector2f(540.f, 60.f));

	//MenuDrawing
	Menu menu(window.getSize().x, window.getSize().y);
	RectangleShape skull(Vector2f(800.f,700.f));
	skull.setPosition(0.f,0.f);
   
	Texture skull1;
	skull1.loadFromFile("skull2.JPEG");

	skull.setTexture(&skull1); 
	menu.draw(window);
	window.display();
	window.clear(Color::Black);



	//PlayerTexture
	Texture playerTexture;
	playerTexture.loadFromFile("project2.png");
	Sprite player(playerTexture);
	player.setPosition(100, 110);
	player.setTextureRect(IntRect(0, 0, 40, 55));


	//Enemies Textures
	Texture enemyT1;
	enemyT1.loadFromFile("enemy111.PNG");
	Sprite enemy1(enemyT1);
	enemy1.setPosition(180.f, 460.f);
	enemy1.setTextureRect(IntRect(0, 0, 50, 55));

	Texture enemyT2;
	enemyT2.loadFromFile("enemy222.PNG");
	Sprite enemy2(enemyT2);
	enemy2.setPosition(720.f, 40.f);
	enemy2.setTextureRect(IntRect(0, 0, 50, 55));

	Texture enemyT3;
	enemyT3.loadFromFile("enemy333.PNG");
	Sprite enemy3(enemyT3);
	enemy3.setPosition(260.f, 40.f);
	enemy3.setTextureRect(IntRect(0, 0, 50, 55));




	Map map_TransLine6(sf::Vector2f(20.f, 80.f));
	map_TransLine6.position(Vector2f(240.f, 150.f));

	



	//SCORE OBJECT
	int score = 0;
	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	//ScoreCounter
	std::ostringstream ssScore;
	ssScore << "Score : " << score;

	sf::Text LabelScore;
	LabelScore.setCharacterSize(40);
	LabelScore.setPosition(0.f, 550.f);
	LabelScore.setFont(arial);
	LabelScore.setString(ssScore.str());
	
	//LivesCounter

	int live = 3;
	sf::Font Arial;
	Arial.loadFromFile("arial.ttf");

	std::ostringstream sScore;
	sScore << "LIVES : " << live;

	sf::Text abelScore;
	abelScore.setCharacterSize(40);
	abelScore.setPosition(600.f, 550.f);
	abelScore.setFont(Arial);
	abelScore.setString(sScore.str());

	//HeartDrawing
	Heart heart1(sf::Vector2f(40.f, 40.f));
	heart1.position(sf::Vector2f(30.f, 30.f));
	
	Heart heart2(sf::Vector2f(40.f, 40.f));
	heart2.position(sf::Vector2f(30.f, 480.f));

	Heart heart3(sf::Vector2f(40.f, 40.f));
	heart3.position(sf::Vector2f(740.f, 30.f));

	Heart heart4(sf::Vector2f(40.f, 40.f));
	heart4.position(sf::Vector2f(740.f, 480.f));


	//CoinDrawing
	
	Coin coin1(sf::Vector2f(40.f, 40.f));
	coin1.position(sf::Vector2f(30.f, 80.f));
	Coin coin2(sf::Vector2f(40.f, 40.f));
	coin2.position(sf::Vector2f(30.f, 130.f));
	Coin coin3(sf::Vector2f(40.f, 40.f));
	coin3.position(sf::Vector2f(30.f, 180.f));
	Coin coin4(sf::Vector2f(40.f, 40.f));
	coin4.position(sf::Vector2f(30.f, 230.f));
	Coin coin5(sf::Vector2f(40.f, 40.f));
	coin5.position(sf::Vector2f(30.f, 280.f));
	Coin coin6(sf::Vector2f(40.f, 40.f));
	coin6.position(sf::Vector2f(30.f, 330.f));
	Coin coin7(sf::Vector2f(40.f, 40.f));
	coin7.position(sf::Vector2f(30.f, 380.f));
	Coin coin8(sf::Vector2f(40.f, 40.f));
	coin8.position(sf::Vector2f(30.f, 430.f));
	

	
	Coin coin11(sf::Vector2f(40.f, 40.f));
	coin11.position(sf::Vector2f(740.f, 80.f));
	Coin coin12(sf::Vector2f(40.f, 40.f));
	coin12.position(sf::Vector2f(740.f, 130.f));
	Coin coin13(sf::Vector2f(40.f, 40.f));
	coin13.position(sf::Vector2f(740.f, 180.f));
	Coin coin14(sf::Vector2f(40.f, 40.f));
	coin14.position(sf::Vector2f(740.f, 230.f));
	Coin coin15(sf::Vector2f(40.f, 40.f));
	coin15.position(sf::Vector2f(740.f, 280.f));
	Coin coin16(sf::Vector2f(40.f, 40.f));
	coin16.position(sf::Vector2f(740.f, 330.f));
	Coin coin17(sf::Vector2f(40.f, 40.f));
	coin17.position(sf::Vector2f(740.f, 380.f));
	Coin coin18(sf::Vector2f(40.f, 40.f));
	coin18.position(sf::Vector2f(740.f, 430.f));
	Coin coin20(sf::Vector2f(40.f, 40.f));
	coin20.position(sf::Vector2f(80.f, 30.f));
	Coin coin21(sf::Vector2f(40.f, 40.f));
	coin21.position(sf::Vector2f(130.f, 30.f));
	Coin coin22(sf::Vector2f(40.f, 40.f));
	coin22.position(sf::Vector2f(180.f, 30.f));
	Coin coin34(sf::Vector2f(40.f, 40.f));
	coin34.position(sf::Vector2f(270.f, 30.f));
	Coin coin35(sf::Vector2f(40.f, 40.f));
	coin35.position(sf::Vector2f(320.f, 30.f));
	Coin coin36(sf::Vector2f(40.f, 40.f));
	coin36.position(sf::Vector2f(370.f, 30.f));
	Coin coin37(sf::Vector2f(40.f, 40.f));
	coin37.position(sf::Vector2f(420.f, 30.f));
	Coin coin38(sf::Vector2f(40.f, 40.f));
	coin38.position(sf::Vector2f(470.f, 30.f));
	Coin coin39(sf::Vector2f(40.f, 40.f));
	coin39.position(sf::Vector2f(570.f, 30.f));
	Coin coin40(sf::Vector2f(40.f, 40.f));
	coin40.position(sf::Vector2f(620.f, 30.f));
	Coin coin41(sf::Vector2f(40.f, 40.f));
	coin41.position(sf::Vector2f(680.f, 30.f));
	Coin coin23(sf::Vector2f(40.f, 40.f));
	coin23.position(sf::Vector2f(180.f, 80.f));
	Coin coin24(sf::Vector2f(40.f, 40.f));
	coin24.position(sf::Vector2f(180.f, 130.f));
	Coin coin25(sf::Vector2f(40.f, 40.f));
	coin25.position(sf::Vector2f(180.f, 180.f));
	Coin coin26(sf::Vector2f(40.f, 40.f));
	coin26.position(sf::Vector2f(180.f, 230.f));
	Coin coin27(sf::Vector2f(40.f, 40.f));
	coin27.position(sf::Vector2f(180.f, 280.f));
	Coin coin28(sf::Vector2f(40.f, 40.f));
	coin28.position(sf::Vector2f(180.f, 330.f));
	Coin coin29(sf::Vector2f(40.f, 40.f));
	coin29.position(sf::Vector2f(180.f, 380.f));
	Coin coin30(sf::Vector2f(40.f, 40.f));
	coin30.position(sf::Vector2f(180.f, 430.f));
	Coin coin31(sf::Vector2f(40.f, 40.f));
	coin31.position(sf::Vector2f(180.f, 480.f));
	Coin coin32(sf::Vector2f(40.f, 40.f));
	coin32.position(sf::Vector2f(80.f, 480.f));
	Coin coin33(sf::Vector2f(40.f, 40.f));
	coin33.position(sf::Vector2f(130.f, 480.f));
	Coin coin42(sf::Vector2f(40.f, 40.f));
	coin42.position(sf::Vector2f(270.f, 480.f));
	Coin coin43(sf::Vector2f(40.f, 40.f));
	coin43.position(sf::Vector2f(320.f, 480.f));
	Coin coin44(sf::Vector2f(40.f, 40.f));
	coin44.position(sf::Vector2f(370.f, 480.f));
	Coin coin45(sf::Vector2f(40.f, 40.f));
	coin45.position(sf::Vector2f(420.f, 480.f));
	Coin coin46(sf::Vector2f(40.f, 40.f));
	coin46.position(sf::Vector2f(470.f, 480.f));
	Coin coin47(sf::Vector2f(40.f, 40.f));
	coin47.position(sf::Vector2f(570.f, 480.f));
	Coin coin48(sf::Vector2f(40.f, 40.f));
	coin48.position(sf::Vector2f(620.f, 480.f));
	Coin coin49(sf::Vector2f(40.f, 40.f));
	coin49.position(sf::Vector2f(680.f, 480.f));
	Coin coin50(sf::Vector2f(40.f, 40.f));
	coin50.position(sf::Vector2f(570.f, 30.f));
	Coin coin51(sf::Vector2f(40.f, 40.f));
	coin51.position(sf::Vector2f(570.f, 80.f));
	Coin coin52(sf::Vector2f(40.f, 40.f));
	coin52.position(sf::Vector2f(570.f, 130.f));
	Coin coin53(sf::Vector2f(40.f, 40.f));
	coin53.position(sf::Vector2f(570.f, 180.f));
	Coin coin54(sf::Vector2f(40.f, 40.f));
	coin54.position(sf::Vector2f(570.f, 230.f));
	Coin coin55(sf::Vector2f(40.f, 40.f));
	coin55.position(sf::Vector2f(570.f, 280.f));
	Coin coin56(sf::Vector2f(40.f, 40.f));
	coin56.position(sf::Vector2f(570.f, 330.f));
	Coin coin57(sf::Vector2f(40.f, 40.f));
	coin57.position(sf::Vector2f(570.f, 380.f));
	Coin coin58(sf::Vector2f(40.f, 40.f));
	coin58.position(sf::Vector2f(570.f, 430.f));
	Coin coin59(sf::Vector2f(40.0f, 40.f));
	coin59.position(sf::Vector2f(570.f, 480.f));


	
	RectangleShape youWin(Vector2f(300.f,200.f));
	youWin.setPosition(260.f,200.f);
   
	Texture win ;
	win.loadFromFile("win.JPEG");
	youWin.setTexture(&win);

	RectangleShape youlose(Vector2f(300.f,200.f));
	youlose.setPosition(260.f,200.f);
   
	Texture lose;
	lose.loadFromFile("lose.JPEG");
	youlose.setTexture(&lose);




	// DIFFICULTY MENU //

		 sf::Text difficulty[4];
		 sf::Font font;
		 font.loadFromFile("6809 chargen.ttf");

		 difficulty[0].setFont(font);
		 difficulty[0].setString("EASY----Press E");
		 difficulty[0].setPosition(sf::Vector2f(250, 300));
	     /*difficulty[0].setColor(sf::Color(58, 133, 154));*/


		 difficulty[1].setFont(font);
		 difficulty[1].setString("MEDIUM----Press M");
		 difficulty[1].setPosition(sf::Vector2f(250, 350));
	     /*difficulty[1].setColor(sf::Color(58, 133, 154));*/

		  difficulty[2].setFont(font);
		 difficulty[2].setString("HARD----Press H");
		 difficulty[2].setPosition(sf::Vector2f(250, 400));
	    /* difficulty[2].setColor(sf::Color(58, 133, 154));*/
		

		 difficulty[3].setFont(font);
		 difficulty[3].setString("DIFFICULTY");
		 difficulty[3].setCharacterSize(70);
		 difficulty[3].setPosition(sf::Vector2f(180, 200));


		 sf::Text return1[4];
		 sf::Font font;
		 font.loadFromFile("6809 chargen.ttf");


		  return1[0].setFont(font);
		  return1[0].setString("EASY----Press E");
		  return1[0].setPosition(sf::Vector2f(250, 300));
	     /*difficulty[0].setColor(sf::Color(58, 133, 154));*/


		 difficulty[1].setFont(font);
		 difficulty[1].setString("MEDIUM----Press M");
		 difficulty[1].setPosition(sf::Vector2f(250, 350));
	     /*difficulty[1].setColor(sf::Color(58, 133, 154));*/

		  difficulty[2].setFont(font);
		 difficulty[2].setString("HARD----Press H");
		 difficulty[2].setPosition(sf::Vector2f(250, 400));
	    /* difficulty[2].setColor(sf::Color(58, 133, 154));*/
		

		 difficulty[3].setFont(font);
		 difficulty[3].setString("DIFFICULTY");
		 difficulty[3].setCharacterSize(70);
		 difficulty[3].setPosition(sf::Vector2f(180, 200));
	    /*difficulty[3].setColor(sf::Color(58, 133, 154));*/

		 sf::RectangleShape diff_menu;
		 diff_menu.setSize(sf::Vector2f(800.0f, 700.0f));
		 sf::Texture menuT;
		 menuT.loadFromFile("skulls3.jpg");
		 diff_menu.setTexture(&menuT);
		 diff_menu.setPosition(sf::Vector2f(0.0f, 0.0f));
		 
	
	
	
	
	while (window.isOpen())
	{
		
		

		Event Event;
		while (window.pollEvent(Event))
		{


			if (Event.type == sf::Event::Closed)
			{
				

				window.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)){
				window.close();
			
			}

			if (Keyboard::isKeyPressed(Keyboard::Space)){
				ClearMenu++;
				Draw = -1;
				
			}
			


		}


		if (Keyboard::isKeyPressed(Keyboard::Up)){
			player.move(0, -playerspeed);
			player.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (player.getGlobalBounds().intersects(map1.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map2.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map3.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map4.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_U.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_D.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_U2.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_D2.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_U.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_D.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_U2.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_D2.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line2.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line3.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line4.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line5.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line6.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line7.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line8.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
				player.move(0, playerspeed);
			if (player.getGlobalBounds().intersects(heart1.getGlobalBounds())){
			    heart1.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin1.getGlobalBounds())){
				coin1.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin2.getGlobalBounds())){
				coin2.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin3.getGlobalBounds())){
				coin3.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin4.getGlobalBounds())){
				coin4.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin5.getGlobalBounds())){
				coin5.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin6.getGlobalBounds())){
				coin6.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin7.getGlobalBounds())){
				coin7.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin8.getGlobalBounds())){
				coin8.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart2.getGlobalBounds())){
				heart2.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play(); 
			}
			if (player.getGlobalBounds().intersects(heart3.getGlobalBounds())){
				heart3.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin11.getGlobalBounds())){
				coin11.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin12.getGlobalBounds())){
				coin12.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin13.getGlobalBounds())){
				coin13.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin14.getGlobalBounds())){
				coin14.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin15.getGlobalBounds())){
				coin15.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin16.getGlobalBounds())){
				coin16.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin17.getGlobalBounds())){
				coin17.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin18.getGlobalBounds())){
				coin18.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart4.getGlobalBounds())){
				heart4.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play(); 
			}
			if (player.getGlobalBounds().intersects(coin20.getGlobalBounds())){
				coin20.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin21.getGlobalBounds())){
				coin21.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin22.getGlobalBounds())){
				coin22.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin23.getGlobalBounds())){
				coin23.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin24.getGlobalBounds())){
				coin24.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin25.getGlobalBounds())){
				coin25.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin26.getGlobalBounds())){
				coin26.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin27.getGlobalBounds())){
				coin27.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin28.getGlobalBounds())){
				coin28.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}

			if (player.getGlobalBounds().intersects(coin29.getGlobalBounds())){
				coin29.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin30.getGlobalBounds())){
				coin30.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin31.getGlobalBounds())){
				coin31.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin32.getGlobalBounds())){
				coin32.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin33.getGlobalBounds())){
				coin33.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin34.getGlobalBounds())){
				coin34.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin35.getGlobalBounds())){
				coin35.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin36.getGlobalBounds())){
				coin36.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin37.getGlobalBounds())){
				coin37.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin38.getGlobalBounds())){
				coin38.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin39.getGlobalBounds())){
				coin39.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin40.getGlobalBounds())){
				coin40.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin41.getGlobalBounds())){
				coin41.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin42.getGlobalBounds())){
				coin42.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin43.getGlobalBounds())){
				coin43.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin44.getGlobalBounds())){
				coin44.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin45.getGlobalBounds())){
				coin45.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin46.getGlobalBounds())){
				coin46.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin47.getGlobalBounds())){
				coin47.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin48.getGlobalBounds())){
				coin48.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin49.getGlobalBounds())){
				coin49.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin50.getGlobalBounds())){
				coin50.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin51.getGlobalBounds())){
				coin51.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin52.getGlobalBounds())){
				coin52.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin53.getGlobalBounds())){
				coin53.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin54.getGlobalBounds())){
				coin54.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin55.getGlobalBounds())){
				coin55.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin56.getGlobalBounds())){
				coin56.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin57.getGlobalBounds())){
				coin57.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin58.getGlobalBounds())){
				coin58.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin59.getGlobalBounds())){
				coin59.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Down)){
			player.move(0, playerspeed);
			player.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (player.getGlobalBounds().intersects(map1.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map2.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map3.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map4.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_U.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_D.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_U2.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeL_D2.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_U.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_D.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_U2.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(shapeT_D2.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line2.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line3.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line4.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line5.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line6.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line7.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line8.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
				player.move(0, -playerspeed);
			if (player.getGlobalBounds().intersects(heart1.getGlobalBounds())){
				heart1.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin1.getGlobalBounds())){
				coin1.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin2.getGlobalBounds())){
				coin2.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin3.getGlobalBounds())){
				coin3.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin4.getGlobalBounds())){
				coin4.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin5.getGlobalBounds())){
				coin5.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin6.getGlobalBounds())){
				coin6.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin7.getGlobalBounds())){
				coin7.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin8.getGlobalBounds())){
				coin8.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart2.getGlobalBounds())){
				heart2.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(heart3.getGlobalBounds())){
				heart3.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin11.getGlobalBounds())){
				coin11.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin12.getGlobalBounds())){
				coin12.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin13.getGlobalBounds())){
				coin13.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin14.getGlobalBounds())){
				coin14.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin15.getGlobalBounds())){
				coin15.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin16.getGlobalBounds())){
				coin16.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin17.getGlobalBounds())){
				coin17.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin18.getGlobalBounds())){
				coin18.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart4.getGlobalBounds())){
			    heart4.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin20.getGlobalBounds())){
				coin20.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin21.getGlobalBounds())){
				coin21.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin22.getGlobalBounds())){
				coin22.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin23.getGlobalBounds())){
				coin23.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin24.getGlobalBounds())){
				coin24.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin25.getGlobalBounds())){
				coin25.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin26.getGlobalBounds())){
				coin26.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin27.getGlobalBounds())){
				coin27.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin28.getGlobalBounds())){
				coin28.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}

			if (player.getGlobalBounds().intersects(coin29.getGlobalBounds())){
				coin29.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin30.getGlobalBounds())){
				coin30.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin31.getGlobalBounds())){
				coin31.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin32.getGlobalBounds())){
				coin32.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin33.getGlobalBounds())){
				coin33.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin34.getGlobalBounds())){
				coin34.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin35.getGlobalBounds())){
				coin35.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin36.getGlobalBounds())){
				coin36.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin37.getGlobalBounds())){
				coin37.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin38.getGlobalBounds())){
				coin38.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin39.getGlobalBounds())){
				coin39.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin40.getGlobalBounds())){
				coin40.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin41.getGlobalBounds())){
				coin41.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin42.getGlobalBounds())){
				coin42.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin43.getGlobalBounds())){
				coin43.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin44.getGlobalBounds())){
				coin44.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin45.getGlobalBounds())){
				coin45.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin46.getGlobalBounds())){
				coin46.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin47.getGlobalBounds())){
				coin47.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin48.getGlobalBounds())){
				coin48.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin49.getGlobalBounds())){
				coin49.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin50.getGlobalBounds())){
				coin50.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin51.getGlobalBounds())){
				coin51.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin52.getGlobalBounds())){
				coin52.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin53.getGlobalBounds())){
				coin53.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin54.getGlobalBounds())){
				coin54.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin55.getGlobalBounds())){
				coin55.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin56.getGlobalBounds())){
				coin56.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin57.getGlobalBounds())){
				coin57.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin58.getGlobalBounds())){
				coin58.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin59.getGlobalBounds())){
				coin59.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}




		}
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			player.move(-playerspeed, 0);
			player.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (player.getGlobalBounds().intersects(map1.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map2.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map3.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map4.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_U.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_D.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_U2.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_D2.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_U.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_D.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_U2.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_D2.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line2.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line3.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line4.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line5.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line6.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line7.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line8.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
				player.move(playerspeed, 0);
			if (player.getGlobalBounds().intersects(heart1.getGlobalBounds())){
				heart1.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin1.getGlobalBounds())){
				coin1.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin2.getGlobalBounds())){
				coin2.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin3.getGlobalBounds())){
				coin3.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin4.getGlobalBounds())){
				coin4.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin5.getGlobalBounds())){
				coin5.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin6.getGlobalBounds())){
				coin6.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin7.getGlobalBounds())){
				coin7.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin8.getGlobalBounds())){
				coin8.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart2.getGlobalBounds())){
				heart2.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(heart3.getGlobalBounds())){
				heart3.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin11.getGlobalBounds())){
				coin11.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin12.getGlobalBounds())){
				coin12.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin13.getGlobalBounds())){
				coin13.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin14.getGlobalBounds())){
				coin14.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin15.getGlobalBounds())){
				coin15.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin16.getGlobalBounds())){
				coin16.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin17.getGlobalBounds())){
				coin17.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin18.getGlobalBounds())){
				coin18.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart4.getGlobalBounds())){
				heart4.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin20.getGlobalBounds())){
				coin20.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin21.getGlobalBounds())){
				coin21.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin22.getGlobalBounds())){
				coin22.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin23.getGlobalBounds())){
				coin23.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin24.getGlobalBounds())){
				coin24.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin25.getGlobalBounds())){
				coin25.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin26.getGlobalBounds())){
				coin26.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin27.getGlobalBounds())){
				coin27.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin28.getGlobalBounds())){
				coin28.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}

			if (player.getGlobalBounds().intersects(coin29.getGlobalBounds())){
				coin29.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin30.getGlobalBounds())){
				coin30.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin31.getGlobalBounds())){
				coin31.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin32.getGlobalBounds())){
				coin32.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin33.getGlobalBounds())){
				coin33.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin34.getGlobalBounds())){
				coin34.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin35.getGlobalBounds())){
				coin35.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin36.getGlobalBounds())){
				coin36.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin37.getGlobalBounds())){
				coin37.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin38.getGlobalBounds())){
				coin38.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin39.getGlobalBounds())){
				coin39.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin40.getGlobalBounds())){
				coin40.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin41.getGlobalBounds())){
				coin41.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin42.getGlobalBounds())){
				coin42.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin43.getGlobalBounds())){
				coin43.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin44.getGlobalBounds())){
				coin44.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin45.getGlobalBounds())){
				coin45.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin46.getGlobalBounds())){
				coin46.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin47.getGlobalBounds())){
				coin47.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin48.getGlobalBounds())){
				coin48.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin49.getGlobalBounds())){
				coin49.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin50.getGlobalBounds())){
				coin50.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin51.getGlobalBounds())){
				coin51.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin52.getGlobalBounds())){
				coin52.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin53.getGlobalBounds())){
				coin53.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin54.getGlobalBounds())){
				coin54.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin55.getGlobalBounds())){
				coin55.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin56.getGlobalBounds())){
				coin56.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin57.getGlobalBounds())){
				coin57.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin58.getGlobalBounds())){
				coin58.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin59.getGlobalBounds())){
				coin59.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}




		}
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			player.move(playerspeed, 0);
			player.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (player.getGlobalBounds().intersects(map1.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map2.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map3.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map4.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_U.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_D.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_U2.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeL_D2.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_U.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_D.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_U2.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(shapeT_D2.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line2.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line3.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line4.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line5.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line6.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line7.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line8.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
				player.move(-playerspeed, 0);
			if (player.getGlobalBounds().intersects(heart1.getGlobalBounds())){
				heart1.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin1.getGlobalBounds())){
				coin1.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin2.getGlobalBounds())){
				coin2.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin3.getGlobalBounds())){
				coin3.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin4.getGlobalBounds())){
				coin4.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin5.getGlobalBounds())){
				coin5.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin6.getGlobalBounds())){
				coin6.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin7.getGlobalBounds())){
				coin7.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin8.getGlobalBounds())){
				coin8.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart2.getGlobalBounds())){
				heart2.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(heart3.getGlobalBounds())){
				heart3.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin11.getGlobalBounds())){
				coin11.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin12.getGlobalBounds())){
				coin12.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin13.getGlobalBounds())){
				coin13.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin14.getGlobalBounds())){
				coin14.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin15.getGlobalBounds())){
				coin15.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin16.getGlobalBounds())){
				coin16.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin17.getGlobalBounds())){
				coin17.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin18.getGlobalBounds())){
				coin18.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(heart4.getGlobalBounds())){
				heart4.position(Vector2f(1000, 2000));
				live++;
				sScore.str("");
				sScore << "LIVES : " << live;
				abelScore.setString(sScore.str()); sound3.play();
			}
			if (player.getGlobalBounds().intersects(coin20.getGlobalBounds())){
				coin20.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin21.getGlobalBounds())){
				coin21.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin22.getGlobalBounds())){
				coin22.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin23.getGlobalBounds())){
				coin23.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin24.getGlobalBounds())){
				coin24.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin25.getGlobalBounds())){
				coin25.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin26.getGlobalBounds())){
				coin26.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin27.getGlobalBounds())){
				coin27.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin28.getGlobalBounds())){
				coin28.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}

			if (player.getGlobalBounds().intersects(coin29.getGlobalBounds())){
				coin29.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin30.getGlobalBounds())){
				coin30.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin31.getGlobalBounds())){
				coin31.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin32.getGlobalBounds())){
				coin32.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin33.getGlobalBounds())){
				coin33.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin34.getGlobalBounds())){
				coin34.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin35.getGlobalBounds())){
				coin35.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin36.getGlobalBounds())){
				coin36.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin37.getGlobalBounds())){
				coin37.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin38.getGlobalBounds())){
				coin38.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin39.getGlobalBounds())){
				coin39.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin40.getGlobalBounds())){
				coin40.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin41.getGlobalBounds())){
				coin41.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin42.getGlobalBounds())){
				coin42.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin43.getGlobalBounds())){
				coin43.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin44.getGlobalBounds())){
				coin44.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin45.getGlobalBounds())){
				coin45.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin46.getGlobalBounds())){
				coin46.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin47.getGlobalBounds())){
				coin47.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin48.getGlobalBounds())){
				coin48.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin49.getGlobalBounds())){
				coin49.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin50.getGlobalBounds())){
				coin50.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin51.getGlobalBounds())){
				coin51.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin52.getGlobalBounds())){
				coin52.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin53.getGlobalBounds())){
				coin53.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin54.getGlobalBounds())){
				coin54.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin55.getGlobalBounds())){
				coin55.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin56.getGlobalBounds())){
				coin56.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin57.getGlobalBounds())){
				coin57.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin58.getGlobalBounds())){
				coin58.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}
			if (player.getGlobalBounds().intersects(coin59.getGlobalBounds())){
				coin59.position(Vector2f(1000, 2000));
				score++;
				ssScore.str("");
				ssScore << "Score : " << score;
				LabelScore.setString(ssScore.str()); sound5.play();
			}




		}
		

		counter++;
		if (counter == 6){
			counter = 0;
		}

		/* ENEMY 1 MOVEMENT */

		if (movement1 == 0)
		{
			enemy1.move(-enemyspeed, 0.0f);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map3.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 1)
		{
			enemy1.move(0.0f, -enemyspeed);
			enemy1.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map1.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 2)
		{
			enemy1.move(enemyspeed, 0.0f);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_Line.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 3)
		{
			enemy1.move(0.0f, enemyspeed);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_TransLine.getGlobalBounds()))
			{
				movement1++;
			}

		}

		if (movement1 == 4)
		{
			enemy1.move(enemyspeed, 0.0f);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 5)
		{
			enemy1.move(0.0f, enemyspeed);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map2.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 6)
		{
			enemy1.move(-enemyspeed, 0.0f);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_Line2.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 7)
		{
			enemy1.move(0.0f, -enemyspeed);
			enemy1.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_Line8.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 8)
		{
			enemy1.move(enemyspeed, 0.0f);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 9)
		{
			enemy1.move(0.0f, -enemyspeed);
			enemy1.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 10)
		{
			enemy1.move(-enemyspeed, 0.0f);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map3.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 11)
		{
			enemy1.move(0.0f, enemyspeed);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map2.getGlobalBounds()))
			{
				movement1++;
			}
		}

		if (movement1 == 12)
		{
			enemy1.move(enemyspeed, 0.0f);
			enemy1.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy1.getGlobalBounds().intersects(map_Line2.getGlobalBounds()))
			{
				movement1 = 0;
			}
		}

		/* ENEMY 2 MOVEMENT */

		if (movement2 == 0)
		{
			enemy2.move(0.0f, enemyspeed);
			enemy2.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map2.getGlobalBounds()))
			{
				movement2++;
			}
		}

		if (movement2 == 1)
		{
			enemy2.move(-enemyspeed, 0.0f);
			enemy2.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map_Line3.getGlobalBounds()))
			{
				movement2++;
			}
		}

		if (movement2 == 2)
		{
			enemy2.move(0.0f, -enemyspeed);
			enemy2.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map_Line6.getGlobalBounds()))
			{
				movement2++;
			}
		}

		if (movement2 == 3)
		{
			enemy2.move(-enemyspeed, 0.0f);
			enemy2.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
			{
				movement2++;
			}
		}

		if (movement2 == 4)
		{
			enemy2.move(0.0f, -enemyspeed);
			enemy2.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
			{
				movement2++;
			}
		}

		if (movement2 == 5)
		{
			enemy2.move(enemyspeed, 0.0f);
			enemy2.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map_TransLine2.getGlobalBounds()))
			{
				movement2++;
			}
		}

		if (movement2 == 6)
		{
			enemy2.move(0.0f, -enemyspeed);
			enemy2.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map1.getGlobalBounds()))
			{
				movement2++;
			}
		}

		if (movement2 == 7)
		{
			enemy2.move(enemyspeed, 0.0f);
			enemy2.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy2.getGlobalBounds().intersects(map4.getGlobalBounds()))
			{
				movement2 = 0;
			}
		}



		//ENEMY 3 MOVEMENT



		if (movement3 == 0)
		{
			enemy3.move(enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line4.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 1)
		{
			enemy3.move(0.0f, enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 2)
		{
			enemy3.move(enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy3.getGlobalBounds().intersects(shapeT_D2.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 3)
		{
			enemy3.move(0.0f, enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_TransLine3.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 4)
		{
			enemy3.move(-enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 5)
		{
			enemy3.move(0.0f, enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_TransLine4.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 6)
		{
			enemy3.move(enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy3.getGlobalBounds().intersects(shapeL_U2.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 7)
		{
			enemy3.move(0.0f, enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy3.getGlobalBounds().intersects(shapeL_D2.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 8)
		{
			enemy3.move(-enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_TransLine5.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 9)
		{
			enemy3.move(0.0f, enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 2, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map2.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 10)
		{
			enemy3.move(-enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line2.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 11)
		{
			enemy3.move(0.0f, -enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line8.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 12)
		{
			enemy3.move(enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line10.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 13)
		{
			enemy3.move(0.0f, -enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line9.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 14)
		{
			enemy3.move(-enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 1, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_TransLine6.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 15)
		{
			enemy3.move(0.0f, -enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_TransLine7.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 16)
		{
			enemy3.move(enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_TransLine8.getGlobalBounds()))
			{
				movement3++;
			}
		}

		if (movement3 == 17)
		{
			enemy3.move(0.0f, -enemyspeed);
			enemy3.setTextureRect(IntRect(counter * 65, 0, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map1.getGlobalBounds()))
			{
				movement3++;
			}
		}



		if (movement3 == 18)
		{
			enemy3.move(enemyspeed, 0.0f);
			enemy3.setTextureRect(IntRect(counter * 65, 65 * 3, 50, 55));
			if (enemy3.getGlobalBounds().intersects(map_Line4.getGlobalBounds()))
			{
				movement3 = 0;
			}
		}


		
		if (player.getGlobalBounds().intersects(enemy1.getGlobalBounds())&&live>0)
		{
			live--;
			sScore.str("");
			sScore << "LIVES : " << live;
			abelScore.setString(sScore.str());
			player.setPosition(100, 110);
			sound1.play();
		}
		

		
		if (player.getGlobalBounds().intersects(enemy2.getGlobalBounds())&&live>0)
		{
			live--;
			sScore.str("");
			sScore << "LIVES : " << live;
			abelScore.setString(sScore.str());
			player.setPosition(100, 110);
			sound1.play();
		}
		

		
		if (player.getGlobalBounds().intersects(enemy3.getGlobalBounds())&&live>0)
		{
			live--;
			sScore.str("");
			sScore << "LIVES : " << live;
			abelScore.setString(sScore.str());
			player.setPosition(100, 110);
			sound1.play();
		}
		

		

		window.clear(Color::Black);


		window.clear();
		window.draw(skull);
		menu.draw(window);
		
		if (score == 56  )
		{
			window.clear();
			Draw=0;
				ClearMenu=0;
			window.draw(youWin);
		}
		if (live==0)
		{
			
			window.clear();
			Draw=0;
		
			ClearMenu=0;

			window.draw(youlose);
		}
		
		if (ClearMenu>0){


			window.clear();
		}



		if (Draw < 0)
		{

			window.draw(diff_menu);
			
			for (int i = 0; i < 4; i++)
			{
				window.draw(difficulty[i]);
			
			}

		  
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
				  Draw += 2;
				  live;
		        	sScore.str("");
			sScore << "LIVES : " << live;
			abelScore.setString(sScore.str());
				}

				else if (Keyboard::isKeyPressed(Keyboard::M))
				{
				  enemyspeed = 0.5;
				live--;
			sScore.str("");
			sScore << "LIVES : " << live;
			abelScore.setString(sScore.str());  
				  Draw += 2;
				}

				else if (Keyboard::isKeyPressed(Keyboard::H))
				{
				  live-=2;
			sScore.str("");
			sScore << "LIVES : " << live;
			abelScore.setString(sScore.str());
				  enemyspeed = 0.7;
				  Draw += 2;
				}
				
		}





		if (Draw>0){
			map1.drawMap(window);
			map2.drawMap(window);
			map3.drawMap(window);
			map4.drawMap(window);
			map_Line.drawMap(window);
			map_Line2.drawMap(window);
			map_Line3.drawMap(window);
			map_Line4.drawMap(window);
			map_Line5.drawMap(window);
			map_Line6.drawMap(window);
			map_Line7.drawMap(window);
			map_Line8.drawMap(window);
			map_Line10.drawMap(window);
			map_Line9.drawMap(window);
			shapeL_U.drawMap(window);
			shapeL_U2.drawMap(window);
			shapeL_D.drawMap(window);
			shapeL_D2.drawMap(window);
			shapeT_U.drawMap(window);
			shapeT_U2.drawMap(window);
			shapeT_D.drawMap(window);
			shapeT_D2.drawMap(window);
			heart1.drawTo(window);
			heart2.drawTo(window);
			heart3.drawTo(window);
			heart4.drawTo(window);
			coin1.drawTo(window);
			coin2.drawTo(window);
			coin3.drawTo(window);
			coin4.drawTo(window);
			coin5.drawTo(window);
			coin6.drawTo(window);
			coin7.drawTo(window);
			coin8.drawTo(window);
			coin11.drawTo(window);
			coin12.drawTo(window);
			coin13.drawTo(window);
			coin14.drawTo(window);
			coin15.drawTo(window);
			coin16.drawTo(window);
			coin17.drawTo(window);
			coin18.drawTo(window);
			coin20.drawTo(window);
			coin21.drawTo(window);
			coin22.drawTo(window);
			coin22.drawTo(window);
			coin23.drawTo(window);
			coin24.drawTo(window);
			coin25.drawTo(window);
			coin26.drawTo(window);
			coin27.drawTo(window);
			coin28.drawTo(window);
			coin29.drawTo(window);
			coin30.drawTo(window);
			coin31.drawTo(window);
			coin32.drawTo(window);
			coin33.drawTo(window);
			coin34.drawTo(window);
			coin35.drawTo(window);
			coin36.drawTo(window);
			coin37.drawTo(window);
			coin38.drawTo(window);
			coin39.drawTo(window);
			coin40.drawTo(window);
			coin41.drawTo(window);
			coin42.drawTo(window);
			coin43.drawTo(window);
			coin44.drawTo(window);
			coin45.drawTo(window);
			coin46.drawTo(window);
			coin47.drawTo(window);
			coin48.drawTo(window);
			coin49.drawTo(window);
			coin51.drawTo(window);
			coin52.drawTo(window);
			coin53.drawTo(window);
			coin54.drawTo(window);
			coin55.drawTo(window);
			coin56.drawTo(window);
			coin56.drawTo(window);
			coin57.drawTo(window);
			coin58.drawTo(window);

			window.draw(player);
			window.draw(enemy1);
			window.draw(enemy2);
			window.draw(enemy3);

			window.draw(LabelScore);
			window.draw(abelScore);
		}

		window.display();
		
	


}



	

	}


