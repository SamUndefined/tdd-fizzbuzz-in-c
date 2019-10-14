#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char GREEN[] = "[0;32m";
char RED[] = "[0;31m";
char YELLOW[] = "[0;33m";
char RESET[] = "[0m";

char* fizzBuzz(char* input) {
    int num = atoi(input);
    char* answer;

    if (num % 3 == 0 && num % 5 == 0) {
        answer = "FizzBuzz";
    } else if (num % 3 == 0) {
        answer = "Fizz";
    } else if (num % 5 == 0) {
        answer = "Buzz";
    } else {
        answer = strdup(input);
    }

    return answer;
}

void consoleColor(char newColor[]) {
    printf("\033%s", newColor);
}

void assertThat(char testName[], char answer[], char expected[]) {
    if (strcmp(answer, expected) == 0) {
        consoleColor(GREEN);
        printf("PASSED - %s!\n", testName);
    } else {
        consoleColor(RED);
        printf("FAILED - %s: \n\n  ", testName);
        consoleColor(YELLOW);
        printf("Expected: %s\n  Actual: %s\n", expected, answer);
    }

    free(expected);

    consoleColor(RESET);
}

void shouldReturn1For1(void) {
    char* answer = fizzBuzz("1");
    char* expected = strdup("1");
    assertThat("Returns one for one", answer, expected);
}

void shouldReturn2For2(void) {
    char* answer = fizzBuzz("2");
    char* expected = strdup("2");
    assertThat("Returns two for two", answer, expected);
}

void shouldReturnFizzFor3(void) {
    char* answer = fizzBuzz("3");
    char* expected = strdup("Fizz");
    assertThat("Returns Fizz for three", answer, expected);
}

void shouldReturnFizzFor6(void) {
    char* answer = fizzBuzz("6");
    char* expected = strdup("Fizz");
    assertThat("Returns Fizz for six", answer, expected);
}

void shouldReturnBuzzFor5(void) {
    char* answer = fizzBuzz("5");
    char* expected = strdup("Buzz");
    assertThat("Returns Buzz for five", answer, expected);
}

void shouldReturnBuzzFor10(void) {
    char* answer = fizzBuzz("10");
    char* expected = strdup("Buzz");
    assertThat("Returns Buzz for ten", answer, expected);
}

void shouldReturnFizzBuzzFor15(void) {
    char* answer = fizzBuzz("15");
    char* expected = strdup("FizzBuzz");
    assertThat("Returns FizzBuzz for fifteen", answer, expected);
}

void shouldReturnFizzBuzzFor30(void) {
    char* answer = fizzBuzz("30");
    char* expected = strdup("FizzBuzz");
    assertThat("Returns FizzBuzz for thirty", answer, expected);
}

void runFizzBuzzTests(void) {
    shouldReturn1For1();
    shouldReturn2For2();
    shouldReturnFizzFor3();
    shouldReturnBuzzFor5();
    shouldReturnFizzFor6();
    shouldReturnBuzzFor10();
    shouldReturnFizzBuzzFor15();
    shouldReturnFizzBuzzFor30();
}

int main() {
    runFizzBuzzTests();
    return 0;
}
