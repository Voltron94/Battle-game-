@echo off
rem Compilation des fichiers sources avec g++
g++ -std=c++23 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -o prog.exe D:\Code\Code\C++\Projet\battle_game\source\player.cpp D:\Code\Code\C++\Projet\battle_game\source\mob.cpp D:\Code\Code\C++\Projet\battle_game\source\game.cpp D:\Code\Code\C++\Projet\battle_game\source\Battle.cpp D:\Code\Code\C++\Projet\battle_game\main.cpp 

rem Exécution du programme compilé
if exist prog.exe (
    echo Lancement du programme...
    start "" "prog.exe"
    timeout /t 99 /nobreak
) else (
    echo La compilation a échoué.
        timeout /t 99 /nobreak
)
pause