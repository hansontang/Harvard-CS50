#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string letter);
int count_words(string word);
int count_sentences(string sentence);

int main(void)
{
    string par = get_string("text: ");
    int letters = count_letters(par);
    int words = count_words(par);
    int sentences = count_sentences(par);

    double x = 0.0588 * (100 * (double) letters / words) - 0.296 * (100 * (double) sentences / words) - 15.8;

    if (x >= 0.5 && x < 16)
    {
        printf("Grade %d\n", (int) round(x));
    }
    else if (x < 0.5)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
int count_letters(string letter)
{
    int letters = 0;
    for (int i = 0; i < strlen(letter); i++)
    {
        if (isalpha(letter[i]))
            letters++;
    }
    return letters;
}

int count_words(string word)
{
    int words = 0;
    int cnt = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isspace(word[i]))
        {
            cnt++;
        }
    }
    words = cnt + 1;
    return words;
}

int count_sentences(string sentence)
{
    int sentences = 0;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
            sentences++;
    }
    return sentences;
}
