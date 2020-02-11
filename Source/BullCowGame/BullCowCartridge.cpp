// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hi there! MOOO"));
    PrintLine(TEXT("Time to play"));

    SetupGame();

    PrintLine(TEXT("Guess the %i letter word..."), HiddenWord.Len());
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You win"));
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The input word has an incorrect lenght\n the hidden word has %i letters"), HiddenWord.Len());
        }

        PrintLine(TEXT("Try again"));
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
    HiddenWord = TEXT("cake");
    Lives = 4;
}