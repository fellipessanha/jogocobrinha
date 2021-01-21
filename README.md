# jogo dacobrinha; or the snek game

## Controls

The controls are wasd, as usual.

## Game description and story

When you, the snek (``Snk``; ``Snek``; ``Sneeek``, depending on your size), eat a frut ( ``0`` ), you score and get bigger. Each frut is worth 1 more than the last.

if you hit any wall ('``#``' or '``!``'), or any part of your body (the ' ``S`` ' hits '``n``', '``e``' or '``k``'), the game is over, and you probably don't want that. You have 20x20 pixels to navigate

The fruts are always spawning in the same locations so you may practice that specific game until i feel like fixing that. But as of right now I'll say it's on purpose so the game has a more competitive cadence

The screen flickers a bit because the render of the game is your processor clearing the screen and rewriting averything in there.

The whole story is that there is a snek who is really hungry for fruts, and grows really fast when it eats, as per usual snek behavior.

## If you really want to play

You should be able to just download the snekGame.exe file and have fun.

## Do whatever you want with the code

if you want to do something to the code you can just do github things and clone it and things it as you see fit.

``snek.h`` the general snek body, and aldo the controls, collisions, initiating the snek, and movement

``visuals.h`` controls the barely functioning graphics

``frut.h`` controls the frut spawning and the scores
