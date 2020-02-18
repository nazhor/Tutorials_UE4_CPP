// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    int32 a = 1;
    int b = ++a;
    int c = ++ ++a; //Dont
    int d = a += 2;
    int e = a++;

    PrintLine(TEXT("%i, %i, %i, %i, %i"), a, b, c, d, e);


    if (bGameOver)
    {
        ClearScreen();
        EndGame();
    }
    else
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You win"));
            EndGame();
        }
        else
        {
            --Lives;
            if (Lives > 0)
            {
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Try again, you still have %i lives"), Lives);
                }
            }
            else
            {
                PrintLine(TEXT("The input word has an incorrect lenght\nthe hidden word has %i letters"), HiddenWord.Len());
                EndGame();
            }
        }
    }


    // if Input is valid then
    //  check word
    // else
    //  print fail msg
    //  remove life
    // if lives > 0
    //  try again loop
    // else
    //  lose msg
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Hi there! MOOO"));

    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Do you want to try again?"));
}