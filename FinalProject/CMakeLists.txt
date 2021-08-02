cmake_minimum_required(VERSION 3.14)
project(FinalProject C)

set(CMAKE_C_STANDARD 11)

include_directories(Headers)

add_executable(FinalProject
        Headers/createBoard.h
        Headers/FindAllPossiblePlayerMoves.h
        Headers/FindSingleSourceMoves.h
       Headers/FindSingleSourceOptimalMove.h
        Headers/General.h
        Headers/Tree.h
       Headers/LoadBoard.h
        Headers/PlayGame.h
        Headers/StoreBoard.h
        Headers/Turn.h
        Headers/List.h
        Headers/printBoard.h
        Headers/File.h
        Headers/FindSingleSourceMoves.h
        Headers/TestingFindSingleSourceOptimalMove.h
       Headers/TestingFindAllPossiblePlayerMoves.h
        TestingFindAllPossiblePlayerMoves.c
        TestingFindSingleSourceMoves.c
        TestingFindSingleSourceOptimalMove.c
        List.c
        Tree.c
        createBoard.c
        FindAllPossiblePlayerMoves.c
        FindSingleSourceOptimalMove.c
        LoadBoard.c
        main.c
        File.c
       PlayGame.c
        StoreBoard.c
        Turn.c
        printBoard.c
        FindSingleSourceMoves.c
        )
