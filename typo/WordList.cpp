#include "WordList.h"
#include <istream>
#include <string>

WordList::WordList(std::istream& stream)
{
    std::string word;
    while (std::getline(stream, word))
    {
        if (word[0] == '$')
        {
            continue;
        }

        if (word[word.length() - 1] == '\r')
        {
            word = word.substr(0, word.size() - 1);
        }

        bool isValidWord = true;
        for (char c : word)
        {
            if (c < 'a' || c > 'z')
            {
                isValidWord = false;
                break;
            }
        }

        if (isValidWord)
        {
            mWords.push_back(word);
        }
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount) const
{
    Heap heap(maxcount);

    for (const std::string& word : mWords)
    {
        if (word.length() != points.size())
        {
            continue;
        }

        float score = 0;
        for (size_t i = 0; i < word.size(); i++)
        {
            const Point& p = QWERTY[word[i] - 'a'];
            float distanceSquared = (points[i].x - p.x) * (points[i].x - p.x) 
                                   + (points[i].y - p.y) * (points[i].y - p.y);
            score += 1 / (10 * distanceSquared + 1);
        }

        score /= word.size();
        if (heap.size() < maxcount)
        {
            heap.push(word, score);
        }
        else if (score > heap.top().score)
        {
            heap.pop();
            heap.push(word, score);
        }
    }

    return heap;
}