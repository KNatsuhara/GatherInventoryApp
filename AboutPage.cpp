/********************************************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * ******************************************************************/

#include "AboutPage.hpp"

// Page Components 
namespace
{
    sf::Text titleText, aboutText, helpText, nameText;
    sf::Sprite sprite;
    sf::Texture texture;
    Button settings, home;
	TextBox textbox(40, sf::Color::Black, false, {400, 75});
}

/**********************************************************
*  Create all the components for the page.                *
***********************************************************/
void AboutPage::createPage()
{
    /**** Title text ****/
    titleText.setString("  About");
    titleText.setFont(font);
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(265, 50);

    /**** Title Bar ****/
    if (!texture.loadFromFile("./Images/Gather Orange Banner.png", sf::IntRect(0, 160, 800, 190)))
    {
        std::cout << "\nTitle Bar image could not be loaded from the file.\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);

    /**** About text ****/
    aboutText.setString("Developed By: ");
    aboutText.setFont(font);
    aboutText.setCharacterSize(30);
    aboutText.setFillColor(sf::Color::Black);
    aboutText.setPosition(50, 400);

    /**** Name text ****/
    nameText.setString("Ava Stromme\nKoji Natsuhara\nOscar Birungi\nNathan Brown");
    nameText.setFont(font);
    nameText.setCharacterSize(30);
    nameText.setFillColor(sf::Color::Black);
    nameText.setPosition(200, 450);

    /**** Help text ****/
    helpText.setString("This app was designed to keep inventory of your items within your household.\n By inputting and updating items in your inventory, a personal grocery list \n can be generated just for you! The inventory button will allow you to view all \n your items and update or delete items if necessary! With this app, we hope \n to save you time and allow you to keep track of everything in your house!");
    helpText.setFont(font);
    helpText.setCharacterSize(20);
    helpText.setFillColor(sf::Color::Black);
    helpText.setPosition(50, 250);

    /**** Home Button ****/ 
    home.setButtonColor(sf::Color::Transparent);
    home.setText("");
    home.setSize({ 100, 100 });
    home.setPosition({ 670, 50 });

    /**** Settings Button ****/ 
    settings.setButtonColor(sf::Color::Transparent);
    settings.setText("");
    settings.setSize({ 100, 100 });
    settings.setPosition({ 30, 50 });
}

/**********************************************************
*  Draw the page to the window.                           *
***********************************************************/
void AboutPage::drawPage(void)
{
    /**** Draw ****/
    window->draw(sprite);
    window->draw(titleText);
    window->draw(aboutText);
    window->draw(nameText);
    window->draw(helpText);
    settings.drawTo(*window);
} 

/**********************************************************
*  Perform the event operations.                          *
***********************************************************/
void AboutPage::eventOperation(const sf::Event & event, Inventory &inventory, Item &item)
{
    // If a button was pressed, perform the operation tied to the button
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (settings.mouseHover(*window))           // if the settings button is pressed, change to settings page
        {
            changePage = true;
            newPage = Page::CurrentPage::SettingsPage;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (home.mouseHover(*window))           // if the home button is pressed, change to home page
        {
            changePage = true;
            newPage = Page::CurrentPage::HomePage;
        }
    }
    
    // for selecting the textbox
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		textbox.setSelected(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		textbox.setSelected(false);
	}

    // for typing into the textbox
    if (event.type == sf::Event::TextEntered)
    {
		textbox.type(event);
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (textbox.mouseHover(*window))
            {
                textbox.setSelected(true);
                textbox.setOutlineColor(sf::Color::Black);
            }
            else
            {
                textbox.setSelected(false);
                textbox.setOutlineColor(sf::Color(192, 192, 192, 250));
            }
        }
    }
} 