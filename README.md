# Tic-Tac-Toe
A simple Tic-Tac-Toe game in C++ played in the terminal. This little game is based on a [Neps Academy](https://neps.academy/br/dashboard) project with the same name ([Tic-Tac-Toe](https://neps.academy/project/22))

## Playing Tic-Tac-Toe
At the beginning, we have a 3x3 board, numbered from 1 to 9, like this:
![board](assets/insidegame.png)

---

Now it's time for the first player (X) to choose one of the nine positions (making sure to not pick an already marked one). <br />
![choose](assets/choosing.png)

---

Once the position is choosen, the board updates: <br />
![newboard](assets/newboard.png)

---

Finally, the second player (O) has to choose one remaining position, and this way the game keeps running.
In case of someone wins or draws, a message like this will appear:
![final](assets/winmessage.png)

---

## What is needed to play
- To be able to play Tic-Tac-Toe, you'll need the GCC compiler instaled on your system, so in case you don't have it installed yet, check it out here: [GCC Compilator](https://gcc.gnu.org/install/)
- If you use Windows, you can learn how to install GCC here: [GCC on Windows](https://gcc.gnu.org/install/binaries.html)

---

## Licence
This project is licensed under the MIT license. For more information, see the [License](LICENSE) file.