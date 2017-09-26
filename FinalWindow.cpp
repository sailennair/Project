#include "FinalWindow.h" 
 
FinalWindow::FinalWindow(unsigned int x, unsigned int y): _width(x), _height(y){ 
    loadText(); 
    setUpWindow(); 
} 
 
//Sets up Window dimensions and Settings 
void FinalWindow::setUpWindow(){ 
    _window.create(VideoMode(_width, _height), "Gyruss"); 
    _window.setMouseCursorVisible(false); 
    _window.setVerticalSyncEnabled(true); 
 
} 
 
// Loads Font 
void FinalWindow::loadText(){ 
    //Loading Font 
    if(!_font.loadFromFile("sansation.ttf")){ 
    std::cerr << "Error Loading the FinalWindwo font"; 
    } 
     
    //PlayerLost Message set up 
    _playerLostOrWonMessage.setFont(_font); 
    int xPos = ((_width/2) - 5*(_prompUserToContinue.getCharacterSize())); 
    _playerLostOrWonMessage.setCharacterSize(20); 
    _playerLostOrWonMessage.setPosition(xPos, 0); 
     
    _continueOrQuitMessage.setFont(_font); 
     
    _prompUserToContinue.setFont(_font); 
    _prompUserToContinue.setString("To Continue Press SPACEBAR or To Quit Pess ESC"); 
    _prompUserToContinue.setCharacterSize(20); 
    xPos = ((_width/2) - 10*(_prompUserToContinue.getCharacterSize())); 
    int yPos = _height/2 - 100; 
    _prompUserToContinue.setPosition(xPos, yPos); 
 
 
} 
 
void FinalWindow::run(){ 
    while(_window.isOpen()){ 
   
        Event event; 
        while(_window.pollEvent(event)){ 
             
            if(didPlayerLoseGame()){ 
                _playerLostOrWonMessage.setString("Sorry, You have Lost the Game"); 
            } 
            else{ 
                _playerLostOrWonMessage.setString("CONGRATULATIONS, You have WON the Game!!"); 
            } 
             
            if(event.type == Event::KeyPressed){    // Need to check this because mouse was been picked up as input 
                hadleUserDecision(event);   
                 
            } 
  
            if(event.type ==  Event::Closed){ 
                _window.close(); 
                break; 
            }          
        } 
         
             
        _window.clear(Color::Black); 
        _window.draw( _prompUserToContinue); 
        _window.draw( _playerLostOrWonMessage); 
        _window.draw(_continueOrQuitMessage); 
        _window.display(); 
         
         
     } 
} 
 
void FinalWindow::hadleUserDecision(const Event& event){ 
        if(event.key.code == Keyboard::Space){    
            _continueOrQuitMessage.setFont(_font); 
            _continueOrQuitMessage.setString("Good Luck Player!!"); 
            _continueOrQuitMessage.setCharacterSize(30); 
            _continueOrQuitMessage.setPosition((_width/2 - 3*_continueOrQuitMessage.getCharacterSize()) , _height/2); 
         
            _window.clear(Color::Black); 
            _window.draw(_continueOrQuitMessage); 
            _window.display(); 
             
            sleep(milliseconds(1500)); 
            _isPlayerQuitting = false; 
            _window.close(); 
        } 
         
        if(event.key.code == Keyboard::Escape){ 
             _continueOrQuitMessage.setFont(_font); 
            _continueOrQuitMessage.setString("Good Bye See You Soon"); 
            _continueOrQuitMessage.setCharacterSize(24); 
            _continueOrQuitMessage.setPosition((_width/2 - 4*_continueOrQuitMessage.getCharacterSize()) , _height/2); 
         
            _window.clear(Color::Black); 
            _window.draw(_continueOrQuitMessage); 
            _window.display(); 
             
            sleep(milliseconds(1500)); 
            _isPlayerQuitting = true; 
            _window.close(); 
        } 
} 
 
 
/// STATUS QUERY FUNCTIONS 
bool FinalWindow::isPlayerQuittingGame(){ 
    return _isPlayerQuitting; 
} 
 
bool FinalWindow::didPlayerLoseGame(){ 
    return _didPlayerLose; 
} 
 
///STATUS SETTING FUNCTINOS 
void FinalWindow::setQuittingGame(bool decision){ 
   _isPlayerQuitting = decision; 
} 
 
void FinalWindow::setPLayerLostGame(bool status){ 
     _didPlayerLose = status; 
}