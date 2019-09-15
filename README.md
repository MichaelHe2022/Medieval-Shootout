# Medieval-Shootout
Original Game coded in C that mirrors a rock-paper-scissors type of game with added features.

How the program works: 
Medieval Shootout is a turn-based game where both players choose an action to perform each turn. There are three actions:
Up Button: Reload
Left Button: Shoot
Right Button: Shield
Down Button: Display Score
There is also an ammo variable to keep track of how many arrows you have to shoot with. This appears in the display score message when you press the down button
Turns happen with both players pressing a button AT THE SAME TIME. Based on what buttons each player chooses, an outcome displays.
If you both reload: Nothing happens, both ammo counts go up by 1
If you both shoot: Draw, both ammo counts go down by 1, both scores go down by 1
If you both shield: Nothing Happens, scores/ammo stay the same
If you shoot while opponent reloads: your score +1, your ammo -1, opponent ammo +1
If you shoot while opponent shields: Nothing happens, Scores stay the same, your ammo -1
If you reload while opponent shoots: opponent score +1, opponent ammo -1, your ammo +1
If you reload while opponent shields: Nothing happens, scores/ammo stay the same
If you shield while opponent shoots: Nothing happens, scores do not change, opponent ammo -1
If you shield while opponent reloads: Nothing happens, scores/ammo stay the same
If you try to shoot while HAVING NO AMMO while opponent reloads: Nothing happens, opponent ammo+1
If you try to shoot while HAVING NO AMMO while opponent shoots with ammo: Opponent score +1, your score-1, opponent ammo-1
If you try to shoot while HAVING NO AMMO while opponent shields: Nothing happens, score/ammo stay the same
First player to 3 points wins. Once a player has got 3 points, end message should print and exit the loop.

How to use the program:
Turns happen with both players pressing a button AT THE SAME TIME.  You can press the down button to check the score at any time, but make sure that when you are conducting a turn that both players simultaneously press a button (does not include down button).
