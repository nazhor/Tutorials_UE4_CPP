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
        EndGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Hi there! MOOO"));

    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Press enter to continue..."));

    // const TCHAR HW[] = TEXT("plums");
    // PrintLine(TEXT("Character 1 of the hidden word is %c"), HiddenWord[0]);
    // PrintLine(TEXT("Character 4 of HW is %c"), HW[3]);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Do you want to try again?"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You win"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The input word has an incorrect lenght\nthe hidden word has %i letters"), HiddenWord.Len());
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters"));
        return;
    }

    --Lives;
    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
        EndGame();
        return;
    }

    PrintLine(TEXT("Try again, you still have %i lives"), Lives);

}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    // for (; Comparison < Word.Len(); Comparison++)
    // {
    // }

    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                PrintLine(TEXT("No luck"));
                return false;
            }
        }
    }

    return true;
}