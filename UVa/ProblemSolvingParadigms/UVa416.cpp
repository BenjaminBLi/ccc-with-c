#include <bits/stdc++.h>
using namespace std;

int leds[12], N, n[10];
string line;

void genn() {
    memset(n, 0, sizeof n);
    // Zero
    for (int i=0 ; i<6 ; i++)
        n[0] |= (1 << i);
    // One
    n[1] |= (1 << 1);
    n[1] |= (1 << 2);
    // Two
    n[2] |= (1 << 0);
    n[2] |= (1 << 1);
    n[2] |= (1 << 3);
    n[2] |= (1 << 4);
    n[2] |= (1 << 6);
    // Three
    for (int i=0 ; i<4 ; i++)
        n[3] |= (1 << i);
    n[3] |= (1 << 6);
    // Four
    n[4] |= (1 << 1);
    n[4] |= (1 << 2);
    n[4] |= (1 << 5);
    n[4] |= (1 << 6);
    // Five
    n[5] |= (1 << 0);
    n[5] |= (1 << 2);
    n[5] |= (1 << 3);
    n[5] |= (1 << 5);
    n[5] |= (1 << 6);
    // Six
    n[6] |= (1 << 0);
    for (int i=2 ; i<7 ; i++)
        n[6] |= (1 << i);
    // Seven
    n[7] |= (1 << 0);
    n[7] |= (1 << 1);
    n[7] |= (1 << 2);
    // Eight
    for (int i=0 ; i<7 ; i++)
        n[8] |= (1 << i);
    // Nine
    for (int i=0 ; i<4 ; i++)
        n[9] |= (1 << i);
    n[9] |= (1 << 5);
    n[9] |= (1 << 6);
}

int check(int ledState, int numberToForm, int ledsTurnedOff) {
    int newNumber = n[numberToForm];

    for (int i=0 ; i<7 ; i++) {
        if (ledsTurnedOff & (1 << i)) {
            newNumber &= ~(1 << i);
        }
    }

    int ledsOn = __builtin_popcount(newNumber);
    if (__builtin_popcount(newNumber | ledState) == ledsOn) {
        for (int i=0 ; i<7 ; i++) {
            if ((newNumber & (1 << i)) && !(ledState & (1 << i)))
                ledsTurnedOff |= (1 << i);
        }
        return ledsTurnedOff;
    }
    return -1;
}

bool solve(int ledIndex, int countDown, int turnedOff) {
    if (countDown < 0) return false;
    if (ledIndex == N) return true;
    int newTurnedOff = check(leds[ledIndex], countDown-1, turnedOff);
    if (newTurnedOff != -1)
        return solve(ledIndex+1, countDown-1, newTurnedOff);

    return false;
}

int main() {

    genn();

    while (scanf("%d\n", &N), N) {
        memset(leds, 0, sizeof leds);
        for (int i=0 ; i<N ; i++) {
            getline(cin, line);

            for (int j=0 ; j<7 ; j++) if (line[j] == 'Y')
                leds[i] |= (1 << j);
        }
        bool solved = false;
        for (int i=9 ; i>=0 ; i--) {
            int ledsOn = __builtin_popcount(n[i]);
            if (__builtin_popcount(leds[0] | n[i]) == ledsOn) {
                int turnedOff = 0;
                for (int j=0 ; j<7 ; j++) {
                    if ((n[i] & (1 << j)) && !(leds[0] & (1 << j))) {
                        turnedOff |= (1 << j);
                    }
                }
                if (solve(1, i, turnedOff)) {
                    printf("MATCH\n");
                    solved = true;
                    break;
                }
            }
        }

        if (!solved)
            printf("MISMATCH\n");
    }
}
