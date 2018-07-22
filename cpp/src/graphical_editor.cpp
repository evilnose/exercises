#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <limits>

class Editor;

typedef void (Editor::*pfunc)();

struct pt
{
    unsigned x;
    unsigned y;
};

class Editor
{
    std::vector<std::vector<char>> canvas;
    std::map<char, pfunc> funcMap;

    std::vector<int> params;
    char c;
    std::string name;

  public:
    Editor() noexcept
    {
        funcMap['I'] = &Editor::init;
        funcMap['C'] = &Editor::clear;
        funcMap['L'] = &Editor::color;
        funcMap['V'] = &Editor::vert;
        funcMap['H'] = &Editor::horiz;
        funcMap['K'] = &Editor::rect;
        funcMap['F'] = &Editor::fill;
        funcMap['S'] = &Editor::save;
    }

    void start()
    {
        bool cont;
        do
        {
            cont = this->next_cmd();
        } while (cont);
    }

  private:
    bool next_cmd()
    {
        char cname;
        std::cin >> cname;
        if (cname == 'X')
            return false;
        pfunc f = this->funcMap[cname];
        if (f != NULL)
        {
            (*this.*(f))();
        }
        else
        {
            // clear line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return true;
    }

    void init()
    {
        this->read_ints(2);
        unsigned m = this->params[0];
        unsigned n = this->params[1];
        this->canvas = std::vector<std::vector<char>>(n, std::vector<char>(m, '0'));
    }

    void clear()
    {
        for (int y = 0; y < this->canvas.size(); y++)
        {
            for (int x = 0; x < this->canvas[0].size(); x++)
            {
                canvas[y][x] = '0';
            }
        }
    }

    void color()
    {
        this->read_ints(2);
        unsigned x = this->params[0] - 1;
        unsigned y = this->params[1] - 1;
        std::cin >> this->c;
        canvas[y][x] = c;
    }

    void vert()
    {
        this->read_ints(3);
        unsigned x = this->params[0] - 1;
        unsigned y1 = this->params[1] - 1;
        unsigned y2 = this->params[2] - 1;
        std::cin >> this->c;
        if (y1 > y2)
            std::swap(y1, y2);
        for (unsigned y = y1; y <= y2; y++)
        {
            this->canvas[y][x] = this->c;
        }
    }

    void horiz()
    {
        this->read_ints(3);
        unsigned x1 = this->params[0] - 1;
        unsigned x2 = this->params[1] - 1;
        unsigned y = this->params[2] - 1;
        std::cin >> this->c;
        if (x1 > x2)
            std::swap(x1, x2);
        for (unsigned x = x1; x <= x2; x++)
        {
            this->canvas[y][x] = this->c;
        }
    }

    void rect()
    {
        this->read_ints(4);
        unsigned x1 = this->params[0] - 1;
        unsigned y1 = this->params[1] - 1;
        unsigned x2 = this->params[2] - 1;
        unsigned y2 = this->params[3] - 1;
        std::cin >> this->c;
        if (x1 > x2)
            std::swap(x1, x2);
        if (y1 > y2)
            std::swap(y1, y2);
        for (unsigned y = y1; y <= y2; y++)
        {
            for (unsigned x = x1; x <= x2; x++)
            {
                this->canvas[y][x] = this->c;
            }
        }
    }

    void fill()
    {
        this->read_ints(2);
        int x = this->params[0] - 1;
        int y = this->params[1] - 1;
        std::cin >> this->c;

        // BFS
        std::vector<pt> q;
        pt o = {(unsigned)x, (unsigned)y};
        q.push_back(o);
        char old_c = this->canvas[y][x];
        pt p;
        while (!q.empty())
        {
            p = q[0];
            q.erase(q.begin());
            if (this->canvas[p.y][p.x] == this->c)
                continue;

            this->canvas[p.y][p.x] = this->c;	

            this->try_add(q, p.x + 1, p.y, old_c);
            this->try_add(q, p.x - 1, p.y, old_c);
            this->try_add(q, p.x, p.y - 1, old_c);
            this->try_add(q, p.x, p.y + 1, old_c);
        }
    }

    void save()
    {
        std::cin >> this->name;
        for (int r = 0; r < this->canvas.size(); r++)
        {
            for (int c = 0; c < this->canvas[0].size(); c++)
            {
                std::cout << this->canvas[r][c];
            }
            std::cout << std::endl;
        }
    }

    void read_ints(unsigned n)
    {
        this->params.clear();
        this->params.reserve(n);
        int t;
        for (unsigned i = 0; i < n; i++)
        {
            std::cin >> t;
            this->params.push_back(t);
        }
    }

    void try_add(std::vector<pt> &q, int x, int y, char old_c)
    {
        if (x < 0 || x >= this->canvas[0].size() || y < 0 || y >= this->canvas.size())
            return;
        
        // std::cout << this->canvas[y][x] << " ?= " << old_c << std::endl;
        if (this->canvas[y][x] == old_c)
        {
            pt n = {(unsigned)x, (unsigned)y};
            q.push_back(n);
        }
    }
};

int graphical_editor()
{
    Editor e;
    e.start();
	return 0;
}