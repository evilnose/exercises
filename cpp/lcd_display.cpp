#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class RowPos {
    TOP,
    TOP_MID,
    MID,
    BOT_MID,
    BOT
};

enum class ColPos {
    L,
    R,
    MID
};

typedef std::pair<RowPos, ColPos> Pos;
typedef std::map<Pos, char> charmap;

const char *DIGITS[]{
    " - "
    "| |"
    "   "
    "| |"
    " - ",

    "   "
    "  |"
    "   "
    "  |"
    "   ",

    " - "
    "  |"
    " - "
    "|  "
    " - ",

    " - "
    "  |"
    " - "
    "  |"
    " - ",

    "   "
    "| |"
    " - "
    "  |"
    "   ",

    " - "
    "|  "
    " - "
    "  |"
    " - ",

    " - "
    "|  "
    " - "
    "| |"
    " - ",

    " - "
    "  |"
    "   "
    "  |"
    "   ",

    " - "
    "| |"
    " - "
    "| |"
    " - ",

    " - "
    "| |"
    " - "
    "  |"
    " - "};


Pos getpos(int r, int c, int nrows, int ncols)
{
    RowPos rp;
    ColPos cp;

    if (r < nrows/2)
        if (r == 0)
            rp = RowPos::TOP;
        else
            rp = RowPos::TOP_MID;
    else if (r > nrows/2)
        if (r == nrows - 1)
            rp = RowPos::BOT;
        else
            rp = RowPos::BOT_MID;
    else
        rp = RowPos::MID;

    if (c == 0)
        cp = ColPos::L;
    else if (c == ncols - 1)
        cp = ColPos::R;
    else
        cp = ColPos::MID;

    return std::make_pair(rp, cp);
}

void load_maps(charmap maps[])
{
    unsigned nrows = 5;
    unsigned ncols = 3;
    for (unsigned i = 0; i < 10; i++)
        for (unsigned r = 0; r < 5; r++)
            for (unsigned c = 0; c < 5; c++)
                maps[i].insert(std::make_pair(getpos(r, c, nrows, ncols), DIGITS[i][r*ncols + c]));
}

unsigned *to_digits(unsigned a[], std::string s)
{
    unsigned i = 0;
    for (char c : s)
        a[i++] = c - '0';
    return a;
}

int main()
{
    charmap maps[10];
    load_maps(maps);
    unsigned s;
    std::string n;

    unsigned ncols;
    unsigned nrows;
    std::pair<RowPos, ColPos> pos;
    char ch;
    while (std::cin >> s >> n && s != 0)
    {
        ncols = s + 2;
        nrows = 2 * s + 3;
        unsigned digits[n.length()];
        to_digits(digits, n);
        for (unsigned r = 0; r < nrows; r++)
        {
            for (unsigned i = 0; i < n.length(); i++) {
                for (unsigned c = 0; c < ncols; c++)
                    std::cout << maps[digits[i]][getpos(r, c, nrows, ncols)];
                if (i != n.length() - 1)
                    std::cout << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}