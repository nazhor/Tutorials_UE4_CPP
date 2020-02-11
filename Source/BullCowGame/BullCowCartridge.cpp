// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
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
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The input word has an incorrect lenght\nthe hidden word has %i letters"), HiddenWord.Len());
                PrintLine(TEXT("Try again"));
            }

            if (Lives == 0)
            {
                EndGame();
            }
        }
    }
    //if Input is valid then
    //  check word
    //else
    //  print fail msg
    //  remove life
    //if lives > 0
    //  try again loop
    //else
    //  lose msg
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Hi there! MOOO"));

    HiddenWord = TEXT("cake");
    Lives = 4;
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Do you want to try again?"));
}