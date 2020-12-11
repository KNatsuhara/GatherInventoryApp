/********************************************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * ******************************************************************/

#include "UserPage.hpp"

// Page Components 
namespace
{
    sf::Text titleText, list;
    sf::Sprite sprite;
    sf::Texture texture;
    Button settings, home;
    Button i1;
    //Button i1(sf::Color::White, sf::Color(154, 134, 186, 130), 50, "Item 1", {300, 45});
    Button i2(sf::Color::White, sf::Color(154, 134, 186, 145), 30, "Item 2", {300, 45});
    Button i3(sf::Color::White, sf::Color(154, 134, 186, 160), 30, "Item 3", {300, 45});
    Button i4(sf::Color::White, sf::Color(154, 134, 186, 185), 30, "Item 4", {300, 45});
    Button i5(sf::Color::White, sf::Color(154, 134, 186, 120), 30, "Item 5", {300, 45});
    Button i6(sf::Color::White, sf::Color(154, 134, 186, 215), 30, "Item 6", {300, 45});
    Button i7(sf::Color::White, sf::Color(154, 134, 186, 230), 30, "Item 7", {300, 45});
    Button i8(sf::Color::White, sf::Color(154, 134, 186, 255), 30, "Item 8", {300, 45});
}

/**********************************************************
*  Create all the components for the page.                *
***********************************************************/
void UserPage::createPage()
{
    /**** Title text ****/
    titleText.setString("List");
    titleText.setFont(font);
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(400 - titleText.getLocalBounds().width / 2, 50);

    /**** Title Bar ****/
    if (!texture.loadFromFile("./Images/Gather Purple Banner.png", sf::IntRect(0, 160, 800, 190)))
    {
        std::cout << "\nTitle Bar image could not be loaded from the file.\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);

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

    /**** List Text ****/ 
    list.setString("Inventory List: ");
    list.setFont(font);
    list.setCharacterSize(40);
    list.setFillColor(sf::Color(195, 141, 162, 255));
    list.setPosition(75, 250);

    i1.setPosition({150, 350});
    i2.setPosition({150, 400});
    i3.setPosition({150, 450});
    i4.setPosition({150, 500});
    i5.setPosition({150, 550});
    i6.setPosition({150, 600});
    i7.setPosition({150, 650});
    i8.setPosition({150, 700});

    i1.setButtonColor(sf::Color(154, 134, 186, 130));
    i1.setTextColor(sf::Color::White);
    i1.setText("Item 1");
    i1.setTextSize(25);
    i1.setSize({ 300, 45 });
    i1.setFont(font);

    i2.setButtonColor(sf::Color(154, 134, 186, 145));
    i2.setTextColor(sf::Color::White);
    i2.setText("Item 2");
    i2.setTextSize(25);
    i2.setSize({ 300, 45 });
    i2.setFont(font);

    i3.setButtonColor(sf::Color(154, 134, 186, 160));
    i3.setTextColor(sf::Color::White);
    i3.setText("Item 3");
    i3.setTextSize(25);
    i3.setSize({ 300, 45 });
    i3.setFont(font);

    i4.setButtonColor(sf::Color(154, 134, 186, 185));
    i4.setTextColor(sf::Color::White);
    i4.setText("Item 4");
    i4.setTextSize(25);
    i4.setSize({ 300, 45 });
    i4.setFont(font);

    i5.setButtonColor(sf::Color(154, 134, 186, 200));
    i5.setTextColor(sf::Color::White);
    i5.setText("Item 5");
    i5.setTextSize(25);
    i5.setSize({ 300, 45 });
    i5.setFont(font);

    i6.setButtonColor(sf::Color(154, 134, 186, 215));
    i6.setTextColor(sf::Color::White);
    i6.setText("Item 6");
    i6.setTextSize(25);
    i6.setSize({ 300, 45 });
    i6.setFont(font);

    i7.setButtonColor(sf::Color(154, 134, 186, 230));
    i7.setTextColor(sf::Color::White);
    i7.setText("Item 7");
    i7.setTextSize(25);
    i7.setSize({ 300, 45 });
    i7.setFont(font);

    i8.setButtonColor(sf::Color(154, 134, 186, 255));
    i8.setTextColor(sf::Color::White);
    i8.setText("Item 8");
    i8.setTextSize(25);
    i8.setSize({ 300, 45 });
    i8.setFont(font);

}

/**********************************************************
*  Draw the page to the window.                           *
***********************************************************/
void UserPage::drawPage(void)
{
    /*** Item Button Positions ****/ 
    i1.setPosition({150, 350});
    i2.setPosition({150, 400});
    i3.setPosition({150, 450});
    i4.setPosition({150, 500});
    i5.setPosition({150, 550});
    i6.setPosition({150, 600});
    i7.setPosition({150, 650});
    i8.setPosition({150, 700});
    
    /**** Draw ****/
    window->draw(sprite);
    window->draw(titleText);
    settings.drawTo(*window);
    home.drawTo(*window);
    window->draw(list);
    i1.drawTo(*window);
    i2.drawTo(*window);
    i3.drawTo(*window);
    i4.drawTo(*window);
    i5.drawTo(*window);
    i6.drawTo(*window);
    i7.drawTo(*window);
    i8.drawTo(*window);
    
} 

/**********************************************************
*  Perform the event operations.                          *
***********************************************************/
void UserPage::eventOperation(const sf::Event & event)
{
    // Change color of the buttons when mouse hovers over it
    if (event.type == sf::Event::MouseMoved)
    {
        if (i1.mouseHover(*window))
            i1.setButtonColor(sf::Color(154, 134, 186, 100));   // changes color of about button
        else 
            i1.setButtonColor(sf::Color(154, 134, 186, 130));   // keep the color the same

        if (i2.mouseHover(*window))
            i2.setButtonColor(sf::Color(154, 134, 186, 100));    //changes color of inventory button
        else 
            i2.setButtonColor(sf::Color(154, 134, 186, 145));    // keep the color the same

        if (i3.mouseHover(*window))
            i3.setButtonColor(sf::Color(154, 134, 186, 100));    //changes color of inventory button
        else 
            i3.setButtonColor(sf::Color(154, 134, 186, 160));    // keep the color the same

        if (i4.mouseHover(*window))
            i4.setButtonColor(sf::Color(154, 134, 186, 100));    //changes color of inventory button
        else 
            i4.setButtonColor(sf::Color(154, 134, 186, 185));    // keep the color the same

        if (i5.mouseHover(*window))
            i5.setButtonColor(sf::Color(154, 134, 186, 100));    //changes color of inventory button
        else 
            i5.setButtonColor(sf::Color(154, 134, 186, 200));    // keep the color the same

        if (i6.mouseHover(*window))
            i6.setButtonColor(sf::Color(154, 134, 186, 100));    //changes color of inventory button
        else 
            i6.setButtonColor(sf::Color(154, 134, 186, 215));    // keep the color the same

        if (i7.mouseHover(*window))
            i7.setButtonColor(sf::Color(154, 134, 186, 100));    //changes color of inventory button
        else 
            i7.setButtonColor(sf::Color(154, 134, 186, 230));    // keep the color the same

        if (i8.mouseHover(*window))
            i8.setButtonColor(sf::Color(154, 134, 186, 100));    //changes color of inventory button
        else 
            i8.setButtonColor(sf::Color(154, 134, 186, 255));    // keep the color the same
    }

    // If a button was pressed, perform the operation tied to the button
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (settings.mouseHover(*window))       // if the settings button is pressed, change to settings page
        {
            changePage = true;
            newPage = Page::CurrentPage::SettingsPage;
        }
        if (home.mouseHover(*window))           // if the home button is pressed, change to home page
        {
            changePage = true;
            newPage = Page::CurrentPage::HomePage;
        }
        
    }

    // Press Esc to exit the application
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		(*window).close();              // close window
	}
} 