#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include <iostream>

#include "../JuceLibraryCode/JuceHeader.h"

#include "gameCanvas.h"
#include "customButton.h"
#include "settingsWindow.h"


class MainContentComponent:
    public Component,
    public Timer,
    public Button::Listener {
public:
    int gameMapWidth = 300;
    int gameMapHeight = 220;
    char gameCellSize = 3;

    int bar = 130;

    // TODO: encapsulate labels
    Label* labelMapSize;

    Label* labelFrame;
    Label* labelFps;
    Label* labelAlive;
    Label* labelHistory;
    Label* labelRam;

    Label* labelDStep;
    Label* labelDDraw;

    Label* labelMouseX;
    Label* labelMouseY;

    Label* labelPenWidth;

    MainContentComponent();
    ~MainContentComponent() override;

    void playCallback();
    void newGameCallback();
    void clearCallback();
    void drawCallback();

    void timerCallback() override;
    void buttonClicked(Button* button) override;
    bool keyPressed(const KeyPress& key) override;
    void resized() override;

private:
    time_t startTime = 0;

    CustomButton* buttonNewGame;
    CustomButton* buttonPlay;
    CustomButton* buttonClear;
    CustomButton* buttonDraw;

    CustomButton* buttonSettings;
    SettingsWindow* settingsW;

    GameCanvas canvas;

    void initMainW();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
};

#endif
