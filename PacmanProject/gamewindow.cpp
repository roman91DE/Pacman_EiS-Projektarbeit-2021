#include "gamewindow.h"
#include <QString>
#include <QMessageBox>
#include <QButtonGroup>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QString>
#include <iostream>


// Konstruktor für eine neue virtuelle Konsole mit Pacman Spiel
gameWindow::gameWindow(std::string lvl_ptr,int _difficultySelected, unsigned int numLines)
    : running(true), xPressed(false), difficultySelected(_difficultySelected) {

    current_game = new Game(lvl_ptr, difficultySelected, numLines);
    // sound effect settings for death and win
    deathSound = new QMediaPlayer(this);
    deathSound->setMedia(QUrl("qrc:/new/sounds/wav_sounds/cembalo-1.wav"));
    deathSound->setVolume(10000);
    winSound = new QMediaPlayer(this);
    winSound->setMedia(QUrl("qrc:/new/sounds/wav_sounds/cembalo-2.wav"));
    winSound->setVolume(10000);

}

gameWindow::~gameWindow() {
    delete current_game;
}

// Zeichnet alle Elemente des Spiels auf die virtuelle Konsole (wird rundenbasiert aufgerufen)
void gameWindow::drawCurrentState() {
    // draw  to console - overview of stats
    int buffer = 6;
    // pills collected
    QString pillString = (
    "Pills: " +  QString::number(current_game->score)
    + "/" + QString::number(current_game->total_pill_count));
    writeString(12,1,pillString.toStdString());
    // time to complete level
    QString time_string = "Timer:" + (QString::number(current_game->roundCount/5));
    writeString(42,1,time_string.toStdString());

    
    if (!xPressed) {
        QString exitInstruction = "Press x-Button to quit Level";
        writeString(12,0, exitInstruction.toStdString());
    }

    // draw map to console
    for (unsigned int iy = 0; iy < current_game->map->vec.size(); iy++) {
        for (unsigned int ix = 0; ix < current_game->map->vec[iy].size(); ix++) {
            setCharacter(ix,iy+buffer,  current_game->map->vec[iy][ix]);
        }
    }
    // draw player to console
    int x_player = current_game->player->getXPosition();
    int y_player = current_game->player->getYPosition();
    char repr_player = current_game->player->getRepresentation();
    setCharacter(x_player, y_player+buffer, repr_player);

    // draw aliens to console
    for (unsigned int i = 0; i < current_game->aliens.size(); i++) {
        int x_alien = current_game->aliens[i]->getXPosition();
        int y_alien = current_game->aliens[i]->getYPosition();
        char repr_alien =  current_game->aliens[i]->getRepresentation();
        setCharacter(x_alien, y_alien+buffer, repr_alien);
    }
}



// Die Funktion hat einen Bug den ich nicht beseitigen konnte, das Spiel kann mit dem Drücken auf die X-Taste mit Sicherheitsabfrage
// beendet werden, diese Option funktiert aber nur einziges mal pro Level, dannach ist die X-Taste gesperrt und die
// Option verschwindet aus dem Display (ansonsten erscheint die QMessageBox in einer Endlosschleife und ich habe nicht rausbekommen wo mein Fehler ist)
void gameWindow::exitGame() {
        xPressed = true;
        QMessageBox::StandardButton userInput;
        userInput = QMessageBox::question(this, "Exit Level?", "Warning - All your progress will be lost!", QMessageBox::Ok | QMessageBox::Cancel);
        if (userInput==QMessageBox::Ok) {
            QString message = "Exit Game";
            endGame(message);
        }
}

// Rundenbasierte Funktion
void gameWindow::onRefresh() {
    clear();
    drawCurrentState();
    current_game->moveAliens(current_game->player->getXPosition(), current_game->player->getYPosition());
    // check if player died
    if ((current_game->isAlive()==false) && running) {
        deathSound->play();
        QString str = "You are Dead!";
        endGame(str);
    }
    if (getPressedKey() == CURSOR_LEFT)     { current_game->movePlayer(1); }
    if (getPressedKey() == CURSOR_RIGHT)    { current_game->movePlayer(2); }
    if (getPressedKey() == CURSOR_UP)       { current_game->movePlayer(3); }
    if (getPressedKey() == CURSOR_DOWN)     { current_game->movePlayer(4); }
    if (getPressedKey() == X_BUTTON && (xPressed==false))    { exitGame(); }



    // check if level completed
    if (current_game->level_complete() && running) {
        winSound->play();
        int timeToFinish = current_game->roundCount/5;
        // score berechnet sich als: ( time_taken / pills_collected * 100) * schwierigkeitsmodifikator
        // modifikator: leicht*=1,0; mittel*=1,25; hardcore *=1,5
        double score = ((current_game->total_pill_count / timeToFinish)*100);
        if (difficultySelected > 0) {
            if (difficultySelected == 1) score *=1.25;
            else                         score +=1.5 ;
        }
        QString str = "You completed the Level!\n";
        str += "Total Time: " + (QString::number(timeToFinish)) + "Seconds\nYour Score:" + QString::number(score);
        endGame((str));
    }

    // update current state of the game
    current_game->update();

}

// Wird sowohl beim Tot von Pacman als auch beim Bestehen des Levels aufgerufen, str enthält je nachdem eine unterschiedliche
// Nachricht für den Spieler. Beendet das Spiel und schließt das aktuelle gameWindow 
void gameWindow::endGame(QString &str) {
    running = false;
    QMessageBox qMB(this);
    qMB.setText(str);
    qMB.exec();
    this->close();
}
