#include <iostream>
#include <vector>
#include <algorithm>

#define black_wins "Black wins.\n"
#define white_wins "White wins.\n"
#define tie "Tie.\n"
#define val_rank "23456789TJQKA"

struct Card
{
    char val;
    char suit;
};

struct CardVal
{
    char val;
    int count;
};

int main()
{
    while (std::cin)
    {
        std::pair<int, int> black = score();
        std::pair<int, int> white = score();
        if (black.first > white.first)
            std::cout << black_wins;
        else if (black.first < white.first)
            std::cout << white_wins;
        else
            if (black.second > white.second)
                std::cout << black_wins;
            else if (black.second < white.second)
                std::cout << white_wins;
            else
                std::cout << tie;
    }
}

std::pair<int, int> score()
{
    std::vector<Card> cards(5);
    for (int i = 0; i < 5; i++)
        cards[i] = read_card();

    // reduce
    std::vector<int> counts(13, 0);
    for (Card c : cards) 
        counts[rank(c.val)] += 1;
    
    std::vector<CardVal> vals;
    for (int i = 0; counts.size(); i++) {
        if (counts[i] > 0) {
            vals.push_back(CardVal{i, counts[i]});
        }
    }

    // TODO sort vals by count

    // TODO check for flush and straight flush

    int largest = vals.at(vals.size() - 1).count;
    if (largest >= 4) {
        // four of a kind
    } else if (largest == 3) {
        // three of a kind
    } else if (largest == 2) {
        if (vals.at(vals.size() - 2).count == 2) {
            // two pairs
        } else {
            // pair
        }
    } else {
        // high card
    }

    return std::make_pair(1, 1);
}

int rank(int val) {
    // TODO
    return -1;
}

Card read_card()
{
    char val;
    char suit;
    std::cin >> val;
    if (val == ' ')
        std::cin >> val;
    std::cin >> suit;
    return Card{val, suit};
}