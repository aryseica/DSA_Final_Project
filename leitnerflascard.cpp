#include <iostream>
#include <string>

using namespace std;

struct Flashcard {
    string word;
    string definition;
    int level = 1;
};

//create flashcard container
struct ReviewQueue {
    int indices[50];
    int front = 0;
    int back = 0;

    void push(int cardIndex) {
        indices[back++] = cardIndex;
    }

    int pop() {
        return indices[front++];
    }

    bool isEmpty() {
        return front == back;
    }

    void reset() {
        front = 0;
        back = 0;
    } //if no cards on the deck and user chooses 2 (review)
};

int main() {
    Flashcard deck[50];
    int currentSize = 0;
    ReviewQueue q;
    int choice;

    //let user choose to add cards, review, or exit (mimics interface nung anu)
    while (true) {
        cout << "\n--- LEITNER CONSOLE ---\n1. Add Card\n2. Review (Lvl 1 Priority)\n3. Exit\nChoice: ";
        if (!(cin >> choice)) break;
        cin.ignore();

        //adds card (word + definition) 
        if (choice == 1) {
            if (currentSize < 50) {
                cout << "Word: ";
                getline(cin, deck[currentSize].word);
                cout << "Definition: ";
                getline(cin, deck[currentSize].definition);
                currentSize++;
            }
        } 

        //review cards
        else if (choice == 2) {
            if (currentSize == 0) {
                cout << "No cards available.\n";
                continue;
            }

            q.reset(); //back to leitner console

            // Level 1 card in the queue first
            for (int i = 0; i < currentSize; i++) {
                if (deck[i].level == 1) q.push(i);
            }

            // Level 2 up
            for (int i = 0; i < currentSize; i++) {
                if (deck[i].level > 1) q.push(i);
            }

            // queue, if right = level up, otherwise it stays level 1 or resets to level 1
            cout << "\n--- Starting Review ---\n";
            while (!q.isEmpty()) {
                int idx = q.pop();
                cout << "\n[Level " << deck[idx].level << "] Word: " << deck[idx].word << "\nAnswer: ";
                
                string userAns;
                getline(cin, userAns);

                if (userAns == deck[idx].definition) {
                    if (deck[idx].level < 5) deck[idx].level++;
                    cout << "Correct! Promoted.\n";
                } else {
                    deck[idx].level = 1;
                    cout << "Wrong! Reset to Level 1. ";
                    cout << "\nAnswer: " << deck[idx].definition << "\n";
                }
            }
            cout << "\nReview session complete!\n";
        } 
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}